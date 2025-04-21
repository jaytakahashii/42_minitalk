/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay <jay@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:49:01 by jtakahas          #+#    #+#             */
/*   Updated: 2025/04/21 15:36:57 by jay              ###   ########.fr       */
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
	int	pid;
	int	index;

	if (ac != 3)
		error_exit("Invalid arguments", "Usage: ./client [PID] [message]");
	index = 0;
	while (av[1][index])
	{
		if (!ft_isdigit(av[1][index]))
			error_exit("Invalid PID", "PID must be a positive integer");
		index++;
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 || pid > 32767)
		error_exit("Invalid PID", NULL);
	index = 0;
	while (av[2][index])
	{
		send_message(pid, av[2][index]);
		index++;
	}
	send_message(pid, '\n');
	return (0);
}
