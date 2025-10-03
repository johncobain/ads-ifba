# 7. Criar um  programa que leia a quantidade de fotas de uma locadora de vídeo possui e o valor que ela cobra por cada aluguel, mostrando as informações pedidas a seguir: a) sabendo que um terço das fitas são alugadas por mês, exiba o faturamento anual da locadora; b)Quando o cliente atrasa a entrega, é cobrada uma multa de 10% sobre o valor do aluguel. Sabendo que um decimo das fitas alugadas no mês são devolvidas com atraso, calcule o valor ganho com multas por mês; c) sabendo ainda que 2% de fitas se estragam ao longo do ano, e um decimo do total é comprado para reposição, exiba a quantidade de fitas que a locadora terá no final do ano.

fitas = int(input("Quantidade de fitas: "))
valor = float(input("Valor do aluguel: "))

faturamento_anual = (fitas / 3) * valor * 12
print(f"Faturamento anual: R$ {faturamento_anual:.2f}")

multas_mes = (fitas / 3) / 10 * (valor * 0.10)
print(f"Multas por mês: R$ {multas_mes:.2f}")

fitas_final = fitas - (fitas * 0.02) + (fitas / 10)
print(f"Fitas no final: {fitas_final:.0f}") 