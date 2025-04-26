/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:44:19 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/25 18:42:48 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	order_index_sort(t_list **a, int size, int rec, int i)
{
	int		value;
	int		max_value;
	t_list	*tmp;
	t_list	*min_node;

	max_value = INT_MAX;
	tmp = *a;
	min_node = NULL;
	while (size--)
	{
		value = tmp->content;
		if (value >= rec && tmp->index == -1)
		{
			if (value <= max_value)
			{
				max_value = value;
				min_node = tmp;
			}
		}
		tmp = tmp->next;
	}
	if (min_node != NULL)
		min_node->index = i;
	return (max_value);
}

static void	setnull_index_list(t_list **lst, int size)
{
	t_list	*tmp;

	tmp = *lst;
	while (size--)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
}

void	sort_index(t_list *a)
{
	int	rec;
	int	i;

	rec = INT_MIN;
	i = 0;
	setnull_index_list(&a, lstsize(a));
	while (i < lstsize(a))
	{
		rec = order_index_sort(&a, lstsize(a), rec, i);
		i++;
	}
}
