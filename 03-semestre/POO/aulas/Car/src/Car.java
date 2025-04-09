public class Car {
    private String brand;
    private int year;
    private int fuel;

    public Car(String brand){
        this.brand = brand;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getFuel() {
        return fuel;
    }

    public void setFuel(int fuel) {
        this.fuel = fuel;
    }

    public void fillFuel(int fuel){
        this.fuel += fuel;
    }
    public void travel(int km){
        this.fuel -= km/15;
    }
    public void display(){
        System.out.println(brand + " - " + year + " - " + fuel);
    }
}
