import math

n = 0
for i in range(10):
  n = int(input("Digite um número: "))
  if n < 0:
    print("Número negativo")
  else:
    print("Raiz quadrada de", n, "é", math.sqrt(n))