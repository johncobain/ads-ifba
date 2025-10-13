package br.edu.ifba.inf011.factoryMethod;

import br.edu.ifba.inf011.interfaces.Response;
import br.edu.ifba.inf011.models.FTP.FTPResponse;
import br.edu.ifba.inf011.models.HTTP.HTTPResponse;

public class ResponseFactory {
    public Response create(TypeProtocol type){
        if(type == TypeProtocol.FTP)
            return new FTPResponse();

        if(type == TypeProtocol.HTTP)
            return new HTTPResponse();

        throw new IllegalArgumentException("Protocolo nao suportado");
    }
}
