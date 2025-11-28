#4) Faça um programa que recebe uma string do usuário e informa se ela é um palíndromo. Um palíndromo é uma frase que, excluindo os espaços em branco, pode ser lida indiferentemente da esquerda para a direita e da direita para a esquerda. Alguns palíndromos conhecidos são: ovo, radar, a grama é amarga, a base to teto desaba. 

string = input("Insira um texto: ").strip()
string_no_spaces = string.replace(" ", "")
string_reversed = string_no_spaces[::-1]

print(f"{string} é um palíndromo" if string_no_spaces == string_reversed else f"{string} NÃO é um palíndromo")