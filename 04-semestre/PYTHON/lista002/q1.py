# 1. Entrar com dois números inteiros e imprimir a seguinte saída: a)dividendo; b) divisor; c) quociente; d) resto.
dividendo = int(input("Digite o dividendo: "))
divisor = int(input("Digite o divisor: "))
quo = dividendo//divisor
res = dividendo%divisor

print(f"""
      Dividendo: {dividendo}
      Divisor: {divisor}
      Quociente: {quo}
      Resto: {res}
      """)