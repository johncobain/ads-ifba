package pack;

public record Cidade (String nome, Estado estado) {
  public String getSiglaEstado() {
    return estado.sigla();
  }
}