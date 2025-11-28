str1 = input("Digite algo: ")
str2 = input("Digite algo novamente: ")

print("Comprimento da primeira string: ", len(str1))
print("Comprimento da segunda string: ", len(str2))

if(len(str1) == len(str2)):
  if(str1 == str2):
    print("As duas strings são iguais em conteúdo e comprimento")
  else:
    print("As duas strings são iguais em comprimento mas não em conteúdo")
else:
  print("As duas strings são diferentes.")