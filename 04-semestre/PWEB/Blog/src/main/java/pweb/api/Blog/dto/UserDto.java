package pweb.api.Blog.dto;

import lombok.Data;
import pweb.api.Blog.model.User;

import java.util.List;

public record UserDto (
        Long id,
        String name,
        String login
){
    public UserDto(User user){
        this(user.getId(), user.getName(), user.getLogin());
    }

    public static UserDto fromUser(User user){
        return new UserDto(user);
    }

    public static List<UserDto> convert(List<User> users){
        return users.stream().map(UserDto::new).toList();
    }
}
