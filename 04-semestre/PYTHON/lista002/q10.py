# 10. Dada a frase “Python é muito legal". use fatiamento para dar nome às variáveis contendo cada palavra. Qual o tamanho dessa frase? E qual o tamanho de cada palavra? 
frase = 'Python é muito legal'

fraseArr = frase.split()

python = fraseArr[0]
e = fraseArr[1]
muito = fraseArr[2]
legal = fraseArr[3]

print(f"Tamanho da Frase {len(frase)}")
print(f"Tamanho de cada palavra {len(python)}, {len(e)}, {len(muito)}, {len(legal)}")