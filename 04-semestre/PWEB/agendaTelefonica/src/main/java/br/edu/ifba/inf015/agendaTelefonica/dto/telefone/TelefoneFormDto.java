package br.edu.ifba.inf015.agendaTelefonica.dto.telefone;

import br.edu.ifba.inf015.agendaTelefonica.model.entities.CategoriaTelefone;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Telefone;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.NotNull;

public record TelefoneFormDto(
    @NotBlank(message = "O número não pode estar vazio")
    String numero,

    @NotNull(message = "A categoria é obrigatória")
    CategoriaTelefone categoria,

    Boolean principal
) {
  public TelefoneFormDto(Telefone telefone){
    this(telefone.getNumero(), telefone.getCategoria(), telefone.getPrincipal());
  }
}
