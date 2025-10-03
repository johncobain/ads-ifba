# 6. Entrar com valor de um empréstimo, a taxa de juros e a quantidade de meses.  Fazer um programa que calcule o valor da prestação.

valor_emprestimo = float(input("Valor do empréstimo: R$ "))
taxa_juros = float(input("Taxa de juros (% ao mês): "))
meses = int(input("Quantidade de meses: "))

juros_total = valor_emprestimo * (taxa_juros / 100) * meses
valor_total = valor_emprestimo + juros_total
prestacao = valor_total / meses

print(f"Valor da prestação: R$ {prestacao:.2f}")