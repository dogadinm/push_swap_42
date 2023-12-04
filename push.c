/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:46:38 by mdogadin          #+#    #+#             */
/*   Updated: 2023/11/28 13:53:06 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(p_list **stack_to, p_list **stack_from)
{
	p_list	*tmp;
	p_list	*head_to;
	p_list	*head_from;

	if (ft_listsize(*stack_from) == 0)
		return (1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(p_list **stack_a, p_list **stack_b)
{
	if (push(stack_a, stack_b) == 1)
		return (1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(p_list **stack_a, p_list **stack_b)
{
	if (push(stack_b, stack_a) == 1)
		return (1);
	ft_putendl_fd("pb", 1);
	return (0);
}