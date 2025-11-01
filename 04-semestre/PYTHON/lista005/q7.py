cidades = ["Ouro Preto", "Santos", "Belo Horizonte", "Campinas", "Rio de Janeiro", "São Paulo", "Salvador", "Fortaleza", "Curitiba"]

estado_cidade = {
    "Ouro Preto": "MG",
    "Santos": "SP",
    "Belo Horizonte": "MG",
    "Campinas": "SP",
    "Rio de Janeiro": "RJ",
    "São Paulo": "SP"
}
sigla = input("Digite a sigla do estado: ").upper()

cidades_estado = list(filter(lambda cidade: estado_cidade.get(cidade) == sigla, cidades))
if not cidades_estado:
    print("nenhuma cidade encontrada")
else:
    cidades_estado.sort()
    print(cidades_estado)