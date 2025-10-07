package br.edu.ifba.inf011.drawing;

import br.edu.ifba.inf011.Document;

public class DrawingDocument implements Document {
    private final String content;

    public DrawingDocument(){
        this.content = "[DrawingDocument] Renderizando Drawing";
    }

    public void open(){
        System.out.println(content);
    }

    public void save(){
        System.out.println("[DrawingDocument] Salvando...");
    }
}
