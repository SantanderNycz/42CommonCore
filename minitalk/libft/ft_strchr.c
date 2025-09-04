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

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
    printf("strchr: %s\n", strchr("abcdef", 'd'));
    printf("ft_strchr: %s\n\n", ft_strchr("abcdef", 'd'));
	
	return (0);
}
*/