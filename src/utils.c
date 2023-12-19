/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:28:27 by aallou-v          #+#    #+#             */
/*   Updated: 2023/12/02 16:58:32 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(char *values)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	while (*values == ' ' || (*values >= '\t' && *values <= '\r'))
		values++;
	if (*values == '+' || *values == '-')
		if (*values++ == '-')
			sign *= -1;
	values--;
	while (*++values >= '0' && *values <= '9')
	{
		if (result == 0)
			result = *values - 48;
		else
			result = result * 10 + (*values - 48);
	}
	return (result * sign);
}

void	ft_freeall(t_stack **stack, t_error *error)
{
	int	i;

	if (stack[A])
		ft_freestack(stack[A]);
	if (stack[B])
		ft_freestack(stack[B]);
	free(stack);
	i = -1;
	if (error->split)
	{
		while (error->split[++i])
			free(error->split[i]);
		free(error->split);
	}
	free(error);
	stack = NULL;
}

int	ft_check_sort(t_stack *stack)
{
	stack = ft_firststack(stack);
	stack = stack->next;
	while (stack)
	{
		if (stack->values < stack->prev->values)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_min(t_stack **stack, enum e_stack type)
{
	t_stack	*a;
	int		min;

	a = stack[type];
	min = a->values;
	while (a)
	{
		if (a->values < min)
			min = a->values;
		a = a->next;
	}
	return (min);
}

int	get_max(t_stack **stack, enum e_stack type)
{
	t_stack	*a;
	int		max;

	a = stack[type];
	max = a->values;
	while (a)
	{
		if (a->values > max)
			max = a->values;
		a = a->next;
	}
	return (max);
}
