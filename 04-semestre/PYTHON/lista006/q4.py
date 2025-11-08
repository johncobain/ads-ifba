alunos = []
while True:
  nome = input("Digite o nome do aluno (ou FIM para parar): ")
  if nome == "FIM":
    break
  notas = []
  for i in range(3):
    notas.append(float(input(f"Digite a nota {i + 1}: ")))
  alunos.append({"nome": nome, "notas": notas})

aprovados = 0
recuperacao = 0
reprovados = 0

for aluno in alunos:
  media = sum(aluno["notas"]) / len(aluno["notas"])
  if media >= 7:
    status = "aprovado"
    aprovados += 1
  elif media >= 5:
    status = "recuperação"
    recuperacao += 1
  else:
    status = "reprovado"
    reprovados += 1
  print(f"Nome: {aluno['nome']}, Notas: {aluno['notas']}, Média: {media}, Status: {status}")

print(f"Quantidade de alunos aprovados: {aprovados}")
print(f"Quantidade de alunos em recuperação: {recuperacao}")
print(f"Quantidade de alunos reprovados: {reprovados}")