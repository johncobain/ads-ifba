package br.edu.ifba.inf0008.uniEvents;

import br.edu.ifba.inf0008.uniEvents.menu.MainMenu;
import br.edu.ifba.inf0008.uniEvents.menu.menuInterface.IMenu;

/**
 * Hello world!
 */
public class App {
    
    public static void main(String[] args) {
        IMenu menu = new MainMenu();
        menu.show();
    }
}
