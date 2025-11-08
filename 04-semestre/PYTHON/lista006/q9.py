consumidores = []
total_consumo = 0
total_residencial = 0
total_comercial = 0
total_industrial = 0
media = 0

while True:
  numero = int(input("Digite o numero do consumidor (ou 0 para parar): "))
  if numero == 0:
    break
  consumo = float(input("Digite a quantidade de kWh consumidos: "))
  tipo = int(input("Digite o tipo de consumidor (1-residencial, 2-comercial, 3-industrial): "))
  custo = consumo * 0.3 if tipo == 1 else consumo * 0.5 if tipo == 2 else consumo * 0.7
  total_consumo += consumo
  total_residencial += consumo if tipo == 1 else 0
  total_comercial += consumo if tipo == 2 else 0
  total_industrial += consumo if tipo == 3 else 0
  media += consumo if tipo == 1 or tipo == 2 else 0
  consumidores.append({"numero": numero, "consumo": consumo, "tipo": tipo, "custo": custo})

print("Consumidores:")
for consumidor in consumidores:
  print(f"Numero: {consumidor['numero']}, Consumo: {consumidor['consumo']}, Tipo: {consumidor['tipo']}, Custo: {consumidor['custo']}")

print(f"Total de consumo: {total_consumo}")
print(f"Total de consumo residencial: {total_residencial}")
print(f"Total de consumo comercial: {total_comercial}")
print(f"Total de consumo industrial: {total_industrial}")
print(f"Media de consumo residencial e comercial: {media / 2}")