package pweb.api.Blog.controller;

import jakarta.validation.Valid;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import pweb.api.Blog.dto.UserDto;
import pweb.api.Blog.exception.UserNotFoundException;
import pweb.api.Blog.model.User;
import pweb.api.Blog.service.UserService;

import java.net.URI;
import java.net.URISyntaxException;
import java.util.List;

@RestController
@RequestMapping("/users")
public class UserController {
    private final UserService userService;

    public UserController(UserService userService) {
        this.userService = userService;
    }

    @GetMapping
    public ResponseEntity<List<UserDto>> getAll(){
        return ResponseEntity.ok(userService.getAll());
    }

    @GetMapping("/{id}")
    public ResponseEntity<UserDto> getOne(@PathVariable Long id){
        UserDto user = userService.getOne(id);
        if(user == null){
            throw new UserNotFoundException(id);
        }
        return ResponseEntity.ok(user);
    }

    @PostMapping
    public ResponseEntity<UserDto> create(@RequestBody @Valid User user) throws URISyntaxException {
        UserDto createdUser = userService.save(user);
        URI location = new URI("/users/" + createdUser.getId());
        return ResponseEntity.created(location).body(createdUser);
    }

    @PutMapping("/{id}")
    public ResponseEntity<UserDto> update(@PathVariable Long id, @RequestBody @Valid User user){
        UserDto updatedUser = userService.getOne(id);
        if(updatedUser == null){
            throw new UserNotFoundException(id);
        }
        return ResponseEntity.ok(userService.update(id, user));
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<UserDto> delete(@PathVariable Long id){
        UserDto user = userService.getOne(id);
        if(user == null){
            throw new UserNotFoundException(id);
        }
        userService.delete(id);
        return ResponseEntity.status(204).build();
    }
}
