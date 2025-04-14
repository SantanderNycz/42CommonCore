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
#include <stdlib.h>

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
