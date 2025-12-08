package br.edu.ifba.inf011.model;

import java.time.LocalDate;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LogProxy implements SysArquivoLeitura{
  private Arquivo arquivo;
  private Map<Credencial, Integer> log;

  public LogProxy(Arquivo arquivo) {
    this.arquivo = arquivo;
    this.log = new HashMap<>();
  }

  @Override
  public String getNome() {
    return this.arquivo.getNome();
  }

  @Override
  public LocalDate getDataCriacao() {
    return this.arquivo.getDataCriacao();
  }

  @Override
  public Long getTamanho() {
    return this.arquivo.getTamanho();
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
  public void ler(Credencial credencial) {
    this.arquivo.ler(credencial);
    this.log.put(credencial, this.log.getOrDefault(credencial, 0) + 1);
  }

  public void doLog() {
    System.out.println("LOG ARQUIVO: " + this.getNome());
    for(Credencial credencial : this.log.keySet())
      System.out.println(credencial.getId() + " - " + this.log.get(credencial) + " leituras");
  }
}
