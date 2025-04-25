/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:31:13 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/25 18:12:24 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "ft_printf.h"

int		ft_printf(const char *format, ...);
int		ft_print_pointer(unsigned long value, int asc);
int		ft_atoi(const char *str);
int		ft_putstr(char *s);
char	*ft_strchr(const char *s, int c);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putnbr_u(unsigned int n);
void	ft_puthex(int nbr);

#endif
