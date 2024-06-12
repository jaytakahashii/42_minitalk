/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:49:01 by jtakahas          #+#    #+#             */
/*   Updated: 2024/06/12 14:07:04 by jtakahas         ###   ########.fr       */
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
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		error_handler("Invalid arguments", "Usage: ./client [PID] [message]");
	i = 0;
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		send_message(pid, av[2][i]);
		i++;
	}
	send_message(pid, '\n');
	return (0);
}
