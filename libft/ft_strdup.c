/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:34:20 by willda-s          #+#    #+#             */
/*   Updated: 2024/11/22 15:02:48 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = malloc(sizeof(char) * (ft_strlen((char *)str1)) + 1);
	if (!dst)
		return (NULL);
	while (str1[i])
	{
		dst[i] = str1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
