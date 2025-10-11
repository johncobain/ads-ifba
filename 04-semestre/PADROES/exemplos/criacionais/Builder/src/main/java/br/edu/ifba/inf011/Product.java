package br.edu.ifba.inf011;

public class Product {
    private final String name;
    private final double price;
    private final String category;
    private final int stock;

    private Product(Builder builder){
        this.name = builder.name;
        this.price = builder.price;
        this.category = builder.category;
        this.stock = builder.stock;
    }

    @Override
    public String toString() {
        return "Product{" +
                "name='" + name + '\'' +
                ", price=" + price +
                ", category='" + category + '\'' +
                ", stock=" + stock +
                '}';
    }

    public static class Builder{
        private String name;
        private double price;
        private String category;
        private int stock;

        public Builder name(String name){
            this.name = name;
            return this;
        }

        public Builder price(double price){
            this.price = price;
            return this;
        }

        public Builder category(String category){
            this.category = category;
            return this;
        }

        public Builder stock(int stock){
            this.stock = stock;
            return this;
        }

        public Product build(){
            return new Product(this);
        }
    }
}
