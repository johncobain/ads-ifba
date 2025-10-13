package br.edu.ifba.inf011.abstractFactory;

import br.edu.ifba.inf011.interfaces.Protocol;
import br.edu.ifba.inf011.interfaces.Request;
import br.edu.ifba.inf011.interfaces.Response;
import br.edu.ifba.inf011.models.FTP.FTPProtocol;
import br.edu.ifba.inf011.models.FTP.FTPRequest;
import br.edu.ifba.inf011.models.FTP.FTPResponse;

public class FTPAbstractFactory implements ProtocolAbstractFactory{
    @Override
    public Protocol getProtocol(Integer port, String host){
        return new FTPProtocol(port, host);
    }

    @Override
    public Request getRequest(){
        return new FTPRequest();
    }

    @Override
    public Response getResponse(){
        return new FTPResponse();
    }
}
