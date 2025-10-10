frutas = ["maçã", "banana", "laranja"]
docinhos_de_festa = ["brigadeiro", "beijinho", "casadinho"]
ingredientes_de_feijoada = ["feijão", "carne seca", "linguiça"]

#a
listona = [frutas, docinhos_de_festa, ingredientes_de_feijoada]
print("Listona: ", listona)

#b
print("brigadeiro" in listona[1])

#c
listona[1].append("brigadeiro")
listona[1].append("brigadeiro")
listona[1].append("brigadeiro")
listona[1].append("brigadeiro")
print("Listona após adicionar brigadeiros: ", listona)

#d
listona.append("bebidas")
print("Listona depois de adicionar bebidas: ", listona)