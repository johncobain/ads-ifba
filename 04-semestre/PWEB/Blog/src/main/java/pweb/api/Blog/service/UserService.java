package pweb.api.Blog.service;

import jakarta.transaction.Transactional;
import org.springframework.stereotype.Service;
import pweb.api.Blog.dto.UserDto;
import pweb.api.Blog.model.User;
import pweb.api.Blog.repository.UserRepository;

import java.util.List;

@Service
public class UserService {
    private final UserRepository userRepository;

    public UserService(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    public List<UserDto> getAll() {
        return UserDto.convert(userRepository.findAll());
    }

    public UserDto getOne(Long id) {
        User user = userRepository.findById(id).orElse(null);
        return user != null ? UserDto.fromUser(user) : null;
    }

    public UserDto save(User user) {
        return UserDto.fromUser(userRepository.save(user));
    }

    @Transactional
    public UserDto update(Long id, User updatedUser) {
        User user = userRepository.findById(id).orElse(null);
        if(user == null) {
            return null;
        }
        user.setName(updatedUser.getName());
        user.setLogin(updatedUser.getLogin());
        user.setPassword(updatedUser.getPassword());
        return UserDto.fromUser(userRepository.save(user));
    }

    @Transactional
    public void delete(Long id) {
        userRepository.deleteById(id);
    }
}
