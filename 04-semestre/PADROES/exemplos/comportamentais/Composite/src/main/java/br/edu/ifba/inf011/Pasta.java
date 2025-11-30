package br.edu.ifba.inf011;

import java.util.ArrayList;
import java.util.List;

public class Pasta implements Arquivo {
  private List<Arquivo> arquivos = new ArrayList<>();
  private String nome;

  public Pasta(String nome){
    this.nome = nome;
  }

  public void addArquivo(Arquivo arquivo){
    this.arquivos.add(arquivo);
  }

  public void removeArquivo(Arquivo arquivo){
    this.arquivos.remove(arquivo);
  }

  @Override
  public void show() {
    System.out.println("Pasta: " + this.nome);
    for (Arquivo arquivo : this.arquivos) {
      arquivo.show();
    }
  }

}
