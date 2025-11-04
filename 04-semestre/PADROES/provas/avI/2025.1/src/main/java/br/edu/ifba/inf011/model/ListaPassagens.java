package br.edu.ifba.inf011.model;

import java.time.Duration;
import java.util.ArrayList;
import java.util.List;

public class ListaPassagens implements Cloneable{

    private List<TempoPassagem> tempos;

    public ListaPassagens() {
        this.tempos = new ArrayList<TempoPassagem>();
    }

    public ListaPassagens(ListaPassagens lista) {
        this.tempos = new ArrayList<TempoPassagem>();
        for(TempoPassagem tempo : lista.tempos)
            this.tempos.add((TempoPassagem) tempo.clone());
    }


    public ListaPassagens(List<TempoPassagem> tempos) {
        this.tempos = tempos;
    }


    public void registrarPassagem(Integer numeroPrima, Duration tempo) {
        for(TempoPassagem tempoPassagem : this.tempos)
            if(tempoPassagem.prisma().numero() == numeroPrima)
                tempoPassagem.setTempo(tempo);
    }


    public Cloneable clone() {
        return new ListaPassagens(this);
    }

    @Override
    public String toString() {
        return "ListaPassagens [tempos=" + tempos + "]";
    }
}