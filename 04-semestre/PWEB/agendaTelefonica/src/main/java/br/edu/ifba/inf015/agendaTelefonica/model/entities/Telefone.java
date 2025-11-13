package br.edu.ifba.inf015.agendaTelefonica.model.entities;

import br.edu.ifba.inf015.agendaTelefonica.dto.telefone.TelefoneFormDto;
import jakarta.persistence.*;

@Entity
public class Telefone {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String numero;
    private CategoriaTelefone categoria;
    private Boolean principal;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "contato_id", nullable = false)
    private Contato contato;

    public Telefone(){}
    public Telefone(TelefoneFormDto telefoneForm){
      this.numero = telefoneForm.numero();
      this.categoria = telefoneForm.categoria();
      this.principal = telefoneForm.principal();
    }

    @PrePersist
    public void prePersist() {
        this.principal = this.principal != null && this.principal;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getNumero() {
        return numero;
    }

    public void setNumero(String numero) {
        this.numero = numero;
    }

    public CategoriaTelefone getCategoria() {
        return categoria;
    }

    public void setCategoria(CategoriaTelefone categoria) {
        this.categoria = categoria;
    }

    public Boolean getPrincipal() {
        return principal;
    }

    public void setPrincipal(Boolean principal) {
        this.principal = principal;
    }

    public Contato getContato() {
        return contato;
    }

    public void setContato(Contato contato) {
        this.contato = contato;
    }
}
