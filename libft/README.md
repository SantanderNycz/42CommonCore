# 📚 Libft

Libft é um projeto da Escola 42 que consiste em recriar funções padrão da linguagem C, além de implementar funções adicionais úteis para manipulação de strings, memória e listas encadeadas.

---

## 📌 Conteúdo

- [Funções Implementadas](#-funções-implementadas)
- [Como Usar](#-como-usar)
- [Compilação](#-compilação)
- [Regras do Makefile](#-compilação)
- [Autor](#️-autor)

---

## 📜 Funções Implementadas

### 🔹 Funções da Libc

| Função       | Descrição                                                 |
| ------------ | --------------------------------------------------------- |
| `ft_isalpha` | Verifica se um caractere é alfabético.                    |
| `ft_isdigit` | Verifica se um caractere é um dígito.                     |
| `ft_isalnum` | Verifica se um caractere é alfanumérico.                  |
| `ft_isascii` | Verifica se um caractere está na tabela ASCII.            |
| `ft_isprint` | Verifica se um caractere é imprimível.                    |
| `ft_strlen`  | Calcula o comprimento de uma string.                      |
| `ft_memset`  | Preenche um bloco de memória com um valor.                |
| `ft_bzero`   | Preenche um bloco de memória com zeros.                   |
| `ft_memcpy`  | Copia um bloco de memória para outro.                     |
| `ft_memmove` | Copia um bloco de memória com tratamento de sobreposição. |
| `ft_strlcpy` | Copia uma string com limite de tamanho.                   |
| `ft_strlcat` | Concatena strings com limite de tamanho.                  |
| `ft_toupper` | Converte um caractere para maiúsculo.                     |
| `ft_tolower` | Converte um caractere para minúsculo.                     |
| `ft_strchr`  | Localiza a primeira ocorrência de um caractere.           |
| `ft_strrchr` | Localiza a última ocorrência de um caractere.             |
| `ft_strncmp` | Compara duas strings até um tamanho máximo.               |
| `ft_memchr`  | Localiza um caractere em um bloco de memória.             |
| `ft_memcmp`  | Compara dois blocos de memória.                           |
| `ft_strnstr` | Localiza uma substring em uma string com limite.          |
| `ft_atoi`    | Converte uma string em um inteiro.                        |
| `ft_calloc`  | Aloca memória e preenche com zeros.                       |
| `ft_strdup`  | Duplica uma string.                                       |

### 🔹 Funções Adicionais

| Função          | Descrição                                                      |
| --------------- | -------------------------------------------------------------- |
| `ft_substr`     | Extrai uma substring de uma string.                            |
| `ft_strjoin`    | Concatena duas strings.                                        |
| `ft_strtrim`    | Remove caracteres especificados do início e fim de uma string. |
| `ft_split`      | Divide uma string em um array de substrings.                   |
| `ft_itoa`       | Converte um inteiro em uma string.                             |
| `ft_strmapi`    | Aplica uma função a cada caractere de uma string.              |
| `ft_striteri`   | Aplica uma função a cada caractere de uma string (com índice). |
| `ft_putchar_fd` | Escreve um caractere em um descritor de arquivo.               |
| `ft_putstr_fd`  | Escreve uma string em um descritor de arquivo.                 |
| `ft_putendl_fd` | Escreve uma string seguida de uma quebra de linha.             |
| `ft_putnbr_fd`  | Escreve um número inteiro em um descritor de arquivo.          |

### 🔹 Funções para Listas Encadeadas

| Função            | Descrição                                           |
| ----------------- | --------------------------------------------------- |
| `ft_lstnew`       | Cria um novo nó de lista encadeada.                 |
| `ft_lstadd_front` | Adiciona um nó no início da lista.                  |
| `ft_lstsize`      | Conta o número de nós na lista.                     |
| `ft_lstlast`      | Retorna o último nó da lista.                       |
| `ft_lstadd_back`  | Adiciona um nó no final da lista.                   |
| `ft_lstdelone`    | Libera a memória de um único nó.                    |
| `ft_lstclear`     | Libera a memória de toda a lista.                   |
| `ft_lstiter`      | Aplica uma função a cada nó da lista.               |
| `ft_lstmap`       | Cria uma nova lista aplicando uma função a cada nó. |

---

## 🚀 Como Usar

```sh
# Clone este repositório:
git clone https://github.com/seu-usuario/libft
```

```sh
# Acesse a pasta:
cd libft
```

```sh
# Compile a biblioteca:
make
```

```sh
# Inclua o cabeçalho no seu código C:
#include "libft.h"
```

```sh
# Compile seu programa com a biblioteca:
gcc seu_programa.c -L. -lft
```

## 🔧 Compilação

| Comando       | Ação                                               |
| ------------- | -------------------------------------------------- |
| `make`        | Compila a biblioteca (`libft.a`).                  |
| `make clean`  | Remove os arquivos objeto (`.o`).                  |
| `make fclean` | Remove os arquivos objeto e a biblioteca.          |
| `make re`     | Executa `fclean` e recompila a biblioteca do zero. |

## ✒️ Autor

Feito por Leo Santander Nycz como parte do currículo da Escola 42.


## 📝 Notas

Todas as funções seguem os padrões da Escola 42.

Certifique-se de que seu sistema tenha o gcc instalado.


# 🔹 Happy coding! 🚀
