package br.edu.ifba.inf011.model;

import java.time.LocalDate;
import java.util.List;

public interface SysArquivo {
  public String getNome();
  public LocalDate getDataCriacao();
  public Long getTamanho();
  public List<SysArquivo> getFilhos() throws UnsupportedOperationException;
  public void addFilho(SysArquivo filho) throws UnsupportedOperationException;
  public void removeFilho(SysArquivo filho) throws UnsupportedOperationException;
}
