package br.edu.ifba.inf011.prototypeRegister;

import br.edu.ifba.inf011.model.*;

import java.util.HashMap;
import java.util.Map;

public class BoletimReg {
    private static BoletimReg boletim;
    private Map<String, ListaPassagens> listas;

    private BoletimReg(){
        this.listas = new HashMap<>();
    }

    public static BoletimReg instance(){
        if(boletim == null){
            boletim = new BoletimReg();
        }
        return boletim;
    }

    private String categoria(Sexo sexo, Idade idade, Dificuldade dificuldade){
        return sexo.toString() + idade.toString() + dificuldade.toString();
    }

    public void register(Sexo sexo, Idade idade, Dificuldade dificuldade, ListaPassagens lista){
        String categoria = this.categoria(sexo, idade, dificuldade);
        this.listas.put(categoria, lista);
    }

    public BoletimProva getBoletim(String numeroCBO, Sexo sexo, Idade idade, Dificuldade dificuldade){
        String categoria = this.categoria(sexo, idade, dificuldade);
        ListaPassagens lista = this.listas.get(categoria);
        if(lista == null){
            return null;
        }
        return new BoletimProva(numeroCBO, (ListaPassagens) lista.clone());
    }
}
