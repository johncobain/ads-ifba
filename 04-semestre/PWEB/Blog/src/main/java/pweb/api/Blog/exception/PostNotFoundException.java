package pweb.api.Blog.exception;

public class PostNotFoundException extends RuntimeException{
    public PostNotFoundException(String message){
        super(message);
    }

    public PostNotFoundException(Long id){
        super("Post not found with id: " + id);
    }
}
