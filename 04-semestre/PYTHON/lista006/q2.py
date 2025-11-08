#total de votos por candidato, percentual de cada um sobre os válidos, total de inválidos e o(s) vencedor(es). Em caso de 
#empate, informe quais empataram.

candidatos = {1: "Ana", 2: "Bruno", 3: "Carla"}
votos_validos = 0
votos_invalidos = 0
votos = []

while True:
  voto = int(input("Digite o voto (0 para sair): "))
  if voto == 0:
    break
  elif voto in candidatos:
    votos.append(voto)
    votos_validos += 1
  else:
    votos_invalidos += 1

print(f"Total de votos validos: {votos_validos}")
print(f"Total de votos invalidos: {votos_invalidos}")

if votos_validos > 0:
  percentual = (votos_validos / (votos_validos + votos_invalidos)) * 100
  print(f"Percentual de votos validos: {percentual:.2f}%")

if votos:
  vencedor = max(set(votos), key=votos.count)
  print(f"Vencedor: {candidatos[vencedor]}")