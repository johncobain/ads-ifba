package br.edu.ifba.inf011;

public class DatabaseConnection {
    private static DatabaseConnection instance;

    private Connection connection;

    private DatabaseConnection(){
        // Código para estabelecer a conexão com o banco de dados
    }

    public static synchronized DatabaseConnection getInstance(){
        if (instance == null){
            instance = new DatabaseConnection();
        }
        return instance;
    }

    public Connection getConnection(){
        return connection;
    }
}
