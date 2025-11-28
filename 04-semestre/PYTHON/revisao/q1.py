num1 = int(input("Digite o primeiro numero: "))
num2 = int(input("Digite o segundo numero: "))

opr = input("Qual operação deseja realizar? (+, -, *, /): ")

if(opr == '+'):
  res = num1 + num2
  print(f"A soma entre {num1} e {num2} é igual a {res}")
elif(opr == '-'):
  res = num1 - num2
  print(f"A subtração entre {num1} e {num2} é igual a {res}")
elif(opr == '*'):
  res = num1 * num2
  print(f"A multiplicação entre {num1} e {num2} é igual a {res}")
elif(opr == '/'):
  if(num2 != 0):
    res = num1 / num2
    print(f"A divisão entre {num1} e {num2} é igual a {res}")
  else:
    print("Erro: Divisão por zero não é permitida.")
else:
  print("Operação inválida. Por favor, escolha entre +, -, * ou /.")