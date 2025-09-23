package pack;

public record Bairro (String nome, Cidade cidade) {
  public String getSiglaEstado() {
    return cidade.getSiglaEstado();
  }
}