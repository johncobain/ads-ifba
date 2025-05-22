package br.edu.ifba.inf0008.uniEvents;

import br.edu.ifba.inf0008.uniEvents.menu.MainMenu;
import br.edu.ifba.inf0008.uniEvents.menu.menuInterface.IMenu;
import br.edu.ifba.inf0008.uniEvents.utils.Colors;
import br.edu.ifba.inf0008.uniEvents.utils.Lines;

/**
 * Hello world!
 */
public class App {
    
    public static void main(String[] args) {
        System.out.println(Lines.mixedLines());
        System.out.println(Lines.titleLine("Welcome to UniEvents!", Colors.GREEN_BOLD));
        System.out.println(Lines.mixedLines());
        IMenu menu = new MainMenu();
        menu.show();
        System.out.println(Lines.mixedLines());
        System.out.println(Lines.titleLine("Exiting UniEvents...", Colors.GREEN_BOLD));
        System.out.println(Lines.mixedLines());
    }
}
