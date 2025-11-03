package br.edu.ifba.inf011.builder;

import br.edu.ifba.inf011.model.Equipe;
import br.edu.ifba.inf011.model.Geolocalizacao;
import br.edu.ifba.inf011.model.Partida;

import java.time.LocalDateTime;

public class PartidaBuilder{
    private String descricao;
    private Equipe equipeA;
    private Equipe equipeB;
    private Integer placarA;
    private Integer placarB;
    private LocalDateTime inicio;
    private LocalDateTime termino;
    private Integer prioridade;
    private Geolocalizacao localizacao;

    public PartidaBuilder(){
        this.init();
    }

    public PartidaBuilder init(){
        this.descricao = "";
        this.equipeA = null;
        this.equipeB = null;
        this.placarA = 0;
        this.placarB = 0;
        this.inicio = LocalDateTime.now();
        this.termino = LocalDateTime.now().plusHours(2);
        this.prioridade = 5;
        this.localizacao = Geolocalizacao.here();
        return this;
    }

    public PartidaBuilder setDescricao(String descricao){
        this.descricao = descricao;
        return this;
    }

    public PartidaBuilder setEquipeA(Equipe equipeA){
        this.equipeA = equipeA;
        return this;
    }

    public PartidaBuilder setEquipeB(Equipe equipeB){
        this.equipeB = equipeB;
        return this;
    }

    public PartidaBuilder setPlacarA(Integer placarA){
        this.placarA = placarA;
        return this;
    }

    public PartidaBuilder setPlacarB(Integer placarB){
        this.placarB = placarB;
        return this;
    }

    public PartidaBuilder setInicio(LocalDateTime inicio){
        this.inicio = inicio;
        return this;
    }

    public PartidaBuilder setTermino(LocalDateTime termino){
        this.termino = termino;
        return this;
    }

    public PartidaBuilder setPrioridade(Integer prioridade){
        this.prioridade = prioridade;
        return this;
    }

    public PartidaBuilder setLocalizacao(Geolocalizacao localizacao){
        this.localizacao = localizacao;
        return this;
    }

    public Partida build(String descricao, Equipe equipeA, Equipe equipeB){
        Partida partida = new  Partida(descricao, equipeA, equipeB, this.placarA, this.placarB, this.inicio, this.termino, this.prioridade, this.localizacao);
        this.init();
        return partida;
    }
}
