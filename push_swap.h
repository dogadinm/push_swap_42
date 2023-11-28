/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:06:11 by mdogadin          #+#    #+#             */
/*   Updated: 2023/11/28 13:11:58 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
// Stack
typedef struct n_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	p_list;


void arg_check(int argc , char **argv);
void	ft_error(char *msg);
void	ft_free(char **str);
void	index_stack(p_list **stack);
#endif