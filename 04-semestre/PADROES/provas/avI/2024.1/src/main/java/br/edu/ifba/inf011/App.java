package br.edu.ifba.inf011;

import br.edu.ifba.inf011.builders.ArmaBuilder;
import br.edu.ifba.inf011.builders.PersonagemBuilder;
import br.edu.ifba.inf011.builders.PersonagemDirector;
import br.edu.ifba.inf011.factories.ComboFactory;
import br.edu.ifba.inf011.factories.StarterCruzadoFactory;
import br.edu.ifba.inf011.models.Personagem;

public class App {
    public void run(ComboFactory combo){
        PersonagemBuilder pb = combo.getPersonagemBuilder();
        ArmaBuilder ab = combo.getArmaBuilder();
        PersonagemDirector director = new PersonagemDirector(pb, ab);
        director.createPersonagem();
        Personagem personagem = pb.build();
        System.out.println(personagem);
    }

    public static void main(String[] args) {
        new App().run(new StarterCruzadoFactory());
    }
}