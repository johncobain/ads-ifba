package br.edu.ifba.inf011.models.HTTP;

import br.edu.ifba.inf011.interfaces.Request;
import br.edu.ifba.inf011.interfaces.Response;

import java.util.HashMap;
import java.util.Map;

public class HTTPRequest implements Request {
    private Map<String, String> header;
    private byte[] body;

    public HTTPRequest() {
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
