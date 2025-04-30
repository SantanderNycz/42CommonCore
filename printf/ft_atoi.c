/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:51:05 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/25 18:35:42 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = (res * 10 + (str[i] - '0'));
		i++;
	}
	return (res * neg);
}

/*#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main(void)
{
    printf("ft_atoi: %d\n", ft_atoi("  +42"));
    printf("ft_atoi: %d\n", ft_atoi("   +123"));
    printf("ft_atoi: %d\n", ft_atoi("  0042abc"));
    printf("ft_atoi: %d\n", ft_atoi("  -42"));
    printf("ft_atoi: %d\n", ft_atoi("   +--123"));
	
	return (0);
}*/
