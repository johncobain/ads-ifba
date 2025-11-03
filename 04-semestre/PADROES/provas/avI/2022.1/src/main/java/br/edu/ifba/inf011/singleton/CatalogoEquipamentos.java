package br.edu.ifba.inf011.singleton;

import br.edu.ifba.inf011.model.Acessorio;
import br.edu.ifba.inf011.model.Equipamento;
import br.edu.ifba.inf011.model.Halteres;
import br.edu.ifba.inf011.model.Maquina;

import java.util.HashMap;
import java.util.Map;

public class CatalogoEquipamentos {
    public static CatalogoEquipamentos catalogoEquipamentos;

    Map<String, Equipamento> equipamentos;

    private CatalogoEquipamentos() {
        this.equipamentos = new HashMap<>();
        this.init();
    }

    public static CatalogoEquipamentos getInstance() {
        if (catalogoEquipamentos == null) {
            catalogoEquipamentos = new CatalogoEquipamentos();
        }
        return catalogoEquipamentos;
    }

    public void init(){
        this.equipamentos.put("Halteres", new Halteres("Halteres", 2, 20));
        this.equipamentos.put("Supino", new Maquina("Supino", 1, "Supino", "Marca"));
        this.equipamentos.put("Acessorio", new Acessorio("Acessorio", 1, "Acessorio"));
    }

    public Equipamento createEquipamento(String identificador, Equipamento eq){
        Equipamento equipamento = equipamentos.get(identificador);
        if(equipamento == null) {
            equipamento = eq;
            equipamentos.put(identificador, equipamento);
        }
        return equipamento;
    }

    public Equipamento getEquipamento(String identificador){
        return equipamentos.get(identificador);
    }

    public Map<String, Equipamento> getEquipamentos(){
        return equipamentos;
    }
}
