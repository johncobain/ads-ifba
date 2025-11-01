aluno = {"nome": "Ana", "notas": [6.5, 7.0, 8.0]}

media = sum(aluno["notas"]) / len(aluno["notas"])

if media >= 7:
    aluno["status"] = "aprovado"
elif media <= 3:
    aluno["status"] = "reprovado"
else:
    aluno["status"] = "prova final"

if min(aluno["notas"]) < 2:
    aluno["atencao"] = True
else:
    aluno["atencao"] = False

print(aluno)