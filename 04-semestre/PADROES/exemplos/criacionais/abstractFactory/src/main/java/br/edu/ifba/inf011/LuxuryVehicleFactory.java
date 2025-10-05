package br.edu.ifba.inf011;

import br.edu.ifba.inf011.luxury.CarLuxury;
import br.edu.ifba.inf011.luxury.MotorcycleLuxury;

public class LuxuryVehicleFactory implements VehicleFactory{
    @Override
    public Car createCar() {
        return new CarLuxury();
    }

    @Override
    public Motorcycle createMotorcycle() {
        return new MotorcycleLuxury();
    }
}
