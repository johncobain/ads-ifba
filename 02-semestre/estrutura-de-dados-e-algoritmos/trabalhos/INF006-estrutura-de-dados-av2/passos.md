# AV2

## **Questão 1**

Você precisa processar listas de números naturais no arquivo de entrada e produzir um arquivo de saída com as listas ordenadas em ordem crescente e classificadas por soma total dos elementos.

1. **Ler o arquivo de entrada (`L1Q1.in`) linha por linha.**

   - Cada linha contém uma ou mais listas separadas pela palavra `start`.

2. **Extrair os números de cada lista.**

   - Identificar onde começa e termina cada lista (delimitada pela palavra `start` ou o final da linha).

3. **Converter os números para inteiros e ordená-los em ordem crescente.**

4. **Calcular a soma dos elementos de cada lista.**

   - Usar essa soma para ordenar as listas entre si.

5. **Escrever as listas ordenadas no arquivo de saída (`L1Q1.out`).**
   - Formatar cada lista para que comece com `start` e incluir os números ordenados.

**Exemplo de saída:**

```plaintext
start -3 1 2
start -1 0 2 3
start 0 1 2 4 5
start -1 2 3 5
start -8 0 6 15
```

## **Questão 2**

Implementar uma pilha de texto em que os elementos estão sempre em ordem alfabética, respeitando a política LIFO (Last In, First Out).

1. **Inicializar uma pilha vazia.**

   - A pilha precisa ser capaz de armazenar textos.

2. **Ler o arquivo de entrada (`L1Q2.in`).**

   - Cada linha contém os elementos a serem manipulados.

3. **Ordenar alfabeticamente os elementos na pilha.**

   - Para inserir (push) um novo elemento, remova (pop) todos os elementos que estão fora de ordem.
   - Reinsira os elementos removidos na ordem correta após a nova inserção.

4. **Registrar as operações realizadas.**

   - Para cada operação (push ou pop), registre o comando e o número de pops realizados.

5. **Gerar o arquivo de saída (`L1Q2.out`).**

   - Exemplo de saída:

     ```plaintext
     push−Bruno push−Dani 1x−pop push−Carla push−Dani 3x−pop push−Antônia push−Bruno push−Carla push−Dani push−Walter
     ```

## **Questão 3**

Manipular uma estrutura de dados composta por uma lista duplamente ligada (não-circular) e listas simplesmente ligadas (circulares) associadas a cada elemento.

1. **Ler o arquivo de entrada (`L1Q3.in`).**

   - Identificar a lista principal (LE) e as listas associadas (LI).

2. **Criar a lista duplamente ligada.**

   - Cada nó da lista deve conter um número inteiro como chave.

3. **Criar as listas simplesmente ligadas circulares.**

   - Associar a cada elemento da lista principal (LE) uma lista circular com números reais que diferem da chave por no máximo 0,99.

4. **Ordenar todas as listas.**

   - A lista principal deve ser ordenada em ordem crescente.
   - Cada lista associada deve ser ordenada individualmente.

5. **Gerar o arquivo de saída (`L1Q3.out`).**

   - Exemplo de saída formatada:

     ```plaintext
     [4(4.11−>4.33−>4.99)−>6(6.15−>6.88)−>9(9.2−>9.3)−>10(10.1)]
     ```

---

Se precisar de ajuda com a implementação em Python ou outra linguagem, é só avisar!
