/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:38:27 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/25 20:07:34 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_error(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (arg_isnt_digit(av[i]) == 0)
			return (0);
		if (check_atol(av[i]) == false)
			return (0);
		i++;
	}
	if (arg_is_double(ac, av) == 0)
		return (0);
	return (1);
}
