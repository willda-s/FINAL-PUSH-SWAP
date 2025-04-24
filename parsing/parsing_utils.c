/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:06:39 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/01 18:59:25 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_sign(char c)
{
	return (c == '-' || c == '+');
}

size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	j;
	bool	inword;

	i = 0;
	j = 0;
	inword = false;
	while (s[i])
	{
		if (s[i] == c)
			inword = false;
		if (s[i] != c && !inword)
		{
			inword = true;
			j++;
		}
		i++;
	}
	return (j);
}
