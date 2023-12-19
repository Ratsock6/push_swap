/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 01:55:18 by aallou-v          #+#    #+#             */
/*   Updated: 2023/12/02 16:58:29 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_init(t_stack **stack, int size)
{
	int	i;

	i = 4;
	while (i)
	{
		while (ft_sizestack(stack[A]) > size / 5 * i + 4)
		{
			if (ft_firststack(stack[A])->index < size / 5 * (5 - i) + 1)
				push(stack, B);
			else
				rotate(stack, A);
		}
		i--;
	}
	while (ft_sizestack(stack[A]) > 3)
	{
		if (ft_firststack(stack[A])->index != size)
			push(stack, B);
		else
			rotate(stack, A);
	}
}

void	ft_push_init_ultimate(t_stack **stack, int size)
{
	int	i;

	i = 19;
	while (i)
	{
		ft_printf("%i\n", i);
		while (ft_sizestack(stack[A]) > size / 20 * i + 19)
		{
			if (ft_firststack(stack[A])->index < size / 20 * (20 - i) + 1)
				push(stack, B);
			else
				rotate(stack, A);
		}
		i--;
	}
	while (ft_sizestack(stack[A]) > 3)
	{
		if (ft_firststack(stack[A])->index != size)
			push(stack, B);
		else
			rotate(stack, A);
	}
}

static void	ft_repush(t_stack **stack, int size)
{
	while (stack[B])
	{
		stack[B] = ft_firststack(stack[B]);
		if (stack[B]->index < ft_firststack(stack[A])->index
			&& (stack[B]->index > ft_laststack(stack[A])->index
				|| ft_laststack(stack[A])->index == size))
			push(stack, A);
		else
		{
			if (stack[B]->index < ft_firststack(stack[A])->index)
				reverse_rotate(stack, A);
			else
				rotate(stack, A);
		}
	}
	while (ft_firststack(stack[A])->index != 1)
		reverse_rotate(stack, A);
}

void	big_sort(t_stack **stack)
{
	int	size;

	set_index(stack);
	size = ft_sizestack(stack[A]);
	if (size <= 100)
		ft_push_init(stack, size);
	else
		ft_push_init_ultimate(stack, size);
	sort_three(stack);
	ft_repush(stack, size);
}
