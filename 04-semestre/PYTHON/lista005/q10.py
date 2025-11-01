municipio = input("Digite o nome do município: ")
eleitores_aptos = int(input("Digite a quantidade de eleitores aptos: "))
votos_candidato = int(input("Digite o número de votos do candidato mais votado: "))

if eleitores_aptos > 20000 and votos_candidato < eleitores_aptos * 0.5:
  print("O município", municipio, "terá segundo turno.")
else:
  print("O município", municipio, "não terá segundo turno.")