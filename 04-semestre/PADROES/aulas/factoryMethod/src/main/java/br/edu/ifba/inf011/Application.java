package br.edu.ifba.inf011;

import br.edu.ifba.inf011.drawing.DrawingDocument;

import java.util.ArrayList;
import java.util.List;

public abstract class Application {
    private final List<Document> docs;

    public Application(){
        this.docs = new ArrayList<>();
    }

    public void openDocument(){
        Document doc = this.createDocument();
        doc.open();
        this.docs.add(doc);
    }

    public abstract Document createDocument();
}
