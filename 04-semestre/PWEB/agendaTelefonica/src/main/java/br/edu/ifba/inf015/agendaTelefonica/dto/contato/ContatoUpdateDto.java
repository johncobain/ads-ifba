package br.edu.ifba.inf015.agendaTelefonica.dto.contato;

import br.edu.ifba.inf015.agendaTelefonica.model.entities.Contato;
import jakarta.validation.constraints.Email;
import jakarta.validation.constraints.Size;

public record ContatoUpdateDto (
    @Size(max = 100, message = "O nome deve ter no máximo 100 caracteres")
    String nome,

    @Size(max = 100, message = "O sobrenome deve ter no máximo 100 caracteres")
    String sobrenome,

    @Email(message = "Email inválido")
    String email
){
  public ContatoUpdateDto(Contato contato){
    this(contato.getNome(), contato.getSobrenome(), contato.getEmail());
  }
}
