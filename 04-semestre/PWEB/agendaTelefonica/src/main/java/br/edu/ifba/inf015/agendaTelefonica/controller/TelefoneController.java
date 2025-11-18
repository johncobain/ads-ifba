package br.edu.ifba.inf015.agendaTelefonica.controller;

import br.edu.ifba.inf015.agendaTelefonica.dto.telefone.TelefoneDto;
import br.edu.ifba.inf015.agendaTelefonica.dto.telefone.TelefoneFormDto;
import br.edu.ifba.inf015.agendaTelefonica.dto.telefone.TelefoneUpdateDto;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Usuario;
import br.edu.ifba.inf015.agendaTelefonica.service.TelefoneService;
import jakarta.validation.Valid;
import org.springframework.http.ResponseEntity;
import org.springframework.security.core.annotation.AuthenticationPrincipal;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/contatos/{contatoId}/telefones")
public class TelefoneController {

  private final TelefoneService telefoneService;

  public TelefoneController(TelefoneService telefoneService) {
    this.telefoneService = telefoneService;
  }

  @PostMapping
  public ResponseEntity<List<TelefoneDto>> addTelefones(
      @PathVariable Long contatoId,
      @Valid @RequestBody List<TelefoneFormDto> telefonesForm,
      @AuthenticationPrincipal Usuario usuario){
    return ResponseEntity.status(201)
        .body(telefoneService.addTelefones(contatoId, telefonesForm, usuario));
  }

  @PutMapping("/{telefoneId}")
  public ResponseEntity<TelefoneDto> updateTelefone(
      @PathVariable Long contatoId,
      @PathVariable Long telefoneId,
      @Valid @RequestBody TelefoneUpdateDto telefoneUpdate,
      @AuthenticationPrincipal Usuario usuario){
    return ResponseEntity.ok()
        .body(telefoneService.updateTelefone(contatoId, telefoneId, telefoneUpdate, usuario));
  }

  @DeleteMapping("/{telefoneId}")
  public ResponseEntity<TelefoneDto> deleteTelefone(
      @PathVariable Long contatoId,
      @PathVariable Long telefoneId,
      @AuthenticationPrincipal Usuario usuario){
    telefoneService.deleteTelefone(contatoId, telefoneId, usuario);
    return ResponseEntity.noContent().build();
  }
}
