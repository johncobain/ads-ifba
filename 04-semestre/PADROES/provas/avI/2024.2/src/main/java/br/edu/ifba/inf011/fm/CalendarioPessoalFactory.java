package br.edu.ifba.inf011.fm;

import br.edu.ifba.inf011.model.Calendario;
import br.edu.ifba.inf011.model.CalendarioPessoal;

public class CalendarioPessoalFactory implements Factory{
    @Override
    public Calendario createCalendario(String eMail, Integer mes, Integer ano) {
        return new CalendarioPessoal(eMail, mes, ano);
    }
}
