nome = input("Insira seu nome: ")
idade = int(input("Insira sua idade: "))
sexo = input("Insira seu sexo (M/F): ").upper()

if sexo == "F" and idade < 25:
    print("ACEITA")
else:
    print("NÃO ACEITA")