package br.edu.ifba.inf011.builders;

import br.edu.ifba.inf011.models.Arma;
import br.edu.ifba.inf011.models.Espada;

public class EspadaBuilder extends AbstractArmaBuilder{
    @Override
    public ArmaBuilder init() {
        this.danoAdicionalRapido = 15.0;
        this.danoAdicionalForca = 20.0;
        this.danoAdicionalEspecial = 30.0;
        this.habilitada = false;
        return this;
    }

    @Override
    public ArmaBuilder withDanoAdicionalRapido(Double atk) {
        this.danoAdicionalRapido = atk;
        return this;
    }

    @Override
    public ArmaBuilder withDanoAdicionalForca(Double atk) {
        this.danoAdicionalForca = atk;
        return this;
    }

    @Override
    public ArmaBuilder withDanoAdicionalEspecial(Double atk) {
        this.danoAdicionalEspecial = atk;
        return this;
    }

    @Override
    public ArmaBuilder habilitar() {
        this.habilitada = true;
        return this;
    }

    @Override
    public Arma build() {
        Espada espada = new Espada(this.danoAdicionalRapido, this.danoAdicionalForca, this.danoAdicionalEspecial, this.habilitada);
        this.init();
        return espada;
    }
}
