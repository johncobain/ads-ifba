package br.edu.ifba.inf011.builder;

import br.edu.ifba.inf011.model.*;

import java.util.ArrayList;
import java.util.List;

public class MapaBuilder extends AbstractCorridaBuilder {
    private Sexo sexo;
    private Idade idade;
    private Dificuldade dificuldade;
    private Integer escala;
    private Integer ecn;
    private PontoGeografico largada;
    private PontoGeografico partida;
    private List<Prisma> prismas;
    private PontoGeografico chegada;

    public MapaBuilder(){
        this.init();
    }

    @Override
    public CorridaBuilder init(){
        this.sexo = Sexo.D;
        this.idade = Idade.INFANTIL;
        this.dificuldade = Dificuldade.N;
        this.escala = 7500;
        this.ecn = 5;
        this.largada = new PontoGeografico(0.0,0.0,0.0);
        this.partida = new PontoGeografico(0.0,0.0,0.0);
        this.chegada = new PontoGeografico(0.0,0.0,0.0);
        this.prismas = new ArrayList<>();
        return this;
    }

    @Override
    public CorridaBuilder withSexo(Sexo sexo) {
        this.sexo = sexo;
        return this;
    }

    @Override
    public CorridaBuilder withIdade(Idade idade) {
        this.idade = idade;
        return this;
    }

    @Override
    public CorridaBuilder withDificuldade(Dificuldade dificuldade) {
        this.dificuldade = dificuldade;
        return this;
    }

    @Override
    public CorridaBuilder withEcn(Integer ecn) {
        this.ecn = ecn;
        return this;
    }

    @Override
    public CorridaBuilder withEscala(Integer escala) {
        this.escala = escala;
        return this;
    }

    @Override
    public CorridaBuilder withLargada(PontoGeografico largada) {
        this.largada = largada;
        return this;
    }

    @Override
    public CorridaBuilder withPartida(PontoGeografico partida) {
        this.partida = partida;
        return this;
    }

    @Override
    public CorridaBuilder withChegada(PontoGeografico chegada) {
        this.chegada = chegada;
        return this;
    }

    @Override
    public CorridaBuilder addPrisma(Prisma prisma) {
        this.prismas.add(prisma);
        return this;
    }

    public Mapa build() {
        Mapa mapa = new Mapa(
                this.sexo, this.idade, this.dificuldade,
                this.escala, this.ecn, this.largada,
                this.partida, this.prismas, this.chegada
        );
        this.init();
        return mapa;
    }
}
