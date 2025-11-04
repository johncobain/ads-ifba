package br.edu.ifba.inf011;

import br.edu.ifba.inf011.builder.*;
import br.edu.ifba.inf011.model.*;
import br.edu.ifba.inf011.prototypeRegister.BoletimReg;

import java.time.Duration;

public class App{
    public void run1(){
        System.out.println("------------ Q1 ------------");
        MapaBuilder mapaBuilder = new MapaBuilder();
        SinaleticaBuilder sinaleticaBuilder = new SinaleticaBuilder();
        ListaPassagensBuilder listaPassagensBuilder = new ListaPassagensBuilder();

        PercursoDirector director = new PercursoDirector();
        director.createPercurso(mapaBuilder);
        director.createPercurso(sinaleticaBuilder);
        director.createPercurso(listaPassagensBuilder);

        System.out.println(mapaBuilder.build());
        System.out.println();
        System.out.println(sinaleticaBuilder.build());
        System.out.println();
        System.out.println(listaPassagensBuilder.build());
    }

    public void run2(){
        System.out.println("------------ Q2 ------------");
        ListaPassagensBuilder listaPassagensBuilder = new ListaPassagensBuilder();
        PercursoDirector director = new PercursoDirector();
        director.createPercurso(listaPassagensBuilder);
        ListaPassagens listaPassagens = listaPassagensBuilder.build();

        BoletimReg boletim = BoletimReg.instance();
        boletim.register(Sexo.D, Idade.VIP, Dificuldade.N, listaPassagens);

        BoletimProva atleta1 = boletim.getBoletim("123456", Sexo.D, Idade.VIP, Dificuldade.N);
        atleta1.registrar(31, Duration.ofSeconds(10));
        atleta1.registrar(32, Duration.ofSeconds(20));

        BoletimProva atleta2 = boletim.getBoletim("123456", Sexo.D, Idade.VIP, Dificuldade.N);
        atleta2.registrar(31, Duration.ofSeconds(13));
        atleta2.registrar(32, Duration.ofSeconds(24));

        System.out.println(atleta1);
        System.out.println(atleta2);
    }

    public static void main(String[] args) {
        App app = new App();
        app.run1();
        app.run2();
    }
}
