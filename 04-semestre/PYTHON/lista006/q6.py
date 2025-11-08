palavras = {}
total_palavras = 0

while True:
  linha = input("Digite uma linha de texto (ou uma linha vazia para parar): ")
  if not linha:
    break
  palavras_linha = linha.split()
  for palavra in palavras_linha:
    palavra = palavra.lower()
    palavra = palavra.strip(",.!?;")
    if palavra in palavras:
      palavras[palavra] += 1
    else:
      palavras[palavra] = 1
    total_palavras += 1

palavras_ordenadas = sorted(palavras.items(), key=lambda item: item[1], reverse=True)
top_5_palavras = palavras_ordenadas[:5]
print("As 5 palavras mais frequentes são:")
for palavra, contagem in top_5_palavras:
  print(f"{palavra}: {contagem}")

print(f"Total de palavras diferentes: {len(palavras)}")
print(f"Total de palavras lidas: {total_palavras}")