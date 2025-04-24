/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 00:08:24 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/03 08:13:22 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push_a(t_list **a, t_list **b)
{
	if (!*b)
		return ;
	add_front(a);
	if (!*a)
	{
		free_lst(b, true);
		exit(-1);
	}
	(*a)->content = (*b)->content;
	(*a)->index = (*b)->index;
	rm_first_node(b);
	ft_printf("pa\n");
}

void	push_b(t_list **a, t_list **b)
{
	if (!*a)
		return ;
	add_front(b);
	if (!*b)
	{
		free_lst(a, true);
		exit(-1);
	}
	(*b)->content = (*a)->content;
	(*b)->index = (*a)->index;
	rm_first_node(a);
	ft_printf("pb\n");
}

void	reverse_rotate_stacks(t_list **a, t_list **b)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
	ft_printf("rrr\n");
}
