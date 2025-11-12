package br.edu.ifba.inf015.agendaTelefonica.dto.usuario;

import br.edu.ifba.inf015.agendaTelefonica.model.entities.Usuario;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.Size;

public record UsuarioFormDto(
        @NotBlank(message = "Username não pode estar vazio")
        String username,
        @NotBlank(message = "Password não pode estar vazio")
        @Size(max = 72, message = "Password deve ter no máximo 72 caracteres")
        String password){
    public UsuarioFormDto(Usuario usuario){
        this(usuario.getUsername(), usuario.getPassword());
    }
}
