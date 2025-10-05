package br.edu.ifba.inf011;

import br.edu.ifba.inf011.economy.CarEconomy;
import br.edu.ifba.inf011.economy.MotorcycleEconomy;

public class EconomyVehicleFactory implements VehicleFactory{

    @Override
    public Car createCar() {
        return new CarEconomy();
    }

    @Override
    public Motorcycle createMotorcycle() {
        return new MotorcycleEconomy();
    }
}
