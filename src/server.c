/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay <jay@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:22:14 by jtakahas          #+#    #+#             */
/*   Updated: 2025/04/21 15:31:18 by jay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	static int	bit;
	static int	c;

	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	t_sa	sa;

	(void)av;
	if (ac != 1)
		error_exit("Invalid arguments", "Usage: ./server");
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1
		|| sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		error_exit("Sigaddset error", NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		error_exit("Sigaction error", NULL);
	sa.sa_flags = 0;
	while (1)
	{
		pause();
		usleep(WAIT_TIME);
	}
	return (0);
}
