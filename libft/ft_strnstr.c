/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:27:47 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/15 14:44:39 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	pos;
	unsigned int	i;

	if (!*to_find)
		return ((char *)str);
	pos = 0;
	while (str[pos] != '\0' && (size_t)pos < len)
	{
		if (str[pos] == to_find[0])
		{
			i = 1;
			while (to_find[i] != '\0' && str[pos + i] == to_find[i]
				&& (size_t)(pos + i) < len)
			{
				++i;
			}
			if (to_find[i] == '\0')
				return ((char *)&str[pos]);
		}
		++pos;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    const char *hay;
	
	hay = "Ache a agulha no palheiro";
    printf("strnstr: %s\n", strnstr(hay, "agulha", 30));
    printf("ft_strnstr: %s\n\n", ft_strnstr(hay, "agulha", 30));
	
	return (0);
}*/
