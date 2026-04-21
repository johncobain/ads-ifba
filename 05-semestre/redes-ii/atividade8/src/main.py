from http.server import BaseHTTPRequestHandler, HTTPServer
from smptconn import SmtpConn
import json
import logging
import os
from dotenv import load_dotenv

load_dotenv()
EMAIL = os.getenv("MAIL_USER")
PASS = os.getenv("MAIL_PASSWORD")

logging.basicConfig(level=logging.INFO)
try:
  smtpConn =  SmtpConn(EMAIL, PASS)
  print("Conectado com sucesso ao email.")
except:
  print("Falhou ao conectar com Email.")
  exit()

class SimpleHTTPRequestHandler(BaseHTTPRequestHandler):
  def do_POST(self):
    if self.path == "/":
      content_length = int(self.headers["Content-Length"])
      post_data = self.rfile.read(content_length)
      try:
        data = json.loads(post_data)
        response = smtpConn.sendMail(data["email"], data["subject"], data["message"])
        self._send_response(201, response)
      except json.JSONDecodeError:
        self._send_response(400, {"error": "Invalid JSON"})
    else:
      self._send_response(404, {"error": "Invalid endpoint"})

  def _send_response(self, status_code, body):
    self.send_response(status_code)
    self.send_header("Content-Type", "application/json")
    self.end_headers()
    self.wfile.write(json.dumps(body).encode("utf-8"))

if __name__ == "__main__":
  server_address = ("", 8080)
  httpd = HTTPServer(server_address, SimpleHTTPRequestHandler)
  print("Servidor rodando em http://127.0.0.1:8080")
  httpd.serve_forever() 