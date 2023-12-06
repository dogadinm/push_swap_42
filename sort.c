/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:23:37 by mdogadin          #+#    #+#             */
/*   Updated: 2023/12/06 11:54:50 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min_element(t_list *stack_a, int size)
{
	t_list	*head_a;
	t_list	*min_element;
	int		min_value;

	head_a = stack_a;
	min_element = NULL;
	min_value = size;
	while (head_a)
	{
		if (head_a->index <= min_value)
		{
			min_value = head_a->index;
			min_element = head_a;
		}
		head_a = head_a->next;
	}
	return (min_element);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*min_element;
	t_list	*head_a;
	int		size;

	head_a = *stack_a;
	size = ft_listsize(head_a);
	while (*stack_a)
	{
		min_element = find_min_element(*stack_a, size);
		while (*stack_a != min_element)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b);
	}
}
