/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:00:11 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/25 18:42:48 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_list **a)
{
	int	tmp;
	int	tmpindex;

	tmp = (*a)->content;
	tmpindex = (*a)->index;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = tmpindex;
	ft_printf("sa\n");
}

void	swap_b(t_list **b)
{
	int	tmp;
	int	tmpindex;

	tmp = (*b)->content;
	tmpindex = (*b)->index;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = tmp;
	(*b)->index = (*b)->next->index;
	(*b)->next->index = tmpindex;
	ft_printf("sb\n");
}

void	swap_stacks(t_list **a, t_list **b)
{
	int	tmp;
	int	tmpindex;

	tmp = (*a)->content;
	tmpindex = (*a)->index;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = tmpindex;
	tmp = (*b)->content;
	tmpindex = (*b)->index;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = tmp;
	(*b)->index = (*b)->next->index;
	(*b)->next->index = tmpindex;
	ft_printf("ss\n");
}
