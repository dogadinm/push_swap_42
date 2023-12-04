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

    // int max_bits;
    // max_bits = 0;
    // while (max != 0)
    // {
    //     max /= 2;
    //     max_bits++;
    // }


// static int max_value(p_list **stack)
// {
//     p_list *head;
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

// void radix_sort(p_list **stack_a, p_list **stack_b)
// {
//     p_list *head_a;
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

void radix_sort(p_list** stack_a, p_list** stack_b) {
    while (*stack_a) {
        // Найти минимальный элемент в stack_a
        int min_value = 2147483647;
        p_list* min_element = NULL;
        p_list* current = *stack_a;

        while (current) {
            if (current->index < min_value) {
                min_value = current->index;
                min_element = current;
            }
            current = current->next;
        }

        // Перенести минимальный элемент в stack_b
        while (*stack_a != min_element) {
            ra(stack_a);
        }
        pb(stack_a, stack_b);
    }

    // Восстановление порядка в stack_a
    while (*stack_b) {
        // Найти максимальный элемент в stack_b
        int max_value = -2147483647;
        p_list* max_element = NULL;
        p_list* current = *stack_b;

        while (current) {
            if (current->value > max_value) {
                max_value = current->value;
                max_element = current;
            }
            current = current->next;
        }

        // Перенести максимальный элемент в stack_a
        while (*stack_b != max_element) {
            rra(stack_b);
        }
        pa(stack_a, stack_b);
    }
}