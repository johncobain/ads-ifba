import math

area = float(input("Digite a area a ser pintada: "))
litros_necessarios = (area / 6) * 1.1 
latas_18l = math.ceil(litros_necessarios / 18)
galoes_36l = math.ceil(litros_necessarios / 3.6)

preco_latas = latas_18l * 80
preco_galoes = galoes_36l * 25

melhor_latas = 0
melhor_galoes = galoes_36l
menor_preco = preco_galoes

max_latas = math.ceil(litros_necessarios / 18)
for latas in range(max_latas + 1):
	litros_restantes = max(0, litros_necessarios - latas * 18)
	galoes = math.ceil(litros_restantes / 3.6)
	preco_total = latas * 80 + galoes * 25

	if preco_total < menor_preco:
		menor_preco = preco_total
		melhor_latas = latas
		melhor_galoes = galoes

print(f"Somente latas de 18 litros: {latas_18l} unidade(s), total R$ {preco_latas:.2f}")
print(f"Somente galões de 3,6 litros: {galoes_36l} unidade(s), total R$ {preco_galoes:.2f}")
print(
	"Mistura com menor custo: "
	f"{melhor_latas} lata(s) de 18 L e {melhor_galoes} galão(ões) de 3,6 L, total R$ {menor_preco:.2f}"
)
