package br.edu.ifba.inf011.interfaces;

public interface Protocol {
    public void open();
    public void message(Request request, Response response);
    public void close();
}
