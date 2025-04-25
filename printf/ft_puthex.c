/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:28:50 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/25 19:00:21 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex(unsigned long n)
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

static char	*hex_to_str(unsigned long n, char *base)
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

int	ft_print_pointer(void *nbr, char *base)
{
	unsigned long	n;
	char	*digits;
	int	len;

	n = (unsigned long)nbr;
	digits = hex_to_str(n, base);
	len = ft_putstr(digits);
	free(digits);
	return (len);
}
