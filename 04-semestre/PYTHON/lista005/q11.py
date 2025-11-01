numeros = [10, 23, 45, 66, 78, 89, 90, 12, 33, 57]
separados = {"pares": list(filter(lambda x: x % 2 == 0, numeros)),
              "impares": list(filter(lambda x: x % 2 != 0, numeros))}

if len(separados["pares"]) > len(separados["impares"]):
    print("mais pares")
else:
    print("mais ímpares")

print("maior pares:", max(separados["pares"]))
print("maior ímpares:", max(separados["impares"]))