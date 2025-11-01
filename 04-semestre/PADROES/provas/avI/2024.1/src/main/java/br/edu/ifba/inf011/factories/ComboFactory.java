package br.edu.ifba.inf011.factories;

import br.edu.ifba.inf011.builders.ArmaBuilder;
import br.edu.ifba.inf011.builders.PersonagemBuilder;

public interface ComboFactory {
    public PersonagemBuilder getPersonagemBuilder();
    public ArmaBuilder getArmaBuilder();
}
