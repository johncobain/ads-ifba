# Atividade 7

## Objetivo

Compartilhar arquivos de uma máquina para outra utilizando o protocolo FTP. Para isso, utilizaremos o servidor FTP vsftpd.

Para essa atividade, utilizaremos 1 máquina virtual, com o adaptador de rede 1 (`enp0s3`) configurado em modo "Bridge".

## Link para o Vídeo de Demonstração

[Vídeo de Demonstração](https://youtu.be/psWsYtBg138)

## Acesso ao Roteador por SSH

Login: root

Pass: thoughtpolice

ssh: ssh root@< ip da maq >

## Configuração da máquina 1

Primeiramente, instale o servidor FTP vsftpd utilizando o gerenciador de pacotes `apt`:

```bash
apt-get update
apt-get install ftp vsftpd -y
```

Agora, configure o servidor FTP vsftpd:

```bash
nano /etc/vsftpd.conf
```

Modifique as seguintes linhas(utilize Ctrl + W para facilitar a busca):

```bash
# Adicionar
pasv_enable=YES
allow_writeable_chroot=YES
# Modificar ou descomentar
anonymous_enable=NO
local_enable=YES
write_enable=YES
chroot_local_user=YES
```

Reinicie o servidor FTP vsftpd:

```bash
service vsftpd restart
```

Crie um grupo e um usuário para acessar o servidor FTP:

```bash
groupadd ftpusers
useradd -m -G ftpusers -s /bin/bash ftpuser # Esse comando criará automaticamente a pasta home do usuário
passwd ftpuser # A senha será ftpuser
```

Agora, crie um subdiretório chamado "publicftp" dentro da pasta home do usuário "ftpuser" e dê as permissões necessárias:

```bash
mkdir /home/ftpuser/publicftp
chown ftpuser:ftpusers /home/ftpuser/publicftp
chmod 755 /home/ftpuser/publicftp
```

Crie um arquivo de teste dentro do diretório "publicftp":

```bash
echo "Arquivo de teste para FTP" > /home/ftpuser/publicftp/testftp.txt
```

Reinicie o servidor FTP vsftpd novamente para garantir que todas as configurações sejam aplicadas:

```bash
service vsftpd restart
```

Por fim, verifique o endereço IP da máquina utilizando o comando `ip a` e anote o endereço IP associado ao adaptador de rede `enp0s3`. Esse será o endereço que utilizaremos para acessar o servidor FTP a partir da máquina local.

## Testando a conexão FTP

Iremos fazer a conexão de duas formas: utilizando ftp puro e utilizando o cliente gráfico FileZilla.

### Conexão utilizando FTP puro

Primeiramente, conecte-se ao servidor FTP vsftpd utilizando o comando `ftp`:

```bash
ftp -p <ip da máquina>
```

Digite o nome de usuário e a senha que você criou anteriormente (ftpuser/ftpuser). Após a conexão ser estabelecida, navegue até o diretório "publicftp" utilizando o comando `cd` e baixe o arquivo de teste utilizando o comando `get`:

```bash
cd publicftp
get testftp.txt
```

O arquivo "testftp.txt" será baixado para o diretório atual da sua máquina local. Você pode abrir o arquivo para verificar seu conteúdo.

### Conexão utilizando o cliente gráfico FileZilla

Instale o cliente FileZilla em sua máquina local por esse link: [FileZilla](https://filezilla-project.org/download.php?type=client).
Ou, se estiver utilizando Linux, instale o cliente FTP utilizando o comando:

```bash
sudo apt install filezilla
```

Abra o FileZilla e configure uma nova conexão utilizando as seguintes informações e clique em "Quickconnect":

```bash
Host: <ip da máquina>
Port: 21
User: ftpuser
Password: ftpuser
```

Após isso, você verá a estrutura de diretórios do servidor FTP no painel direito do FileZilla. Navegue até o diretório "publicftp" e baixe o arquivo de teste "testftp.txt" para o seu computador local arrastando o arquivo para o painel esquerdo do FileZilla.
