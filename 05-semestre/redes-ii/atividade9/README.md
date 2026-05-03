# Atividade 9

## Objetivo

Criar uma aplicação ssh que permite acesso entre uma máquina e outra.
Para isso, serão utilizadas 2 máquinas virtuais, uma como cliente e a outra como servidor.

Ambas as máquinas terão o adaptador 1 (enp0s3) configurado em modo Bridge.

## Link para o Vídeo de Demonstração

[Vídeo de Demonstração](https://youtu.be/DlV2ovbKBaE)

## Acesso remoto por SSH

Login: root

Pass: thoughtpolice

ssh: ssh root@< ip da maq >

## Configuração da máquina 1

Instale o OpenSSH Server:

```bash
sudo apt update
sudo apt install openssh-server
```

Crie um arquivo de teste com `touch testessh.txt`.

Verifique o ip da máquina servidora com `ip a` e guarde essa informação.

## Configuração da máquina 2

Instale o OpenSSH Client:

```bash
sudo apt update
sudo apt install openssh-client
```

Utilize o comando ssh para acessar a máquina 1:

```bash
ssh root@<ip da máquina 1>
```

Caso seja a primeira vez que esteja acessando a máquina 1, será necessário aceitar a chave de autenticação digitando `yes`.

Digite a senha `thoughtpolice` para acessar a máquina 1.

Verifique se o arquivo `testessh.txt` criado na máquina 1 está presente utilizando o comando `ls`.

Edite o arquivo `testessh.txt` utilizando o comando `nano testessh.txt` e adicione a frase "SSH funcionando!" no arquivo.

Salve o arquivo e saia do editor.

Utilize o comando `ip a` para verificar se o IP mostrado será o mesmo da máquina 1, confirmando que o acesso remoto foi realizado com sucesso.

Na máquina 1, utilize o comando `cat testessh.txt` para verificar se a frase "SSH funcionando!" foi adicionada ao arquivo, confirmando que as alterações feitas na máquina 2 foram refletidas na máquina 1.

Para sair da sessão SSH, utilize o comando `exit` ou pressione `Ctrl + D`.
