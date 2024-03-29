/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:17:20 by mdogadin          #+#    #+#             */
/*   Updated: 2023/12/25 14:01:08 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	create_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
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

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_listsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (1);
	arg_check(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	create_stack(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

/*
void print_stack(t_list **stack) {
	t_list *current = *stack;
	printf("Stack: ");
	while (current != NULL) {
		printf("(%d, %d) ", current->value, current->index);
		current = current->next;
	}
	printf("\n");
}

	print_stack(stack_a);
	print_stack(stack_b);
*/