mg_tax = 0.07
sp_tax = 0.12
rj_tax = 0.15
ms_tax = 0.08

value = float(input("Digite o valor do produto: "))
state = input("Insira a sigla do estado de destino (MG, SP, RJ, MS): ").upper()

if state == 'MG':
  final_price = value + (value * mg_tax)
  print(f"Valor final: R${final_price:.2f}")
elif state == 'SP':
  final_price = value + (value * sp_tax)
  print(f"Valor final: R${final_price:.2f}")
elif state == 'RJ':
  final_price = value + (value * rj_tax)
  print(f"Valor final: R${final_price:.2f}")
elif state == 'MS':
  final_price = value + (value * ms_tax)
  print(f"Valor final: R${final_price:.2f}")
else:
    print("Erro: Estado inválido.")