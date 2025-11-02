package br.edu.ifba.inf011.builder;

import br.edu.ifba.inf011.model.Alimento;

public class PreparoDirector {
    private Builder builder;

    public PreparoDirector(Builder builder){
        this.builder = builder;
    }

    public void setBuilder(Builder builder){
        this.builder = builder;
    }

    public void fazerOvoFrito(){
        this.builder.init();
        this.builder.withNome("Ovo Frito");
        try{
            this.builder.addAlimento(new Alimento("OVO", 0.24,1.95, 7.28));
            this.builder.addAlimento(new Alimento("MANTEIGA", 0.24,1.95, 7.28));
            this.builder.addAlimento(new Alimento("SAL", 0.0, 0.0, 0.0));
            this.builder.lowCarb().semGluten();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
