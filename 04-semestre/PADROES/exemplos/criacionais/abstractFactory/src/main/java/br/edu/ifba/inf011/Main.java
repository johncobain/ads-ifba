package br.edu.ifba.inf011;

public class Main{
    public static void main(String[] args) {
        VehicleFactory factoryE = new EconomyVehicleFactory();
        VehicleFactory factoryL = new LuxuryVehicleFactory();

        Car carE = factoryE.createCar();
        Motorcycle motorcycleE = factoryE.createMotorcycle();

        Car carL = factoryL.createCar();
        Motorcycle motorcycleL = factoryL.createMotorcycle();

        System.out.println("Carro Economico: " + carE);
        System.out.println("Motocicleta Economico: " + motorcycleE);
        System.out.println("Carro Luxo: " + carL);
        System.out.println("Motocicleta Luxo: " + motorcycleL);
    }
}