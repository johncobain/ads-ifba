package br.edu.ifba.inf011.models;

import br.edu.ifba.inf011.builders.CruzadoBuilder;

import java.util.List;

public class Cruzado implements Personagem {
    private Double ataqueRapido;
    private Double ataqueForca;
    private Double ataqueEspecial;
    private Double defesa;
    private Double moedas;
    private Boolean habilidade;
    private List<Arma> armas;

    public Cruzado(Double ataqueRapido, Double ataqueForca, Double ataqueEspecial, Double defesa, Double moedas, Boolean habilidade, List<Arma> armas){
        this.ataqueRapido = ataqueRapido;
        this.ataqueForca = ataqueForca;
        this.ataqueEspecial = ataqueEspecial;
        this.defesa = defesa;
        this.moedas = moedas;
        this.habilidade = habilidade;
        this.armas = armas;
    }

    @Override
    public String toString() {
        return "Cruzado{" +
                "\n\tataqueRapido=" + ataqueRapido +
                "\n\tataqueForca=" + ataqueForca +
                "\n\tataqueEspecial=" + ataqueEspecial +
                "\n\tdefesa=" + defesa +
                "\n\tmoedas=" + moedas +
                "\n\thabilidade=" + habilidade +
                "\n\tarmas=" + armas +
                "\n}";
    }

    @Override
    public Double getAtaqueRapido() {
        return this.ataqueRapido;
    }

    @Override
    public Double getAtaqueForca() {
        return this.ataqueForca;
    }

    @Override
    public Double getAtaqueEspecial() {
        return this.ataqueEspecial;
    }

    @Override
    public Double getDefesa() {
        return this.defesa;
    }
}
