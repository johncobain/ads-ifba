package br.edu.ifba.inf015.agendaTelefonica.repository;

import br.edu.ifba.inf015.agendaTelefonica.model.entities.Telefone;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

public interface TelefoneRepository extends JpaRepository<Telefone, Long> {
  Optional<Telefone> findByIdAndContatoId(Long id, Long contatoId);
}
