/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_twothree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:00:04 by williamguer       #+#    #+#             */
/*   Updated: 2025/04/25 18:42:48 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_two(t_list **lsta)
{
	if ((*lsta)->content > (*lsta)->next->content)
		swap_a(lsta);
	return (1);
}

void	sort_three(t_list **lsta)
{
	t_list	*tmp;
	int		content;

	tmp = (*lsta)->next;
	content = (*lsta)->content;
	if (content > tmp->content && content > (*lsta)->prev->content)
	{
		rotate_a(lsta);
		if (tmp->content > tmp->next->content)
			swap_a(lsta);
		return ;
	}
	else if (content > (*lsta)->prev->content && content < tmp->content)
		reverse_rotate_a(lsta);
	else if (content < (*lsta)->prev->content && content < tmp->content)
	{
		if (tmp->content > tmp->next->content)
		{
			reverse_rotate_a(lsta);
			swap_a(lsta);
		}
	}
	else if (content > tmp->content && content < (*lsta)->prev->content)
		swap_a(lsta);
}
