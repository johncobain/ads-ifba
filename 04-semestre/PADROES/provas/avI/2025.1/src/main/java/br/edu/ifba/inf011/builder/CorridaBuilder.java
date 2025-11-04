package br.edu.ifba.inf011.builder;

import br.edu.ifba.inf011.model.*;

public interface CorridaBuilder {
    public CorridaBuilder init();
    public CorridaBuilder withSexo(Sexo sexo);
    public CorridaBuilder withIdade(Idade idade);
    public CorridaBuilder withDificuldade(Dificuldade dificuldade);
    public CorridaBuilder withDistancia(Double distancia);
    public CorridaBuilder withDesnivel(Double desnivel);
    public CorridaBuilder withEscala(Integer escala);
    public CorridaBuilder withEcn(Integer ecn);
    public CorridaBuilder withLargada(PontoGeografico largada);
    public CorridaBuilder withPartida(PontoGeografico partida);
    public CorridaBuilder addPrisma(Prisma prisma);
    public CorridaBuilder withChegada(PontoGeografico chegada);
    public CorridaBuilder addPassagem(TempoPassagem tempoPassagem);
}
