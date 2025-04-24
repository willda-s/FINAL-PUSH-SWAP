/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:28:10 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/03 07:56:23 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	free_lst(t_list **lst, bool error)
{
	t_list	*tmp;
	int		size;

	size = lstsize(*lst);
	if (!(*lst))
		return ;
	while (size--)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	if (error == true)
	{
		write(2, "Error\n", 7);
		exit(-1);
	}
	exit(0);
}

void	free_str(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
