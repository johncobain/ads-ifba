package pweb.api.Blog.dto;

import jakarta.validation.constraints.NotNull;
import pweb.api.Blog.model.Category;
import pweb.api.Blog.model.Post;
import pweb.api.Blog.model.User;

public record PostFormDto(
        @NotNull(message = "Title is required")
        String title,
        @NotNull(message = "Content is required")
        String content,
        @NotNull(message = "Category is required")
        Category category,
        @NotNull(message = "User is required")
        User user
    ){

    public PostFormDto(Post post){
        this(post.getTitle(), post.getContent(), post.getCategory(), post.getUser());
    }
}
