# Lista 3

## 1. No terminal digite os comandos

a) id

```bash
id
```

b) who

```bash
who
```

c) whoami

```bash
whoami
```

## 2. Houve alguma diferença nos resultados apresentados? Se sim, quais foram? Se não houve diferença, o que deveria, justifique e apresente a diferença entre os comandos

```plaintext
Sim, houve diferenças significativas nos resultados:

a) id - Mostra informações completas do usuário:
   - UID (User ID): identificador numérico do usuário
   - GID (Group ID): identificador do grupo principal
   - Grupos: todos os grupos aos quais o usuário pertence
   - Contexto de segurança (SELinux)

b) who - Mostra informações sobre sessões ativas:
   - Nome do usuário logado
   - Terminal/console em uso
   - Data e hora do login
   - Pode mostrar múltiplas sessões se o usuário estiver logado em vários terminais

c) whoami - Mostra apenas:
   - O nome do usuário atual
```

## 3. Usando o comando touch, crie um arquivo texto na pasta /home

```bash
cd ~
touch exemplo.txt
```

## 4. Edite o arquivo texto criado para adicionar a este arquivo um conteudo de texto qualquer com mais de uma página. Salve o arquivo

```bash
nano exemplo.txt
```

## 5. Liste o conteudo do arquivo, no terminal, pausadamente

```bash
more exemplo.txt
```

## 6. Como é possível listar no terminal o conteúdo deste arquivo a partir da 25º linha?

```bash
tail -n +25 exemplo.txt
```

## 7. Apresente o conteudo do arquivo texto criado, com linhas numeradas

```bash
cat -n exemplo.txt
```

## 8. Apresente as 15 primeiras linhas do arquivo texto criado

```bash
head -n 15 exemplo.txt
```

## 9. Apresente as 10 últimas linhas do arquivo texto criado

```bash
tail -n 10 exemplo.txt
```

## 10. Crie um arquivo texto na pasta /home que contenha itens de uma lista de compras, onde cada item deve estar em uma linha

```bash
cd ~
touch lista3.txt
nano lista3.txt
```

## 11. Liste, no terminal, o conteúdo deste arquivo em ordem alfabética

```bash
sort lista3.txt
```

## 12. Reverta a ordem de apresentação do item da questão anterior

```bash
sort -r lista3.txt
```

## 13. Crie um novo arquivo texto contendo o primeiro nome de todos os alunos da turma de sistemas operacionais do seu semestre

```bash
touch alunos.txt
nano alunos.txt
```

## 14. Usando um comando apresente apenas os nomes distintos desta lista

```bash
sort -u alunos.txt
```

## 15. Usando um comando no terminal, concatene o conteúdo do arquivo da lista de compras com o conteúdo dos alunos da turma de SO em um terceiro arquivo

```bash
cat alunos.txt lista3.txt > alunosECompras.txt
```

## 16. Apresente o conteúdo do terceiro arquivo em tela

```bash
cat alunosECompras.txt
```

## 17. Usando o comando find, liste todos os arquivos da pasta /etc com extensão .conf

```bash
find /etc -maxdepth 1 -name "*.conf"
```

## 18. Como você poderia alterar o comando anterior para incluir as subpastas?

```bash
find /etc -name "*.conf"
```

## 19. Exemplifique como é possível delimitar a quantidade de subpastas a ser listada com o comando find

```bash
find /etc -maxdepth 2 -name "*.conf"
# utilizando o decimal 2 para limitar a quantidade de subpastas
```

## 20. Use o comando find para listar apenas os arquivos da pasta /etc

```bash
# Apenas da pasta /etc (sem subpastas):
find /etc -maxdepth 1 -type f

# Ou incluindo subpastas:
find /etc -type f
```

## 21. Agora, use o mesmo comando para listar apenas os diretórios da mesma pasta /etc

```bash
find /etc -maxdepth 1 -type d
```

## 22. Use o comando find para localizar arquivos modificados nos últimos dois meses

```bash
find /etc -mtime -60
```
