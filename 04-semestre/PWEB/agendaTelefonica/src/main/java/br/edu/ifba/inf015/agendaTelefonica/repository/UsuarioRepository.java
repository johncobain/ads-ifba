package br.edu.ifba.inf015.agendaTelefonica.repository;

import br.edu.ifba.inf015.agendaTelefonica.model.entities.Usuario;
import org.springframework.data.jpa.repository.JpaRepository;

public interface UsuarioRepository extends JpaRepository<Usuario, Long> {
    Usuario findByUsername(String username);
}
