package br.edu.ifba.inf011.interfaces;

public interface Response {
    public void addHeader(String key, String value);
    public void addBody(byte[] body);
}
