/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:22:14 by jtakahas          #+#    #+#             */
/*   Updated: 2024/06/12 15:11:24 by jtakahas         ###   ########.fr       */
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
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
		error_handler("Invalid arguments", "Usage: ./server");
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1)
		error_handler("Sigaddset error", "SIGUSR1");
	if (sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		error_handler("Sigaddset error", "SIGUSR2");
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		error_handler("Sigaction error", "SIGUSR1");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handler("Sigaction error", "SIGUSR2");
	while (1)
		pause();
	return (0);
}
