package br.edu.ifba.inf011.models.FTP;

import br.edu.ifba.inf011.interfaces.Protocol;
import br.edu.ifba.inf011.interfaces.Request;
import br.edu.ifba.inf011.interfaces.Response;

public class FTPProtocol implements Protocol {
    private Integer port;
    private String host;

    public FTPProtocol(Integer port, String host){
        this.port = port;
        this.host = host;
    }

    @Override
    public void open() {
        System.out.println("[FTPProtocol] Open connection");
    }

    @Override
    public void message(Request request, Response response) {
        System.out.println("[FTPProtocol] Sending message to: " + this.host + ":" + this.port);
    }

    @Override
    public void close() {
        System.out.println("[FTPProtocol] Close connection");
    }
}
