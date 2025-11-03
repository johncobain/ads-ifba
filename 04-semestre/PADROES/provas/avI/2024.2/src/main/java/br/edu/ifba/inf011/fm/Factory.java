package br.edu.ifba.inf011.fm;

import br.edu.ifba.inf011.model.Calendario;

public interface Factory {
    public Calendario createCalendario(String eMail, Integer mes, Integer ano);
}
