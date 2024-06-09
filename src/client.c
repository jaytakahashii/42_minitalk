/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:49:01 by jtakahas          #+#    #+#             */
/*   Updated: 2024/06/09 21:36:10 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	if (ac != 3)
		error_handler("Invalid arguments", "Usage: ./client [PID] [message]");
	(void)av;
	return (0);
}
