#!/bin/bash

# Considere o documento de texto banco.txt
# Faça um script para criar um novo arquivo (usuários.txt) no formato CSV considerando 
# os seguintes campos: nome completo, CPF e idade (calculada com base na data de nascimento) 

echo "nome,cpf,idade" > usuarios.csv

while IFS=$'\t' read -r nome cpf nascimento _; do

  [[ -z "$nome" && -z "$cpf" && -z "$nascimento" ]] && continue

  b_year=$(echo "$nascimento" | cut -d'/' -f3)
  b_month=$(echo "$nascimento" | cut -d'/' -f2)
  b_day=$(echo "$nascimento" | cut -d'/' -f1)

  curr_year=$(date +%Y)
  curr_month=$(date +%m)
  curr_day=$(date +%d)

  idade=$((curr_year - b_year))

  if (( curr_month < b_month )) || (( curr_month == b_month && curr_day < b_day )); then
    idade=$((idade-1))
  fi
  
  echo "$nome,$cpf,$idade" >> usuarios.csv
done < banco.txt