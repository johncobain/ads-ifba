package br.edu.ifba.inf0008.uniEvents.menu;

import java.util.ArrayList;
import java.util.List;

public class MainMenu extends Menu{
  private final List<String> options = new ArrayList<>();
  
  public MainMenu(){
    super("Main Menu");
    options.add("Exit");
    options.add("Create Event");
    options.add("List Events");
  }
  
  @Override
  public void show() {
    int response = super.showResponse(options);

    System.out.println("Response: " + options.get(response));
  }
}
