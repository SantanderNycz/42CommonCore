/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:41:43 by lsantand          #+#    #+#             */
/*   Updated: 2025/07/06 18:41:49 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dc(int n)
{
	int	i;

	i = 0;
	if (n < 0 || n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	int				n1;
	unsigned int	n2;
	int				i;
	char			*d;

	i = ft_dc(n);
	n1 = 0;
	n2 = n;
	d = malloc(i);
	d[--i] = '\0';
	if (n < 0)
	{
		n2 = n * -1;
		d[n1] = '-';
		n1++;
	}
	while (n1 < i--)
	{
		d[i] = n2 % 10 + '0';
		n2 /= 10;
	}
	return (d);
}
