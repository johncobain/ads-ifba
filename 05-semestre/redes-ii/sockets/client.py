import socket

def client(host = 'localhost', port = 8082):

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server_address = (host,port)

    print(f"Conectando a {host} porta {port}")

    sock.connect(server_address)

    try:
        message = "Mensagem teste. Isso será lido"

        print(f"Enviando \"{message}\"")

        sock.sendall(message.encode('utf-8'))

        amount_received = 0
        amount_expected = len(message.encode('utf-8'))
        
        while amount_received < amount_expected:
            data = sock.recv(16)

            amount_received += len(data)

            print(f"Received: {data.decode('utf-8')}")

    except socket.error as e:
        print(f"Socket error: {str(e)}")

    finally:
        print("Fechando conexão ao servidor")

        sock.close()

client()
