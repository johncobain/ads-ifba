package br.edu.ifba.inf011;

public class Main {
    public static void main(String[] args) {
        Product.Builder builder = new Product.Builder();
        Product product = builder.name("Product1").price(5000).category("Category1").stock(10).build();
        System.out.println(product);
    }
}
