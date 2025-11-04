package br.edu.ifba.inf011.builder;

import br.edu.ifba.inf011.model.*;

public class AbstractCorridaBuilder implements CorridaBuilder {
    public CorridaBuilder init() {
        return this;
    }
    public CorridaBuilder withSexo(Sexo sexo) {
        return this;
    }
    public CorridaBuilder withIdade(Idade idade) {
        return this;
    }
    public CorridaBuilder withDificuldade(Dificuldade dificuldade) {
        return this;
    }
    public CorridaBuilder withDistancia(Double distancia) {
        return this;
    }
    public CorridaBuilder withDesnivel(Double desnivel) {
        return this;
    }
    public CorridaBuilder withEscala(Integer escala) {
        return this;
    }
    public CorridaBuilder withEcn(Integer ecn) {
        return this;
    }
    public CorridaBuilder withLargada(PontoGeografico largada) {
        return this;
    }
    public CorridaBuilder withPartida(PontoGeografico partida) {
        return this;
    }
    public CorridaBuilder addPrisma(Prisma prisma) {
        return this;
    }
    public CorridaBuilder withChegada(PontoGeografico chegada) {
        return this;
    }
    public CorridaBuilder addPassagem(TempoPassagem tempoPassagem) {
        return this;
    }
}
