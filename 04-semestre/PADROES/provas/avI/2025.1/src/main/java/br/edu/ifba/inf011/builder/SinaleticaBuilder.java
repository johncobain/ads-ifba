package br.edu.ifba.inf011.builder;

import br.edu.ifba.inf011.model.Dificuldade;
import br.edu.ifba.inf011.model.Idade;
import br.edu.ifba.inf011.model.Sexo;
import br.edu.ifba.inf011.model.Sinaletica;

public class SinaleticaBuilder extends AbstractCorridaBuilder{
    private Sexo sexo;
    private Idade idade;
    private Dificuldade dificuldade;
    private Double distancia;
    private Double desnivel;

    public SinaleticaBuilder() {
        this.init();
    }

    public CorridaBuilder init(){
        this.sexo = Sexo.D;
        this.idade = Idade.INFANTIL;
        this.dificuldade = Dificuldade.N;
        this.distancia = 0.0;
        this.desnivel = 0.0;
        return this;
    }

    @Override
    public CorridaBuilder withSexo(Sexo sexo) {
        this.sexo = sexo;
        return this;
    }

    @Override
    public CorridaBuilder withIdade(Idade idade) {
        this.idade = idade;
        return this;
    }

    @Override
    public CorridaBuilder withDificuldade(Dificuldade dificuldade) {
        this.dificuldade = dificuldade;
        return this;
    }

    @Override
    public CorridaBuilder withDistancia(Double distancia) {
        this.distancia = distancia;
        return this;
    }

    @Override
    public CorridaBuilder withDesnivel(Double desnivel) {
        this.desnivel = desnivel;
        return this;
    }

    public Sinaletica build() {
        Sinaletica sinaletica = new Sinaletica(
                this.sexo, this.idade, this.dificuldade,
                this.distancia, this.desnivel
        );
        this.init();
        return sinaletica;
    }
}
