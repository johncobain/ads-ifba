# Atividade 4

## Objetivo

Configurar e testar um ambiente onde mais de um site pode ser hospedado em um mesmo servidor Apache, fazendo uso do mesmo endereço IP. Também será configurado um servidor DNS com duas zonas, responsável por resolver nomes para os sites. Finalmente, realizaremos testes, simulando acessos externos.

Faremos o uso de três máquinas virtuais: a primeira para o servidor Apache, a segunda para os DNS e a terceira para simular os acessos externos.

## Link para o Vídeo de Demonstração

[Vídeo de Demonstração](https://youtu.be/ecj0iBzJSaM)

## Acesso ao Roteador por SSH

Login: root

Pass: thoughtpolice

ssh: ssh root@< ip da maq >

## Configuração das Interfaces de Rede

Primeiramente, se desejar acessar as máquinas virtuais por SSH, configure o segundo adaptador de rede para o modo "Bridge". Já o primeiro adaptador deve ser configurado para o modo de Rede Interna e com o nome "intnet". Dessa forma, as máquinas virtuais poderão se comunicar entre si e também com a máquina host.

Ao acessar cada máquina virtual, configure o IP da interface de rede interna (enp0s3) para 10.10.0.X/24, onde X é um número diferente para cada máquina, e a interface de rede externa (enp0s8) para utilizar DHCP, para obter um IP válido na rede local. Para isso, edite o arquivo de configuração da rede `/etc/network/interfaces` em cada máquina virtual, adicionando as seguintes linhas:

Máquina 1 (Servidor Apache):

```bash
auto enp0s3
iface enp0s3 inet static
    address 10.10.0.2
    netmask 255.255.255.0

auto enp0s8
iface enp0s8 inet dhcp
```

Máquina 2 (Servidor DNS):

```bash
auto enp0s3
iface enp0s3 inet static
    address 10.10.0.3
    netmask 255.255.255.0

auto enp0s8
iface enp0s8 inet dhcp
```

Máquina 3 (Simulador de Acessos Externos):

```bash
auto enp0s3
iface enp0s3 inet static
    address 10.10.0.4
    netmask 255.255.255.0

auto enp0s8
iface enp0s8 inet dhcp
```

## Configuração do Servidor Apache (Máquina 1)

Primeiramente, instale o servidor Apache na máquina 1:

```bash
apt-get update
apt-get install apache2 -y
```

Após a instalação, inicie o serviço do Apache e verifique se ele está rodando corretamente:

```bash
systemctl start apache2
service apache2 status
```

Em seguida, crie os diretórios para os dois sites que serão hospedados no servidor Apache (troque o domínio pelo seu nome):

```bash
mkdir /var/www/html/gomesdev.com.br
mkdir /var/www/html/gomesdev.org.br
```

Remova o arquivo `index.html` padrão do Apache:

```bash
rm /var/www/html/index.html
```

Adicione e configure o arquivo `index.html` em cada um dos diretórios criados:

```html
nano /var/www/html/gomesdev.com.br/index.html

<!DOCTYPE html>
<html>
  <head>
    <title>GomesDev</title>
  </head>
  <body>
    <h1>Bem-vindo ao GomesDev!</h1>
    <p>Este eh o site do gomesdev.com.br</p>
  </body>
</html>
```

```html
nano /var/www/html/gomesdev.org.br/index.html

<!DOCTYPE html>
<html>
  <head>
    <title>GomesDev</title>
  </head>
  <body>
    <h1>Bem-vindo ao GomesDev!</h1>
    <p>Este eh o site do gomesdev.org.br</p>
  </body>
</html>
```

Agora, crie o diretório `conf.d` e configure o arquivo `virtual.conf`:

```bash
mkdir /etc/apache2/conf.d
nano /etc/apache2/conf.d/virtual.conf
```

Adicione a seguinte configuração:

```bash
NameVirtualHost *
```

Dentro do diretório `sites-available`, crie os arquivos de configuração para cada um dos sites:

.com.br:

```bash
nano /etc/apache2/sites-available/gomesdev.com.br.conf

<VirtualHost *:80>
  ServerAdmin webmaster@gomesdev.com.br
  ServerName www.gomesdev.com.br
  ServerAlias gomesdev.com.br

  DirectoryIndex index.html
  DocumentRoot /var/www/html/gomesdev.com.br
</VirtualHost>
```

.org.br:

```bash
nano /etc/apache2/sites-available/gomesdev.org.br.conf

<VirtualHost *:80>
  ServerAdmin webmaster@gomesdev.org.br
  ServerName www.gomesdev.org.br
  ServerAlias gomesdev.org.br

  DirectoryIndex index.html
  DocumentRoot /var/www/html/gomesdev.org.br
</VirtualHost>
```

Agora, habilite os sites criados:

```bash
a2ensite gomesdev.com.br.conf
a2ensite gomesdev.org.br.conf
```

Reinicie o serviço do Apache para aplicar as mudanças:

```bash
systemctl restart apache2
```

Para testar a configuração, acesse os sites utilizando o IP da máquina 1 no navegador:

```plaintext
http://<IP da máquina 1>/gomesdev.com.br
http://<IP da máquina 1>/gomesdev.org.br
```

## Configuração do Servidor DNS (Máquina 2)

Primeiramente, instale o servidor DNS na máquina 2:

```bash
apt-get update
apt-get install bind9 -y
```

Configure o Bind9 para responder por duas zonas:

```bash
nano /etc/bind/named.conf
```

Adicione a seguinte configuração:

```bash
zone "gomesdev.com.br" {
    type master;
    file "/etc/bind/db.gomesdev.com.br";
};

zone "gomesdev.org.br" {
    type master;
    file "/etc/bind/db.gomesdev.org.br";
};
```

Crie os arquivos de configuração para cada uma das zonas:

db.gomesdev.com.br:

```bash
nano /etc/bind/db.gomesdev.com.br

$TTL 604800
@ IN SOA gomesdev.com.br. root.gomesdev.com.br. (
    060520139 ; Serial
    604800    ; Refresh
    86400     ; Retry
    2419200   ; Expire
    604800    ; Negative Cache TTL
)
@ IN NS ns1.gomesdev.com.br.
ns1 IN A 10.10.0.2
www IN A 10.10.0.2
maq1 IN A 10.10.0.2
```

db.gomesdev.org.br:

```bash
nano /etc/bind/db.gomesdev.org.br

$TTL 604800
@ IN SOA gomesdev.org.br. root.gomesdev.org.br. (
    060520139 ; Serial
    604800    ; Refresh
    86400     ; Retry
    2419200   ; Expire
    604800    ; Negative Cache TTL
)
@ IN NS ns1.gomesdev.org.br.
ns1 IN A 10.10.0.2
www IN A 10.10.0.2
maq1 IN A 10.10.0.2
```

Observação: O IP utilizado para os registros A deve ser o IP da máquina 1, onde o servidor Apache está configurado.

Edite o arquivo `/etc/resolv.conf` para utilizar o servidor DNS configurado:

```bash
nano /etc/resolv.conf
```

Adicione a seguinte configuração:

```bash
search gomesdev.com.br gomesdev.org.br

nameserver 10.10.0.3
```

Reinicie o serviço do Bind9 para aplicar as mudanças e teste a resolução de nomes:

```bash
named-checkconf -z
named-checkzone gomesdev.com.br /etc/bind/db.gomesdev.com.br
named-checkzone gomesdev.org.br /etc/bind/db.gomesdev.org.br

service bind9 restart

ping -c 3 www.gomesdev.com.br
ping -c 3 www.gomesdev.org.br
```

## Configuração do Simulador de Acessos Externos (Máquina 3)

Primeiramente, instale o lynx e o dnsutils na máquina 3:

```bash
apt-get update
apt-get install lynx dnsutils -y
```

Defina a máquina 2 como servidor DNS padrão:

```bash
nano /etc/resolv.conf

nameserver 10.10.0.3
```

Agora, teste utilizando os seguintes comandos:

```bash
nslookup www.gomesdev.com.br
nslookup www.gomesdev.org.br
lynx www.gomesdev.com.br
lynx www.gomesdev.org.br
```
