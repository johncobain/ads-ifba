package br.edu.ifba.inf011.builder;

import br.edu.ifba.inf011.model.ListaPassagens;
import br.edu.ifba.inf011.model.Prisma;
import br.edu.ifba.inf011.model.TempoPassagem;

import java.util.ArrayList;
import java.util.List;

public class ListaPassagensBuilder extends AbstractCorridaBuilder{
    private List<TempoPassagem> tempoPassagems;

    public ListaPassagensBuilder() {
        this.init();
    }

    public CorridaBuilder init(){
        this.tempoPassagems = new ArrayList<>();
        return this;
    }

    @Override
    public CorridaBuilder addPrisma(Prisma prisma){
        this.tempoPassagems.add(new TempoPassagem(prisma));
        return this;
    }

    @Override
    public CorridaBuilder addPassagem(TempoPassagem tempoPassagem) {
        this.tempoPassagems.add(tempoPassagem);
        return this;
    }

    public ListaPassagens build(){
        ListaPassagens listaPassagens = new ListaPassagens(this.tempoPassagems);
        this.init();
        return listaPassagens;
    }


}
