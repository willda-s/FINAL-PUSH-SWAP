/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:45:13 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/25 18:42:48 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	firstwhile(t_list **a, t_list **b, int chunk)
{
	while (*a && lstsize(*a) > 5)
	{
		if ((*a)->index < chunk)
		{
			push_b(a, b);
			break ;
		}
		rotate_a(a);
	}
}

void	hourglass_sort(t_list **a, t_list **b)
{
	int	chunk;
	int	asize;

	asize = lstsize(*a);
	chunk = 0.0375 * asize + 11.25;
	if (chunk >= lstsize(*a))
		chunk = 1;
	firstwhile(a, b, chunk);
	while (lstsize(*a) > 5)
	{
		if ((*a)->index > chunk + lstsize(*b) || (*a)->index >= asize - 5)
			rotate_a(a);
		else
		{
			push_b(a, b);
			if ((*b)->index > lstsize(*b) && (*b)->index <= chunk + lstsize(*b))
				rotate_b(b);
		}
	}
}

static int	indexmaxpos(t_list *b, int ind)
{
	int	i;

	i = 1;
	while (b->index != ind)
	{
		b = b->next;
		i++;
	}
	return (i);
}

void	pushback_in_a(t_list **a, t_list **b)
{
	int	ind;
	int	i;

	while (*b)
	{
		ind = lstsize(*b) - 1;
		i = indexmaxpos((*b), ind);
		while ((*b)->index != ind)
		{
			if (i > lstsize(*b) / 2)
				reverse_rotate_b(b);
			else
				rotate_b(b);
		}
		push_a(a, b);
	}
}
