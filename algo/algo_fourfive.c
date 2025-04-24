/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_fourfive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:56:07 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/01 18:59:44 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static int	get_index_minvalue(t_list *a, int size)
{
	int		value;
	t_list	*tmp;

	tmp = a->next;
	while (size--)
	{
		value = tmp->content;
		if (a->content > value)
			a = tmp;
		tmp = tmp->next;
	}
	return (a->index);
}

static int	indexminpos(t_list *a)
{
	int	i;
	int	size;
	int	indexmin;

	i = 1;
	size = lstsize(a);
	indexmin = get_index_minvalue(a, size);
	while (a->index != indexmin)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	algo_fourfive(t_list **a, t_list **b)
{
	int		minpos;
	int		size_a;
	t_list	*tmp;

	while (lstsize(*a) > 3)
	{
		tmp = *a;
		size_a = lstsize(*a);
		minpos = indexminpos(*a);
		while (tmp->index != get_index_minvalue(*a, size_a))
			tmp = tmp->next;
		while ((*a)->content != tmp->content)
		{
			if (minpos > size_a / 2)
				reverse_rotate_a(a);
			else
				rotate_a(a);
		}
		push_b(a, b);
	}
	sort_three(a);
}
