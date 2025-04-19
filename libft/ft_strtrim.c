/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:10:15 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:15:08 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t		ft_strlen(char const *str);

static int	h_to_trim(const char *set, char c);

static char	*h_new_str(const char *s1, size_t start, size_t end);

/*se len = 0, nao tem o que cortar, entao retorna uma string vazia;
encontrar o primeiro caracter para separar(crescente e decrescente);
new_str(nova str, o comeco e o len/end (end - start - '\0'));*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (h_to_trim(set, s1[i]))
		i++;
	while (h_to_trim(set, s1[j]) && j > i)
		j--;
	return (h_new_str(s1, i, j - i + 1));
}

/*Verifica se o len/end da new_string é 0 
	ou se o start da new_string é posterior ao final da s1*/
/*calloc ao invés de malloc para
	nao precisar colocar null ao fim da string*/
static char	*h_new_str(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	if (len == 0)
		return (ft_strdup(""));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	return (str);
}

static int	h_to_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
    char *trimmed = ft_strtrim("--42 Porto--", "-");
    printf("ft_strtrim: %s\n\n", trimmed);
    free(trimmed);
	
	return (0);
}
*/