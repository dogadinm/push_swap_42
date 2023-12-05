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

	// t_list	*max_element;
	// t_list	*current;
	// int		max_value;

		// max_value = 0;
		// max_element = NULL;
		// current = *stack_b;
		// while (current)
		// {
		// 	if (current->index >= max_value)
		// 	{
		// 		max_value = current->index;
		// 		max_element = current;
		// 	}
		// 	current = current->next;
		// }
		// while (*stack_b != max_element)
		// 	rra(stack_b);

void	sort(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*head_a;
	t_list	*min_element;
	int		min_value;
	int		size;

	size = ft_listsize(*stack_a);
	while (*stack_a)
	{
		min_value = size;
		min_element = NULL;
		head_a = *stack_a;
		while (head_a)
		{
			if (head_a->index <= min_value)
			{
				min_value = head_a->index;
				min_element = head_a;
			}
			head_a = head_a->next;
		}
		while (*stack_a != min_element)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}


// t_list	*find_min_element(t_list *stack_a, int size)
// {
// 	t_list	*current = stack_a;
// 	t_list	*min_element = NULL;
// 	int		min_value;

// 	min_value = size;
// 	while (current)
// 	{
// 		if (current->index <= min_value)
// 		{
// 			min_value = current->index;
// 			min_element = current;
// 		}
// 		current = current->next;
// 	}

// 	return min_element;
// }

// // // Function to find the maximum element in the stack
// // t_list	*find_max_element(t_list *stack_b)
// // {
// // 	t_list	*current = stack_b;
// // 	t_list	*max_element = NULL;
// // 	int		max_value = 0;


// // 	while (current)
// // 	{
// // 		if (current->index >= max_value)
// // 		{
// // 			max_value = current->index;
// // 			max_element = current;
// // 		}
// // 		current = current->next;
// // 	}

// // 	return max_element;
// // }

// // Function to sort the stacks
// void	sort(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*min_element;
// 	// t_list	*max_element;
// 	t_list	*head_a;
// 	int		size;

// 	head_a = *stack_a;
// 	size = ft_listsize(head_a);
// 	while (*stack_a)
// 	{
// 		min_element = find_min_element(*stack_a, size);
// 		while (*stack_a != min_element)
// 			ra(stack_a);
// 		pb(stack_a, stack_b);
// 	}
// 	while (*stack_b)
// 	{
// 		// max_element = find_max_element(*stack_b);
// 		// while (*stack_b != max_element)
// 		// 	rra(stack_b);
// 		pa(stack_a, stack_b);
// 	}
// }