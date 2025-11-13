package br.edu.ifba.inf015.agendaTelefonica.dto.contato;

import br.edu.ifba.inf015.agendaTelefonica.dto.telefone.TelefoneDto;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Contato;

import java.util.List;

public record ContatoDto(
        Long id,
        String nome,
        String sobrenome,
        String email,
        List<TelefoneDto> telefones
) {
    public static ContatoDto fromEntity(Contato contato){
        return new ContatoDto(
                contato.getId(),
                contato.getNome(),
                contato.getSobrenome(),
                contato.getEmail(),
                contato.getTelefones().stream().map(TelefoneDto::fromEntity).toList()
        );
    }
}
