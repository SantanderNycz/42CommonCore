/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:46:35 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/10 11:58:03 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
#include <stddef.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t b)
{
	unsigned char	*ustr;
	unsigned char	uc;

	ustr = (unsigned char *)str;
	uc = (unsigned char)c;
	while (b--)
	{
		if (*ustr == uc)
			return (ustr);
		ustr++;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>
#include "libft.h"

int     main(void)
{
    const char str[] = "Testando memchr123";
    char c = 'i';
    printf("memchr: %s\n", (char *)memchr(str, c, 8));
    printf("ft_memchr: %s\n", (char *)ft_memchr(str, c, 8));
    printf("memchr ptr: %p\n", (char *)memchr(str, c, 8));
    printf("ft_memchr ptr: %p\n\n", (char *)ft_memchr(str, c, 8));
	
	return (0);
}*/