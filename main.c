/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:17:20 by mdogadin          #+#    #+#             */
/*   Updated: 2023/11/29 12:51:13 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
static void	create_stack(p_list **stack, int argc, char **argv)
{
	p_list	*new;
	char	**args;
	int		i;

	i = 0;
	
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_listnew(ft_atoi(args[i]));
		ft_listadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

static void	sort_stack(p_list **stack_a, p_list **stack_b)
{
	if (ft_listsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

void print_stack(p_list **stack) {
    p_list *current = *stack;
    printf("Stack: ");
    while (current != NULL) {
        printf("(%d, %d) ", current->value, current->index);
        current = current->next;
    }
    printf("\n");
}

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
	create_stack(stack_a, argc, argv);
	// print_stack(stack_a);
    // print_stack(stack_b);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	print_stack(stack_a);
    print_stack(stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);



}