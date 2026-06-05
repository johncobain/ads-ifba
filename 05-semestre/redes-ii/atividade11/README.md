# Atividade 11

## Objetivo

Configurar um Servidor Zabbix usando SNMP e conseguir acessar a interface pela máquina host.
Para isso, utilizaremos uma máquina virtual com o adaptador 1 (enp0s3) configurado em modo Bridge.

## Link para o Vídeo de Demonstração

[Vídeo de Demonstração](https://youtu.be/mOlrf5p9CZo)

## Acesso remoto por SSH

Login: root

Pass: thoughtpolice

ssh: ssh root@< ip da maq >

## Configuração da VM

Primeiramente instale o Zabbix Server, Frontend e Agent:

```bash
wget https://repo.zabbix.com/zabbix/6.0/debian/pool/main/z/zabbix-release/zabbix-release_latest+debian12_all.deb
dpkg -i zabbix-release_latest+debian12_all.deb
apt update
apt install zabbix-server-mysql zabbix-frontend-php zabbix-apache-conf zabbix-sql-scripts zabbix-agent
```

## Configuração do MySQL

Caso o MySQL ainda nao esteja instalado, instale-o:

```bash
apt-get install mysql-server
apt-get install php-mysql
```

Agora, configure o MySQL:

```bash
mysql -uroot -p
```

Escolha uma senha caso seja a primeira vez que esteja acessando o MySQL. (ex: pass)

Crie o banco de dados para o Zabbix:

```sql
CREATE DATABASE zabbix CHARACTER SET utf8 COLLATE utf8_bin;
CREATE USER 'zabbix'@'localhost' IDENTIFIED BY 'pass';
GRANT ALL PRIVILEGES ON zabbix.* TO 'zabbix'@'localhost';
FLUSH PRIVILEGES;
EXIT;
```

Importe o esquema do banco de dados para o Zabbix:

```bash
zcat /usr/share/zabbix-sql-scripts/mysql/server.sql.gz | mysql --default-character-set=utf8mb4 -uzabbix -ppass zabbix
```

## Configuração do Zabbix Server

Agora, configure o Zabbix Server:

```bash
nano /etc/zabbix/zabbix_server.conf
```

Adicione as seguintes linhas:

```conf
DBHost=localhost
DBName=zabbix
DBUser=zabbix
DBPassword=pass
```

Configure o timezone do PHP:

```bash
nano /etc/php/<versao>/apache2/php.ini
```

Procure por `date.timezone` e adicione a seguinte linha:

```conf
date.timezone = America/Bahia
```

Configure o log do Zabbix Server:

```bash
mkdir -p /var/log/zabbix-server
chown zabbix:zabbix /var/log/zabbix-server

mkdir -p /etc/zabbix/zabbix_server.conf.d
mkdir -p /etc/zabbix/zabbix_agentd.conf.d
```

Reinicie os serviços:

```bash
service apache2 restart
service zabbix-server restart
service zabbix-agent restart
```

## Configuração do Zabbix Frontend

Na máquina host, abra um navegador e acesse `http://<ip da máquina virtual>/zabbix` e pressione o botão Next Step.

Na próxima tela, o Zabbix irá verificar se todas as dependências estão instaladas. Caso haja algum erro, instale as dependências faltantes e reinicie os serviços.

Na próxima tela, preencha as informações do banco de dados:

- Database type: MySQL
- Database host: localhost
- Database port: 0
- Database name: zabbix
- User: zabbix
- Password: pass

Escolha um nome para o servidor Zabbix, o timezone, o tema e clique em Next Step.

Após isso, faça login com o usuário `Admin` e senha `zabbix` para acessar a interface do Zabbix.

Com isso, o Zabbix Server estará configurado e pronto para monitorar os hosts da rede.
