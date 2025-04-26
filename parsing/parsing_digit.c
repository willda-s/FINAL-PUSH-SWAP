/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 02:32:36 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/25 18:42:48 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	arg_isnt_digit(char *dst)
{
	int	i;

	i = 0;
	while (dst[i] != '\0')
	{
		if (is_sign(dst[0]))
		{
			i++;
			while (is_digit(dst[i]))
			{
				i++;
				if (dst[i] == '\0')
					return (1);
			}
			return (0);
		}
		else if (!is_digit(dst[i]))
			return (0);
		i++;
	}
	return (1);
}
