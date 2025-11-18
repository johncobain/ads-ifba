package br.edu.ifba.inf015.agendaTelefonica.repository;

import br.edu.ifba.inf015.agendaTelefonica.model.entities.Contato;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;
import java.util.Optional;

public interface ContatoRepository extends JpaRepository<Contato, Long> {
    List<Contato> findAllByUsuarioId(Long usuarioId);

    Optional<Contato> findByIdAndUsuarioId(Long id, Long usuarioId);
}
