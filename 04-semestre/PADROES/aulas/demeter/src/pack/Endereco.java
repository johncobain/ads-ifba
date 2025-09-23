package pack;

public record Endereco (String nome, Bairro bairro) {
  public String getSiglaEstado() {
    return bairro.getSiglaEstado();
  }
}