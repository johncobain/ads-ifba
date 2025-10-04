package br.edu.ifba.inf011;

public class MySQLFactory implements ConnectionFactory{
    @Override
    public Connection createConnection() {
        // conexões

        return new MySQLConnection();
    }
}
