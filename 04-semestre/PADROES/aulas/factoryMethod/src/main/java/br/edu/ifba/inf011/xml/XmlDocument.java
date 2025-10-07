package br.edu.ifba.inf011.xml;

import br.edu.ifba.inf011.Document;

public class XmlDocument implements Document {
    private final String content;

    public XmlDocument(){
        this.content = "[XmlDocument] Dados XML";
    }

    public void open(){
        System.out.println(content);
    }

    public void save(){
        System.out.println("[XmlDocument] Salvando...");
    }
}
