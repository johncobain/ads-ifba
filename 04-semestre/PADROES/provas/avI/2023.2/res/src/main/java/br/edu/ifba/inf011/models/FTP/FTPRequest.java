package br.edu.ifba.inf011.models.FTP;

import br.edu.ifba.inf011.interfaces.Request;

import java.util.HashMap;
import java.util.Map;

public class FTPRequest implements Request {
    private Map<String, String> header;
    private byte[] body;

    public FTPRequest() {
        this.header = new HashMap<>();
    }

    @Override
    public void addHeader(String key, String value) {
        header.put(key, value);
    }

    @Override
    public void addBody(byte[] body) {
        this.body = body;
    }
}
