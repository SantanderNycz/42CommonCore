/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:09:58 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/15 18:02:30 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

static char	*h_str_cat(char *dest, const char *src)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	ft_strlcpy(dest, s1, ft_strlen(s1) + 1);
	h_str_cat(dest, s2);
	return (dest);
}

/*
#include <stdio.h>

int main(void)
{
	char *s1 = "Hello, ";
	char *s2 = "world!";
	char *result = ft_strjoin(s1, s2);

	if (result)
	{
		printf("Resultado da concatenação: %s\n", result);
		free(result);  // Lembre-se de liberar a memória depois!
	}
	else
	{
		printf("Erro na alocação de memória\n");
	}

	return 0;
}*/