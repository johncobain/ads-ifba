package br.edu.ifba.inf0008.uniEvents.menu;

import java.util.List;
import java.util.Scanner;

import br.edu.ifba.inf0008.uniEvents.menu.menuInterface.IMenu;
import br.edu.ifba.inf0008.uniEvents.utils.Lines;

public abstract class Menu implements IMenu {
  protected String title;
  protected String color;

  public Menu(String title){
    this.title = title;
  }

  public Menu(String title, String color){
    this.title = title;
    this.color = color;
  }

  protected int menuResponse(List<String> options){
    try (Scanner scanner = new Scanner(System.in)) {
      do { 
        System.out.println(Lines.doubleLine());
        if(color != null) System.out.println(Lines.titleLine(title, color));
        else System.out.println(Lines.titleLine(title));
        System.out.println(Lines.doubleLine());

        for(int i = 0; i < options.size(); i++){
          System.out.println(Lines.leftText("" + i + " - " + options.get(i)));
        }
        System.out.println(Lines.doubleLine());
        System.out.print(">> ");
        String choice = scanner.nextLine();
        int response = processOption(choice);

        if(response == -1){
          System.out.println(Lines.clear());
          System.out.println(Lines.straightLine());
          System.out.println(Lines.errorLine("Invalid input!"));
          System.out.println(Lines.straightLine());
        }else if(response >= 0 && response <= options.size() - 1){
            System.out.println(Lines.clear());
            return response;
        }else{
            System.out.println(Lines.clear());
            System.out.println(Lines.straightLine());
            System.out.println(Lines.errorLine("Invalid option!"));
            System.out.println(Lines.straightLine());
        } 
      } while (true);
    }
  }

  @Override
  public int processOption(String option){
    if(option == null || option.isEmpty()){
      return -1;
    }
    try {
        int optionInt = Integer.parseInt(option);
        return optionInt;
    } catch (NumberFormatException e) {
        return -1;
    }
  }
}
