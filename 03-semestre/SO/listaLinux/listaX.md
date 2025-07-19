# Lista X

## 1. Execute um comando que gere um arquvo chamado usuarios.txt contendo as últimas 5 linhas do arquivo /etc/passwd

```bash
tail -n 5 /etc/passwd > usuarios.txt
```

## 2. O arquivo /etc/shells contém os shell instalados em seu sistema. Execute um comando que mostre esses shells em ordem alfabética, excluindo a linha com comentário

```bash
cat /etc/shells | grep -v '#' | sort
```

## 3. Conte a quantidade de linhas do aruivo /etc/passwd

```bash
wc -l /etc/passwd
```

## 4. Crie um comando que mostre quantas vezes o nome de seu usuário aparece no arquivo /etc/group

```bash
grep -c "aluno" /etc/group
```

## 5. Escreva um comando que mostre apenas o primeiro campo de cada linha do arquivo /etc/passwd

```bash
cut -d: -f1 /etc/passwd
```

## 6. Usando o editor de texto nano ou vi, crie um pequeno texto com uma avaliação deste curso até agora. Salve o arquivo com o nome avaliacao.txt

```bash
vi avaliacao.txt
```

## 7. Qual o comando usado para

a) apresentar as estatísticas de um arquivo (quantidade de Letras, linhas e palavras de um arquivo)

```bash
wc avaliacao.txt
```

b) ordenar um arquivo na tela

```bash
sort avaliacao.txt
```

c) exibir o inicio de um arquivo. Qual o número de linhas padrão apresentado?

```bash
head avaliacao.txt
# Padrão: 10 linhas
```

d) exibir o fim de um arquivo

```bash
tail avaliacao.txt
# Padrão: 10 linhas
```

e) filtrar ou pesquisar expressões de texto no corpo de um arquivo

```bash
grep "palavra" avaliacao.txt
```

f) filtrar a saída de um comando

```bash
ls | grep ".txt"
# ou
comando | grep "filtro"
```

g) exibir mensagens na tela

```bash
echo "mensagem"
```
