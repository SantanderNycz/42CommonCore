/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:12:39 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/29 17:28:35 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr_u(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_utoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	ft_putnbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write (1, s, len);
	return (len);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
