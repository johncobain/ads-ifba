package pweb.api.Blog.model;

import jakarta.persistence.*;
import jakarta.validation.constraints.NotNull;
import lombok.*;
import pweb.api.Blog.dto.PostFormDto;

@AllArgsConstructor
@NoArgsConstructor
@Getter
@Setter
@Entity
@Table(name = "posts")
public class Post {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String title;
    private String content;
    @Enumerated(EnumType.STRING)
    private Category category;
    @ManyToOne
    @JoinColumn(name = "user_id")
    private User user;

    public Post(PostFormDto postFormDto){
        this.title = postFormDto.title();
        this.content = postFormDto.content();
        this.category = postFormDto.category();
        this.user = postFormDto.user();
    }
}
