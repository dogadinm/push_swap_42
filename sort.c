/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:23:37 by mdogadin          #+#    #+#             */
/*   Updated: 2023/12/06 14:37:51 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	*find_min_element(t_list *stack_a, int size)
// {
// 	t_list	*head_a;
// 	t_list	*min_element;
// 	int		min_value;

// 	head_a = stack_a;
// 	min_element = NULL;
// 	min_value = size;
// 	while (head_a)
// 	{
// 		if (head_a->index <= min_value)
// 		{
// 			min_value = head_a->index;
// 			min_element = head_a;
// 		}
// 		head_a = head_a->next;
// 	}
// 	return (min_element);
// }

// void	sort(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*min_element;
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
// 		pa(stack_a, stack_b);
// 	}
// }

// #include <limits.h>
// int find_min_index(t_list *stack, int *position)
// {
// 	int min_index = INT_MAX;
// 	int current_index = 0;

// 	while (stack)
// 	{
// 		if (stack->value < min_index)
// 		{
// 			min_index = stack->value;
// 			*position = current_index;
// 		}
// 		stack = stack->next;
// 		current_index++;
// 	}

// 	return min_index;
// }

// void move_to_top(t_list **stack, int position)
// {
// 	int size = ft_listsize(*stack);

// 	if (position <= size / 2)
// 	{
// 		while (position-- > 0)
// 			ra(stack);
// 	}
// 	else
// 	{
// 		position = size - position;
// 		while (position-- > 0)
// 			rra(stack);
// 	}
// }

// void sort(t_list **stack_a, t_list **stack_b)
// {
// 	int position;

// 	while (*stack_a)
// 	{
// 		find_min_index(*stack_a, &position);

// 		move_to_top(stack_a, position);

// 		pb(stack_a, stack_b);
// 	}

// 	while (*stack_b)
// 		pa(stack_a, stack_b);
// }

// #include <limits.h>
// int find_min_index(t_list *stack, int *position)
// {
//     int min_index = INT_MAX;
//     int current_index = 0;

//     while (stack)
//     {
//         if (stack->value < min_index)
//         {
//             min_index = stack->value;
//             *position = current_index;
//         }
//         stack = stack->next;
//         current_index++;
//     }

//     return min_index;
// }

// void move_to_top_optimized(t_list **stack, int position, int size)
// {
//     if (position <= size / 2)
//     {
//         while (position-- > 0)
//             ra(stack);
//     }
//     else
//     {
//         position = size - position;
//         while (position-- > 0)
//             rra(stack);
//     }
// }

// void sort(t_list **stack_a, t_list **stack_b)
// {
//     int position;

//     while (*stack_a)
//     {
//         int min_index = find_min_index(*stack_a, &position);

//         move_to_top_optimized(stack_a, position, ft_listsize(*stack_a));

//         if (*stack_b && (*stack_b)->value > min_index)
//         {
//             move_to_top_optimized(stack_b, 0, ft_listsize(*stack_b));
//             pa(stack_a, stack_b);
//         }
//         else
//         {
//             pb(stack_a, stack_b);
//         }
//     }

//     while (*stack_b)
//     {
//         move_to_top_optimized(stack_b, 0, ft_listsize(*stack_b));
//         pa(stack_a, stack_b);
//     }
// }


// static int	get_max_bits(t_list **stack)
// {
// 	t_list	*head;
// 	int		max;
// 	int		max_bits;

// 	head = *stack;
// 	max = head->index;
// 	max_bits = 0;
// 	while (head)
// 	{
// 		if (head->index > max)
// 			max = head->index;
// 		head = head->next;
// 	}
// 	while ((max >> max_bits) != 0)
// 		max_bits++;
// 	return (max_bits);
// }

// void	sort(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*head_a;
// 	int		i;
// 	int		j;
// 	int		size;
// 	int		max_bits;

// 	i = 0;
// 	head_a = *stack_a;
// 	size = ft_listsize(head_a);
// 	max_bits = get_max_bits(stack_a);
// 	while (i < max_bits)
// 	{
// 		j = 0;
// 		while (j++ < size)
// 		{
// 			head_a = *stack_a;
// 			if (((head_a->index >> i) & 1) == 1)
// 				ra(stack_a);
// 			else
// 				pb(stack_a, stack_b);
// 		}
// 		while (ft_listsize(*stack_b) != 0)
// 			pa(stack_a, stack_b);
// 		i++;
// 	}
// }