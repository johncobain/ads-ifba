package br.edu.ifba.inf011;

import br.edu.ifba.inf011.builder.PartidaBuilder;
import br.edu.ifba.inf011.fm.CalendarioPessoalFactory;
import br.edu.ifba.inf011.fm.Factory;
import br.edu.ifba.inf011.model.Calendario;
import br.edu.ifba.inf011.model.Equipe;
import br.edu.ifba.inf011.model.Geolocalizacao;
import br.edu.ifba.inf011.model.Partida;

import java.time.LocalDate;
import java.time.LocalDateTime;

public class App {
    public void run1(Factory factory){
        System.out.println("------------ Q1 ------------");
        Calendario calendario = factory.createCalendario("calendar.ifba.edu.br", 1, 2024);

        try{
            calendario.download("calendar.ifba.edu.br");
            calendario.sinalizarEventos(LocalDate.of(LocalDate.now().getYear(),
                    LocalDate.now().getMonth(),
                    1));
        }catch(Exception e){
            System.out.println(e.getMessage());
        }
    }

    public void run2(PartidaBuilder builder){
        System.out.println("------------ Q2 ------------");
        builder.setInicio(LocalDateTime.of(1970, 6, 21, 12,0))
            .setLocalizacao(new Geolocalizacao("Estádio Azteca - Cidade do México"))
                .setPlacarA(4).setPlacarB(1);

        Partida partida = builder.build(
                "Final da Copa do Mundo de 1970",
                new Equipe("Brasil"),
                new Equipe("Itália")
        );

        System.out.println(partida);
    }

    public static void main(String[] args) {
        App app = new App();
        app.run1(new CalendarioPessoalFactory());
        app.run2(new PartidaBuilder());
    }
}