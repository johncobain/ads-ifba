package pweb.api.Blog.controller;

import jakarta.validation.Valid;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import pweb.api.Blog.dto.PostDto;
import pweb.api.Blog.dto.UserDto;
import pweb.api.Blog.exception.PostNotFoundException;
import pweb.api.Blog.exception.UserNotFoundException;
import pweb.api.Blog.model.Post;
import pweb.api.Blog.model.User;
import pweb.api.Blog.service.PostService;
import pweb.api.Blog.service.UserService;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

@RestController
@RequestMapping("/posts")
public class PostController {

    private final PostService postService;
    private final UserService userService;

    public PostController(PostService postService, UserService userService) {
        this.postService = postService;
        this.userService = userService;
    }

    @GetMapping
    public ResponseEntity<List<PostDto>> getAll(){
        return ResponseEntity.ok(postService.getAll());
    }

    @GetMapping("/{id}")
    public ResponseEntity<PostDto> getOne(@PathVariable Long id){
        PostDto post = postService.getOne(id);
        if(post == null){
            throw new PostNotFoundException(id);
        }
        return ResponseEntity.ok(post);
    }

    @GetMapping("/search")
    public ResponseEntity<List<PostDto>> getByTitle(@RequestParam String title){
        return ResponseEntity.ok(postService.getByTitle(title));
    }

    @PostMapping
    public ResponseEntity<PostDto> create(@RequestBody @Valid Post post){
        UserDto user = userService.getOne(post.getUser().getId());
        if(user == null) {
            throw new UserNotFoundException(post.getUser().getId());
        }
        post.getUser().setName(user.getName());
        post.getUser().setLogin(user.getLogin());
        return ResponseEntity.ok(postService.create(post));
    }

    @PutMapping("/{id}")
    public ResponseEntity<PostDto> update(@PathVariable Long id, @RequestBody @Valid Post post){
        PostDto updatedPost = postService.getOne(id);
        if(updatedPost == null){
            throw new PostNotFoundException(id);
        }
        UserDto user = userService.getOne(post.getUser().getId());
        if(user == null){
            throw new UserNotFoundException(post.getUser().getId());
        }
        post.getUser().setName(user.getName());
        post.getUser().setLogin(user.getLogin());
        return ResponseEntity.ok(postService.update(id, post));
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<PostDto> delete(@PathVariable Long id){
        PostDto post = postService.getOne(id);
        if(post == null){
            throw new PostNotFoundException(id);
        }
        postService.delete(id);
        return ResponseEntity.status(204).build();
    }
}
