package pweb.api.Blog.service;

import org.springframework.stereotype.Service;
import pweb.api.Blog.dto.PostDto;
import pweb.api.Blog.model.Post;
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
        return post != null ? new PostDto(post) : null;
    }

    public List<PostDto> getByTitle(String title) {
        return PostDto.convert(postRepository.findByTitleContainingIgnoreCase(title));
    }

    public PostDto create(Post post) {
        return new PostDto(postRepository.save(post));
    }

    public PostDto update(Long id, Post updatedPost) {
        Post post = postRepository.findById(id).orElse(null);
        if(post == null) {
            return null;
        }
        post.setTitle(updatedPost.getTitle());
        post.setContent(updatedPost.getContent());
        post.setCategory(updatedPost.getCategory());
        post.setUser(updatedPost.getUser());
        return new PostDto(postRepository.save(post));
    }

    public void delete(Long id) {
        postRepository.deleteById(id);
    }
}
