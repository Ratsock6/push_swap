/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:18:02 by aallou-v          #+#    #+#             */
/*   Updated: 2023/12/02 16:58:32 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	if (stack[A]->values > stack[A]->next->values)
		swap(stack, A);
	if (stack[A]->next->next->values != get_max(stack, A))
		reverse_rotate(stack, A);
	if (stack[A]->values > stack[A]->next->values)
		swap(stack, A);
}

void	sort_four(t_stack **stack)
{
	while (ft_firststack(stack[A])->values != get_min(stack, A))
		rotate(stack, A);
	push(stack, B);
	sort_three(stack);
	push(stack, A);
}

void	sort_five(t_stack **stack)
{
	while (ft_firststack(stack[A])->index > 2)
		rotate(stack, A);
	push(stack, B);
	sort_four(stack);
	push(stack, A);
	if (stack[A]->values > stack[A]->next->values)
		swap(stack, A);
}

void	sort(t_stack **stack)
{
	int	size;

	size = ft_sizestack(stack[A]);
	if (size == 2)
		swap(stack, A);
	if (size == 3)
		sort_three(stack);
	if (size == 4)
		sort_four(stack);
	set_index(stack);
	if (size == 5)
		sort_five(stack);
	if (size > 5)
		radix_sort(stack);
}
