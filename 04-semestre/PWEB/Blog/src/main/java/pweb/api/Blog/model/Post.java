package pweb.api.Blog.model;

import jakarta.persistence.*;
import jakarta.validation.constraints.NotNull;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@AllArgsConstructor
@NoArgsConstructor
@Data
@Entity
@Table(name = "posts")
public class Post {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    @NotNull(message = "Title is required")
    private String title;
    @NotNull(message = "Content is required")
    private String content;
    @Enumerated(EnumType.STRING)
    @NotNull(message = "Category is required")
    private Category category;
    @ManyToOne
    @JoinColumn(name = "user_id")
    @NotNull(message = "User is required")
    private User user;
}
