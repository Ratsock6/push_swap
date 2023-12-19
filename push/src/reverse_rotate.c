/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:09:24 by snourry           #+#    #+#             */
/*   Updated: 2023/12/02 16:58:32 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_operator(t_stack **stack, enum e_stack type)
{
	t_stack	*start;
	t_stack	*last;
	t_stack	*tmp;

	last = ft_laststack(stack[type]);
	if (!last->prev)
		return ;
	start = ft_firststack(stack[type]);
	tmp = last;
	last = last->prev;
	last->next = NULL;
	tmp->prev = NULL;
	tmp->next = start;
	start->prev = tmp;
	stack[type] = tmp;
}

void	reverse_rotate(t_stack **stack, enum e_stack type)
{
	if (type == A)
	{
		ft_operator(stack, A);
		ft_putendl_fd("rra", 1);
	}
	else if (type == B)
	{
		ft_operator(stack, B);
		ft_putendl_fd("rrb", 1);
	}
	else if (type == BOTH)
	{
		ft_operator(stack, A);
		ft_operator(stack, B);
		ft_putendl_fd("rrr", 1);
	}
}
