package br.edu.ifba.inf011.model;

import java.util.ArrayList;
import java.util.List;

public class Exercicio {

    private String id;
    private String descricao;
    private List<TipoExercicio> tipos;
    private List<GrupoMuscular> gruposMusculares;
    private List<Equipamento> equipamentos;


    public Exercicio(String id, String descricao, List<TipoExercicio> tipos,
                        List<GrupoMuscular> gruposMusculares,
                        List<Equipamento> equipamentos) {
        this.id = id;
        this.descricao = descricao;
        this.tipos = new ArrayList<TipoExercicio>(tipos);
        this.gruposMusculares = new ArrayList<GrupoMuscular>(gruposMusculares);
        this.equipamentos = new ArrayList<Equipamento>(equipamentos);
    }

    public String toString() {
        String desc = this.id + "\t" + this.descricao;
        desc += "\n\t";
        for(TipoExercicio tipo : this.tipos)
            desc += (tipo + "\n\t");
        if(this.tipos.size() == 0)
            desc += "\n\t";
        for(GrupoMuscular grupo : this.gruposMusculares)
            desc += (grupo + "\n\t");
        if(this.gruposMusculares.size() == 0)
            desc += "\n\t";
        for(Equipamento equipamento : this.equipamentos)
            desc += (equipamento + "\n\t");
        if(this.gruposMusculares.size() == 0)
            desc += "\n\t";
        return desc;
    }


}