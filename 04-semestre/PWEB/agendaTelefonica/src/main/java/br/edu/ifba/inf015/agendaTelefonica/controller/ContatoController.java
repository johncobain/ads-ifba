package br.edu.ifba.inf015.agendaTelefonica.controller;

import br.edu.ifba.inf015.agendaTelefonica.dto.contato.ContatoDto;
import br.edu.ifba.inf015.agendaTelefonica.dto.contato.ContatoFormDto;
import br.edu.ifba.inf015.agendaTelefonica.dto.contato.ContatoUpdateDto;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Usuario;
import jakarta.validation.Valid;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.http.ResponseEntity;
import org.springframework.security.core.annotation.AuthenticationPrincipal;
import org.springframework.web.bind.annotation.*;

import br.edu.ifba.inf015.agendaTelefonica.service.ContatoService;

import java.util.List;

@RestController
@RequestMapping("/contatos")
public class ContatoController {
  private final ContatoService contatoService;

  public ContatoController(ContatoService contatoService) {
    this.contatoService = contatoService;
  }

  @PostMapping
  public ResponseEntity<ContatoDto> save(
          @Valid @RequestBody ContatoFormDto contatoForm,
          @AuthenticationPrincipal Usuario usuario){
      return ResponseEntity.status(201).body(contatoService.save(contatoForm, usuario));
  }

  @GetMapping
  public ResponseEntity<List<ContatoDto>> findAll(@AuthenticationPrincipal Usuario usuario) {
    return ResponseEntity.ok(contatoService.findAllFromUser(usuario));
  }

  @GetMapping("/{contatoId}")
  public ResponseEntity<ContatoDto> findById(
          @PathVariable Long contatoId,
          @AuthenticationPrincipal Usuario usuario){
      return ResponseEntity.ok(contatoService.findById(contatoId, usuario));
  }

  @PutMapping("/{contatoId}")
  public ResponseEntity<ContatoDto> update(
          @PathVariable Long contatoId,
          @Valid @RequestBody ContatoUpdateDto contatoUpdate,
          @AuthenticationPrincipal Usuario usuario){
    return ResponseEntity.ok(contatoService.update(contatoId, contatoUpdate, usuario));
  }

  @DeleteMapping("/{contatoId}")
  public ResponseEntity<Void> delete(
          @PathVariable Long contatoId,
          @AuthenticationPrincipal Usuario usuario){
    contatoService.delete(contatoId, usuario);
    return ResponseEntity.noContent().build();
  }

}
