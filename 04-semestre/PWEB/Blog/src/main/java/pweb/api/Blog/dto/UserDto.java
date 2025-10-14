package pweb.api.Blog.dto;

import lombok.Data;
import pweb.api.Blog.model.User;

import java.util.List;

@Data
public class UserDto {
    private Long id;
    private String name;
    private String login;

    public UserDto(User user){
        this.id = user.getId();
        this.name = user.getName();
        this.login = user.getLogin();
    }

    public static UserDto fromUser(User user){
        return new UserDto(user);
    }

    public static List<UserDto> convert(List<User> users){
        return users.stream().map(UserDto::new).toList();
    }
}
