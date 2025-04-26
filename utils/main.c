/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:53:20 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/26 00:10:23 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	wich_algo(t_list **stack_a, t_list **stack_b, int ac)
{
	if (!*stack_a)
	{
		if (ac > 1)
			write(2, "Error\n", 7);
		return ;
	}
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

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		if (check_error(ac, av) == 0)
			return (write(2, "Error\n", 7));
		init_list(&stack_a, ac, av);
		sort_index(stack_a);
		wich_algo(&stack_a, &stack_b, ac);
		free_lst(&stack_a, false);
	}
	else if (ac == 1)
		return (-1);
	return (0);
}
