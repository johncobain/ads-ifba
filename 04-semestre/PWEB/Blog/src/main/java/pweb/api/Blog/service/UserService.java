package pweb.api.Blog.service;

import jakarta.transaction.Transactional;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.stereotype.Service;
import pweb.api.Blog.dto.UserDto;
import pweb.api.Blog.dto.UserFormDto;
import pweb.api.Blog.model.User;
import pweb.api.Blog.repository.UserRepository;

import java.util.List;

@Service
public class UserService {
    private final UserRepository userRepository;

    public UserService(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    public Page<UserDto> getAll(Pageable pageable) {
        return this.userRepository.findAll(pageable).map(UserDto::new);
    }

    public UserDto getOne(Long id) {
        User user = this.userRepository.findById(id).orElse(null);
        return user != null ? UserDto.fromUser(user) : null;
    }

    @Transactional
    public UserDto save(UserFormDto user) {
        return UserDto.fromUser(this.userRepository.save(new User(user)));
    }

    @Transactional
    public UserDto update(Long id, UserFormDto updatedUser) {
        User user = this.userRepository.findById(id).orElse(null);
        if(user == null) {
            return null;
        }
        user.setName(updatedUser.name());
        user.setLogin(updatedUser.login());
        user.setPassword(updatedUser.password());
        return UserDto.fromUser(this.userRepository.save(user));
    }

    @Transactional
    public void delete(Long id) {
        this.userRepository.deleteById(id);
    }
}
