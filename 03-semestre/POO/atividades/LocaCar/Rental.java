import java.util.ArrayList;

public class Rental{
  private String name;
  private final ArrayList<Vehicle> vehicles;

  public Rental(String name){
    this.name = name;
    vehicles = new ArrayList<>();
  }

  public String getName(){
    return name;
  }
  public void setName(String name){
    this.name = name;
  }

  public void addVehicle(Vehicle vehicle){
    vehicles.add(vehicle);
  }

  public void removeVehicle(String plate){
    for(int i = 0; i < vehicles.size(); i++){
      if(vehicles.get(i).getPlate().equals(plate)){
        if(vehicles.get(i) instanceof Car){
          Car.removeFromTotalCars();
        }else if(vehicles.get(i) instanceof Motorcycle){
          Motorcycle.removeFromTotalMotorcycles();
        }
          
        vehicles.remove(i);
        System.out.println("Vehicle with plate " + plate + " removed from rental.");
        return;
      }
    }
    System.out.println("Vehicle with plate " + plate + " not found in rental.");
  }

  public void listVehicles(){
    System.out.println("Vehicles in " + name + " rental:");
    for (Vehicle vehicle : vehicles){
      vehicle.showInfo();
      System.out.println("--------------------");
    }
  }

  public void calculateTotalRental(String plate, int days){
    for(Vehicle vehicle : vehicles){
      if(vehicle.getPlate().equals(plate)){
        double total = vehicle.calculateDailyRate(days);
        System.out.println("Total rental cost for " + vehicle.getModel() + " with plate " + plate + " for " + days + " days: $" + total);
        System.out.println("--------------------");
        break;
      }
    }
  }
}