/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:52:44 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/25 21:15:28 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	add_front(t_list **lst)
{
	t_list	*node;
	t_list	*tmp;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		free_lst(lst, true);
		return ;
	}
	if (!*lst)
	{
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = node;
		(*lst)->prev = node;
		node->next = *lst;
		node->prev = tmp;
	}
	*lst = node;
}

void	add_back(t_list **lst)
{
	t_list	*node;
	t_list	*tmp;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		free_lst(lst, true);
		return ;
	}
	if (!*lst)
	{
		*lst = node;
		(*lst)->next = NULL;
		(*lst)->prev = NULL;
	}
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = node;
		(*lst)->prev = node;
		node->next = *lst;
		node->prev = tmp;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst || (!lst->next))
		return (lst);
	tmp = lst->prev;
	return (tmp);
}

void	init_list(t_list **lst, int ac, char **av)
{
	t_list	*node;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		add_back(lst);
		node = ft_lstlast(*lst);
		if (!node)
			return ;
		node->content = ft_atoi(av[i]);
		node->index = j;
		i++;
		j++;
	}
}
