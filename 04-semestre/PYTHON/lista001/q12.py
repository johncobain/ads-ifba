# 12. Krissia gosta de bolinhas de queijo. Ela quer saber quantas bolinhas de queijo dá para colocar dentro de um  pote de sorvete de 2L. Ela pensou assim: 
#Um pote de sorvete tem dimensões 15 cm x 10 cm x 13 cm. Uma bolinha de queijo é uma esfera de raio r = 1.2 cm.  O fator de empacotamento ideal é 0.74, mas o pote de sorvete tem tamanho comparável às bolinhas de queijo, aí  tem efeitos de borda, então o fator deve ser menor. Mas as bolinhas de queijo são razoavelmente elásticas, então  empacota mais. Esse valor parece razoável. 
#Sabendo que o volume de uma esfera de raio r é V = 4 3 πr3, o volume do pote de sorvete é V = x · y · z e o fator de empacotamento é a fração de volume ocupado pelas bolinhas de queijo. Ou seja, 74% do pote de sorvete vai ser ocupado pelas bolinhas de queijo. 
#Ajude a Krissia descobrir quantas bolinhas de queijo cabem no pote de sorvete!

import math

raio_bolinha = 1.2
volume_bolinha = (4/3) * math.pi * raio_bolinha**3

volume_pote = (15 * 10 * 13)
fator_empacotamento = 0.74

volume_ocupado = fator_empacotamento * volume_pote

quantidade_bolinhas = volume_ocupado / volume_bolinha
print(f"Quantas bolinhas de queijo cabem no pote de sorvete: {int(quantidade_bolinhas)} bolinhas")
