tot = []
par = []
impar = []

for i in range(20):
  num = int(input(f"Insira o {i+1}º número: "))
  tot.append(num)
  par.append(num) if num%2 == 0 else impar.append(num)
  
print("Números: ", tot)
print("Pares: ", par)
print("Ímpares: ", impar)
