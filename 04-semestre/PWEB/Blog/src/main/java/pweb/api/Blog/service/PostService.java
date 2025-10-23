package pweb.api.Blog.service;

import jakarta.transaction.Transactional;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.stereotype.Service;
import pweb.api.Blog.dto.PostDto;
import pweb.api.Blog.dto.PostFormDto;
import pweb.api.Blog.model.Post;
import pweb.api.Blog.repository.PostRepository;

import java.util.List;

@Service
public class PostService {

    private final PostRepository postRepository;

    public PostService(PostRepository postRepository) {
        this.postRepository = postRepository;
    }

    public Page<PostDto> getAll(Pageable pageable) {
        return this.postRepository.findAll(pageable).map(PostDto::new);
    }

    public PostDto getOne(Long id) {
        Post post = this.postRepository.findById(id).orElse(null);
        return post != null ? PostDto.fromPost(post) : null;
    }

    public Page<PostDto> getByTitle(Pageable pageable, String title) {
        return this.postRepository.findByTitleContainingIgnoreCase(title, pageable).map(PostDto::new);
    }

    @Transactional
    public PostDto save(PostFormDto post) {
        return PostDto.fromPost(this.postRepository.save(new Post(post)));
    }

    @Transactional
    public PostDto update(Long id, PostFormDto updatedPost) {
        Post post = this.postRepository.findById(id).orElse(null);
        if(post == null) {
            return null;
        }
        post.setTitle(updatedPost.title());
        post.setContent(updatedPost.content());
        post.setCategory(updatedPost.category());
        post.setUser(updatedPost.user());
        return PostDto.fromPost(this.postRepository.save(post));
    }

    @Transactional
    public void delete(Long id) {
        this.postRepository.deleteById(id);
    }
}
