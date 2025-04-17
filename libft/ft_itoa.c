/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:10:50 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/15 18:03:35 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	h_count_size(long n)
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
	return (i);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		size;
	long	nb;

	nb = n;
	size = h_count_size(nb);
	dest = (char *)malloc((size + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[size] = '\0';
	if (nb < 0)
	{
		dest[0] = '-';
		nb *= -1;
	}
	while (nb >= 10)
	{
		dest[--size] = (nb % 10) + 48;
		nb /= 10;
	}
	dest[--size] = nb + 48;
	return (dest);
}

/*#include <stdio.h>
#include <limits.h>
#include "libft.h"

int	main(void)
{
	int		test_values[] = {0, 42, -42, 123456, -123456, INT_MAX, INT_MIN};
	size_t	i = 0;
	char	*str;

	while (i < sizeof(test_values) / sizeof(test_values[0]))
	{
		str = ft_itoa(test_values[i]);
		if (str)
		{
			printf("ft_itoa(%d) = \"%s\"\n", test_values[i], str);
			free(str); // libera a memória alocada
		}
		else
		{
			printf("ft_itoa(%d) = NULL (erro de malloc?)\n", test_values[i]);
		}
		i++;
	}
	return (0);
}
*/
