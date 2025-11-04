package br.edu.ifba.inf011.model;

import java.time.Duration;

public class TempoPassagem implements Cloneable{

    private Prisma prisma;
    private Duration tempo;

    public TempoPassagem(Prisma prisma) {
        this.prisma = prisma;
        this.tempo = Duration.ofSeconds(0);
    }

    public TempoPassagem(Prisma prisma, Duration tempo) {
        this.prisma = prisma;
        this.tempo = tempo;
    }

    public TempoPassagem(TempoPassagem tempo) {
        this.prisma = tempo.prisma();
        this.tempo = tempo.tempo();
    }


    public Prisma prisma() {
        return this.prisma;
    }

    public Duration tempo() {
        return this.tempo;
    }

    public void setTempo(Duration tempo) {
        this.tempo = tempo;
    }


    public Cloneable clone() {
        return new TempoPassagem(this);
    }

    @Override
    public String toString() {
        return "TempoPassagem [prisma=" + prisma + ", tempo=" + tempo + "]";
    }



}