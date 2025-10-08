package pweb.api.Blog.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import pweb.api.Blog.model.Post;

public interface PostRepository extends JpaRepository<Post, Long> {
}
