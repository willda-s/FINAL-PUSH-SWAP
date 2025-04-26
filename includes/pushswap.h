/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:09:15 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/26 03:33:37 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

///////////////// UTILS ///////////////////////

void				init_list(t_list **lst, int ac, char **av);

void				rm_first_node(t_list **lst);

t_list				*ft_lstlast(t_list *lst);

void				add_front(t_list **lst);

void				add_back(t_list **lst);

int					lstsize(t_list *lst);

void				rev_lst(t_list **a, t_list **b);

///////////////// INSTRUCTIONS ///////////////////////

void				swap_a(t_list **a);

void				swap_b(t_list **b);

void				swap_stacks(t_list **a, t_list **b);

void				push_a(t_list **a, t_list **b);

void				push_b(t_list **a, t_list **b);

void				rotate_a(t_list **a);

void				rotate_b(t_list **b);

void				rotate_stacks(t_list **a, t_list **b);

void				reverse_rotate_a(t_list **a);

void				reverse_rotate_b(t_list **b);

void				reverse_rotate_stacks(t_list **a, t_list **b);

////////////////// PARSING ///////////////

bool				is_digit(char c);

bool				is_sign(char c);

int					arg_isnt_digit(char *dst);

int					arg_is_double(int ac, char **av);

bool				check_atol(const char *str);

int					check_error(int ac, char **av);

int					check_if_sorted(t_list *a);

int					check_if_reversed(t_list *a);

////////////////// ALGO 2 3 ///////////////

int					sort_two(t_list **lsta);

void				sort_three(t_list **lsta);

////////////////// ALGO 4 5 ///////////////

void				algo_fourfive(t_list **a, t_list **b);

////////////////// ALGO MAIN ///////////////

void				hourglass_sort(t_list **a, t_list **b);

void				pushback_in_a(t_list **a, t_list **b);

////////////////// sort INDEX  ///////////////

int					order_index_sort(t_list **a, int size, int rec, int i);

void				sort_index(t_list *a);

////////////////// FREE  ///////////////

void				free_lst(t_list **lst, bool error);
