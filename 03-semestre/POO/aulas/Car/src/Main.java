public class Main {
    public static void main(String[] args) {
        Car myCar = new Car("BMW");
        Car myCar2 = myCar;
        myCar2 = null;
//        myCar = null;
//        myCar.brand = "FIAT";
        myCar.fillFuel(10);
        myCar.travel(45);
        myCar.display();

        System.exit(12);
    }
}