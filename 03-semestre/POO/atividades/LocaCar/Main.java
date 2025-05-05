import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Welcome to the Vehicle Rental System!");
    System.out.print("Please enter your name: ");
    Rental rental = new Rental(scanner.nextLine());

    int choice;
    do { 
      System.out.println("\nHello " + rental.getName() + ", What would you like to do?");
      System.out.println("---------------------");
        System.out.println("1. Add a Car");
        System.out.println("2. Add a Motorcycle");
        System.out.println("3. Remove a Vehicle");
        System.out.println("4. List all Vehicles");
        System.out.println("5. Calculate Rental Cost");
        System.out.println("0. Exit");
        System.out.print("Enter your choice: ");
        choice = scanner.nextInt();
        scanner.nextLine();

        switch (choice){
          case 1 -> {
              System.out.print("Enter Car Plate: ");
              String carPlate = scanner.nextLine();
              System.out.print("Enter Car Model: ");
              String carModel = scanner.nextLine();
              System.out.print("Enter Car Year(0 to default): ");
              int carYear = scanner.nextInt();
              System.out.print("Enter Number of Doors(0 to default): ");
              int carDoors = scanner.nextInt();
              
              if(carYear == 0 && carDoors == 0){
                  Car car = new Car(carPlate, carModel);
                  rental.addVehicle(car);
              } else if(carYear == 0){
                  Car car = new Car(carPlate, carModel);
                  car.setDoors(carDoors);
                  rental.addVehicle(car);
              } else if(carDoors == 0){
                  Car car = new Car(carPlate, carModel);
                  car.setYear(carYear);
                  rental.addVehicle(car);
              } else {
                  Car car = new Car(carPlate, carModel, carYear, carDoors);
                  rental.addVehicle(car);
              }
              System.out.println("Car added successfully!");
            }
          case 2 -> {
              System.out.print("Enter Motorcycle Plate: ");
              String motorcyclePlate = scanner.nextLine();
              System.out.print("Enter Motorcycle Model: ");
              String motorcycleModel = scanner.nextLine();
              System.out.print("Enter Motorcycle Year(0 to default): ");
              int motorcycleYear = scanner.nextInt();
              System.out.print("Enter CC(0 to default): ");
              int motorcycleCc = scanner.nextInt();
              if(motorcycleYear == 0 && motorcycleCc == 0){
                  Motorcycle motorcycle = new Motorcycle(motorcyclePlate, motorcycleModel);
                  rental.addVehicle(motorcycle);
              } else if(motorcycleYear == 0){
                  Motorcycle motorcycle = new Motorcycle(motorcyclePlate, motorcycleModel);
                  motorcycle.setCc(motorcycleCc);
                  rental.addVehicle(motorcycle);
              } else if(motorcycleCc == 0){
                  Motorcycle motorcycle = new Motorcycle(motorcyclePlate, motorcycleModel);
                  motorcycle.setYear(motorcycleYear);
                  rental.addVehicle(motorcycle);
              } else {
                  Motorcycle motorcycle = new Motorcycle(motorcyclePlate, motorcycleModel, motorcycleYear, motorcycleCc);
                  rental.addVehicle(motorcycle);
              }
              System.out.println("Motorcycle added successfully!");
            }
          case 3 -> {
              System.out.print("Enter the plate of the vehicle to remove: ");
              String plateToRemove = scanner.nextLine();
              rental.removeVehicle(plateToRemove);
            }
          case 4 -> {
              System.out.println("\n--------------------");
              System.out.println("Total Vehicles: " + Vehicle.getTotalVehicles());
              System.out.println("Total Cars: " + Car.getTotalCars());
              System.out.println("Total Motorcycles: " + Motorcycle.getTotalMotorcycles());
              rental.listVehicles();
            }
          case 5 -> {
              System.out.print("Enter the plate of the vehicle to calculate rental cost: ");
              String plateToCalculate = scanner.next();
              System.out.print("Enter the number of days for rental: ");
              int days = scanner.nextInt();
              rental.calculateTotalRental(plateToCalculate, days);
            }
          case 0 -> System.out.println("\nExiting...");
          default -> System.out.println("\nInvalid choice. Please try again.");

        }
    } while (choice != 0);


    scanner.close();
  }
}