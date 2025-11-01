estoque = {"teclado": 12, "mouse": 5, "monitor": 2}
pedidos = [{"produto": "mouse", "qtd": 3}, {"produto": "monitor", "qtd": 4}, {"produto": "teclado", "qtd": 5}]
pendentes = []

def processar_pedido(p):
    prod = p["produto"]
    qtd = p["qtd"]
    if estoque[prod] >= qtd:
        estoque[prod] -= qtd
    else:
        pendentes.append(p)

list(map(processar_pedido, pedidos))

print("Estoque atualizado:", estoque)
print("Pedidos pendentes:", pendentes)


