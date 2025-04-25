/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:10:50 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/25 19:14:18 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
    char *itoa_result = ft_itoa(-12345);
    printf("ft_itoa: %s\n\n", itoa_result);
    free(itoa_result);
	return (0);
}
*/
