package br.edu.ifba.inf011.json;

import br.edu.ifba.inf011.Application;
import br.edu.ifba.inf011.Document;

public class JsonApplication extends Application {
    @Override
    public Document createDocument() {
        return new JsonDocument();
    }
}
