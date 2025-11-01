package br.edu.ifba.inf011.models;

public class Espada implements Arma{
    private Double danoAdicionalRapido;
    private Double danoAdicionalForca;
    private Double danoAdicionalEspecial;
    private Boolean habilitada;

    public Espada(Double danoAdicionalRapido, Double danoAdicionalForca, Double danoAdicionalEspecial, Boolean habilitada){
        this.danoAdicionalRapido = danoAdicionalRapido;
        this.danoAdicionalForca = danoAdicionalForca;
        this.danoAdicionalEspecial = danoAdicionalEspecial;
        this.habilitada = habilitada;
    }
    @Override
    public Double getDanoAdicionalRapido() {
        return this.danoAdicionalRapido;
    }

    @Override
    public Double getDanoAdicionalForca() {
        return this.danoAdicionalForca;
    }

    @Override
    public Double getDanoAdicionalEspecial() {
        return this.danoAdicionalEspecial;
    }

    @Override
    public Boolean habilitada() {
        return this.habilitada;
    }

    @Override
    public String toString() {
        return "Espada{" +
                "danoAdicionalRapido=" + danoAdicionalRapido +
                ", danoAdicionalForca=" + danoAdicionalForca +
                ", danoAdicionalEspecial=" + danoAdicionalEspecial +
                ", habilitada=" + habilitada +
                '}';
    }
}
