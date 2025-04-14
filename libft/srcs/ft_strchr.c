/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:20:17 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/10 11:46:17 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
char	*ft_strchr(const char *str, int c)
{
	while (*str != (unsigned char)c)
	{
		if (!*str++)
		return (NULL);
	}
	return ((char *)str);
}*/

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}
