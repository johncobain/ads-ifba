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