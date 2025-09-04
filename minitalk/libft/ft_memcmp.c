/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:45:31 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/15 14:52:01 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*us1;
	const unsigned char	*us2;

	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*us1 != *us2)
			return (*us1 - *us2);
		++us1;
		++us2;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
    printf("memcmp: %d\n", memcmp("abc", "abd", 2));
    printf("ft_memcmp: %d\n\n", ft_memcmp("abc", "abd", 2));
	
	return (0);
}
*/