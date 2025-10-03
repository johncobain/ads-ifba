# 7. uma figura cujo ângulo e 80 graus. Imprima o seno, co-seno, tangente, secante, cp-secante, e co-tangente. 
import math

rad = math.radians(80)
sin = math.sin(rad)
cos = math.cos(rad)
tan = math.tan(rad)
sec = 1 / cos
cossec = 1 / sin
cotan = 1 / tan

print(f"Para o ângulo de 80 graus:")
print(f"    Seno: {sin:.4f}")
print(f"    Cosseno: {cos:.4f}")
print(f"    Tangente: {tan:.4f}")
print(f"    Secante: {sec:.4f}")
print(f"    Cossecante: {cossec:.4f}")
print(f"    Cotangente: {cotan:.4f}")