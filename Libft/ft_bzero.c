/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:42:31 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/10 11:55:07 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	ft_memset(str, 0, len);
}
/*
	unsigned char *ptr;

	ptr = (unsigned char *)str;
	while (len-- > 0)
	{
		*ptr = 0;
		ptr++;
	}
*/

/*int	main(void)
{
    char buffer3[10] = "abcdefghi";
    char buffer4[10] = "abcdefghi";
    bzero(buffer3, 4);
    ft_bzero(buffer4, 4);
    printf("bzero: %.9s\n", buffer3);
    printf("ft_bzero: %.9s\n\n", buffer4);
	
	return (0);
}
*/