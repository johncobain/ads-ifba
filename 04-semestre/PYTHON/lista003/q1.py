# 1
lista_int = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print("Q01: ", lista_int)

# 2
print("Q02: ", lista_int[0])
print("Q02: ", lista_int[-1])
print("Q02: ", lista_int[len(lista_int) // 2])

# 3
lista_int[0] = 11
print("Q03: ", lista_int)

# 4
lista_int.append(int(input("Digite um número inteiro para adicionar ao final da lista: ")))
print("Q04: ", lista_int)

# 5
del lista_int[-1]
print("Q05: ", lista_int)

# 6
print("Q06: ", len(lista_int))

# 7
print("Q07: ", sum(lista_int))

# 8
list_random = [5, 3, 5, 8, 8, 12, 2, 74, 4, 22, 10, 8, 9]
list_random.sort()
print("Q08: ", list_random)

# 9
list_random.reverse()
print("Q09: ", list_random)

# 10
print("Q10: ", list_random.count(8))

# 11
list_sliced = list_random[0:5]
print("Q11: ", list_sliced)
list_sliced2 = list_sliced[1:-1]
print("Q11: ", list_sliced2)

# 12
list1 = [1, 2, 3]
list2 = [4, 5, 6]
list3 = list1 + list2
print("Q12: ", list3)

# 13
list_check = [10, 20, 30, 40, 50]
element = int(input("Digite um número para verificar se está na lista: "))
if element in list_check:
  print("Q13: ", "O elemento", element, "está na lista")
else:
  print("Q13: ", "O elemento", element, "não está na lista")

# 14
list_duplicates = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
list_no_duplicates = list(set(list_duplicates))
print("Q14: ", list_no_duplicates)