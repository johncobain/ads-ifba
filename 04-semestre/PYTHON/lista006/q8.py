chico_height = 1.50
juca_height = 1.10
chico_growth = 0.02 
juca_growth = 0.03
years = 0

while chico_height >= juca_height:
  chico_height += chico_growth
  juca_height += juca_growth
  years += 1

print(f"Juca ficará mais alto que Chico em {years} anos.")