produtos = []

while True:
  produto = input("Digite o nome do produto (ou 0 para parar): ")
  if produto == "0":
    break
  preco = float(input(f"Digite o preço do {produto}: "))
  produtos.append({"produto": produto, "preco": preco})

menor_preco = min(produtos, key=lambda x: x["preco"])["preco"]
maior_preco = max(produtos, key=lambda x: x["preco"])["preco"]
preco_medio = sum(x["preco"] for x in produtos) / len(produtos)

print(f"Menor preço: {menor_preco}")
print(f"Maior preço: {maior_preco}")
print(f"Precio médio: {preco_medio}")

for produto in produtos:
  if produto["preco"] > preco_medio:
    print(f"Produto: {produto['produto']}, Preço: {produto['preco']}")