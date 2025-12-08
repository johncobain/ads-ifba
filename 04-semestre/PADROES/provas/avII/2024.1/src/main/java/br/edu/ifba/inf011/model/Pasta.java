package br.edu.ifba.inf011.model;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Pasta implements SysArquivo{
  private String nome;
  private LocalDate dataCriacao;
  private List<SysArquivo> filhos;

  public Pasta(String nome, LocalDate dataCriacao) {
    this.nome = nome;
    this.dataCriacao = dataCriacao;
    this.filhos = new ArrayList<>();
  }

  @Override
  public String getNome() {
    return this.nome;
  }

  @Override
  public LocalDate getDataCriacao() {
    return this.dataCriacao;
  }

  public List<SysArquivo> getFilhos() throws UnsupportedOperationException{
    return this.filhos;
  }

  public void addFilho(SysArquivo filho) throws UnsupportedOperationException{
    this.filhos.add(filho);
  }

  public void removeFilho(SysArquivo filho) throws UnsupportedOperationException{
    this.filhos.remove(filho);
  }

  @Override
  public Long getTamanho() {
    Long tamanho = 0L;
    for(SysArquivo filho : this.getFilhos())
      tamanho += filho.getTamanho();
    return tamanho;
  }
}
