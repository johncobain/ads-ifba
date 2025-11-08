
estoque = {"teclado": 12, "mouse": 5, "monitor": 2}
pendentes = []

while True:
  produto = input("Digite o produto (ou FIM para parar): ")
  if produto == "FIM":
    break
  qtd = int(input(f"Digite a quantidade de {produto}: "))
  if produto in estoque and estoque[produto] >= qtd:
    estoque[produto] -= qtd
  else:
    pendentes.append({"produto": produto, "qtd": qtd})

print("Estoque atualizado:")
for produto, qtd in estoque.items():
  print(f"{produto}: {qtd}")

print("Pedidos pendentes:")
for pedido in pendentes:
  print(f"Produto: {pedido['produto']}, Quantidade: {pedido['qtd']}")