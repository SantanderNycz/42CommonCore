/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:16:18 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/23 13:48:12 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*j_dest;
	unsigned char	*j_src;

	j_dest = (unsigned char *)dest;
	j_src = (unsigned char *)src;
	i = 0;
	if (dest > src)
	{
		while (n)
		{
			n--;
			j_dest[n] = j_src[n];
		}
	}
	if (dest < src)
	{
		while (i < n)
		{
			j_dest[i] = j_src[i];
			i++;
		}
	}
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
