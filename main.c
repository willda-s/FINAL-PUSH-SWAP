/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:53:20 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/24 19:16:37 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	split_initlst(char **dst, int i, t_list **stack_a)
{
	if (check_error(false, i, dst) == 0)
	{
		free_str(dst);
		write(2, "Error\n", 7);
		exit(-1);
	}
	init_list(stack_a, i, dst, false);
	free_str(dst);
}

static void	wich_algo(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a)
		return ;
	if (check_if_sorted(*stack_a) == 1)
		return ;
	if (check_if_reversed(*stack_a) == 1)
	{
		rev_lst(stack_a, stack_b);
		return ;
	}
	if (lstsize(*stack_a) == 2)
		sort_two(stack_a);
	else if (lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (lstsize(*stack_a) > 3)
	{
		hourglass_sort(stack_a, stack_b);
		algo_fourfive(stack_a, stack_b);
		pushback_in_a(stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	char	**dst;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2)
	{
		dst = ft_split(av[1], ' ');
		if (!dst)
			return (-1);
		i = ft_countword(av[1], ' ');
		split_initlst(dst, i, &stack_a);
	}
	else
	{
		if (check_error(true, ac, av) == 0)
			return (write(2, "Error\n", 7));
		init_list(&stack_a, ac, av, true);
	}
	sort_index(stack_a);
	wich_algo(&stack_a, &stack_b);
	free_lst(&stack_a, false);
}
