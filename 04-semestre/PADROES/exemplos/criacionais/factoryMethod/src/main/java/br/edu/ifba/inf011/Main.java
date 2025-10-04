package br.edu.ifba.inf011;

public class Main {
    public static void main(String[] args) {
        ConnectionFactory factory = new MySQLFactory();
        ConnectionFactory factory1 = new SQLiteFactory();

        Connection connection = factory1.createConnection();
    }
}