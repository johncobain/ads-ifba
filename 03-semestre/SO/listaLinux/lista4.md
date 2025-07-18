# Lista 4

## 1. Crie dois usuários utilizando o terminal. Sugestao (Joao e Maria)

```bash
sudo adduser Joao
sudo adduser Maria
```

## 2. O que acontece na pasta /home?

```plaintext
Foram criados os diretórios pessoais para cada usuário do sistema, que armazenam arquivos, configurações e dados individuais de cada usuário.
```

## 3. O que acontece no perfil destes usuários (/home)? Porque?

```plaintext
Os diretórios pessoais de Joao e Maria foram criados em `/home/Joao` e `/home/Maria`.
Cada diretório contém arquivos de configuração específicos do usuário, como `.bashrc`, `.profile`, e outros arquivos ocultos, permitindo que cada usuário tenha um ambiente separado dos demais.
Isso ocorre para garantir privacidade, organização e segurança dos dados de cada usuário.
```

## 4. O que acontece no diretorio /var/spool/mail? Porque?

```plaintext
O diretório /var/spool/mail armazena caixas de correio dos usuários do sistema.
Quando usuários são criados, são criados arquivos individuais (Joao, Maria) para
armazenar e-mails locais do sistema (notificações, cron jobs, etc.).
Isso permite gerenciamento centralizado do correio local.
```

## 5. O que acontece nos arquivo que gerencia os grupos do sistema operacional? Porque?

```plaintext
Os arquivos /etc/group e /etc/gshadow gerenciam informações dos grupos do sistema.
Quando usuários são criados, são adicionadas entradas nesses arquivos contendo:
nome do grupo, GID (Group ID), lista de membros e permissões.
```

## 6. O que acontece no arquivo /etc/passwd? Porque?

```plaintext
O arquivo /etc/passwd armazena informações básicas dos usuários do sistema.
Quando usuários são criados (Joao e Maria), são adicionadas novas linhas contendo:
nome de usuário, UID (User ID), GID principal, diretório home, shell padrão e outros dados.
Isso permite ao sistema identificar e autenticar usuários durante o login.
```

## 7. Crie uma data de expiração para conta de Maria em 31/07/2020

```bash
sudo usermod -e 2020-07-31 Maria
```

## 8. Crie um novo grupo de usuário e acrescente Joao a este grupo

```bash
sudo groupadd grupo1
sudo usermod -a -G grupo1 Joao
```

## 9. Conecte no perfil de João e crie um arquivo de texto qualquer com conteúdo. Salve o arquivo numa área comum do computador

```bash
sudo passwd Joao # definir a senha, 123 por exemplo
su Joao

# criando em área comum à todos os usuários
cd /tmp
touch exemplo.txt
nano exemplo.txt

# criando em área do usuário João
cd ~
touch exemplo.txt
nano exemplo.txt

exit
```

## 10. Agora, conecte ao usuário de Maria

```bash
# Como Maria tem uma data de expiração que ja passou
# Primeiro tem que redefinir a data para o futuro ou remover a expiração
sudo usermod -e "" Maria
sudo passwd Maria # definir a senha, 123 por exemplo
su Maria
```

## 11. Tente ver o arquivo criado com o perfil de João. O que aconteceu?

```bash
cat /tmp/exemplo.txt
cat /home/Joao/exemplo.txt
```

```plaintext
Maria conseguiu ver o arquivo criado em /tmp/exemplo.txt porque /tmp é uma área comum do sistema com permissões de leitura para todos os usuários.

Porém, Maria não conseguiu ver o arquivo criado em /home/Joao/exemplo.txt porque o diretório home de João tem permissões restritivas que só permitem acesso ao próprio usuário.
```

## 12. Use três formas diferentes para reverter essa situação

a) Alterando a permissão do arquivo

```bash
sudo chmod 755 /home/Joao # Precisa dar permissão no diretório também
sudo chmod 644 /home/Joao/exemplo.txt
```

`Permite que outros usuários possam ler o arquivo.`

b) Adicionando Maria ao mesmo grupo de João

```bash
sudo usermod -a -G grupo1 Maria
sudo chmod 750 /home/Joao
sudo chmod 640 /home/Joao/exemplo.txt
```

`Maria passa a fazer parte do grupo1 (mesmo grupo de João) e pode acessar o arquivo se as permissões de grupo permitirem.`

c) Acrescentando Maria ao grupo de usuários com permissão irrestrita

```bash
sudo usermod -a -G sudo Maria
# no meu caso, se adiciona Maria ao grupo wheel, padrão do Fedora, ficando assim:
sudo usermod -a -G wheel Maria
```

`Com permissões administrativas, Maria pode acessar qualquer arquivo usando sudo.`
