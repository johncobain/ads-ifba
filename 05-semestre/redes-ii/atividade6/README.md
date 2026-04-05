# Atividade 6

## Objetivo

Elaborar um servidor proxy, que no nosso caso será o Squid, para bloquear o acesso a alguns sites. Além do squid, utilizaremos o navegador Lynx para testar o acesso e bloqueio de acesso aos sites.

## Link para o Vídeo de Demonstração

[Vídeo de Demonstração](https://youtu.be/CBdFARwSAJM)

## Acesso ao Roteador por SSH

Login: root

Pass: thoughtpolice

ssh: ssh root@< ip da maq > ou ssh -p 3022 root@localhost

## Configuração Inicial

Para essa atividade, utilizaremos o adaptador de rede 1 (`enp0s3`) configurado em modo "NAT".

Nas configurações do adaptador de rede, adicione os seguintes redirecionamentos de porta:

name | protocol | host port | guest port
--- | --- | --- | ---
ssh | TCP | 3022 | 22
proxy | TCP | 3128 | 3128

## Instalação e Configuração do Lynx e Squid

Primeiramente, vamos instalar o navegador Lynx e o servidor proxy Squid utilizando o gerenciador de pacotes `apt`:

```bash
apt-get update
apt-get install -y lynx squid
```

Agora, vamos configurar o servidor proxy Squid:

```bash
nano /etc/squid/squid.conf

acl bad_url dstdomain "/etc/squid/bad-sites.acl"
http_access deny bad_url
```

Agora, vamos criar o arquivo `/etc/squid/bad-sites.acl` com os sites que queremos bloquear:

```bash
nano /etc/squid/bad-sites.acl

.google.com
.facebook.com
```

Reinicie o serviço do Squid para aplicar as mudanças:

```bash
service squid restart
```

Agora, vamos configurar o navegador Lynx para utilizar o proxy:

```bash
nano /etc/lynx/lynx.cfg

http_proxy:http://localhost:3128/
https_proxy:http://localhost:3128/
```

## Testando o Acesso

Agora, vamos testar o acesso aos sites utilizando o navegador Lynx:

```bash
lynx google.com

lynx facebook.com

lynx wikipedia.org -accept-all-cookies
```
