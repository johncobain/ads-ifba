package pweb.api.Blog.controller;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import pweb.api.Blog.exception.UserNotFoundException;
import pweb.api.Blog.model.User;
import pweb.api.Blog.service.UserService;

import java.util.List;

@RestController
@RequestMapping("/users")
public class UserController {
    private final UserService userService;

    public UserController(UserService userService) {
        this.userService = userService;
    }

    @GetMapping
    public ResponseEntity<List<User>> getAll(){
        return ResponseEntity.ok(userService.getAll());
    }

    @GetMapping("/{id}")
    public ResponseEntity<User> getOne(@PathVariable Long id){
        User user = userService.getOne(id);
        if(user == null){
            throw new UserNotFoundException(id);
        }
        return ResponseEntity.ok(user);
    }

    @PostMapping
    public ResponseEntity<User> create(@RequestBody User user){
        return ResponseEntity.ok(userService.save(user));
    }

    @PutMapping("/{id}")
    public ResponseEntity<User> update(@PathVariable Long id, @RequestBody User user){
        User updatedUser = userService.getOne(id);
        if(updatedUser == null){
            throw new UserNotFoundException(id);
        }
        return ResponseEntity.ok(userService.update(id, user));
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<?> delete(@PathVariable Long id){
        User user = userService.getOne(id);
        if(user == null){
            throw new UserNotFoundException(id);
        }
        userService.delete(id);
        return ResponseEntity.status(204).build();
    }
}
