## 🧠 Objetivo do projeto

Criar uma função:

char \*get_next_line(int fd);

Essa função deve ler uma linha por vez de um file descriptor (fd), e deve conseguir lidar com múltiplos FDs ao mesmo tempo.

## 📁 Arquivos esperados

    get_next_line.c – função principal

    get_next_line_utils.c – funções auxiliares (ex: ft_strlen, ft_strjoin, etc.)

    get_next_line.h – protótipos e includes

## 📌 Regras importantes

    Você só pode usar essas funções da libc:

        read, malloc, free

        nenhuma função da libft

    O retorno de get_next_line deve incluir o \n no final da linha (se houver).

    Você precisa lidar com múltiplos FDs ao mesmo tempo, ou seja, sem perder o progresso de leitura de cada um.

    BUFFER_SIZE é definido na compilação, por isso use:

    cc -D BUFFER_SIZE=42 ...

## ⚙️ Estrutura geral da função

Você deve:

-Ler BUFFER_SIZE bytes do fd.

-Juntar com o que sobrou da leitura anterior.

- Verificar se tem \n.

- Separar o que vem antes do \n (para retornar) e o resto (para guardar).

- Repetir até encontrar o \n ou EOF.

## 🧩 Funções que você provavelmente vai precisar criar

- ft_strjoin
- ft_strchr
- ft_bzero
- ft_calloc
- ft_strlen

## 🔄 Gerenciamento de múltiplos FDs

Use uma variável estática, por exemplo:

static char \*fd_storage[1024];

Assim, você consegue manter um “resto” de leitura diferente para cada fd.

## 🧪 Teste

- Crie um arquivo .txt e leia usando:

int fd = open("arquivo.txt", O_RDONLY);
char \*linha;
while ((linha = get_next_line(fd)))
{
printf("%s", linha);
free(linha);
}
close(fd);
