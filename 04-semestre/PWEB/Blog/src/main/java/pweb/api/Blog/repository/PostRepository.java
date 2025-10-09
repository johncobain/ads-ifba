package pweb.api.Blog.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import pweb.api.Blog.model.Post;

import java.util.List;

public interface PostRepository extends JpaRepository<Post, Long> {
    public List<Post> findByTitleContainingIgnoreCase(String title);
}
