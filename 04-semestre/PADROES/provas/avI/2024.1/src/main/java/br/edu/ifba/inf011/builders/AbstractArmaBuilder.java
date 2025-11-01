package br.edu.ifba.inf011.builders;

import br.edu.ifba.inf011.models.Arma;

import java.util.List;

public abstract class AbstractArmaBuilder implements ArmaBuilder{
    protected Double danoAdicionalRapido;
    protected Double danoAdicionalForca;
    protected Double danoAdicionalEspecial;
    protected Boolean habilitada;
}
