/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:03:19 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/10 11:52:02 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last;

	last = NULL;
	while (*str)
	{
		if (*str == (char)c)
			last = str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return ((char *)last);
}

/*#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
    printf("strrchr: %s\n", strrchr("banana", 'a'));
    printf("ft_strrchr: %s\n\n", ft_strrchr("banana", 'a'));
	
	return (0);
}
*/