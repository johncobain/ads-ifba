value = float(input("Digite o valor inicial da dívida: "))
interest = float(input("Digite o juro mensal (em %): "))
payment = float(input("Digite o valor mensal a ser pago: "))

months = 0
total = 0
interestTotal = 0

while(value > 0):
  value = value + value*(interest/100)
  value = value - payment
  months = months + 1
  interestTotal = interestTotal + value*(interest/100)
  total = total + payment

print(f"Total de meses: {months} \nTotal pago: {total} \nTotal de juros: {interestTotal}")