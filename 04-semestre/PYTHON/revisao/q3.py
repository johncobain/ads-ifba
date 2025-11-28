vel = int(input("Insira a velocidade do carro(km/h): "))

if(vel<=80):
  print("Velocidade permitida.")
else:
  fine = 5*(vel-80)
  print(f"Velocidade máxima excedida! Multa aplicada no valor de R${fine},00")