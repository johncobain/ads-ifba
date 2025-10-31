package negocio;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Random;
import java.util.Scanner;

public class AdvinhaPalavra implements Runnable {
	Socket client;
	String[] palavras = { "Futebol", "Capoeira", "Samba", "Carnaval", "Acaraje" };
	String[] dicas = { "Esporte mais popular do Brasil", "Luta marcial brasileira", "Ritmo matriz da Bolsa Nova",
			"Festa popular", "Culinaria tipica da Bahia" };
	String palvFormada;
	int n;
	int tentativas;

	public AdvinhaPalavra(Socket client) {
		this.client = client;
		Random r = new Random();
		n = r.nextInt(5);
		tentativas = 5;
		this.getFraseCliente();
	}

	@Override
	public void run() {
		try {
			Scanner in = new Scanner(this.client.getInputStream());
			PrintWriter out = new PrintWriter(this.client.getOutputStream(), true);
			out.println(this.dicas[n]);
			while (tentativas > 0) {
				String s = this.verificaPalavra(in.nextLine().charAt(0));
				if (s.equals(this.palavras[n])) {
					out.println("Voce ganhou");
					break;
				} else
					out.println(s+" Tentativas: "+tentativas);
			}
			if (tentativas == 0)
				out.println("Voce perdeu");

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void getFraseCliente() {
		char[] palavra = new char[this.palavras[n].length()];
		for (int i = 0; i < this.palavras[n].length(); i++) {
			palavra[i] = '_';
		}
		this.palvFormada = new String(palavra);
	}

	public String verificaPalavra(char c) {
		boolean acertou = false;
		char[] palavra = this.palavras[n].toCharArray();
		char[] newPalvr = this.palvFormada.toCharArray();

		for (int i = 0; i < this.palavras[n].length(); i++) {
			if (c == palavra[i]) { 
				newPalvr[i] = c;
				acertou = true;	
			}
		}
		if(!acertou)
			tentativas--;
		this.palvFormada = new String(newPalvr);
		return palvFormada;
	}

}