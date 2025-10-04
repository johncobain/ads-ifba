package br.edu.ifba.inf011;

public class SQLiteFactory implements ConnectionFactory{
    @Override
    public Connection createConnection() {
        return new SQLiteConnection();
    }
}
