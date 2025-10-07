package br.edu.ifba.inf011.xml;

import br.edu.ifba.inf011.Application;
import br.edu.ifba.inf011.Document;

public class XmlApplication extends Application {
    @Override
    public Document createDocument(){
        return new XmlDocument();
    }
}
