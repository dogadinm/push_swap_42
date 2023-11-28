/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:17:20 by mdogadin          #+#    #+#             */
/*   Updated: 2023/11/28 12:12:04 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

static void	sort_stack(p_list **stack_a, p_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
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

}