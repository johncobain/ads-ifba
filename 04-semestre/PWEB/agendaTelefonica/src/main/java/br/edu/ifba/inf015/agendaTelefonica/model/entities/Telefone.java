package br.edu.ifba.inf015.agendaTelefonica.model.entities;

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
}
