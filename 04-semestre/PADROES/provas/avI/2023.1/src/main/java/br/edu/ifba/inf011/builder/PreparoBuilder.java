package br.edu.ifba.inf011.builder;

import br.edu.ifba.inf011.model.Alimento;
import br.edu.ifba.inf011.model.Preparo;

import java.util.ArrayList;
import java.util.List;

public class PreparoBuilder implements Builder{
    private String nome;
    private Boolean lowCarb;
    private Boolean lowVegano;
    private Boolean semLactose;
    private Boolean semGluten;
    private Boolean reduzidoSodio;
    private String modoDeFazer;
    private List<Alimento> alimentos;

    public PreparoBuilder() {
        this.init();
    }

    @Override
    public void init() {
        this.lowCarb = false;
        this.lowVegano = false;
        this.semLactose = false;
        this.semGluten = false;
        this.reduzidoSodio = false;
        this.modoDeFazer = "";
        this.alimentos = new ArrayList<Alimento>();
    }

    @Override
    public PreparoBuilder lowCarb() {
        this.lowCarb = true;
        return this;
    }

    @Override
    public PreparoBuilder vegano() {
        this.lowVegano = true;
        return this;
    }

    @Override
    public PreparoBuilder semLactose() {
        this.semLactose = true;
        return this;
    }

    @Override
    public PreparoBuilder semGluten() {
        this.semGluten = true;
        return this;
    }

    @Override
    public PreparoBuilder reduzidoSodio() {
        this.reduzidoSodio = true;
        return this;
    }

    @Override
    public PreparoBuilder withNome(String nome) {
        this.nome = nome;
        return this;
    }

    @Override
    public PreparoBuilder addAlimento(Alimento alimento) {
        this.alimentos.add(alimento);
        return this;
    }

    @Override
    public PreparoBuilder withModoDeFazer(String modoDeFazer) {
        this.modoDeFazer = modoDeFazer;
        return this;
    }

    public Preparo build() {
        Preparo preparo = new Preparo(this.nome, this.alimentos, this.lowCarb, this.lowVegano, this.semLactose, this.semGluten, this.reduzidoSodio, this.modoDeFazer);
        this.init();
        return preparo;
    }
}
