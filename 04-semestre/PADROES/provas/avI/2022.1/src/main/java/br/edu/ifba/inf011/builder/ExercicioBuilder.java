package br.edu.ifba.inf011.builder;

import br.edu.ifba.inf011.model.Equipamento;
import br.edu.ifba.inf011.model.Exercicio;
import br.edu.ifba.inf011.model.GrupoMuscular;
import br.edu.ifba.inf011.model.TipoExercicio;

import java.util.ArrayList;
import java.util.List;

public class ExercicioBuilder {
    private String id;
    private List<TipoExercicio> tipos;
    private List<GrupoMuscular> gruposMusculares;
    private List<Equipamento> equipamentos;

    public ExercicioBuilder(){
        this.init();
    }

    public void init(){
        this.id = "";
        this.tipos = new ArrayList<>();
        this.gruposMusculares = new ArrayList<>();
        this.equipamentos = new ArrayList<>();
    }

    public ExercicioBuilder id(String id){
        this.id = id;
        return this;
    }

    public ExercicioBuilder tipo(TipoExercicio tipo){
        this.tipos.add(tipo);
        return this;
    }

    public ExercicioBuilder grupoMuscular(GrupoMuscular grupo){
        this.gruposMusculares.add(grupo);
        return this;
    }

    public ExercicioBuilder equipamento(Equipamento equipamento){
        this.equipamentos.add(equipamento);
        return this;
    }

    public Exercicio build(String nome){
        Exercicio exercicio = new Exercicio(this.id, nome, this.tipos, this.gruposMusculares, this.equipamentos);
        this.init();
        return exercicio;
    }
}
