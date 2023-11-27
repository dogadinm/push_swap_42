/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:17:20 by mdogadin          #+#    #+#             */
/*   Updated: 2023/11/27 12:27:52 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    p_list **stack_a;
    p_list **stack_b;

    if (argc < 2)
        return(1);
    arg_check(argc, argv);
    stack_a = (p_list **)malloc(sizeof(p_list));
	stack_b = (p_list **)malloc(sizeof(p_list));
    *stack_a = NULL;
	*stack_b = NULL;
}