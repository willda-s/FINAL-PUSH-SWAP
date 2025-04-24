/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:38:27 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/01 18:59:27 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	check_error(bool format, int ac, char **av)
{
	int	i;

	i = 1;
	if (!format)
		i = 0;
	while (i < ac)
	{
		if (arg_isnt_digit(av[i]) == 0)
			return (0);
		if (check_atol(av[i]) == false)
			return (0);
		i++;
	}
	if (arg_is_double(format, ac, av) == 0)
		return (0);
	return (1);
}
