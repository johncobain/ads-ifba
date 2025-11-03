package br.edu.ifba.inf011.model;

public class Maquina extends Equipamento{

    private String descricao;
    private String marca;

    public Maquina(String identificador, int quantidade,
                   String descricao, String marca) {
        super(identificador, quantidade);
        this.descricao = descricao;
        this.marca = marca;
    }


    public Maquina(String identificador, int quantidade) {
        this(identificador, quantidade, null, null);
    }

    public Maquina() {
        super();
    }

    public String getDescricao() {
        return this.descricao;
    }

    public String getMarca() {
        return this.marca;
    }

    public String toString() {
        return "M�quina - " + super.toString()
                + (this.getDescricao() != null ? " - " + this.getDescricao() : "")
                + (this.getMarca() != null ? " - " + this.getMarca() : "");
    }

}