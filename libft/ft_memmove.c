/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:16:18 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/10 12:02:29 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*udest;
	const unsigned char	*usrc;

	if (!dest && !src)
		return (NULL);
	udest = (unsigned char *) dest;
	usrc = (const unsigned char *) src;
	if (udest < usrc)
		return (ft_memcpy(dest, src, len));
	while (len--)
		udest[len] = usrc[len];
	return (dest);
}

/*#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
    char overlap1[] = "123456789";
    char overlap2[] = "123456789";
    memmove(overlap1 + 2, overlap1, 5);
    ft_memmove(overlap2 + 2, overlap2, 5);
    printf("memmove: %s\n", overlap1);
    printf("ft_memmove: %s\n\n", overlap2);
	
	return (0);
}
*/