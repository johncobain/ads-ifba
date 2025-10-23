package pweb.api.Blog.controller;

import jakarta.validation.Valid;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import pweb.api.Blog.dto.PostDto;
import pweb.api.Blog.dto.PostFormDto;
import pweb.api.Blog.dto.UserDto;
import pweb.api.Blog.exception.PostNotFoundException;
import pweb.api.Blog.exception.UserNotFoundException;
import pweb.api.Blog.service.PostService;
import pweb.api.Blog.service.UserService;

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
    public ResponseEntity<Page<PostDto>> getAll(Pageable pageable){
        return ResponseEntity.ok(postService.getAll(pageable));
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
    public ResponseEntity<Page<PostDto>> getByTitle(Pageable pageable, @RequestParam String title){
        return ResponseEntity.ok(postService.getByTitle(pageable, title));
    }

    @PostMapping
    public ResponseEntity<PostDto> create(@RequestBody @Valid PostFormDto post) {
        UserDto user = userService.getOne(post.user().getId());
        if(user == null) {
            throw new UserNotFoundException(post.user().getId());
        }
        post.user().setName(user.name());
        post.user().setLogin(user.login());

        return ResponseEntity.status(201).body(postService.save(post));
    }

    @PutMapping("/{id}")
    public ResponseEntity<PostDto> update(@PathVariable Long id, @RequestBody @Valid PostFormDto post){
        PostDto updatedPost = postService.getOne(id);
        if(updatedPost == null){
            throw new PostNotFoundException(id);
        }
        UserDto user = userService.getOne(post.user().getId());
        if(user == null){
            throw new UserNotFoundException(post.user().getId());
        }
        post.user().setName(user.name());
        post.user().setLogin(user.login());
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
