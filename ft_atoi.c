/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:18:25 by yrafai            #+#    #+#             */
/*   Updated: 2024/11/08 21:02:48 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_overflow(unsigned long nbr, int ndigit, int sign)
{
	if (sign == 1)
		if ((nbr >= 922337203685477580 && ndigit > 7)
			|| nbr > 922337203685477580)
			return (-1);
	if (sign == -1)
		if ((nbr >= 922337203685477580 && ndigit > 8)
			|| nbr > 922337203685477580)
			return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	result;
	int				sign;
	int				overflow;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	sign = 1;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		overflow = handle_overflow(result, (str[i] - '0'), sign);
		if (overflow != 1)
			return (overflow);
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result * sign);
}
