package br.edu.ifba.inf015.agendaTelefonica.dto.telefone;

import br.edu.ifba.inf015.agendaTelefonica.model.entities.CategoriaTelefone;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Telefone;

public record TelefoneUpdateDto(
  String numero,
  CategoriaTelefone categoria,
  Boolean principal
  ) {
  public TelefoneUpdateDto(Telefone telefone) {
    this(telefone.getNumero(), telefone.getCategoria(), telefone.getPrincipal());
  }
}