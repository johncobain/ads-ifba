# Atividade 5

## Objetivo

Desenvolver uma API que manipula uma tabela em um banco de dados utilizando requisições HTTP e WebSockets.

Os servidores de banco de dados, sockets e HTTP serão configurados em uma máquina virtual, enquanto o cliente será configurado na máquina host.

O livro de apoio considera a máquina host sendo Windows, mas para essa atividade, a maquina host será Linux Mint 22.3.

Também é utillizado o MySQL como banco de dados, mas, a partir do Debian 9, o MySQL foi substituído pelo MariaDB. Portanto, utilizaremos o MariaDB para essa atividade.

## Requisitos

- Python 3.10 ou superior

## Link para o Vídeo de Demonstração

[Vídeo de Demonstração](https://youtu.be/gGyOt5ATu8U)

## Acesso ao Roteador por SSH

Login: root

Pass: thoughtpolice

ssh: ssh root@< ip da maq > ou ssh -p 3022 root@localhost

## Configuração Inicial

Para essa atividade, vamos configurar o adaptador de rede 1 para NAT e adicionar os seguintes redirecionamentos de portas:

name: http
host port: 8080
guest port: 8080

name: ws
host port: 8081
guest port: 8081

caso queira acessar as máquinas virtuais por SSH (recomendado para colar os blocos de códigos a serem utilizados), adicione tambem:

name: ssh
host port: 3022
guest port: 22

Observação: Lembre-se de habilitar o redirecionamento de portas na VM com o comando `echo 1 > /proc/sys/net/ipv4/ip_forward` e verifique se a interface de rede está configurada para obter um IP válido na rede local utilizando DHCP. Para isso, edite o arquivo de configuração da rede `/etc/network/interfaces` na máquina virtual, adicionando as seguintes linhas:

```bash
auto enp0s3 // substitua "enp0s3" pelo nome da interface de rede, caso seja diferente
iface enp0s3 inet dhcp
```

## Configuração MariaDB

Primeiramente, instale o MariaDB Server na máquina virtual:

```bash
apt-get update
apt-get install mariadb-server -y
```

Em seguida, acesse o console do MariaDB utilizando o comando:

```bash
mysql -u root -proot // substitua "root" pela senha do usuário root, caso seja diferente
```

Dentro do console do MariaDB, execute os seguintes comandos para criar o banco de dados e a tabela necessária para a atividade:

```sql
CREATE DATABASE IF NOT EXISTS DB; 
USE DB; 
 
CREATE TABLE IF NOT EXISTS USERS ( 
    ID INT AUTO_INCREMENT PRIMARY KEY, 
    NAME VARCHAR(255) NOT NULL, 
    EMAIL VARCHAR(255) UNIQUE NOT NULL 
); 
```

Agora, vamos adicionar uma base de dados inicial:

```sql
INSERT INTO USERS (NAME, EMAIL) VALUES 
('Joao Silva', 'joao.silva@example.com'), 
('Maria Oliveira', 'maria.oliveira@example.com'), 
('Pedro Souza', 'pedro.souza@example.com');
```

Vamos também conceder acesso total ao usuario root a partir de qualquer IP:

```sql
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' 
IDENTIFIED BY 'root' WITH GRANT OPTION; 
ALTER USER 'root'@'localhost' IDENTIFIED BY 'root';
FLUSH PRIVILEGES; 
```

## Configuração da API Python

Instale o Python 3.11 ou superior na máquina virtual, caso ainda não esteja instalado:

```bash
apt-get update
apt-get install python3.11 python3.11-venv -y
```

Vamos criar uma pasta para salvar os códigos python e acessá-la:

```bash
mkdir dbpyfolder
cd dbpyfolder
```

Dentro dessa pasta, crie um ambiente virtual para isolar as dependências do projeto:

```bash
python3 -m venv venv
source venv/bin/activate
```

Instale as dependências necessárias para a API utilizando o pip:

```bash
pip install mysql-connector-python websockets
```

Agora, iremos começar a codificar a API. Iniciaremos criando o arquivo responsável por gerencial a conexão com o banco de dados, chamado `db.py`:

```python
import mysql.connector  

class DBConnection(): 
  def __init__(self): 
    self.connection = mysql.connector.connect( 
      host="localhost", 
      user="root", 
      password="root", 
      database="DB" 
    ) 
 
 
  def selectAll(self): 
    self.connection.commit()
    cursor = self.connection.cursor() 
    cursor.execute("SELECT * FROM USERS") 
    return cursor.fetchall() 
  
  def insertData(self, data): 
    cursor = self.connection.cursor() 
    sql = "INSERT INTO USERS (name, email) VALUES (%s, %s)" 
    val = (data[0], data[1]) 
    try: 
      cursor.execute(sql, val) 
      self.connection.commit() 
      return cursor.lastrowid 
    except: 
      return False 

  def updateData(self, data): 
    cursor = self.connection.cursor() 
    sql = "UPDATE USERS SET name=%s, email=%s WHERE ID=%s" 
    val = (data[0], data[1], data[2]) 
    try: 
      cursor.execute(sql, val) 
      self.connection.commit() 
      return cursor.rowcount 
    except: 
      return False 

  def deleteData(self, data): 
    cursor = self.connection.cursor() 
    sql = "DELETE FROM USERS WHERE ID=%s" 
    val = (data[0], ) 
    try: 
      cursor.execute(sql, val) 
      self.connection.commit() 
      return cursor.rowcount 
    except: 
     return False 
```

Após isso, crie o arquivo `ws.py`, responsável por gerenciar as conexões WebSockets:

```python
#!/usr/bin/env python3

import asyncio, logging
from db import DBConnection
from websockets import serve # type: ignore

dbconnection =  DBConnection()
logging.basicConfig(level=logging.INFO)

async def receiveRequest(websocket):
  request = await websocket.recv()
  print(f"<<< {request}")
  request = request.split()

  match request[0]:
    case "GET":
      response = getAllData()
    case "POST":
      response = postData(request)
    case "UPDATE":
      response = updateData(request)
    case "DELETE":
      response = deleteData(request)
    case _:
      response = f"Comando inválido."
  await websocket.send(response)
  print(f">>> {response}")

def getAllData():
  response = f"Este é o resultado da sua consulta:"
  for item in dbconnection.selectAll():
    response+= f"\n {item}"
  return response


def postData(request):
  request.remove("POST")
  # Se a requisição tiver mais de 2 partes, significa que o nome tem espaços.
  # O último item é o email, e todo o resto faz parte do nome.
  if len(request) > 1:
    email = request[-1]
    name = " ".join(request[:-1])
    
    # Remove as aspas simples se o usuário as digitou
    name = name.strip("'")

    data_to_insert = [name, email]
    
    id = dbconnection.insertData(data_to_insert)
    if not id:
      response = f"Inserção não realizada, Email já está cadastrado no banco de dados..."
    else:
      response = f"Sua inserção no Banco de Dados foi realizada com sucesso! ID do item adicionado: {id}"
  else:
    # Se tiver 1 ou 0 itens, os dados estão incompletos.
    response = f"Operação não realizada, faltaram dados..."
  return response

def updateData(request):
  request.remove("UPDATE")
  if len(request) != 3:
    response = f"Operação não realizada, faltaram dados..."
  else:
    qtd = dbconnection.updateData(request)
    if not qtd:
      response = f"Operação não realizada, Email já está cadastrado no banco de dados..."
    else:
      response = f"Sua Operação no Banco de Dados foi realizada com sucesso! Itens afetados: {qtd}"
  return response

def deleteData(request):
  request.remove("DELETE")
  if len(request) != 1:
    response = f"Operação não realizada, faltaram dados..."
  else:
    qtd = dbconnection.deleteData(request)
    if not qtd:
      response = f"Operação não realizada, usuário não existe no banco de dados..."
    else:
      response = f"Sua Operação no Banco de Dados foi realizada com sucesso! Itens afetados: {qtd}"
  return response


async def main():
  async with serve(receiveRequest, "0.0.0.0", 8081):
    await asyncio.get_running_loop().create_future()  # run forever


if __name__ == "__main__":
  asyncio.run(main())
```

Por fim, crie o arquivo `controller.py`, responsável por gerenciar as requisições HTTP:

```python
from http.server import BaseHTTPRequestHandler, HTTPServer
from db import DBConnection
import json, logging

# Banco de dados em memória (dicionário)
dbconnection =  DBConnection()
logging.basicConfig(level=logging.INFO)

class SimpleHTTPRequestHandler(BaseHTTPRequestHandler):
  def do_GET(self):
    if self.path == "/":  # Retorna todos os itens
      self._send_response(200, list(dbconnection.selectAll()))
    else:
      self._send_response(404, {"error": "Invalid endpoint"})

  def do_POST(self):
    if self.path == "/":  # Cria um novo person
      content_length = int(self.headers["Content-Length"])
      post_data = self.rfile.read(content_length)
      try:
        data = json.loads(post_data)
        global current_id
        new_person = (data.get("name"), data.get("email"))
        dbconnection.insertData(new_person)
        self._send_response(201, new_person)
      except json.JSONDecodeError:
        self._send_response(400, {"error": "Invalid JSON"})
    else:
      self._send_response(404, {"error": "Invalid endpoint"})

  def do_PUT(self):
    if self.path.startswith("/"):  # Atualiza um person existente
      person_id = self._extract_id()
      content_length = int(self.headers["Content-Length"])
      put_data = self.rfile.read(content_length)
      try:
        data = json.loads(put_data)
        person = (data.get("name"), data.get("email"), person_id)
        dbconnection.updateData(person)
        self._send_response(200, person)
      except json.JSONDecodeError:
        self._send_response(400, {"error": "Invalid JSON"})
    else:
      self._send_response(404, {"error": "Invalid endpoint"})
        
  def do_DELETE(self):
    if self.path.startswith("/"):  # Remove um person pelo ID
      person_id = self._extract_id()
      try:
        person = (person_id, )
        dbconnection.deleteData(person)
        self._send_response(200, {"message": "person deleted"})
      except:
        self._send_response(404, {"error": "person not found"})

  # Métodos auxiliares
  def _send_response(self, status_code, body):
    self.send_response(status_code)
    self.send_header("Content-Type", "application/json")
    self.end_headers()
    self.wfile.write(json.dumps(body).encode("utf-8"))


  def _extract_id(self):
    try:
      return int(self.path.split("/")[-1])
    except ValueError:
      return None

# Inicialização do servidor
if __name__ == "__main__":
  server_address = ("", 8080)
  httpd = HTTPServer(server_address, SimpleHTTPRequestHandler)
  print("Servidor rodando em http://127.0.0.1:8080")
  httpd.serve_forever()
```

Execute os servidores:

```bash
python3 ws.py & python3 controller.py &
```

Se tudo estiver configurado corretamente, deve aparacer algo assim:

```plaintext
Servidor rodando em http://127.0.0.1:8080
INFO:websockets.server:server listening on 0.0.0.0:8081
```

## Configuração e Teste do Cliente (Máquina Host)

Com o Python 3 instalado e o venv configurado, crie um arquivo chamado `client.py` e adicione o seguinte código para testar as requisições HTTP e WebSockets:

```python
#!/usr/bin/env python

import asyncio
from websockets import connect # type: ignore

async def transaction():
  uri = "ws://127.0.0.1:8081"
  request = ""
  async with connect(uri) as websocket:
    while request !="GET" and request!="POST" and request!="UPDATE" and request!="DELETE":
      request = input("Digite um comando(GET/POST/UPDATE/DELETE): ").upper()
    match request:
      case "POST":
        request+= " "+input("Digite o nome: ")
        request+= " "+input("Digite o email: ")
      case "UPDATE":
        request+= " "+input("Digite o novo nome: ")
        request+= " "+input("Digite o novo email: ")
        request+= " "+input("Digite o ID: ")
      case "DELETE":
        request+= " "+input("Digite o ID: ")
        
    await websocket.send(request)
    print(f">>> {request}")
    response = await websocket.recv()
    print(f"<<< {response}")

if __name__ == "__main__":
  asyncio.run(transaction())
```

Execute o cliente e teste as operações:

```bash
python3 client.py
```

Agora podemos realizar as manipulações no banco de dados via Sockets (executando o arquivo client.py) ou via HTTP (utilizando ferramentas como Postman ou curl), por exemplo:

```bash
curl -X POST -H "Content-Type: application/json" -d '{"name": "John Doe", "email": "john.doe@example.com"}' http://127.0.0.1:8080
```
