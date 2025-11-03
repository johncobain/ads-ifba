package br.edu.ifba.inf011.model;

public class Halteres extends Equipamento{

    private double peso;

    public Halteres(String identificador, int quantidade, double peso) {
        super(identificador, quantidade);
        this.peso = peso;
    }


    public Halteres(String identificador, int quantidade) {
        this(identificador, quantidade, 0);
    }

    public Halteres() {
        super();
    }

    public double getPeso() {
        return peso;
    }

    public String toString() {
        return "Halteres - " + super.toString() + " - "
                + this.getPeso() + "Kg." ;
    }

}