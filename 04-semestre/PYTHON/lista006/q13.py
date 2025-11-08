def calcular_preco(tipo_carne, quantidade_kg):
    if tipo_carne.lower() == 'file duplo':
        if quantidade_kg <= 5:
            preco_por_kg = 4.90
        else:
            preco_por_kg = 5.80
    elif tipo_carne.lower() == 'alcatra':
        if quantidade_kg <= 5:
            preco_por_kg = 5.90
        else:
            preco_por_kg = 6.80
    elif tipo_carne.lower() == 'picanha':
        if quantidade_kg <= 5:
            preco_por_kg = 6.90
        else:
            preco_por_kg = 7.80
    else:
        raise ValueError("Tipo de carne inválido.")
    
    return preco_por_kg * quantidade_kg

def gerar_cupom(tipo_carne, quantidade_kg, forma_pagamento):
    try:
        total = calcular_preco(tipo_carne, quantidade_kg)
        if forma_pagamento.lower() == 'cartão tabajara':
            desconto = total * 0.05
        else:
            desconto = 0
        total_a_pagar = total - desconto

        print("----- CUPOM FISCAL -----")
        print(f"Tipo de carne: {tipo_carne}")
        print(f"Quantidade: {quantidade_kg} Kg")
        print(f"Preço total: R$ {total:.2f}")
        print(f"Forma de pagamento: {forma_pagamento}")
        print(f"Valor do desconto: R$ {desconto:.2f}")
        print(f"Total a pagar: R$ {total_a_pagar:.2f}")
        print("------------------------")
    except ValueError as e:
        print(e)
        
tipo_carne = input("Digite o tipo de carne (File Duplo, Alcatra, Picanha): ")
quantidade_kg = float(input("Digite a quantidade de carne em Kg: "))
forma_pagamento = input("Digite a forma de pagamento (cartão Tabajara ou outro): ")
gerar_cupom(tipo_carne, quantidade_kg, forma_pagamento)