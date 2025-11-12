package br.edu.ifba.inf015.agendaTelefonica.service;

import br.edu.ifba.inf015.agendaTelefonica.model.entities.Usuario;
import com.auth0.jwt.JWT;
import com.auth0.jwt.algorithms.Algorithm;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import java.time.Instant;
import java.time.LocalDateTime;
import java.time.ZoneOffset;

@Service
public class JWTTokenService {
    @Value("${api.security.token.secret}")
    private String secret;

    public String generateToken(Usuario usuario){
        try{
            var algorithm = Algorithm.HMAC256(secret);
            return JWT.create()
                    .withIssuer("agenda-telefonica")
                    .withSubject(usuario.getUsername())
                    .withExpiresAt(expirationDate())
                    .sign(algorithm);
        } catch (Exception e){
            throw new RuntimeException("Erro ao gerar token", e);
        }
    }

    public String getSubject(String tokenJWT){
        try{
            var algorithm = Algorithm.HMAC256(secret);
            return JWT.require(algorithm)
                    .withIssuer("agenda-telefonica")
                    .build()
                    .verify(tokenJWT)
                    .getSubject();
        } catch (Exception e){
            throw new RuntimeException("Token invalido ou expirado ", e);
        }
    }

    private Instant expirationDate(){
        return LocalDateTime.now().plusHours(2).toInstant(ZoneOffset.of("-03:00"));
    }
}
