/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:51:40 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:10:20 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < dest_size)
		ft_memcpy(dest, src, (src_len + 1));
	else if (dest_size)
	{
		ft_memcpy(dest, src, dest_size - 1);
		dest[dest_size - 1] = 0;
	}
	return (src_len);
}

/*#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
    char s1[10];
    char s2[10];
    strlcpy(s1, "copy", sizeof(s1));
    ft_strlcpy(s2, "copy", sizeof(s2));
    printf("strlcpy: %s\n", s1);
    printf("ft_strlcpy: %s\n\n", s2);
	
	return (0);
}
*/