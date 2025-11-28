#1) Sabendo-se que a UAL calcula a divisão através de subtrações sucessivas, criar um programa que calcule e imprima o resto da divisão de números inteiros lidos. suponha que os números lidos sejam positivos e que o dividendo seja maior que o divisor. 

dividend = int(input("Digite o dividendo: "))
divisor = int(input("Digite o divisor: "))

quocient = 0
remainder = dividend

while remainder - divisor >= 0:
  remainder = remainder - divisor
  quocient += 1
  
print(f"\Quociente: {quocient}")
print(f"\nResto: {remainder}")
