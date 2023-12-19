/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 01:01:16 by aallou-v          #+#    #+#             */
/*   Updated: 2023/12/02 16:58:32 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_get_mini(t_stack **stack)
{
	t_stack		*a;
	long long	min;

	a = stack[A];
	min = 2147483648;
	while (a)
	{
		if (a->values < min && a->index == 0)
			min = a->values;
		a = a->next;
	}
	return (min);
}

void	set_index(t_stack	**stack)
{
	long long	l;
	long long	index;
	t_stack		*a;

	l = ft_get_mini(stack);
	index = 1;
	while (l != 2147483648)
	{
		a = ft_firststack(stack[A]);
		while (a)
		{
			if (a->values == l)
			{
				a->index = index;
				break ;
			}
			a = a->next;
		}
		l = ft_get_mini(stack);
		index++;
	}
}
