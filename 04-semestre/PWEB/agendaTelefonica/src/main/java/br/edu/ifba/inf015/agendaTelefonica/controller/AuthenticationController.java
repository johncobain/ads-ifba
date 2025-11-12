package br.edu.ifba.inf015.agendaTelefonica.controller;

import br.edu.ifba.inf015.agendaTelefonica.dto.usuario.AuthenticationData;
import br.edu.ifba.inf015.agendaTelefonica.dto.usuario.JWTTokenData;
import br.edu.ifba.inf015.agendaTelefonica.dto.usuario.UsuarioDto;
import br.edu.ifba.inf015.agendaTelefonica.dto.usuario.UsuarioFormDto;
import br.edu.ifba.inf015.agendaTelefonica.model.entities.Usuario;
import br.edu.ifba.inf015.agendaTelefonica.service.JWTTokenService;
import br.edu.ifba.inf015.agendaTelefonica.service.UsuarioService;
import jakarta.validation.Valid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/auth")
public class AuthenticationController {
    @Autowired
    private AuthenticationManager authenticationManager;

    @Autowired
    private UsuarioService usuarioService;

    @Autowired
    private JWTTokenService tokenService;

    @PostMapping("/login")
    public ResponseEntity<JWTTokenData> login(@RequestBody AuthenticationData data){
        var dto = new UsernamePasswordAuthenticationToken(data.username(), data.password());
        var auth = this.authenticationManager.authenticate(dto);
        var token = this.tokenService.generateToken((Usuario) auth.getPrincipal());

        return ResponseEntity.ok(new JWTTokenData(token));
    }

    @PostMapping("/register")
    public ResponseEntity<UsuarioDto> register(@Valid @RequestBody UsuarioFormDto userForm) {
        return ResponseEntity.ok(usuarioService.register(userForm));
    }
}
