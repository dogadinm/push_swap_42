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

static int max_value(p_list **stack)
{
    p_list *head;
    int max;
    // int max_bits;

    head = *stack;
    max = head->index;
    // max_bits = 0;

    while (head)
    {
        if (head->index > max)
            max = head->index;
        head = head->next;
    }

    // while (max != 0)
    // {
    //     max /= 2;
    //     max_bits++;
    // }

    return max;
}

unsigned int compute_power_of_two(int exponent) {
    unsigned int result = 1;
    int i;

    i = 0;
    while (i < exponent)
    {
       result *= 2;
       i++;
    }
    return result;
}

void radix_sort(p_list **stack_a, p_list **stack_b)
{
    p_list *head_a;
    int i;
    int j;
    int size;
    int max_bits;

    i = 0;
    head_a = *stack_a;
    size = ft_listsize(head_a);
    max_bits = max_value(stack_a);

    while (i < max_bits)
    {
        j = 0;
        while (j++ < size)
        {
            head_a = *stack_a;
            if (((head_a->index / compute_power_of_two(i)) % 2) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
        }

        while (ft_listsize(*stack_b) != 0)
            pa(stack_a, stack_b);

        i++;
    }
}