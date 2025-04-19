/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:09:04 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:12:36 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	i;

	if (!str)
		return (NULL);
	s_len = ft_strlen(str);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!(res))
		return (NULL);
	i = 0;
	while (str[start + i] && i < len)
	{
		res[i] = str[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
    char *sub = ft_substr("Hello World", 6, 5);
    printf("ft_substr: %s\n\n", sub);
    free(sub);
	
	return (0);
}
*/