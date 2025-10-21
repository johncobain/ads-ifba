package pweb.api.Blog.service;

import jakarta.transaction.Transactional;
import org.springframework.stereotype.Service;
import pweb.api.Blog.dto.PostDto;
import pweb.api.Blog.dto.PostFormDto;
import pweb.api.Blog.model.Post;
import pweb.api.Blog.model.User;
import pweb.api.Blog.repository.PostRepository;

import java.util.List;

@Service
public class PostService {

    private final PostRepository postRepository;

    public PostService(PostRepository postRepository) {
        this.postRepository = postRepository;
    }

    public List<PostDto> getAll() {
        return PostDto.convert(postRepository.findAll());
    }

    public PostDto getOne(Long id) {
        Post post = postRepository.findById(id).orElse(null);
        return post != null ? PostDto.fromPost(post) : null;
    }

    public List<PostDto> getByTitle(String title) {
        return PostDto.convert(postRepository.findByTitleContainingIgnoreCase(title));
    }

    @Transactional
    public PostDto save(PostFormDto post) {
        return PostDto.fromPost(postRepository.save(new Post(post)));
    }

    @Transactional
    public PostDto update(Long id, PostFormDto updatedPost) {
        Post post = postRepository.findById(id).orElse(null);
        if(post == null) {
            return null;
        }
        post.setTitle(updatedPost.title());
        post.setContent(updatedPost.content());
        post.setCategory(updatedPost.category());
        post.setUser(updatedPost.user());
        return PostDto.fromPost(postRepository.save(post));
    }

    @Transactional
    public void delete(Long id) {
        postRepository.deleteById(id);
    }
}
