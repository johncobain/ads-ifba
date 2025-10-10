package br.edu.ifba.inf011;

public class GameSettings implements Cloneable {
    private int brightness;
    private int volume;
    private String difficulty;

    public GameSettings(int brightness, int volume, String difficulty) {
        this.brightness = brightness;
        this.volume = volume;
        this.difficulty = difficulty;
    }

    @Override
    protected GameSettings clone() throws CloneNotSupportedException {
        try {
            return (GameSettings) super.clone();
        } catch (CloneNotSupportedException e) {
            throw new RuntimeException(e);
        }
    }

    public int getBrightness() {
        return brightness;
    }

    public void setBrightness(int brightness) {
        this.brightness = brightness;
    }

    public int getVolume() {
        return volume;
    }

    public void setVolume(int volume) {
        this.volume = volume;
    }

    public String getDifficulty() {
        return difficulty;
    }

    public void setDifficulty(String difficulty) {
        this.difficulty = difficulty;
    }
}
