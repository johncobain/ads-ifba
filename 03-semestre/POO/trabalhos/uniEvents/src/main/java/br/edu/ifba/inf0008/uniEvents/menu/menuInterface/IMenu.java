package br.edu.ifba.inf0008.uniEvents.menu.menuInterface;

import java.util.List;

public interface IMenu {
  
  int show(List<String> options);
  
  int processOption(String option);
}
