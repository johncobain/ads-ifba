package br.edu.ifba.inf011;

public class Main {
    public static void main(String[] args) {
        // Criando o protótipo de configurações do jogo
        GameSettings prototypeSettings = new GameSettings(50, 70, "Normal");
        System.out.println(prototypeSettings.hashCode());

        // Clonando e modificando para um novo jogador
        GameSettings playerSettings = null;
        try {
            playerSettings = prototypeSettings.clone();
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println(playerSettings.hashCode());
        playerSettings.setDifficulty("Hard");
        playerSettings.setBrightness(2);

        System.out.println("Player Settings: Difficulty is " + playerSettings.getDifficulty());
        System.out.println("Player Settings: Volume is " + playerSettings.getVolume());
        System.out.println("Player Settings: brightness is " + playerSettings.getBrightness());
        System.out.println("Prototype Settings: brightness is " + prototypeSettings.getBrightness());
    }
}
