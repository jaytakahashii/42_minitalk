/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:22:19 by jtakahas          #+#    #+#             */
/*   Updated: 2024/06/12 14:37:58 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*pass_space(char *str)
{
	while (ft_isspace(*str))
		str++;
	return (str);
}

static int	check_plus_minus(char *str)
{
	int	sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return (sign);
}

static bool	is_int(long long num, int sign)
{
	if (sign == 1 && num > __INT_MAX__)
		return (false);
	if (sign == -1 && num * -1 < INT_MIN)
		return (false);
	return (true);
}

bool	bool_atoi(char *str, int *nbr)
{
	int			sign;
	long long	ans;

	if (str == NULL)
		return (false);
	sign = 1;
	ans = 0;
	str = pass_space(str);
	sign = check_plus_minus(str);
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		ans = (*str - '0') + (ans * 10);
		if (!is_int(ans, sign))
			return (false);
		str++;
	}
	*nbr = ans * sign;
	return (true);
}
