#!/bin/bash

#Faça um script que receba como parâmetro o arquivo usuários.csv e execute as 
#seguintes ações: 
#a.  crie um usuário no formato nome.sobrenome.idade 
#b.  atribua para este usuário a senha que seja o seu cpf (sem os separadores de  
#“ponto” e “traço“) 
#c.  para a criação deste usuário considere que o mesmo deve ter o diretório 
#home atribuído (/home/nome.sobrenome.idade) e deve uƟlizar o shell padrão 
#do sistema operacional uƟlizado no laboratório 
#d.  Caso o script encontre um usuário  com o mesmo login, ele deve salvar o 
#nome completo, CPF e data de nascimento deste usuário em um arquivo 
#chamado pendencias.txt. 

tail -n +2 usuarios.csv | head -n 1 | while IFS=',' read -r nome_completo cpf idade; do
  primeiro_nome=$(echo "$nome_completo" | awk '{print $1}')
  ultimo_nome=$(echo "$nome_completo" | awk '{print $NF}')

  usuario="${primeiro_nome}.${ultimo_nome}.${idade}"
  senha=$(echo "$cpf" | tr -d '.-')

  echo "usuario: $usuario"
  echo "senha: $senha"

  sudo useradd -m -d /home/$usuario -s $(which bash) $usuario
  echo "$usuario:$senha" | sudo chpasswd
done
