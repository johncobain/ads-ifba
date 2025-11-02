package br.edu.ifba.inf011.singleton;

import br.edu.ifba.inf011.exception.NutrienteNaoEncontradoException;
import br.edu.ifba.inf011.model.Nutriente;

import java.util.HashMap;
import java.util.Map;

public class CatalogoNutrientes implements ArmazemNutrientes{

    private static CatalogoNutrientes instance;
    private final Map<String, Nutriente> catalogo;

    private CatalogoNutrientes() {
        this.catalogo = new HashMap<>();
        this.init();
    }

    private void init(){
        this.create("CARBOIDRATO", "GRAMA", 4.0);
        this.create("PROTEINA", "GRAMA", 4.0);
        this.create("GORDURA", "GRAMA", 9.0);
    }

    public static CatalogoNutrientes instance(){
        if(instance == null){
            instance = new CatalogoNutrientes();
        }
        return instance;
    }

    @Override
    public Nutriente create(String nome, String unidade, Double caloriaUnidade){
        Nutriente nutriente = catalogo.get(nome);
        if(nutriente == null) nutriente = new Nutriente(nome);
        nutriente.setCaloriaPorUnidade(caloriaUnidade);
        nutriente.setUnidade(unidade);
        catalogo.put(nome, nutriente);
        return nutriente;
    }

    @Override
    public Nutriente create(String nome) throws NutrienteNaoEncontradoException {
        Nutriente nutriente = catalogo.get(nome);
        if(nutriente == null){
            throw new NutrienteNaoEncontradoException(nome);
        }
        return nutriente;
    }
}
