/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:23:37 by mdogadin          #+#    #+#             */
/*   Updated: 2023/12/05 15:20:44 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	// int max_bits;
	// max_bits = 0;
	// while (max != 0)
	// {
	//     max /= 2;
	//     max_bits++;
	// }


// static int max_value(t_list **stack)
// {
//     t_list *head;
//     int max;


//     head = *stack;
//     max = head->index;


//     while (head)
//     {
//         if (head->index > max)
//             max = head->index;
//         head = head->next;
//     }

//     return (max / 2);
// }

// unsigned int compute_power_of_two(int exponent) {
//     unsigned int result = 1;
//     int i;

//     i = 0;
//     while (i < exponent)
//     {
//        result *= 2;
//        i++;
//     }
//     return result;
// }

// void radix_sort(t_list **stack_a, t_list **stack_b)
// {
//     t_list *head_a;
//     int i;
//     int j;
//     int size;
//     int max;

//     i = 0;
//     head_a = *stack_a;
//     size = ft_listsize(head_a);
//     max = max_value(stack_a);

//     while (i < max)
//     {
//         j = 0;
//         while (j++ < size)
//         {
//             head_a = *stack_a;
//             if (((head_a->index / compute_power_of_two(i)) % 2) == 1)
//                 ra(stack_a);
//             else
//                 pb(stack_a, stack_b);
//         }

//         while (ft_listsize(*stack_b) != 0)
//             pa(stack_a, stack_b);

//         i++;
//     }
// }
*/

void	sort(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*head_a;
	t_list	*max_element;
	t_list	*current;
	t_list	*min_element;
	int		max_value;
	int		min_value;
	int		size;

	head_a = *stack_a;
	size = ft_listsize(head_a);
	while (*stack_a)
	{
		min_value = size;
		min_element = NULL;
		current = *stack_a;
		while (current)
		{
			if (current->index <= min_value)
			{
				min_value = current->index;
				min_element = current;
			}
			current = current->next;
		}
		while (*stack_a != min_element)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	while (*stack_b)
	{
		max_value = 0;
		max_element = NULL;
		current = *stack_b;
		while (current)
		{
			if (current->index >= max_value)
			{
				max_value = current->index;
				max_element = current;
			}
			current = current->next;
		}
		while (*stack_b != max_element)
			rra(stack_b);
		pa(stack_a, stack_b);
	}
}
