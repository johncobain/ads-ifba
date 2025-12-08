package br.edu.ifba.inf011;

import br.edu.ifba.inf011.model.*;

import java.time.LocalDate;

public class App {

  public void runQ1() {
    SysArquivo a1 = new Arquivo("A1", LocalDate.now(), 5L);
    SysArquivo b1 = new Arquivo("B1", LocalDate.now(), 20L);
    SysArquivo c1 = new Arquivo("C1", LocalDate.now(), 10L);

    SysArquivo a = new Pasta("A", LocalDate.now());
    SysArquivo b = new Pasta("B", LocalDate.now());
    SysArquivo c = new Pasta("C", LocalDate.now());
    SysArquivo raiz = new Pasta("/", LocalDate.now());

    raiz.addFilho(a);
    raiz.addFilho(b);

    a.addFilho(a1);

    b.addFilho(c);
    b.addFilho(b1);

    c.addFilho(c1);

    try {
      a1.addFilho(c1);
    }catch (UnsupportedOperationException e) {
      System.out.println("Não foi possível adicionar C1 a A1");
    }


    System.out.println(raiz.getNome() + ": " + raiz.getTamanho() + "K");


  }


  public void runQ2() {

    Credencial user01 = new Credencial("user01");
    Credencial user02 = new Credencial("user02");

    SysArquivoLeitura a1 = new LogProxy(new Arquivo("A1", LocalDate.now(), 5L));
    SysArquivoLeitura b1 = new LogProxy(new Arquivo("B1", LocalDate.now(), 20L));
    SysArquivoLeitura c1 = new Arquivo("C1", LocalDate.now(), 10L);

    SysArquivo a = new Pasta("A", LocalDate.now());
    SysArquivo b = new Pasta("B", LocalDate.now());
    SysArquivo c = new Pasta("C", LocalDate.now());
    SysArquivo raiz = new Pasta("/", LocalDate.now());

    raiz.addFilho(a);
    raiz.addFilho(b);

    a.addFilho(a1);

    b.addFilho(c);
    b.addFilho(b1);

    c.addFilho(c1);

    try {
      a1.ler(user01);
      a1.ler(user01);
      a1.ler(user01);
      b1.ler(user01);
      b1.ler(user02);
    }catch(Exception e) {
      System.out.println("Erro em Leitura");
    }

    System.out.println("\nLOGS\n");

    ((LogProxy) a1).doLog();
    ((LogProxy) b1).doLog();

  }


  public static void main(String[] args) {
    App app = new App();
    app.runQ1();
    app.runQ2();

  }
}