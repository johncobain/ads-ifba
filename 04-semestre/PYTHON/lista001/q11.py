# 11. Você e os outros integrantes da sua república (Joca, Moacir, Demival e Jackson) foram no supermercado e compraram alguns itens: 
# • 75 latas de cerveja: R$ 2,20 cada (da ruim ainda, pra fazer o dinheiro render) 
# • 2 pacotes de macarrão: R$ 8,73 cada 
# • 1 pacote de Molho de tomate: R$ 3,45 
# • 420g Cebola: R$ 5,40/kg 
# • 250g de Alho: R$ 30/kg 
# • 450g de pães franceses: R$ 25/kg 
# Calcule quanto ficou para cada um. 

# Itens comprados
cerveja_preco = 2.20
macarrao_preco = 8.73
molho_preco = 3.45
cebola_preco_kg = 5.40
alho_preco_kg = 30.00
pao_preco_kg = 25.00

# Quantidades
cerveja_qt = 75
macarrao_qt = 2
molho_qt = 1
cebola_qt_kg = 420 / 1000
alho_qt_kg = 250 / 1000
pao_qt_kg = 450 / 1000

# Custos totais
total = (
    cerveja_qt * cerveja_preco +
    macarrao_qt * macarrao_preco +
    molho_qt * molho_preco +
    cebola_qt_kg * cebola_preco_kg +
    alho_qt_kg * alho_preco_kg +
    pao_qt_kg * pao_preco_kg
)

# Dividindo o total entre 5 pessoas
custo_por_pessoa = total / 5
print(f"Custo total para cada pessoa: R$ {custo_por_pessoa:.2f}")