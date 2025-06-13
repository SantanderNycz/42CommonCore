#!/bin/bash

# Verifica se o programa push_swap existe
if ! [ -x ./push_swap ]; then
  echo "❌ push_swap não compilado. Rode 'make' primeiro."
  exit 1
fi

# Entrada de teste (você pode mudar essa linha)
ARGS="3 2 1 0"

# Exibe a entrada
echo "🎯 Testando entrada: $ARGS"

# Executa push_swap e conta quantas operações foram feitas
OPS=$(./push_swap $ARGS)
COUNT=$(echo "$OPS" | wc -l)

# Exibe as instruções (opcional, pode comentar se quiser)
echo -e "\n📜 Instruções:"
echo "$OPS"

# Valida a saída com o checker da 42 (se estiver disponível)
if [ -x ./checker_OS ]; then
	echo -e "\n🔍 Verificando com checker_OS:"
	echo "$OPS" | ./checker_OS $ARGS
fi

# Exibe o número de operações
echo -e "\n🔢 Número de operações: $COUNT"
