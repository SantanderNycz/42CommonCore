/* Libft - Testes para cada função */
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Exemplo de testes curtos */
int main(void)
{



    // Teste ft_tolower


    // Teste ft_strlen
    printf("ft_strlen('Hello') = %zu\n", ft_strlen("Hello"));

    // Teste ft_strcpy
    char dest1[10];
    printf("ft_strcpy: %s\n", ft_strcpy(dest1, "Hi"));

    // Teste ft_strncpy
    char dest2[10];
    printf("ft_strncpy: %s\n", ft_strncpy(dest2, "Hello", 3));

    // Teste ft_strcat
    char str1[20] = "Hello ";
    printf("ft_strcat: %s\n", ft_strcat(str1, "World"));

    // Teste ft_strncat
    char str2[20] = "Hi ";
    printf("ft_strncat: %s\n", ft_strncat(str2, "there", 3));

    // Teste ft_strlcat
    char str3[20] = "42 ";
    printf("ft_strlcat: %zu -> %s\n", ft_strlcat(str3, "Porto", 10), str3);

    // Teste ft_strchr
    printf("ft_strchr: %s\n", ft_strchr("Hello", 'l'));

    // Teste ft_strrchr
    printf("ft_strrchr: %s\n", ft_strrchr("Hello", 'l'));

    // Teste ft_strstr
    printf("ft_strstr: %s\n", ft_strstr("Hello World", "World"));

    // Teste ft_strnstr
    printf("ft_strnstr: %s\n", ft_strnstr("Hello World", "World", 11));

    // Teste ft_strcmp
    printf("ft_strcmp: %d\n", ft_strcmp("abc", "abd"));

    // Teste ft_strncmp
    printf("ft_strncmp: %d\n", ft_strncmp("abc", "abd", 2));

    // Teste ft_memset
    char mem1[10];
    ft_memset(mem1, 'A', 5);
    printf("ft_memset: %.5s\n", mem1);

    // Teste ft_bzero


    // Teste ft_memcpy
    char src3[10] = "abc";
    char dst3[10];
    ft_memcpy(dst3, src3, 4);
    printf("ft_memcpy: %s\n", dst3);

    // Teste ft_memccpy
    char dst4[10];
    char *res = ft_memccpy(dst4, "abcde", 'c', 5);
    printf("ft_memccpy: %s | return = %s\n", dst4, res);

    // Teste ft_memmove
    char overlap[] = "123456";
    ft_memmove(overlap + 2, overlap, 4);
    printf("ft_memmove: %s\n", overlap);

    // Teste ft_memchr
    printf("ft_memchr: %s\n", (char *)ft_memchr("abcdef", 'd', 6));

    // Teste ft_memcmp
    printf("ft_memcmp: %d\n", ft_memcmp("abc", "abd", 3));



    // Teste ft_strdup
    char *dup = ft_strdup("Lib42");
    printf("ft_strdup: %s\n", dup);
    free(dup);

    // Testes adicionais, parte 2
    printf("ft_substr: %s\n", ft_substr("abcdef", 2, 3));
    printf("ft_strjoin: %s\n", ft_strjoin("42", "Porto"));
    printf("ft_strtrim: %s\n", ft_strtrim("  hello  ", " "));
    
    char **split = ft_split("a,b,c", ',');
    printf("ft_split: %s %s %s\n", split[0], split[1], split[2]);
    free(split[0]); free(split[1]); free(split[2]); free(split);

    printf("ft_itoa: %s\n", ft_itoa(-123));

    char *mapped = ft_strmapi("abc", [](unsigned int i, char c) { return c + 1; });
    printf("ft_strmapi: %s\n", mapped);
    free(mapped);

    return 0;
}
