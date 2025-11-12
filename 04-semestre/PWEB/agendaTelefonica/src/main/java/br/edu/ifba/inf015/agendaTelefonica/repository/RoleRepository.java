package br.edu.ifba.inf015.agendaTelefonica.repository;

import br.edu.ifba.inf015.agendaTelefonica.model.entities.Role;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

public interface RoleRepository extends JpaRepository<Role, Long> {
    Optional<Role> findByRole(String role);
}
