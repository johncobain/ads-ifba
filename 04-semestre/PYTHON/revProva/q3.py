#3) Faça um programa que calcule o menor número possível de notas (cédulas) que um valor, inserido pelo usuário, pode ser decomposto. As notas consideradas são de 100, 50, 20, 10, 5, 2 e 1. 

qtd_notas = {
  100: 0,
  50: 0,
  20: 0,
  10: 0,
  5: 0,
  2: 0,
  1: 0
}

valor = int(input("Insira o valor (inteiro): R$"))

for nota in sorted(qtd_notas.keys(), reverse=True):
  qtd_notas[nota] = valor // nota
  valor = valor % nota

# while valor > 0:
#   if valor >= 100:
#     qtd_notas[100] += 1
#     valor -= 100
#   elif valor >= 50:
#     qtd_notas[50] += 1
#     valor -= 50
#   elif valor >= 20:
#     qtd_notas[20] += 1
#     valor -= 20
#   elif valor >= 10:
#     qtd_notas[10] += 1
#     valor -= 10
#   elif valor >= 5:
#     qtd_notas[5] += 1
#     valor -= 5
#   elif valor >= 2:
#     qtd_notas[2] += 1
#     valor -= 2
#   elif valor >= 1:
#     qtd_notas[1] += 1
#     valor -= 1
    
print(f"""
  Nota  | Quantidade
  R$100 | {qtd_notas[100]}
  R$50  | {qtd_notas[50]}
  R$20  | {qtd_notas[20]}
  R$10  | {qtd_notas[10]}
  R$5   | {qtd_notas[5]}
  R$2   | {qtd_notas[2]}
  R$1   | {qtd_notas[1]}
""")