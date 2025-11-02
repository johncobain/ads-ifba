package br.edu.ifba.inf011.builder;

import br.edu.ifba.inf011.model.Alimento;
import br.edu.ifba.inf011.model.ValorNutricional;

public class FichaNutricionalBuilder implements Builder{
    private Double cho, ptn, lip;

    public FichaNutricionalBuilder() {
        this.init();
    }

    @Override
    public void init() {
        this.cho = 0.0;
        this.ptn = 0.0;
        this.lip = 0.0;
    }

    @Override
    public Builder lowCarb() {
        return this;
    }

    @Override
    public Builder vegano() {
        return this;
    }

    @Override
    public Builder semLactose() {
        return this;
    }

    @Override
    public Builder semGluten() {
        return this;
    }

    @Override
    public Builder reduzidoSodio() {
        return this;
    }

    @Override
    public Builder withNome(String nome) {
        return this;
    }

    @Override
    public Builder addAlimento(Alimento alimento) {
        this.cho += alimento.getQuantidadeNutriente("CARBOIDRATO");
        this.ptn += alimento.getQuantidadeNutriente("PROTEINA");
        this.lip += alimento.getQuantidadeNutriente("GORDURA");
        return this;
    }

    @Override
    public Builder withModoDeFazer(String modoDeFazer) {
        return this;
    }

    public ValorNutricional build() {
        return new ValorNutricional(this.cho, this.ptn, this.lip);
    }

}
