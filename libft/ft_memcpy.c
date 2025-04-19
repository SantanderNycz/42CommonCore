/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:52:40 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/10 12:01:57 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*udest;
	const unsigned char	*usrc;

	udest = (unsigned char *) dest;
	usrc = (const unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	while (n--)
		*udest++ = *usrc++;
	return (dest);
}

/*#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
    char src2[] = "abcde";
    char dst1[10] = {0};
    char dst2[10] = {0};
    memccpy(dst1, src2, 'd', 5);
    ft_memccpy(dst2, src2, 'd', 5);
    printf("memccpy: %s\n", dst1);
    printf("ft_memccpy: %s\n\n", dst2);
	
	return (0);
}
*/