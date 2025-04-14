/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:10:50 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/13 20:56:26 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_size(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (1);	
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		size;
	long	nb;

	nb = n;
	size = count_size(nb);
	dest = (char *)malloc((size + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	if (n < 0)
		dest[0] = '-';
		n *= -1;
	while (nb >= 10)
	{
		dest[--size] = (n % 10) + 48;
		n /= 10;
	}
	dest[--size] = nb + 48;
	return (dest);
}

//testar com n positivo e n negativo
