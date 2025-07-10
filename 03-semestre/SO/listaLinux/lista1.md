# Lista 1

## 1 Descubra para que servem os comandos abaixo e liste suas opções de uso mais comuns

a) cal

- função: exibe o calendário do mês atual.
- uso mais comum: $ cal, que exibe o calendário com o mês atual e destaca o dia atual.

b) date

- função: exibe a data atual em dia da semana, mês, dia do mês, hora, minuto, segundo, fuso horário e ano
- uso mais comum: $ date

c) clear

- função: limpa a tela do terminal
- uso mais comum: $ clear

d) exit

- função: encerra a execução do shell atual
- uso mais comum: $ exit

e) uname

- função: imprime informações sobre o sistema
- uso mais comum: $ uname -a, imprime todas as informações do sistema como, kernel, ditribuição, data e versão do kernel etc.

## 2 Usando o comando adequado

a) descubra qual o seu diretório corrente ao logar em um terminal Linux

```bash
  pwd
```

b) Navegue até a pasta /home

```bash
  cd ~
```

c) liste todos os arquivos da pasta /home

```bash
  ls -la
```

d) navegue até a pasta /bin

```bash
  cd /bin
```

e) certifique-se de qual diretório você se encontra

```bash
  pwd
```

f) a partir do diretório corrente, liste o conteúdo da pasta /etc

```bash
  ls -la /etc
```

g) agora liste os arquivos da pasta corrente

```bash
  ls -la
```

h) volte ao diretório home

```bash
  cd ~
```

i) crie uma pasta com o seu nome

```bash
  mkdir nascimento
```

j) crie um arquivo texto dentro da pasta que você criou com o seu nome

```bash
  touch nascimento/nascimento.txt
```

k) copie este arquivo para a pasta /home.

```bash
  cp nascimento/nascimento.txt .
```

l) renomeie o arquivo criado na pasta home

```bash
  mv nascimento.txt nasc.txt
```

m) mova este arquivo que está na pasta que você criou com o seu nome para a pasta home

```bash
  mv nascimento/nascimento.txt .
```

n) exclua o diretório que você criou com o seu nome

```bash
  rmdir nascimento
```
