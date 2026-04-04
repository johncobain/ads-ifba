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