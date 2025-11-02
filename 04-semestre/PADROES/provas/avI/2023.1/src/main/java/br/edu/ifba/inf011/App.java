package br.edu.ifba.inf011;

import br.edu.ifba.inf011.builder.Builder;
import br.edu.ifba.inf011.builder.FichaNutricionalBuilder;
import br.edu.ifba.inf011.builder.PreparoBuilder;
import br.edu.ifba.inf011.builder.PreparoDirector;
import br.edu.ifba.inf011.exception.NutrienteNaoEncontradoException;
import br.edu.ifba.inf011.model.Nutriente;
import br.edu.ifba.inf011.model.Preparo;
import br.edu.ifba.inf011.model.ValorNutricional;
import br.edu.ifba.inf011.singleton.CatalogoNutrientes;

public class App {

    public void runQ1(){
        System.out.println("------------ Q1 ------------");
        try{
            Nutriente nutriente = CatalogoNutrientes.instance().create("CARBOIDRATO");
            System.out.println(nutriente);
        }catch(NutrienteNaoEncontradoException e){
            System.out.println(e.getNome() + " nao encontrado");
        }

        CatalogoNutrientes instance = CatalogoNutrientes.instance();
        Nutriente cho = instance.create("CARBOIDRATO", "GRAMA", 4.5);
        Nutriente ptn = instance.create("PROTEINA", "GRAMA", 4.0);
        Nutriente lip = instance.create("GORDURA", "GRAMA", 9.0);

        System.out.println(cho);
        System.out.println(ptn);
        System.out.println(lip);

        instance.create("CARBOIDRATO", "GRAMA", 4.0);

        System.out.println(cho);

        try{
            Nutriente nutriente = CatalogoNutrientes.instance().create("CARBOIDRATO");
            System.out.println(nutriente);
        }catch(NutrienteNaoEncontradoException e){
            System.out.println(e.getNome() + " nao encontrado");
        }
    }

    public void runQ2(){
        System.out.println("------------ Q2 ------------");
        PreparoBuilder builderP = new PreparoBuilder();
        FichaNutricionalBuilder builderV = new FichaNutricionalBuilder();

        PreparoDirector director = new PreparoDirector(builderP);
        director.fazerOvoFrito();
        Preparo ovoFrito = builderP.build();

        director.setBuilder(builderV);
        director.fazerOvoFrito();
        ValorNutricional fichaNutricional = builderV.build();

        System.out.println(ovoFrito + "\n" + fichaNutricional);

    }

    public static void main(String[] args) {
        App app = new App();
        app.runQ1();
        app.runQ2();
    }
}