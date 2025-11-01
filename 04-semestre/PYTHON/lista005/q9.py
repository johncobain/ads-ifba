valor_compra = float(input("Digite o valor de compra do produto: "))

if valor_compra < 20.00:
    lucro = 0.45
else:
    lucro = 0.30

valor_venda = valor_compra + (valor_compra * lucro)
print("O valor de venda do produto é:", valor_venda)