package br.edu.ifba.inf015.agendaTelefonica.dto.usuario;

import br.edu.ifba.inf015.agendaTelefonica.model.entities.Usuario;

public record UsuarioDto(
        Long id,
        String username){
    public static UsuarioDto fromEntity(Usuario usuario){
        return new UsuarioDto(
                usuario.getId(),
                usuario.getUsername()
        );
    }
}
