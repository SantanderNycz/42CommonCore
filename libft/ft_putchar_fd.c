/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:11:50 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:18:04 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/*#include <unistd.h>
#include "libft.h"
int		main(void)
{
	ft_putchar_fd('A', 1);
    write(1, "\n", 1);
    
	return (0);
}
*/