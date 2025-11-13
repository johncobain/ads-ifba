package br.edu.ifba.inf015.agendaTelefonica.dto.contato;

import br.edu.ifba.inf015.agendaTelefonica.dto.telefone.TelefoneFormDto;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Contato;
import jakarta.validation.Valid;
import jakarta.validation.constraints.Email;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.Size;

import java.util.List;

public record ContatoFormDto (
    @NotBlank(message = "O nome não pode estar vazio")
    @Size(max = 100, message = "O nome deve ter no máximo 100 caracteres")
    String nome,

    @Size(max = 100, message = "O sobrenome deve ter no máximo 100 caracteres")
    String sobrenome,

    @NotBlank(message = "O email não pode estar vazio")
    @Email(message = "Email inválido")
    String email,

    @Valid
    List<TelefoneFormDto> telefones
){
  public ContatoFormDto(Contato contato){
    this(
        contato.getNome(),
        contato.getSobrenome(),
        contato.getEmail(),
        contato.getTelefones().stream().map(TelefoneFormDto::new).toList()
        );
  }
}
