package br.edu.ifba.inf011.factoryMethod;

import br.edu.ifba.inf011.interfaces.Protocol;
import br.edu.ifba.inf011.models.FTP.FTPProtocol;
import br.edu.ifba.inf011.models.HTTP.HTTPProtocol;

public class ProtocolFactory {
    public Protocol create(TypeProtocol type, Integer port, String host){
        if(type == TypeProtocol.FTP)
            return new FTPProtocol(port, host);

        if(type == TypeProtocol.HTTP)
            return new HTTPProtocol(port, host);

        throw new IllegalArgumentException("Protocolo nao suportado");
    }
}
