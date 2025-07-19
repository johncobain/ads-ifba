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

## 7. Qual o comando 