peso = float(input("Digite o peso dos peixes em quilos: "))

limite = 50
excesso = max(0, peso - limite)
valor_multa_por_kg = 4
multa = excesso * valor_multa_por_kg

print(f"Excesso: {excesso:.2f} kg")
print(f"Multa a pagar: R$ {multa:.2f}")
