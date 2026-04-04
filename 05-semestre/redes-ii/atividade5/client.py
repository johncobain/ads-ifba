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