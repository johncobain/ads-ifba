package br.edu.ifba.inf011.factoryMethod;

import br.edu.ifba.inf011.interfaces.Request;
import br.edu.ifba.inf011.models.FTP.FTPRequest;
import br.edu.ifba.inf011.models.HTTP.HTTPRequest;

public class RequestFactory {
    public Request create(TypeProtocol type){
        if(type == TypeProtocol.FTP)
            return new FTPRequest();

        if(type == TypeProtocol.HTTP)
            return new HTTPRequest();

        throw new IllegalArgumentException("Protocolo nao suportado");
    }
}
