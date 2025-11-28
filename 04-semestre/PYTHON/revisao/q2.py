value = float(input("Digite o valor da casa: R$"))
salary = float(input("Insira seu salário: R$"))

paymentYears = int(input("Em quantos anos deseja pagar? "))
monthPayment = value/(paymentYears*12)

if(salary*0.3 < monthPayment):
  print("COMPRA NEGADA")
else:
  print("COMPRA APROVADA")