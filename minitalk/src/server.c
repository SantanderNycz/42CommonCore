/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:17:33 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/04 23:17:34 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	sig_usr(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = -1;

	(void)context;
	if (kill(info->si_pid, 0) < 0)
	{
		ft_printf("ERROR : cant send sig to pid : %d\n", info->si_pid);
		exit(EXIT_FAILURE);
	}
	if (bit < 0 && !c)
		ft_printf("\nClient say : ");
	if (bit < 0)
		bit = __CHAR_BIT__ * sizeof(c) - 1;
	if (sig == SIGUSR1)
		c |= 1 << bit;
	else if (sig == SIGUSR2)
		c &= ~(1 << bit);
	if (!bit && c)
		ft_putchar_fd(c, 1);
	else if (!bit && !c)
		kill(info->si_pid, SIGUSR2);
	bit--;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	init_sig(SIGUSR1, &sig_usr);
	init_sig(SIGUSR2, &sig_usr);
	ft_printf("pid: %d", getpid());
	while (1)
		sleep(1);
}
