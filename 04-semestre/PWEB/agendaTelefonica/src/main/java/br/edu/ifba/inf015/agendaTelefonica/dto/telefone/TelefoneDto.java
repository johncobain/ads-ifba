package br.edu.ifba.inf015.agendaTelefonica.dto.telefone;

import br.edu.ifba.inf015.agendaTelefonica.model.entities.CategoriaTelefone;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Telefone;

public record TelefoneDto(
        Long id,
        String numero,
        CategoriaTelefone categoria,
        Boolean principal
) {
    public static TelefoneDto fromEntity(Telefone telefone){
        return new TelefoneDto(
                telefone.getId(),
                telefone.getNumero(),
                telefone.getCategoria(),
                telefone.getPrincipal()
        );
    }
}
