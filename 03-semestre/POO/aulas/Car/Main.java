import br.edu.ifba.inf008.Car;

public class Main {
    public static void main(String[] args) {
        Car car1 = new Car("BMW", 2020, 0);
        Car car2 = new Car();
        Car car3 = new Car("Mercedes", 2021, 50);

        car2.setBrand("Audi");
        car2.setYear(2022);
        car2.setFuel(100);

        car1.display();
        car2.display();
        car3.display();
    }
}