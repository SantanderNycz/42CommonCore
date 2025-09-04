/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:13:10 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:17:36 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd (n / 10, fd);
	}
	ft_putchar_fd ((n % 10) + 48, fd);
}

/*
#include <unistd.h>
#include "libft.h"

int main(void)
{
    ft_putnbr_fd(42, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(-12345, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(0, 1);
    write(1, "\n", 1);
	return (0);
}*/
