package pweb.api.Blog.service;

import jakarta.transaction.Transactional;
import org.springframework.stereotype.Service;
import pweb.api.Blog.model.User;
import pweb.api.Blog.repository.UserRepository;

import java.util.List;

@Service
public class UserService {
    private final UserRepository userRepository;

    public UserService(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    public List<User> getAll() {
        return userRepository.findAll();
    }

    public User getOne(Long id) {
        return userRepository.findById(id).orElse(null);
    }

    public User save(User user) {
        return userRepository.save(user);
    }

    @Transactional
    public User update(Long id, User updatedUser) {
        User user = getOne(id);
        if(user == null) {
            return null;
        }
        user.setName(updatedUser.getName());
        user.setLogin(updatedUser.getLogin());
        user.setPassword(updatedUser.getPassword());
        return userRepository.save(user);
    }

    @Transactional
    public void delete(Long id) {
        userRepository.deleteById(id);
    }
}
