public class Vehicle {
  private String plate;
  private String model;
  private int year;

  private static int totalVehicles = 0;

  public Vehicle(String plate, String model, int year) {
    this.plate = plate;
    this.model = model;
    this.year = year;
    totalVehicles++;
  }
  
  public String getPlate(){
    return plate;
  }

  public void setPlate(String plate){
    this.plate = plate;
  }

  public String getModel(){
    return model;
  }

  public void setModel(String model){
    this.model = model;
  }

  public int getYear(){
    return year;
  }

  public void setYear(int year){
    this.year = year;
  }

  public void showInfo() {
    System.out.println("Vehicle Information:");
    System.out.println("Plate: " + plate);
    System.out.println("Model: " + model);
    System.out.println("Year: " + year);
  }

  public static int getTotalVehicles() {
    return totalVehicles;
  }

  public static void removeFromTotalVehicles() {
    totalVehicles--;
  }

  public double calculateDailyRate(int days) {
    return 0.0; // Default implementation, can be overridden
  }
}