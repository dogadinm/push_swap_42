/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:58:01 by mdogadin          #+#    #+#             */
/*   Updated: 2023/12/05 15:36:46 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creates new node and returns the pointer of it
t_list	*ft_listnew(int value)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

// Adds the specified node to a stack (list) making it the head
void	ft_listadd_front(t_list **stack, t_list *new)
{
	new->next = *stack;
	*stack = new;
}

// Returns the last node of a list 
t_list	*ft_listlast(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

// Adds the specified node to a stack (list) making it the last node
void	ft_listadd_back(t_list **stack, t_list *new)
{
	t_list	*n;

	if (*stack)
	{
		n = ft_listlast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

// Returns the size of the Linked List
int	ft_listsize(t_list *head)
{
	size_t	i;
	t_list	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
