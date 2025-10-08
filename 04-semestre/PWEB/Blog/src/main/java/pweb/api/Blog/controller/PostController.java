package pweb.api.Blog.controller;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import pweb.api.Blog.dto.PostDto;
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
    public ResponseEntity<?> getOne(@PathVariable Long id){
        PostDto post = postService.getOne(id);
        if(post == null){
            Map<String, String> error = new HashMap<>();
            error.put("message", "Post not found");
            return ResponseEntity.status(404).body(error);
        }
        return ResponseEntity.ok(post);
    }

    @PostMapping
    public ResponseEntity<?> create(@RequestBody Post post){
        User user = userService.getOne(post.getUser().getId());
        if(user == null){
            Map<String, String> error = new HashMap<>();
            error.put("message", "User not found");
            return ResponseEntity.status(404).body(error);
        }
        post.setUser(user);
        return ResponseEntity.ok(postService.create(post));
    }

    @PutMapping("/{id}")
    public ResponseEntity<?> update(@PathVariable Long id, @RequestBody Post post){
        PostDto updatedPost = postService.getOne(id);
        if(updatedPost == null){
            Map<String, String> error = new HashMap<>();
            error.put("message", "Post not found");
            return ResponseEntity.status(404).body(error);
        }
        User user = userService.getOne(post.getUser().getId());
        if(user == null){
            Map<String, String> error = new HashMap<>();
            error.put("message", "User not found");
            return ResponseEntity.status(404).body(error);
        }
        post.setUser(user);
        return ResponseEntity.ok(postService.update(id, post));
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<?> delete(@PathVariable Long id){
        PostDto post = postService.getOne(id);
        if(post == null){
            Map<String, String> error = new HashMap<>();
            error.put("message", "Post not found");
            return ResponseEntity.status(404).body(error);
        }
        postService.delete(id);
        return ResponseEntity.status(204).build();
    }
}
