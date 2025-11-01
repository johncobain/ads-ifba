package br.edu.ifba.inf011.builders;

import br.edu.ifba.inf011.models.Arma;
import br.edu.ifba.inf011.models.Personagem;

public interface PersonagemBuilder {
    public PersonagemBuilder init();
    public PersonagemBuilder withAtaqueRapido(Double atk);
    public PersonagemBuilder withAtaqueForca(Double atk);
    public PersonagemBuilder withAtaqueEspecial(Double atk);
    public PersonagemBuilder withDefesa(Double def);
    public PersonagemBuilder withMoedas(Double mo);
    public PersonagemBuilder withHabilidade(Boolean hab);
    public PersonagemBuilder addArma(Arma arma);

    public Personagem build();
}
