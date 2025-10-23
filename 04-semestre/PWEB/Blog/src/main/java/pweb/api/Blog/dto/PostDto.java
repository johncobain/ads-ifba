package pweb.api.Blog.dto;

import lombok.Data;
import pweb.api.Blog.model.Category;
import pweb.api.Blog.model.Post;

import java.util.List;

public record PostDto(
        Long id,
        String title,
        String content,
        UserDto user,
        Category category
) {

    public PostDto(Post post){
        this(post.getId(), post.getTitle(), post.getContent(), UserDto.fromUser(post.getUser()), post.getCategory());
    }

    public static PostDto fromPost(Post post){
        return new PostDto(post);
    }
}
