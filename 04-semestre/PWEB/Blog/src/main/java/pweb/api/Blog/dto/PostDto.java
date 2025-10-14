package pweb.api.Blog.dto;

import lombok.Data;
import pweb.api.Blog.model.Category;
import pweb.api.Blog.model.Post;

import java.util.List;

@Data
public class PostDto {
    private Long id;
    private String title;
    private String content;
    private UserDto user;
    private Category category;

    public PostDto(Post post){
        this.id = post.getId();
        this.title = post.getTitle();
        this.content = post.getContent();
        this.user = UserDto.fromUser(post.getUser());
        this.category = post.getCategory();
    }

    public static PostDto fromPost(Post post){
        return new PostDto(post);
    }

    public static List<PostDto> convert(List<Post> posts){
        return posts.stream().map(PostDto::new).toList();
    }
}
