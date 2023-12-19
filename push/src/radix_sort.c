/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:31:11 by aallou-v          #+#    #+#             */
/*   Updated: 2023/12/02 16:58:32 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = ft_firststack(stack[A]);
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = ft_firststack(stack[A]);
	size = ft_sizestack(stack[A]);
	max_bits = get_max_bits(stack);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = ft_firststack(stack[A]);
			if (((head_a->index >> i) & 1) == 1)
				rotate(stack, A);
			else
				push(stack, B);
		}
		while (ft_sizestack(stack[B]) != 0)
			push(stack, A);
		i++;
	}
}
