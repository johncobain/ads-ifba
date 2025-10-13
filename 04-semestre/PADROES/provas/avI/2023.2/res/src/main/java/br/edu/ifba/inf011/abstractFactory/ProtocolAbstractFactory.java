package br.edu.ifba.inf011.abstractFactory;

import br.edu.ifba.inf011.interfaces.Protocol;
import br.edu.ifba.inf011.interfaces.Request;
import br.edu.ifba.inf011.interfaces.Response;

public interface ProtocolAbstractFactory {
    public Protocol getProtocol(Integer port, String host);
    public Request getRequest();
    public Response getResponse();
}
