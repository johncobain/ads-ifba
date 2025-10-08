package pweb.api.Blog.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import pweb.api.Blog.model.User;

public interface UserRepository extends JpaRepository<User, Long> {
}
