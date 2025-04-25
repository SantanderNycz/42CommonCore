/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:12:16 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/25 18:35:22 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c);

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		ft_putchar("(null)");
		return (6);
	}
	len = ft_strlen(s);
	write (1, s, len);
	return (len);
}

/*#include <unistd.h>
#include "ft_printf.h"

int		main(void)
{
    ft_putstr_fd("Hello, world!", 1);
    write(1, "\n", 1);
	
	return (0);
}
*/
