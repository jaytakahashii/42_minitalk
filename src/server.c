/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:22:14 by jtakahas          #+#    #+#             */
/*   Updated: 2024/06/12 12:23:05 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdio.h>

int	count;

void	signal_handler(int signal)
{
	static int	bit;
	static int	c;

	if (signal == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
		struct	sigaction sa;
		int			pid;

		if (ac != 1)
				error_handler("Invalid arguments", "Usage: ./server");
		// get pid (always successful)
		pid = getpid();
		ft_printf("Server PID: %d\n", pid);
		sa.sa_handler = signal_handler;
		sa.sa_flags = 0;
		while(1)
		{
				sigaction(SIGUSR1, &sa, NULL);
				sigaction(SIGUSR2, &sa, NULL);
				pause();
		}
		(void)av;
		return (0);
}
