/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:12:16 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/25 16:35:17 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c);

void	ft_putstr(char *s)
{
	int		len;

	if (!s)
	{
		ft_putchar("(null)");
		return (6);
	}
	len = ft_strlen(str);
	write (1, str, len);
	return (len);
}

/*#include <unistd.h>
#include "libft.h"

int		main(void)
{
    ft_putstr_fd("Hello, world!", 1);
    write(1, "\n", 1);
	
	return (0);
}
*/