package br.edu.ifba.inf011.factories;

import br.edu.ifba.inf011.builders.ArmaBuilder;
import br.edu.ifba.inf011.builders.CruzadoBuilder;
import br.edu.ifba.inf011.builders.EspadaBuilder;
import br.edu.ifba.inf011.builders.PersonagemBuilder;

public class StarterCruzadoFactory implements ComboFactory {
    @Override
    public PersonagemBuilder getPersonagemBuilder() {
        return new CruzadoBuilder();
    }

    @Override
    public ArmaBuilder getArmaBuilder() {
        return new EspadaBuilder();
    }
}
