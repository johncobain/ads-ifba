agenda = {}

def add_person(cpf):
  name = input("Insira o nome: ")
  age = input("Insira a idade: ")
  phone = input("Insira o telefone: ")
  agenda[cpf] = {
    "nome": name,
    "idade": age,
    "telefone": phone
  }
  
add_person(input("Insira o CPF: "))
add_person(input("Insira o CPF: "))
add_person(input("Insira o CPF: "))
add_person(input("Insira o CPF: "))
add_person(input("Insira o CPF: "))

print(agenda)