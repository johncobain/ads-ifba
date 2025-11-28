#2) Na usina de Angra dos Reis, os técnicos analisam a perda de massa de um material radioativo. Sabendo-se que este perde 25% de sua massa a cada 30 segundos, criar um programa que imprima o tempo necessário para que a massa deste material se torne menor que 0,10 gramas. O programa pode calcular o tempo para várias massas. 

initial_mass = float(input("Insira a massa inicial do material(gramas): "))
seconds = 0

mass_reduced = initial_mass

while mass_reduced >= 0.10:
  mass_reduced -= mass_reduced*0.25
  seconds += 30
  
print(f"O material com massa inicial de {initial_mass:.2f}g chegara a {mass_reduced:.2f} em {seconds} segundos")