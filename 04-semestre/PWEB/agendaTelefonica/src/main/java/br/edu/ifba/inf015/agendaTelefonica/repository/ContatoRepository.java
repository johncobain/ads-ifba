package br.edu.ifba.inf015.agendaTelefonica.repository;

import br.edu.ifba.inf015.agendaTelefonica.model.entities.Contato;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

public interface ContatoRepository extends JpaRepository<Contato, Long> {
    Page<Contato> findAllByUsuarioId(Pageable pageable, Long usuarioId);

    Optional<Contato> findByIdAndUsuarioId(Long id, Long usuarioId);
}
