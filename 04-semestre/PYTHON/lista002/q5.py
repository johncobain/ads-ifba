#5. Calcular a quantidade de litros de combustível gastos em uma viagem, sabendo-se que o carro faz 12km com 1 litro. Deverão. Ser fornecidos a) tempo gasto na viagem; b) e a velocidade media. Apresentar os valores da velocidade media, tempo gasto, distancia percorrida e quatidade de litros gastos. 
tempo = int(input("Insira o tempo gasto na viagem(em minutos): "))
vel = float(input("Insira a velocidade média: "))
horas = tempo/60

dist = horas * vel

litros = dist / 12

print(f"Tempo gasto: {horas:.2f} Horas")
print(f"Velocidade média: {vel:.2f} Km/h")
print(f"Distância percorrida: {dist:.2f} Km")
print(f"Quantidade de litros gastos: {litros:.2f} L")
