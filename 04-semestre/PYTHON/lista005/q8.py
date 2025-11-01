nome = input("Digite o nome do aluno: ")
nota1 = float(input("Digite a primeira nota: "))
nota2 = float(input("Digite a segunda nota: "))

media = (nota1 + nota2) / 2

if media >= 7:
  print("Aluno", nome, "aprovado com média", media)
elif media >= 3 and media < 7:
  print("Aluno", nome, "em prova final com média", media)
else:
  print("Aluno", nome, "reprovado com média", media)