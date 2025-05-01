# Ideia do passa a passo...

O FD indica um arquivo.

O valor de FD é recebido na main.c atraves da funcao open() --> fd = open("arquivo", O_RDONLY)
O valor recebido é passado para o GNL.

GNL lê a proxima linha do FD e retorna como um char \*.

1. Validação de segurança: se o FD for inválido, se BUFFER_SIZE <= 0, etc.
2. Chama h_read_to_buf(), para garantir que teremos no 'buffer' pelo menos uma linha completa, ou EOF.
3. Extrai a linha com o h_extract_line().
4. Atualiza o 'buffer' com h_trim_line(), removendo a linha já lida.

---

# 1. h_join_and_free()

Concatena o buffer (buffer geral) e o buf (buffer temporário), depois libera o antigo buffer para evitar memory leak.
Buf é um copo, buffer é um balde. Buf enche o buffer até uma linha completa (\n) ou até chegar no fim do arquivo.

# 2. h_read_to_buf()

Lê o FD até encontrar uma linha completa (\n) ou EOF, acumulando o resolvado em 'res'.
Garante que 'res' comece alocado (com o calloc).
Aloca o 'buffer' temporário do tamanho BUFFER_SIZE + 1.
Enquanto não achar \n e não atingir EOF, ela lê o arquivo e junta o novo conteúdo (buffer) com o acumulado (res), via h_join_and_free().
Libera o 'buffer' e retorna 'res'.
Basicamente utiliza novamente a ideia do copo (res) despejando conteudo (buffer) até ter o suficiente para encher uma linha inteira (até \n).

# 3. h_extract_line()

Extrai a próxima linha do buffer (incluindo \n, se houver).
Se o buffer começar com \0, então retorna NULL. Então calcula o tamanho da linha, sem o \n e aloca espaço para ela (+ \n + \0).
Copia os caracteres até encontrar \n ou \0, adiciona o \n ao final (se existir) e finaliza a nova string com \0.
Pense como se buffer fosse uma página inteira e você quer copiar só o primeiro paragrafo(line) até o primeiro ponto final (\n). Você lê até achar o primeiro ponto (\n), pega um pedaço de papel com espaço suficiente (line), copia tudo até esse ponto e finaliza com um grampo (\0), por exemplo, para sinalizar que terminou a cópia.
Essa linha retorna pela GNL.

# 4. h_trim_line()

Remove a primeira linha do buffer, retornando o restante.
Ela encontra o index do \n. Se não houver \n, libera o buffer e retorna NULL. Depois aloca espaço para o resto, copia os caracteres após o \n para a nova string e libera o buffer antigo.
É como se o buffer fosse um scroll de texto. A h_trim_line corta a primeira linha e entrega o que sobrou para a próxima chamada da GNL.
