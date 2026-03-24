# Atividade 2

## Objetivo

Configurar um servidor apache e instalar o PHP nesse servidor para ter uma página que possa ser acessada utilizando o browser local.

Será necessário utilizar uma das máquinas virtuais criadas na atividade 1 (maq 1), configurando o adapter 3 para bridge para que ela obtenha um endereço de IP local real via DHCP, e instalar o apache e o PHP nessa máquina. Depois disso, criar uma página PHP simples para testar a configuração.

## Link para o Vídeo de Demonstração

[Vídeo de Demonstração](https://youtu.be/W57p_RPRkfY)

## Acesso ao Roteador por SSH

Login: root

Pass: thoughtpolice

ssh: ssh root@<ip da maq 1>

## Configuração Inicial

Primeiramente, é necessário mudar o repositório do sistema para o repositório principal do Debian e atualizar o sistema. Para isso, execute os seguintes comandos:

```bash
echo "deb http://deb.debian.org/debian/ bookworm main contrib non-free non-free-firmware
deb http://deb.debian.org/debian/ bookworm-updates main contrib non-free non-free-firmware
deb http://security.debian.org/debian-security bookworm-security main contrib non-free non-free-firmware" | tee /etc/apt/sources.list
```

```bash
apt-get update
```

Após isso, é necessário instalar o apache e o PHP. Para isso, execute os seguintes comandos:

Observação: php5, como utilizado no livro, não está mais disponível para download no repositório

```bash
apt-get install apache2 net-tools php libapache2-mod-php -y
```

## Configuração do Apache

Ative o servidor do Apache:

```bash
/etc/init.d/apache2 start
```

Para desativar o servidor, execute o seguinte comando:

```bash
/etc/init.d/apache2 stop
```

Verifique o status do servidor do Apache:

```bash
netstat -tulpn | grep :80
```

Para descobrir o ip da máquina, execute o seguinte comando:

```bash
ip a
```

O endereço de IP da máquina será exibido na interface 3 da rede (enp0s9). Com esse IP, digite na barra de navegação do browser para testar o apache.

## Criando uma página PHP

Crie um arquivo PHP para testar a configuração do PHP. Para isso, execute o seguinte comando:

```bash
echo "<?php
  phpinfo();
?>" > /var/www/html/info.php
```

Para testar o PHP, digite na barra de navagação do browser: http://<ip da maq 1>/info.php

Após isso, vá no arquivo /var/www/html/index.html e insira algo, por exemplo:

```bash
nano /var/www/html/index.html
```

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
</head>
<body>
  <h1>Atividade 2</h1>
  <p>Hello World</p>
</body>
</html>
```

Também é possível testar utilizando o telnet ip 80 ou instalando o Lynx na máquina virtuual.

```bash
apt-get install lynx -y
```

```bash
lynx http://<ip da maq 1>
```
