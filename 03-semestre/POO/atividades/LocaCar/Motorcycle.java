public class Motorcycle extends Vehicle {
  private int cc;

  private static int totalMotorcycles = 0;

  public Motorcycle(String plate, String model, int year, int cc) {
    super(plate, model, year);
    this.cc = cc;
    totalMotorcycles++;
  }

  public Motorcycle(String plate, String model) {
    super(plate, model, 2025);
    this.cc = 150;
    totalMotorcycles++;
  }

  public static int getTotalMotorcycles() {
    return totalMotorcycles;
  }

  public static void removeFromTotalMotorcycles() {
    totalMotorcycles--;
    Vehicle.removeFromTotalVehicles();
  }
  
  public int getCc(){
    return cc;
  }

  public void setCc(int cc){
    this.cc = cc;
  }

  @Override
  public void showInfo() {
    super.showInfo();
    System.out.println("CC: " + cc);
  }

  @Override
  public double calculateDailyRate(int days){
    double dailyRate = 50.0;
    double total;
    total = dailyRate * days;
    total += 0.10 * cc;

    return total;
  }
}