/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:59:13 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/21 18:04:49 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdarg.h>

int     ft_printf(const char *format, ...);
static size_t    ft_typecmp(const char *str);

int     ft_printf(const char *format, ...)
{
    va_list     args;

    va_start( args, format);
    
    va_arg( args, char *);
    va_arg( args, int);
    va_arg( args, float);
    va_arg( args, void);
    //va_arg( args, bool);
    ft_typecmp(const char *str);
    
    va_end (args);
}

static size_t    ft_typecmp(const char *format)
{
    char    *str;
    int     c;

    c = 0;
    while (str[c])
    {
        if (str[c] == '%')
            format = (typeof(str[c + 1]));
        else if (format == 's')
            return ((char) ft(* char));
        else if (format == 'd')
            return ((int) ft(int));
        else if (format == 'f')
            return ((float) ft(float));
        else (format == 'p')
            return ((void) ft(void));
        c++;
    }
}
