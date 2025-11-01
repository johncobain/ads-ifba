package br.edu.ifba.inf011.builders;

import br.edu.ifba.inf011.models.Arma;

public interface ArmaBuilder {
    public ArmaBuilder init();
    public ArmaBuilder withDanoAdicionalRapido(Double atk);
    public ArmaBuilder withDanoAdicionalForca(Double atk);
    public ArmaBuilder withDanoAdicionalEspecial(Double atk);
    public ArmaBuilder habilitar();
    public Arma build();
}
