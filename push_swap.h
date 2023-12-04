/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:06:11 by mdogadin          #+#    #+#             */
/*   Updated: 2023/11/28 13:49:32 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
// Stack
typedef struct n_list
{
	int				value;
	int				index;
	struct n_list	*next;
}	p_list;


void arg_check(int argc , char **argv);
void	ft_error(char *msg);
void	ft_free(char **str);
void	index_stack(p_list **stack);

p_list	*ft_listnew(int value);
void	ft_listadd_front(p_list **stack, p_list *new);
p_list	*ft_listlast(p_list *head);
void	ft_listadd_back(p_list **stack, p_list *new);
int	ft_listsize(p_list *head);
void	printList(p_list *head);

// Util functions


void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
int		is_sorted(p_list **stack);
int		get_distance(p_list **stack, int index);
void	make_top(p_list **stack, int distance);
void	free_stack(p_list **stack);
void	ft_free(char **str);

// Algorithm utils
void	sort(p_list **stack_a, p_list **stack_b);
void	simple_sort(p_list **stack_a, p_list **stack_b);
void	sort_5(p_list **stack_a, p_list **stack_b);

// Instruction functions
int		swap(p_list **stack);
int		push(p_list **stack_to, p_list **stack_from);
int		rotate(p_list **stack);
int		reverseRotate(p_list **stack);

int		sa(p_list **stack_a);
int		sb(p_list **stack_b);
int		ss(p_list **stack_a, p_list **stack_b);
int		pa(p_list **stack_a, p_list **stack_b);
int		pb(p_list **stack_b, p_list **stack_a);
int		ra(p_list **stack_a);
int		rb(p_list **stack_b);
int		rr(p_list **stack_a, p_list **stack_b);
int		rra(p_list **stack_a);
int		rrb(p_list **stack_b);
int		rrr(p_list **stack_a, p_list **stack_b);

#endif