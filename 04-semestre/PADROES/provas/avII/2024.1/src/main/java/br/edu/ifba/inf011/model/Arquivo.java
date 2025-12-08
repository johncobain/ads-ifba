package br.edu.ifba.inf011.model;

import java.time.LocalDate;
import java.util.List;

public class Arquivo implements SysArquivoLeitura{
  private String nome;
  private LocalDate dataCriação;
  private Long tamanho;

  public Arquivo(String nome, LocalDate dataCriacao, Long tamanho) {
    this.nome = nome;
    this.dataCriação = dataCriacao;
    this.tamanho = tamanho;
  }

  @Override
  public String getNome() {
    return this.nome;
  }

  @Override
  public LocalDate getDataCriacao() {
    return this.dataCriação;
  }

  @Override
  public List<SysArquivo> getFilhos() throws UnsupportedOperationException{
    throw new UnsupportedOperationException();
  }

  @Override
  public void addFilho(SysArquivo filho) throws UnsupportedOperationException{
    throw new UnsupportedOperationException();

  }

  @Override
  public void removeFilho(SysArquivo filho) throws UnsupportedOperationException{
    throw new UnsupportedOperationException();
  }

  @Override
  public Long getTamanho() {
    return this.tamanho;
  }

  @Override
  public void ler(Credencial credencial) {
    System.out.println(credencial.getId() + " lendo entrada: " + this.getNome());
  }
}
