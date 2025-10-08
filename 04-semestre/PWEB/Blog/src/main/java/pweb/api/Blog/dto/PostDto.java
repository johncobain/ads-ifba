package pweb.api.Blog.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import pweb.api.Blog.model.Category;
import pweb.api.Blog.model.Post;

import java.util.List;

@Data
public class PostDto {
    private Long id;
    private String title;
    private String content;
    private String user;
    private Category category;

    public PostDto(Post post){
        this.id = post.getId();
        this.title = post.getTitle();
        this.content = post.getContent();
        this.user = post.getUser().getName();
        this.category = post.getCategory();
    }

    public static List<PostDto> convert(List<Post> posts){
        return posts.stream().map(PostDto::new).toList();
    }
}
