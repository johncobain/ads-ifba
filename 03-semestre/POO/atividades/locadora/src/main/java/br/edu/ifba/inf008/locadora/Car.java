package br.edu.ifba.inf008.locadora;

public class Car extends Vehicle {
  private int doors;

  private static int totalCars = 0;

  public Car(String plate, String model, int year, int doors){
    super(plate, model, year);
    this.doors = doors;
    totalCars++;
  }

  public Car(String plate, String model){
    super(plate, model, 2025);
    this.doors = 4;
    totalCars++;
  }

  public static int getTotalCars() {
    return totalCars;
  }

  public static void removeFromTotalCars() {
    totalCars--;
    Vehicle.removeFromTotalVehicles();
  }

  public int getDoors(){
    return doors;
  }
  public void setDoors(int doors){
    this.doors = doors;
  }

  @Override
  public void showInfo() {
    super.showInfo();
    System.out.println("Doors: " + doors);
  }

  @Override
  public double calculateDailyRate(int days){
    double dailyRate = 100.0;
    double total;
    total = dailyRate *days;
    total += 20*doors;

    return total;
  }
}