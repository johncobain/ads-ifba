# 8. Dado um numero de conta corrente com três dígitos, retorne o seu digito verificador, o qual é calculado da seguinte maneira. Exemplo: numero conta 235, somar o numero da conta com seu inverso : 235+532=767. Multiplicar cada digito pela sua ordem posicional e somar estes resultados: 7 6 7 (7x1+6x2+7x3) = 40. O ultimo digito desse resultado é o digito verificador da conta (40-> 0 ) 

num_conta = input("Insira o numero da conta (000): ")

num_reverso = num_conta[::-1]

soma = int(num_conta) + int(num_reverso)
soma_str = str(soma)

cen = soma_str[0]
dez = soma_str[1]
uni = soma_str[2]

res = str(int(cen) * 1 + int(dez) * 2 + int(uni) * 3)

print(res[-1])