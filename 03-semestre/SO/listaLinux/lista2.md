# Lista 2

## 1. Usando o terminal

a) Acesse a pasta /etc

```bash
cd /etc
```

b) Execute o comando ls

```bash
ls
```

c) Agora execute o comando ls –la

```bash
ls -la
```

d) O que foi modificado?

```plaintext
O comeando ls mostrou todos os arquivos da pasta /etc um ao lado do outro
Já o comando ls -la mostrou também os arquivos ocultos, que iniciam com "." e mostrou em forma de lista os arquivos e suas informações.
```

e) Como é possível ver o tamanho dos arquivos?

```bash
ls -lh
```

f) Os parâmetros que acompanham os principais comandos Linux são case sensitive?

```bash
Sim, os parâmetros dos comandos Linux são case sensitive.
Exemplo: `ls -l` e `ls -L` possuem funções diferentes.
```

g) O que faz o comando ls –lauS?

```bash
-l mostra os arquivos em forma de lista;
-a mostra os arquivos ocultos;
-u com -l: mostra o tempo de acesso e ordena por nome (alfabeticamente);
-S mostra os arquivos em ordem de tamanho (Maior primeiro);

logo
-lauS mostra os arquivos em forma de lista detalhada, incluindo arquivos ocultos, ordenados por tamanho (prioridade do -S) e alfabeticamente (quando tem o mesmo tamanho), exibindo o tempo de acesso.
```

h) Como inverter a ordem de exibição?

```bash
ls -lr
```

i) Ainda com ls, na pasta /etc, faça as seguintes atividades:

j) Liste todos os arquivos que iniciam pela letra r

```bash
ls /etc/r*
```

k) Liste a quantidade de arquivos de um diretório

```bash
ls | wc -l
```

l) No diretório raiz, exiba todas as pastas e subpastas pausadamente

```bash
find / -type d | more
```

m) Liste o conteúdo da pasta /bin de duas formas:

- Se movendo para a pasta destino;

```bash
cd /bin && ls -la
```

- Sem se mover para a pasta de destino.

```bash
ls -la /bin
# ou
ls -laL /bin
# (O -L serve para o ls seguir o link simbólico)
```

n) Liste apenas o conteúdo da pasta /etc que termine com “.conf”

```bash
ls /etc/*.conf
```

o) Repita a listagem da letra (n) e desta vez grave o resultado da listagem num arquivo, que deverá estar localizado na pasta /home do usuário

```bash
ls /etc/*.conf > ~/arquivosConf.txt
```

p) Crie um arquivo chamado “exemplo1.txt” na pasta /home do usuário com o seguinte conteúdo:

Bebeto, Dunga, Cafu, Branco, Ronaldo, Rivaldo, Taffarel, Roberto Carlos, Romário, Ronaldinho Gaúcho

```bash
echo "Bebeto, Dunga, Cafu, Branco, Ronaldo, Rivaldo, Taffarel, Roberto Carlos, Romário, Ronaldinho Gaúcho" > ~/exemplo1.txt
```

q) Após salvar o arquivo anterior e fechar, exiba o conteúdo do arquivo criado sem usar editor.

```bash
cat ~/exemplo1.txt
```

r) Leia o arquivo e exiba apenas os nomes que começam com Ro

```bash
cat ~/exemplo1.txt | grep -o '\bRo\w*'
```

s) Gere um novo em /home/exemplo2.txt que armazene automaticamente o resultado da questão anterior (letra r).

```bash
cat ~/exemplo1.txt | grep -o '\bRo\w*' > ~/exemplo2.txt
```

t) Exiba a diferença entre os arquivos exemplo1.txt e exemplo2.txt no terminal

```bash
diff ~/exemplo1.txt ~/exemplo2.txt
```
