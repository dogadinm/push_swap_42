/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:23:37 by mdogadin          #+#    #+#             */
/*   Updated: 2023/11/29 15:58:16 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int get_max_bits(p_list **stack)
// {
//     p_list *head;
//     int max;
//     int max_bits;

//     head = *stack;
//     max = head->index;
//     max_bits = 0;

//     while (head)
//     {
//         if (head->index > max)
//             max = head->index;
//         head = head->next;
//     }

//     while (max != 0)
//     {
//         max /= 2;
//         max_bits++;
//     }

//     return max_bits;
// }

// void radix_sort(p_list **stack_a, p_list **stack_b)
// {
//     p_list *head_a;
//     int i;
//     int j;
//     int size;
//     int max_bits;

//     i = 0;
//     head_a = *stack_a;
//     size = ft_listsize(head_a);
//     max_bits = get_max_bits(stack_a);

//     while (i < max_bits)
//     {
//         j = 0;
//         while (j++ < size)
//         {
//             head_a = *stack_a;
//             if ((head_a->index / (10 * i + 1)) % 2 == 1)
//                 ra(stack_a);
//             else
//                 pb(stack_a, stack_b);
//         }

//         while (ft_listsize(*stack_b) != 0)
//             pa(stack_a, stack_b);

//         i++;
//     }
// }
#include <stdio.h>
#include <stdlib.h>

#define RADIX 10

void radix_sort(p_list **stack_a, p_list **stack_b)
{
    int max_digits = find_max_digits(*stack_a);
    int divisor = 1;

    for (int i = 1; i <= max_digits; i++, divisor *= RADIX)
    {
        while (*stack_a != NULL)
        {
            int index = ((*stack_a)->value / divisor) % RADIX;
            while ((*stack_a)->index != index)
            {
                if ((*stack_a)->index > index)
                    apply_operation(stack_a, stack_b, "rra");
                else
                    apply_operation(stack_a, stack_b, "ra");
            }
            apply_operation(stack_a, stack_b, "pb");
        }

        while (*stack_b != NULL)
            apply_operation(stack_a, stack_b, "pa");
    }
}

void apply_operation(p_list **stack_a, p_list **stack_b, const char *operation)
{
    if (strcmp(operation, "sa") == 0)
    {
        // Swap the first 2 elements at the top of stack a.
        // Do nothing if there is only one or no elements.
        // Implementation of sa move...
    }
    else if (strcmp(operation, "sb") == 0)
    {
        // Swap the first 2 elements at the top of stack b.
        // Do nothing if there is only one or no elements.
        // Implementation of sb move...
    }
    else if (strcmp(operation, "ss") == 0)
    {
        // sa and sb at the same time.
        apply_operation(stack_a, stack_b, "sa");
        apply_operation(stack_a, stack_b, "sb");
    }
    else if (strcmp(operation, "pa") == 0)
    {
        // Take the first element at the top of b and put it at the top of a.
        // Do nothing if b is empty.
        if (*stack_b != NULL)
        {
            p_list *temp = *stack_b;
            *stack_b = (*stack_b)->next;

            temp->next = *stack_a;
            *stack_a = temp;
        }
    }
    else if (strcmp(operation, "pb") == 0)
    {
        // Take the first element at the top of a and put it at the top of b.
        // Do nothing if a is empty.
        if (*stack_a != NULL)
        {
            p_list *temp = *stack_a;
            *stack_a = (*stack_a)->next;

            temp->next = *stack_b;
            *stack_b = temp;
        }
    }
    else if (strcmp(operation, "ra") == 0)
    {
        // Shift up all elements of stack a by 1.
        // The first element becomes the last one.
        // Implementation of ra move...
    }
    // Add implementations for other moves (sb, rr, rra, rrb, rrr) similarly
}


