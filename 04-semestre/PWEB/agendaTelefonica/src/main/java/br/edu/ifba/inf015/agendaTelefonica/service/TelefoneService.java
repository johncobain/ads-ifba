package br.edu.ifba.inf015.agendaTelefonica.service;

import br.edu.ifba.inf015.agendaTelefonica.dto.telefone.TelefoneDto;
import br.edu.ifba.inf015.agendaTelefonica.dto.telefone.TelefoneFormDto;
import br.edu.ifba.inf015.agendaTelefonica.dto.telefone.TelefoneUpdateDto;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Contato;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Telefone;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Usuario;
import br.edu.ifba.inf015.agendaTelefonica.repository.ContatoRepository;
import br.edu.ifba.inf015.agendaTelefonica.repository.TelefoneRepository;
import jakarta.transaction.Transactional;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class TelefoneService {
  private final TelefoneRepository telefoneRepository;
  private final ContatoRepository contatoRepository;

  public TelefoneService(TelefoneRepository telefoneRepository, ContatoRepository contatoRepository) {
    this.telefoneRepository = telefoneRepository;
    this.contatoRepository = contatoRepository;
  }

  @Transactional
  public List<TelefoneDto> addTelefones(Long contatoId, List<TelefoneFormDto> telefonesForm, Usuario usuario){
    Contato contato = contatoRepository.findByIdAndUsuarioId(contatoId, usuario.getId())
        .orElseThrow(() -> new RuntimeException("Contato nao encontrado"));

    List<Telefone> telefones = telefonesForm.stream()
        .map(form -> {
          Telefone telefone = new Telefone(form);
          telefone.setContato(contato);
          return telefone;
        }).toList();

    List<Telefone> savedTelefones = telefoneRepository.saveAll(telefones);

    return savedTelefones.stream()
        .map(TelefoneDto::fromEntity)
        .toList();
  }

  @Transactional
  public TelefoneDto updateTelefone(Long contatoId, Long telefoneId, TelefoneUpdateDto telefoneUpdate, Usuario usuario){
    Contato contato = contatoRepository.findByIdAndUsuarioId(contatoId, usuario.getId())
        .orElseThrow(() -> new RuntimeException("Contato nao encontrado"));

    Telefone telefone = telefoneRepository.findByIdAndContatoId(telefoneId, contatoId)
        .orElseThrow(() -> new RuntimeException("Telefone nao encontrado"));

    if(telefoneUpdate.numero() != null){
      telefone.setNumero(telefoneUpdate.numero());
    }
    if(telefoneUpdate.categoria() != null){
      telefone.setCategoria(telefoneUpdate.categoria());
    }
    if(telefoneUpdate.principal() != null){
      telefone.setPrincipal(telefoneUpdate.principal());
    }

    return TelefoneDto.fromEntity((telefoneRepository.save(telefone)));
  }

  @Transactional
  public void deleteTelefone(Long contatoId, Long telefoneId, Usuario usuario){
    Contato contato = contatoRepository.findByIdAndUsuarioId(contatoId, usuario.getId())
        .orElseThrow(() -> new RuntimeException("Contato nao encontrado"));

    Telefone telefone = telefoneRepository.findByIdAndContatoId(telefoneId, contatoId)
        .orElseThrow(() -> new RuntimeException("Telefone nao encontrado"));

    telefoneRepository.delete(telefone);
  }
}
