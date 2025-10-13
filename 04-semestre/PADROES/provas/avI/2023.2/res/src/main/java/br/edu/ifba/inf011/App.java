package br.edu.ifba.inf011;

import br.edu.ifba.inf011.abstractFactory.HTTPAbstractFactory;
import br.edu.ifba.inf011.abstractFactory.ProtocolAbstractFactory;
import br.edu.ifba.inf011.factoryMethod.TypeProtocol;
import br.edu.ifba.inf011.factoryMethod.ProtocolFactory;
import br.edu.ifba.inf011.factoryMethod.RequestFactory;
import br.edu.ifba.inf011.factoryMethod.ResponseFactory;
import br.edu.ifba.inf011.interfaces.Protocol;

public class App {
    public void runQ1(){
        System.out.println("------------------------------------ Q1 ------------------------------------");
        TypeProtocol type = TypeProtocol.FTP;

        Protocol protocol = (new ProtocolFactory()).create(type, 21, "ftp.inf011.ifba.edu.br");
        protocol.open();
        protocol.message((new RequestFactory()).create(type), (new ResponseFactory()).create(type));
        protocol.close();
    }

    public void runQ2(){
        System.out.println("------------------------------------ Q2 ------------------------------------");
        ProtocolAbstractFactory factory = new HTTPAbstractFactory();

        Protocol protocol = factory.getProtocol(21, "http.inf011.ifba.edu.br");

        protocol.open();
        protocol.message(factory.getRequest(), factory.getResponse());
        protocol.close();
    }

    public static void main(String[] args) {
        App app = new App();
        app.runQ1();
        app.runQ2();
    }
}
