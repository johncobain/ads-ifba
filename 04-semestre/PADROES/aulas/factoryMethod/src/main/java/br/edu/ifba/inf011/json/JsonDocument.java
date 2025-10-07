package br.edu.ifba.inf011.json;

import br.edu.ifba.inf011.Document;

public class JsonDocument implements Document {
    @Override
    public void open() {
        System.out.println("[Documento Json] Abrindo e jasando");
    }

    @Override
    public void save() {
        System.out.println("[Documento Json] Salvando");
    }
}
