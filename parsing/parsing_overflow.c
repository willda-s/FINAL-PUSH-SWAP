/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_overflow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 01:57:59 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/26 03:50:39 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

bool	check_atol(const char *str)
{
	int				i;
	int				sign;
	long long int	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (((str[i] >= '\t') && (str[i] <= '\r')) || (str[i] == ' '))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb *= sign;
	if (((nb > INT_MAX) || (nb < INT_MIN)) || ft_strlen(str) > 11)
		return (false);
	return (true);
}
