# 2. Entrar com quatro números e imprimir a media ponderada, sabendo-se que os pesos são respectivamente  1,2,3,4.

num1 = int(input("Digite o primeiro número: "))
num2 = int(input("Digite o segundo número: "))
num3 = int(input("Digite o terceiro número: "))
num4 = int(input("Digite o quarto número: "))

med = (num1 + num2*2 + num3*3 + num4*4)/10

print(f'Média ponderada: {med}')