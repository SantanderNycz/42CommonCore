/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:10:39 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:12:48 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	h_word_count(const char *str, char c);
static char	*h_fill_word(const char *str, int start, int end);
static void	*h_free(char **strs, int count);
static void	h_initiate_vars(size_t *i, int *j, int *s_word);

static void	h_initiate_vars(size_t *i, int *j, int *s_word)
{
	*i = 0;
	*j = 0;
	*s_word = -1;
}

static void	*h_free(char **strs, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*h_fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static int	h_word_count(const char *str, char c)
{
	int		count;
	int		x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c)
			x = 0;
		str++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	int		j;
	int		s_word;

	h_initiate_vars(&i, &j, &s_word);
	res = ft_calloc((h_word_count(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
		{
			res[j] = h_fill_word(s, s_word, i);
			if (!(res[j]))
				return (h_free(res, j));
			s_word = -1;
			j++;
		}
		i++;
	}
	return (res);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
    char **split = ft_split("42-Porto-Escola", '-');
    printf("ft_split:\n");
    for (int i = 0; split[i]; i++)
    {
        printf("[%s]\n", split[i]);
        free(split[i]);
    }
    free(split);
    printf("\n");

	return (0);
}
*/
