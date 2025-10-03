# 4. Calcular o salario liquido de um professor. Os dados fornecidos serão: a) valor hora aula; b) numero de aulas dadas; c) percentual de desconto INSS.
hora_aula = int(input("Insira a Hora Aula: "))
tot_aula = int(input("Insira o total de aulas dadas: "))
inss = int(input("Insira o percentual de desconto do INSS: "))

sal_bruto = hora_aula*tot_aula
desconto = sal_bruto * (inss/100)

sal_liq = sal_bruto - desconto

print(sal_liq)