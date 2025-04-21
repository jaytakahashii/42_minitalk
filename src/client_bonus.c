/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay <jay@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:49:01 by jtakahas          #+#    #+#             */
/*   Updated: 2025/04/21 15:31:40 by jay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int signal)
{
	if (signal == SIGUSR1 || signal == SIGUSR2)
		write(1, "SIGUSR!!\n", 9);
}

void	send_message(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_exit("Kill error", "SIGUSR1");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_exit("Kill error", "SIGUSR2");
		}
		usleep(WAIT_TIME);
		bit++;
	}
}

int	main(int ac, char **av)
{
	t_sa	sa;
	int		pid;
	int		index;

	if (ac != 3)
		error_exit("Invalid arguments", "Usage: ./client [PID] [message]");
	if (!bool_atoi(av[1], &pid))
		error_exit("Invalid PID", "PID must be a positive integer");
	if (pid <= 0)
		error_exit("Invalid PID", "PID must be a positive integer");
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1
		|| sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		error_exit("Sigaddset error", NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		error_exit("Sigaction error", NULL);
	sa.sa_flags = 0;
	index = 0;
	while (av[2][index])
		send_message(pid, av[2][index++]);
	send_message(pid, '\n');
	usleep(WAIT_TIME);
	return (0);
}
