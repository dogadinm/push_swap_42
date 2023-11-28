/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseRotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:05:06 by mdogadin          #+#    #+#             */
/*   Updated: 2023/11/28 11:39:48 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverseRotate(p_list **stack)
{
	p_list	*head;
	p_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			 head->next = NULL;
			 break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(p_list **stack_a)
{
	if (reverseRotate(stack_a) == 1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(p_list **stack_b)
{
	if (reverseRotate(stack_b) == 1)
		return (1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(p_list **stack_a, p_list **stack_b)
{
    if ((rra(stack_a) == 1 || rrb(stack_b) == 1));
        return(1);
	ft_putendl_fd("rrr", 1);
	return (0);
}