package pweb.api.Blog.dto;

import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Size;
import pweb.api.Blog.model.User;

public record UserFormDto (
    @NotNull(message = "Name is required")
    String name,
    @NotBlank(message = "Login can not be blank")
    @Size(min = 6, max = 30, message = "Login must be between 6 and 30 characters")
    String login,
    @NotBlank(message = "Password can not be blank")
    @Size(min = 6, message = "Password must be at least 6 characters")
    String password
    ){

    public UserFormDto(User user){
        this(user.getName(), user.getLogin(), user.getPassword());
    }
}
