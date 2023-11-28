/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:17:03 by mdogadin          #+#    #+#             */
/*   Updated: 2023/11/28 13:57:08 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(p_list **stack)
{
	p_list	*head;
	p_list	*tail;

	if (ft_listsize(*stack) < 2)
		return (1);
	head = *stack;
	tail = ft_listlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0); 
}

int	ra(p_list **stack_a)
{
	if (rotate(stack_a) == 1)
		return (1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(p_list **stack_b)
{
	if (rotate(stack_b) == 1)
		return (1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(p_list **stack_a, p_list **stack_b)
{

    if ((ra(stack_a) == 1 || rb(stack_b) == 1))
        return(1);
    ft_putendl_fd("rr", 1);
	return (0);
}