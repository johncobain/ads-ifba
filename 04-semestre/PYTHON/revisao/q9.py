word = input("Insira uma palavra: ").strip().upper()
word_set = set(c for c in word if c.isalpha())
correct_guesses = set(c for c in word if not c.isalpha())
wrong_guesses = set()
guesses = 0
tries = 3

while True:
  print("\n Palavra: ", end="")
  for letter in word:
    if letter in correct_guesses:
      print(letter, end=" ")
    else:
      print("_", end=" ")
  print("\n Letras erradas: ", " ".join(sorted(wrong_guesses)))
  print(f" Tentativas restantes: {tries - guesses}")
  
  guess = input(" Insira uma letra: ").strip().upper()
  if len(guess) != 1 or not guess.isalpha():
    print(" Por favor, insira apenas uma letra.")
    continue
  
  if guess in correct_guesses or guess in wrong_guesses:
    print(" Você já tentou essa letra")
    continue
  
  if guess in word_set:
    correct_guesses.add(guess)
    if word_set.issubset(correct_guesses):
      print("\nParabéns! Você ganhou!")
      print("A palavra era:", word)
      break
  else:
    wrong_guesses.add(guess)
    guesses += 1
    if guesses >= tries:
      print("\nENFORCADO! Você perdeu.")
      print("A palavra era:", word)
      break
    