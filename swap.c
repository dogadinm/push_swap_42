/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:26:15 by mdogadin          #+#    #+#             */
/*   Updated: 2023/11/28 13:54:15 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap(p_list **stack)
{
    p_list	*head;
	p_list	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_listsize(*stack) < 2)
		return (1);
    head = *stack;
	next = head->next;
    if (!head && !next)
		ft_error("Error occured while swapping!");
    tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(p_list **stack_a)
{
	if (swap(stack_a) == 1)
		return (1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(p_list **stack_b)
{
	if (swap(stack_b) == 1)
		return (1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(p_list **stack_a, p_list **stack_b)
{
    // sa(p_list **stack_a);
    // sb(p_list **stack_b);

    if ((sa(stack_a) == 1 || sb(stack_b) == 1))
        return(1);
    ft_putendl_fd("ss", 1);

	// if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
	// 	return (1);
	// swap(stack_a);
	// swap(stack_b);
	// ft_putendl_fd("ss", 1);
	return (0);
}


