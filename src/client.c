/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:49:01 by jtakahas          #+#    #+#             */
/*   Updated: 2024/06/12 15:07:56 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_handler("Kill error", "SIGUSR1");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_handler("Kill error", "SIGUSR2");
		}
		usleep(10);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	index;

	if (ac != 3)
		error_handler("Invalid arguments", "Usage: ./client [PID] [message]");
	index = 0;
	if (!bool_atoi(av[1], &pid))
		error_handler("Invalid PID", "PID must be a positive integer");
	if (pid <= 0)
		error_handler("Invalid PID", "PID must be a positive integer");
	while (av[2][index])
	{
		send_message(pid, av[2][index]);
		index++;
	}
	send_message(pid, '\n');
	return (0);
}
