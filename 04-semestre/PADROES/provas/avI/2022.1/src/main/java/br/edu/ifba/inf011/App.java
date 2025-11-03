package br.edu.ifba.inf011;

import br.edu.ifba.inf011.builder.ExercicioBuilder;
import br.edu.ifba.inf011.model.Equipamento;
import br.edu.ifba.inf011.model.Exercicio;
import br.edu.ifba.inf011.model.GrupoMuscular;
import br.edu.ifba.inf011.model.TipoExercicio;
import br.edu.ifba.inf011.singleton.CatalogoEquipamentos;

public class App {
    public void run1(){
        System.out.println("------------ Q1 ------------");
        CatalogoEquipamentos catalogoEquipamentos = CatalogoEquipamentos.getInstance();
        catalogoEquipamentos.getEquipamentos().forEach((identificador, equipamento) -> {
            System.out.println(identificador + " - " + equipamento);
        });
    }

    public void run2(){
        System.out.println("------------ Q2 ------------");
        ExercicioBuilder builder = new ExercicioBuilder();
        builder.id("1")
                .tipo(TipoExercicio.Funcional)
                .grupoMuscular(GrupoMuscular.Inferiores)
                .equipamento(CatalogoEquipamentos.getInstance().getEquipamento("Halteres"));

        Exercicio exercicio = builder.build("Exercicio");
        System.out.println(exercicio);
    }

    public static void main(String[] args) {
        App app = new App();
        app.run1();
        app.run2();
    }
}