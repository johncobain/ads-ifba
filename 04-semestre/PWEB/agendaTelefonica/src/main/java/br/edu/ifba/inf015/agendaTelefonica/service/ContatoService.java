package br.edu.ifba.inf015.agendaTelefonica.service;

import br.edu.ifba.inf015.agendaTelefonica.dto.contato.ContatoDto;
import br.edu.ifba.inf015.agendaTelefonica.dto.contato.ContatoFormDto;
import br.edu.ifba.inf015.agendaTelefonica.dto.contato.ContatoUpdateDto;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Contato;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Telefone;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Usuario;
import br.edu.ifba.inf015.agendaTelefonica.repository.ContatoRepository;
import jakarta.transaction.Transactional;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.stereotype.Service;

@Service
public class ContatoService {
  private final ContatoRepository contatoRepository;

  public ContatoService(ContatoRepository contatoRepository){
      this.contatoRepository = contatoRepository;
  }

  @Transactional
  public ContatoDto save(ContatoFormDto contatoForm, Usuario usuario){
    Contato contato = new Contato(contatoForm);
    contato.setUsuario(usuario);

    if(contatoForm.telefones() != null && !contatoForm.telefones().isEmpty()){
      contato.setTelefones(contatoForm.telefones().stream().map(telefoneForm -> {
          Telefone telefone = new Telefone(telefoneForm);
          telefone.setContato(contato);
          return telefone;
      }).toList());
    }

    return ContatoDto.fromEntity(contatoRepository.save(contato));
  }

  public Page<ContatoDto> findAllFromUser(Pageable pageable, Usuario usuario){
    return contatoRepository.findAllByUsuarioId(pageable, usuario.getId()).map(ContatoDto::fromEntity);
  }

  public ContatoDto findById(Long contatoId, Usuario usuario){
    Contato contato = contatoRepository.findByIdAndUsuarioId(contatoId, usuario.getId())
        .orElseThrow(() -> new RuntimeException("Contato nao encontrado"));

    return ContatoDto.fromEntity(contato);
  }

  @Transactional
  public ContatoDto update(Long contatoId, ContatoUpdateDto contatoUpdate, Usuario usuario){
    Contato contato = contatoRepository.findByIdAndUsuarioId(contatoId, usuario.getId())
        .orElseThrow(() -> new RuntimeException("Contato nao encontrado"));

    if(contatoUpdate.nome() != null){
      contato.setNome(contatoUpdate.nome());
    }

    if(contatoUpdate.sobrenome() != null){
      contato.setSobrenome(contatoUpdate.sobrenome());
    }

    if(contatoUpdate.email() != null) {
      contato.setEmail(contatoUpdate.email());
    }

    return ContatoDto.fromEntity(contatoRepository.save(contato));
  }

  public void delete(Long contatoId, Usuario usuario){
    Contato contato = contatoRepository.findByIdAndUsuarioId(contatoId, usuario.getId())
        .orElseThrow(() -> new RuntimeException("Contato nao encontrado"));
    contatoRepository.delete(contato);
  }
}
