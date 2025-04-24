/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 00:03:12 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/01 18:59:36 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rotate_a(t_list **a)
{
	*a = (*a)->next;
	ft_printf("ra\n");
}

void	rotate_b(t_list **b)
{
	*b = (*b)->next;
	ft_printf("rb\n");
}

void	rotate_stacks(t_list **a, t_list **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	ft_printf("rr\n");
}

void	reverse_rotate_a(t_list **a)
{
	*a = (*a)->prev;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **b)
{
	*b = (*b)->prev;
	ft_printf("rrb\n");
}
