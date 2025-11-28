dict_pessoas = {}
dict_menor = {}

while True:
  nome = input("Insira o nome da pessoa: ")
  idade = int(input("Insira a idade da pessoa: "))
  cpf = input("Insira o CPF da pessoa: ")
  
  dict_pessoas[cpf] = {'nome': nome, 'idade': idade}

  continuar = input("Deseja continuar? (S/N): ").upper()
  if(continuar == 'N'):
    break

for cpf in list(dict_pessoas.keys()):
  if dict_pessoas[cpf]['idade'] < 18:
    dict_menor[cpf] = dict_pessoas[cpf]
    del dict_pessoas[cpf]

print(dict_pessoas)
print(dict_menor)