/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 02:54:12 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/25 18:42:48 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rm_first_node(t_list **lst)
{
	t_list	*tmp;
	int		size;

	size = lstsize(*lst);
	if (size == 0)
		return ;
	if (size == 1)
	{
		free(*lst);
		*lst = NULL;
		return ;
	}
	tmp = (*lst)->next;
	if (size == 2)
	{
		tmp->prev = NULL;
		tmp->next = NULL;
	}
	else
	{
		(*lst)->prev->next = tmp;
		tmp->prev = (*lst)->prev;
	}
	free(*lst);
	*lst = tmp;
}

int	lstsize(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = 1;
	if (!lst)
		return (0);
	if (!lst->next)
		return (1);
	tmp = lst->next;
	while (tmp != lst && tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	check_if_sorted(t_list *a)
{
	int		size;
	t_list	*tmp;

	tmp = a;
	size = lstsize(a);
	if (size == 1)
		return (1);
	while (a->next != tmp)
	{
		if (a->index > a->next->index)
			return (-1);
		a = a->next;
	}
	return (1);
}

int	check_if_reversed(t_list *a)
{
	int		size;
	t_list	*tmp;

	tmp = a;
	size = lstsize(a);
	if (size == 1)
		return (1);
	while (a->next != tmp)
	{
		if (a->index < a->next->index)
			return (-1);
		a = a->next;
	}
	return (1);
}

void	rev_lst(t_list **a, t_list **b)
{
	while (lstsize(*a) > 3)
	{
		reverse_rotate_a(a);
		push_b(a, b);
	}
	sort_three(a);
	while (*b)
		push_a(a, b);
}
