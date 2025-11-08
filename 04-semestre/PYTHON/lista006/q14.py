litros = float(input("Informe a quantidade de litros vendidos: "))
combustivel = input("Informe o tipo de combustível (A-álcool, G-gasolina): ").strip().upper()

if combustivel == "A":
	preco_por_litro = 1.9
	desconto = 0.05 if litros > 20 else 0.03
elif combustivel == "G":
	preco_por_litro = 2.5
	desconto = 0.06 if litros > 20 else 0.04
else:
	raise ValueError("Tipo de combustível inválido. Use 'A' para álcool ou 'G' para gasolina.")

valor_bruto = litros * preco_por_litro
valor_desconto = valor_bruto * desconto
valor_final = valor_bruto - valor_desconto

print(f"Valor a ser pago: R$ {valor_final:.2f}")
