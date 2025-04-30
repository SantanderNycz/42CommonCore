/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:59:13 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/29 16:26:46 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

static size_t	ft_typecmp(const char *format, int c, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	c;
	int				ret;

	va_start(args, format);
	c = 0;
	ret = 0;
	while (format[c])
	{
		if (format[c] == '%' && ft_strchr("cspdiuxX%", format[c + 1]))
		{
			ret += ft_typecmp(format, c, args);
			c++;
		}
		else
			ret += ft_putchar(format[c]);
		c++;
	}
	va_end (args);
	return (ret);
}

static size_t	ft_typecmp(const char *format, int c, va_list args)
{
	void	*ptr;

	if (format[c + 1] == '%')
		return (ft_putchar('%'));
	else if (format[c + 1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format[c + 1] == 'd' || format[c + 1] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format[c + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format[c + 1] == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (format[c + 1] == 'x')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format[c + 1] == 'X')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format[c + 1] == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			return (ft_putstr("(nil)"));
		return (ft_putstr("0x")
			+ ft_print_pointer(ptr, "0123456789abcdef"));
	}
	return (0);
}
