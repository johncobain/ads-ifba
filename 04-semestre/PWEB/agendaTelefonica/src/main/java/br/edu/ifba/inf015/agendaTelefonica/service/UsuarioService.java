package br.edu.ifba.inf015.agendaTelefonica.service;

import br.edu.ifba.inf015.agendaTelefonica.dto.usuario.UsuarioDto;
import br.edu.ifba.inf015.agendaTelefonica.dto.usuario.UsuarioFormDto;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Role;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Usuario;
import br.edu.ifba.inf015.agendaTelefonica.repository.RoleRepository;
import br.edu.ifba.inf015.agendaTelefonica.repository.UsuarioRepository;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

@Service
public class UsuarioService {
    private final UsuarioRepository usuarioRepository;
    private final PasswordEncoder passwordEncoder;
    private final RoleRepository roleRepository;

    public UsuarioService(UsuarioRepository usuarioRepository, PasswordEncoder passwordEncoder, RoleRepository roleRepository) {
        this.usuarioRepository = usuarioRepository;
        this.passwordEncoder = passwordEncoder;
        this.roleRepository = roleRepository;
    }

    public UsuarioDto register(UsuarioFormDto usuarioForm){
        Usuario usuario = new Usuario(usuarioForm);
        usuario.setPassword(passwordEncoder.encode(usuarioForm.password()));
        Role defaultRole = roleRepository.findByRole("ROLE_USER")
                .orElseThrow(() -> new RuntimeException("Papel não encontrado"));
        usuario.setRole(defaultRole);
        return UsuarioDto.fromEntity(usuarioRepository.save(usuario));
    }
}
