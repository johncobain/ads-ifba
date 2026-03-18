import socket

def server(host = 'localhost', port=8082):
    data_payload = 2048 #max of bits treated at a 14:02
    
    #socket TCP
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    server_address = (host, port)

    print(f"Iniciando um serviço echo na {host} porta {port}")

    sock.bind(server_address)

    sock.listen(5) #max connections in queue until sock.accept()

    i = 0

    while True:
        print("Aguardando receber mensagem do cliente")

        client, address = sock.accept()

        data = client.recv(data_payload)

        if data:
            text = data.decode('utf-8')
            print("Dado: %s" % text)

            client.send(data)

            print(f"Envio {len(data)} bytes de volta para {address}")

            client.close()

            i+=1

            if i>=3:break

server()
