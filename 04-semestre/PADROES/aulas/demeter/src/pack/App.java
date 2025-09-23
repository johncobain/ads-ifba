package pack;

public class App{
  public void run(){
    Endereco e = new Endereco("Emídio dos Santos",
                              new Bairro("Barbalho",
                                         new Cidade("Salvador",
                                                    new Estado("Bahia","BA"))));
    System.out.println(e.getSiglaEstado());
  }

  public static void main(String[] args) {
    new App().run();
  }
}