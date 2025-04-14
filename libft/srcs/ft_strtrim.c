/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:10:15 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/13 20:18:17 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlen(char const *str);

static int	to_trim(const char *set, char c);

static char	*new_str(const char *s1, size_t start, size_t end);

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
	while (to_trim(set, s1[i]))
		i++;
	while (to_trim(set, s1[j]) && j > i)
		j--;
	return (new_str(s1, i, j - i + 1));
}

/*Verifica se o len/end da new_string é 0 
	ou se o start da new_string é posterior ao final da s1*/
/*calloc ao invés de malloc para
	nao precisar colocar null ao fim da string*/
static char	*new_str(const char *s1, size_t start, size_t len)
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

static int	to_trim(const char *set, char c)
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
