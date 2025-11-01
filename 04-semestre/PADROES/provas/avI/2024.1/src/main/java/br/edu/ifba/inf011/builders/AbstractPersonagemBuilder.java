package br.edu.ifba.inf011.builders;

import br.edu.ifba.inf011.models.Arma;
import br.edu.ifba.inf011.models.Personagem;

import java.util.List;

public abstract class AbstractPersonagemBuilder implements PersonagemBuilder{
    protected Double ataqueRapido;
    protected Double ataqueForca;
    protected Double ataqueEspecial;
    protected Double defesa;
    protected Double moedas;
    protected Boolean habilidade;
    protected List<Arma> armas;
}
