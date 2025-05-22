package br.edu.ifba.inf0008.uniEvents.utils;

public class Lines {
  public static String straightLine(){
    return "----------------------------------------------------------------";
  }
  public static String doubleLine(){
    return "================================================================";
  }
  public static String mixedLines(){
    return "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
  }

  public static String clear(){
    return "\033[H\033[2J";
  }

  public static String titleLine(String title){
    int totalLenght = 62 - title.length();
    int leftPadding = totalLenght/2;
    int rightPadding = totalLenght - leftPadding;
    String finalLine = "|";
    for(int i =0; i<leftPadding; i++){
      finalLine = finalLine + " ";
    }
    finalLine = finalLine + title;
    for(int i =0; i<rightPadding; i++){
      finalLine = finalLine + " ";
    }
    finalLine = finalLine + "|";
    return finalLine;
  }

  public static String titleLine(String title, String color){
    int totalLenght = 62 - title.length();
    int leftPadding = totalLenght/2;
    int rightPadding = totalLenght - leftPadding;
    String finalLine = "|";
    for(int i =0; i<leftPadding; i++){
      finalLine = finalLine + " ";
    }
    finalLine = finalLine + color + title + Colors.RESET;
    for(int i =0; i<rightPadding; i++){
      finalLine = finalLine + " ";
    }
    finalLine = finalLine + "|";
    return finalLine;
  }

  public static String leftText(String text){
    int totalLenght = 62 - text.length();
    String finalLine = "|";
    finalLine = finalLine + text;
    for(int i =0; i<totalLenght; i++){
      finalLine = finalLine + " ";
    }
    finalLine = finalLine + "|";
    return finalLine;
  }

  public static String rightText(String text){
    int totalLenght = 62 - text.length();
    String finalLine = "|";
    for(int i =0; i<totalLenght; i++){
      finalLine = finalLine + " ";
    }
    finalLine = finalLine + text;
    finalLine = finalLine + "|";
    return finalLine;
  }

  public static String errorLine(String text){
    int totalLenght = 62 - text.length();
    int leftPadding = totalLenght/2;
    int rightPadding = totalLenght - leftPadding;
    String finalLine = "|";
    for(int i =0; i<leftPadding; i++){
      finalLine = finalLine + " ";
    }
    finalLine = finalLine + Colors.RED_BOLD + text + Colors.RESET;
    for(int i =0; i<rightPadding; i++){
      finalLine = finalLine + " ";
    }
    finalLine = finalLine + "|";
    return finalLine;
  }

  public static String successLine(String text){
    int totalLenght = 62 - text.length();
    int leftPadding = totalLenght/2;
    int rightPadding = totalLenght - leftPadding;
    String finalLine = "|";
    for(int i =0; i<leftPadding; i++){
      finalLine = finalLine + " ";
    }
    finalLine = finalLine + Colors.GREEN_BOLD + text + Colors.RESET;
    for(int i =0; i<rightPadding; i++){
      finalLine = finalLine + " ";
    }
    finalLine = finalLine + "|";
    return finalLine;
  }

  public static String warningLine(String text){
    int totalLenght = 62 - text.length();
    int leftPadding = totalLenght/2;
    int rightPadding = totalLenght - leftPadding;
    String finalLine = "|";
    for(int i =0; i<leftPadding; i++){
      finalLine = finalLine + " ";
    }
    finalLine = finalLine + Colors.YELLOW_BOLD + text + Colors.RESET;
    for(int i =0; i<rightPadding; i++){
      finalLine = finalLine + " ";
    }
    finalLine = finalLine + "|";
    return finalLine;
  }
}
