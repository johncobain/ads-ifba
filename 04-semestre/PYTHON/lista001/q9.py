# 9. supondo um retângulo de 10cm de base e 5cm de altura, imprimir a seguinte saída perímetro: / área: /  diagonal:  
import math

base = 10
height = 5
perimeter = 2 * (base + height)
area = base * height
diagonal = math.sqrt(base**2 + height**2)
print(f"Retângulo com base {base}cm e altura {height}cm:")
print(f"    Perímetro: {perimeter} cm")
print(f"    Área: {area} cm²")
print(f"    Diagonal: {diagonal:.2f} cm")