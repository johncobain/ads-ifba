package br.edu.ifba.inf011.abstractFactory;

import br.edu.ifba.inf011.interfaces.Protocol;
import br.edu.ifba.inf011.interfaces.Request;
import br.edu.ifba.inf011.interfaces.Response;
import br.edu.ifba.inf011.models.HTTP.HTTPProtocol;
import br.edu.ifba.inf011.models.HTTP.HTTPRequest;
import br.edu.ifba.inf011.models.HTTP.HTTPResponse;

public class HTTPAbstractFactory implements ProtocolAbstractFactory{
    @Override
    public Protocol getProtocol(Integer port, String host){
        return new HTTPProtocol(port, host);
    }

    @Override
    public Request getRequest(){
        return new HTTPRequest();
    }

    @Override
    public Response getResponse(){
        return new HTTPResponse();
    }
}
