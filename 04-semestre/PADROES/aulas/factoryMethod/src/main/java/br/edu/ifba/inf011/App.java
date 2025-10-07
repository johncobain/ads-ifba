package br.edu.ifba.inf011;

import br.edu.ifba.inf011.json.JsonApplication;

public class App {
    public static void run(Application app){
        app.openDocument();
    }

    public static void main(String[] args) {
        App.run(new JsonApplication());
    }
}