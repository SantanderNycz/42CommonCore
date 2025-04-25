/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:28:50 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/25 19:32:15 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	count_hex(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static char	*hex_to_str(unsigned int n, char *base)
{
	int	size;
	char *hex;

	size = count_hex(n);
	hex = (char *)malloc(sizeof(char) * (size + 1));
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (size > 0)
	{
		hex[size - 1] = base [n % 16];
		n /= 16;
		size--;
	}
	return (hex);
}

int	ft_puthex(unsigned int nbr, char *base)
{
	char	*digits;
	int	len;

	digits = hex_to_str(nbr, base);
	len = ft_putstr(digits);
	free(digits);
	return (len);
}
