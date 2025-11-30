package br.edu.ifba.inf011;

public class Main{
  public static void main(String[] args) {
    Arquivo arquivo1 = new ArquivoSimples("arquivo1.txt");
    Arquivo arquivo2 = new ArquivoSimples("arquivo2.txt");
    Arquivo arquivo3 = new ArquivoSimples("arquivo3.txt");

    Pasta pasta1 = new Pasta("pasta1");
    pasta1.addArquivo(arquivo1);
    pasta1.addArquivo(arquivo2);
    pasta1.addArquivo(arquivo3);

    Arquivo arquivo4 = new ArquivoSimples("arquivo4.txt");
    Arquivo arquivo5 = new ArquivoSimples("arquivo5.txt");

    Pasta pasta2 = new Pasta("pasta2");
    pasta2.addArquivo(arquivo4);
    pasta2.addArquivo(arquivo5);

    pasta1.addArquivo(pasta2);

    pasta1.show();
  }
}