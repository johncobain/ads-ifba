import smtplib
from email.mime.text import MIMEText

class SmtpConn():
  def __init__(self, sourceMail, password):
    self.mail = sourceMail
    self.connection = smtplib.SMTP('smtp.gmail.com', 587)
    self.connection.ehlo()
    self.connection.starttls()
    self.connection.login(self.mail, password)

  def sendMail(self, destinationMail, subject, message):
    try:
      msg = MIMEText(message, 'plain', 'utf-8')
      msg['From'] = self.mail
      msg['To'] = destinationMail
      msg['Subject'] = subject
      
      self.connection.sendmail(self.mail, destinationMail, msg.as_string())
      
      response = "Email enviado com sucesso!\n"
      print(response)
      return response
    except Exception as e:
      response = f"Erro ao enviar e-mail: {e}\n"
      print(response)
      return response