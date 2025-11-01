package br.edu.ifba.inf011.builders;

import br.edu.ifba.inf011.models.Arma;
import br.edu.ifba.inf011.models.Cruzado;
import br.edu.ifba.inf011.models.Personagem;

import java.util.ArrayList;

public class CruzadoBuilder extends AbstractPersonagemBuilder{
    @Override
    public PersonagemBuilder init() {
        this.ataqueRapido = 10.0;
        this.ataqueForca = 50.0;
        this.ataqueEspecial = 100.0;
        this.defesa = 150.0;
        this.moedas = 100.0;
        this.habilidade = false;
        this.armas = new ArrayList<>();
        return this;
    }

    public CruzadoBuilder(){
        this.init();
    }

    @Override
    public PersonagemBuilder withAtaqueRapido(Double atk) {
        this.ataqueRapido = atk;
        return this;
    }

    @Override
    public PersonagemBuilder withAtaqueForca(Double atk) {
        this.ataqueForca = atk;
        return this;
    }

    @Override
    public PersonagemBuilder withAtaqueEspecial(Double atk) {
        this.ataqueEspecial = atk;
        return this;
    }

    @Override
    public PersonagemBuilder withDefesa(Double def) {
        this.defesa = def;
        return this;
    }

    @Override
    public PersonagemBuilder withMoedas(Double mo) {
        this.moedas = mo;
        return this;
    }

    @Override
    public PersonagemBuilder withHabilidade(Boolean hab) {
        this.habilidade = hab;
        return this;
    }

    @Override
    public PersonagemBuilder addArma(Arma arma) {
        this.armas.add(arma);
        return this;
    }

    @Override
    public Personagem build() {
        Cruzado cruzado = new Cruzado(this.ataqueRapido, this.ataqueForca, this.ataqueEspecial, this.defesa, this.moedas, this.habilidade, this.armas);
        this.init();
        return cruzado;
    }
}
