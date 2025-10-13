package br.edu.ifba.inf011.models.HTTP;

import br.edu.ifba.inf011.interfaces.Protocol;
import br.edu.ifba.inf011.interfaces.Request;
import br.edu.ifba.inf011.interfaces.Response;

public class HTTPProtocol implements Protocol {
    private Integer port;
    private String host;

    public HTTPProtocol(Integer port, String host){
        this.port = port;
        this.host = host;
    }

    @Override
    public void open() {
        System.out.println("[HTTPProtocol] Open connection");
    }

    @Override
    public void message(Request request, Response response) {
        System.out.println("[HTTPProtocol] Sending message to: " + this.host + ":" + this.port);
    }

    @Override
    public void close() {
        System.out.println("[HTTPProtocol] Close connection");
    }
}
