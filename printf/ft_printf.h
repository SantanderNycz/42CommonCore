/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:31:13 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/25 19:32:30 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "ft_printf.h"

int		ft_printf(const char *format, ...);
int     ft_puthex(unsigned int nbr, char *base);
int		ft_atoi(const char *str);
int		ft_putstr(char *s);
char	*ft_strchr(const char *s, int c);
int	    ft_putchar(char c);
int	    ft_putnbr(int n);
int	    ft_putnbr_u(unsigned int n);
int	    ft_print_pointer(void *nbr, char *base);
int     ft_strlen(const char *str);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
 
#endif
