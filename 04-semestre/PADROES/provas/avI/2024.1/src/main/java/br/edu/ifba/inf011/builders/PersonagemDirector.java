package br.edu.ifba.inf011.builders;

import br.edu.ifba.inf011.models.Arma;

public class PersonagemDirector {
    private final PersonagemBuilder pb;
    private final ArmaBuilder ab;

    public PersonagemDirector(PersonagemBuilder pb, ArmaBuilder ab) {
        this.pb = pb;
        this.ab = ab;
    }

    public void createPersonagem() {
        Arma arma = ab.init().habilitar().build();
        pb.init().addArma(arma);
    }
}
