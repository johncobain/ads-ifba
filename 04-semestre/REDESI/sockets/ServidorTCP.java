import java.io.*;
import java.net.*;
/**
 *
 * @author Aluno
 */
public class ServidorTCP {
  public static void main(String[] args) throws Exception {
    String fraseCliente;
    String fraseMaiusculas;
    try (ServerSocket socketRecepcao = new ServerSocket(6789)) {
      System.out.println("Servidor TCP esperando conexões na porta 6789...");
      while(true) {
        Socket socketConexao = socketRecepcao.accept();
        System.out.println("Conexao aceita!");
        BufferedReader doCliente =
        new BufferedReader(new
        InputStreamReader(socketConexao.getInputStream()));
        DataOutputStream paraCliente =
        new DataOutputStream(socketConexao.getOutputStream());
        fraseCliente= doCliente.readLine();
        System.out.println("Recebido do Cliente: " + fraseCliente);
        fraseMaiusculas = fraseCliente.toUpperCase() + '\n';
        paraCliente.writeBytes(fraseMaiusculas);
        System.out.println("Dados enviados ao cliente.");
        socketConexao.close();
      }
    }
  }
}
