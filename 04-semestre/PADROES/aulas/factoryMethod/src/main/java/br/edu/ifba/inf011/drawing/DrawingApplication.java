package br.edu.ifba.inf011.drawing;

import br.edu.ifba.inf011.Application;
import br.edu.ifba.inf011.Document;

import java.util.ArrayList;
import java.util.List;

public class DrawingApplication extends Application {
    @Override
    public Document createDocument(){
        return new DrawingDocument();
    }
}
