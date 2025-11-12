package br.edu.ifba.inf015.agendaTelefonica.model.entities;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import org.springframework.security.core.GrantedAuthority;

@Entity
public class Role implements GrantedAuthority {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String role;

    public Role(){}
    public Role(String role){
        this.role = role;
    }

    @Override
    public String getAuthority() {
        return this.role;
    }
}
