package br.edu.ifba.inf011.model;

import java.util.Objects;

public abstract class Equipamento {
    private String identificador;
    private int quantidade;

    public Equipamento() {
        this(null, 0);
    }

    public Equipamento(String identificador, int quantidade) {
        super();
        this.setIdentificador(identificador);
        this.setQuantidade(quantidade);
    }

    public void setIdentificador(String identificador) {
        this.identificador = identificador;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public String getIdentificador() {
        return identificador;
    }

    public int getQuantidade() {
        return quantidade;
    }

    @Override
    public int hashCode() {
        return Objects.hash(identificador);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Equipamento other = (Equipamento) obj;
        return Objects.equals(identificador, other.identificador);
    }

    public String toString() {
        return "[ID: " + this.getIdentificador() + "]: " +
                this.getQuantidade() + " unidades";
    }

    public void aumentarQuantidade(int quantidade) {
        this.quantidade += quantidade;
    }

}