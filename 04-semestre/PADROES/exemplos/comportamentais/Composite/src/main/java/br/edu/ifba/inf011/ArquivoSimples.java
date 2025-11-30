package br.edu.ifba.inf011;

public class ArquivoSimples implements Arquivo {
  private String nome;

  public ArquivoSimples(String nome){
    this.nome = nome;
  }

  @Override
  public void show() {
    System.out.println("Arquivo: " + this.nome);
  }
}
