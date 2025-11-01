sigla = input("Insira a sigla do seu estado (UF): ").upper()

if sigla == "SP":
    print("Você é paulista.")
elif sigla == "RJ":
    print("Você é carioca.")
elif sigla == "MG":
    print("Você é mineiro.")
else:
    print("Você é de outro estado.")
