package br.edu.ifba.inf011.builder;

import br.edu.ifba.inf011.model.Alimento;

public interface Builder {
    public void init();
    public Builder lowCarb();
    public Builder vegano();
    public Builder semLactose();
    public Builder semGluten();
    public Builder reduzidoSodio();
    public Builder withNome(String nome);
    public Builder addAlimento(Alimento alimento);
    public Builder withModoDeFazer(String modoDeFazer);

}
