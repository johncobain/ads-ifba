precos = {"arroz": 22.0, "feijao": 8.5, "carne": 39.9, "suco": 7.5, "pao": 4.0}
compras = ["arroz", "carne", "suco", "chocolate", "feijao", "leite"]
indisponiveis = []

total = sum(map(lambda item: precos[item] if item in precos else indisponiveis.append(item) or 0, compras))

if total > 500:
  total *= 0.9
elif total > 300:
  total *= 0.95

print("Total:", total)
print("Itens indisponíveis:", indisponiveis)