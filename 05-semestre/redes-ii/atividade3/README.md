# Atividade 3

## Objetivo

Configurar um servidor DNS utilizando o software BIND9 em uma máquina virtual. Essa configuração deve permitir que o servidor seja capaz de responder por uma zona DNS direta e uma reversa. Essas zonas serão responsáveis por mapear nomes de domínio para endereços IP e vice-versa, respectivamente.

## Link para o Vídeo de Demonstração

[Vídeo de Demonstração](https://youtu.be/XGe9cyzgdtE)

## Acesso ao Roteador por SSH

Login: root

Pass: thoughtpolice

ssh: ssh root@<ip da maq 1>

## Configuração Inicial

Primeiramente, é necessário instalar o BIND9 e o net-tools na máquina virtual:

```bash
apt-get update
apt-get install bind9 net-tools -y
```

Valide a instalação do bind com esse comando:

```bash
sudo service named status
```

Vá na interface de rede interna (enp0s3) e configure o IP para 10.10.1.2/24:

Modo temporário:

```bash
ifconfig enp0s3 10.10.1.2/24 up
```

ou, modo permanente (editando o arquivo de configuração da rede):

```bash
nano /etc/network/interfaces
```

```bash
auto enp0s3
iface enp0s3 inet static
    address 10.10.1.2
    netmask 255.255.255.0
```

Após configurar o IP, reinicie o serviço bind:

```bash
service bind9 restart
```

## Configuração do servidor

Primeiramente, acesse o diretório de configuração do BIND9 e edite o arquivo `named.conf`:

```bash
cd /etc/bind
nano named.conf
```

Adicione a seguinte configuração:

```bash
zone "example.com.br" {
    type master;
    file "/etc/bind/db.example.com.br";
};

zone "1.10.10.in-addr.arpa" {
    type master;
    notify no;
    file "/etc/bind/db.10";
};
```

Agora, edite o arquivo `db.example.com.br`:

```bash
nano db.example.com.br
```

Adicione a seguinte configuração:

```bash
$TTL 604800
@   IN  SOA example.com.br. root.example.com.br. (
  060520139  ; Serial
  604800     ; Refresh
  86400      ; Retry
  2419200    ; Expire
  604800     ; Negative Cache TTL
)
@   IN  NS  ns1.example.com.br.
ns1 IN  A   10.10.1.2
www IN  A   10.10.1.2
maq2 IN A   10.10.1.2
```

Agora, edite o arquivo `db.10`:

```bash
nano db.10
```

Adicione a seguinte configuração:

```bash
$TTL 604800
@   IN  SOA example.com.br. root.example.com.br. (
  060520139     ; Serial
  604800        ; Refresh
  86400         ; Retry
  2419200       ; Expire
  604800        ; Negative Cache TTL
)
;
@       IN      NS      ns1.example.com.br.
2       IN      PTR     www.example.com.br.
```

Agora, vá para o diretório `/etc/` e edite o arquivo `resolv.conf`:

```bash
nano /etc/resolv.conf
```

Adicione a seguinte configuração:

```bash
domain example.com.br
search example.com.br
nameserver 10.10.1.2
```

Reinicie o serviço bind:

```bash
service bind9 restart
```

## Testando a Configuração

Agora, vamos testar a configuração do nosso servidor DNS.

Primeiramente, vamos verificar a validade da zona reversa:

```bash
named-checkzone 1.10.10.in-addr.arpa /etc/bind/db.10
```

Agora, vamos testar a resolução de nomes utilizando:

```bash
dig www.example.com.br
ping www.example.com.br
```
