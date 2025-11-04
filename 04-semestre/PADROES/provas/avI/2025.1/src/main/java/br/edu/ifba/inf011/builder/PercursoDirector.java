package br.edu.ifba.inf011.builder;

import br.edu.ifba.inf011.model.Idade;
import br.edu.ifba.inf011.model.PontoGeografico;
import br.edu.ifba.inf011.model.Prisma;

public class PercursoDirector {
    public void createPercurso(CorridaBuilder builder){
        builder.init().withIdade(Idade.VIP)
                .withPartida(new PontoGeografico(-12.99759, -38.47413, 0.0))
                .addPrisma(new Prisma(31, new PontoGeografico(-12.99747, -38.47435, 0.0)))
                .addPrisma(new Prisma(32, new PontoGeografico(-12.99825, -38.47526, 0.0)))
                .withChegada(new PontoGeografico(-12.99701, -38.47424, 0.0));
    }
}
