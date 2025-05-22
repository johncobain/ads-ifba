package br.edu.ifba.inf0008.uniEvents;

import java.util.ArrayList;

import br.edu.ifba.inf0008.uniEvents.menu.MainMenu;
import br.edu.ifba.inf0008.uniEvents.menu.menuInterface.IMenu;

/**
 * Hello world!
 */
public class App {
    
    public static void main(String[] args) {
        ArrayList<String> options = new ArrayList<>();
        options.add("Option 0");
        options.add("Option 1");
        options.add("Option 2");

        IMenu menu = new MainMenu();
        int res = menu.show(options);
        
        System.out.println("Result: " + options.get(res));
    }
}
