package pweb.api.Blog.model;

import jakarta.persistence.*;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Size;
import lombok.*;

@AllArgsConstructor
@NoArgsConstructor
@Data
@Entity
@Table(name = "users")
public class User {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    @NotNull(message = "Name is required")
    private String name;
    @NotBlank(message = "Login can not be blank")
    @Size(min = 6, max = 30, message = "Login must be between 6 and 30 characters")
    private String login;
    @NotBlank(message = "Password can not be blank")
    @Size(min = 6, message = "Password must be at least 6 characters")
    private String password;
}
