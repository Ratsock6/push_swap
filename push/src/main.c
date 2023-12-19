/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:54:43 by aallou-v          #+#    #+#             */
/*   Updated: 2023/12/02 16:58:32 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init2(char **split)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = NULL;
	while (split[i])
	{
		stack = ft_newstack(stack, NULL, ft_atoll(split[i]));
		if (stack->prev)
			stack->prev->next = stack;
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	stack = ft_firststack(stack);
	return (stack);
}

t_stack	*init(char **argv)
{
	char	*all;
	char	*tmp;
	char	**split;
	int		i;

	i = 0;
	all = ft_strdup("");
	while (argv[++i])
	{
		tmp = ft_strjoin(all, argv[i]);
		free(all);
		all = ft_strjoin(tmp, " ");
		free(tmp);
	}
	split = ft_split(all, ' ');
	free(all);
	return (init2(split));
}

char	*check_error2(char **argv)
{
	int			i;
	int			j;
	long long	values;
	long long	values2;

	i = -1;
	while (argv[++i])
	{
		if (ft_isonly(argv[i], "-"))
			return ("Value impossible to sort (Multiple \"-\")");
		values = ft_atoll(argv[i]);
		if (values > 2147483647 || values < -2147483648)
			return ("There is a number too big or too small");
		j = -1;
		while (argv[++j])
		{
			if (i == j)
				continue ;
			values2 = ft_atoll(argv[j]);
			if (values == values2)
				return ("There are duplicate values");
		}
	}
	return (NULL);
}

char	*check_error(char **argv, t_error *error)
{
	char	*all;
	char	*tmp;
	int		i;

	i = 0;
	all = ft_strdup("");
	while (argv[++i])
	{
		tmp = ft_strjoin(all, argv[i]);
		free(all);
		all = ft_strjoin(tmp, " ");
		free(tmp);
	}
	if (!ft_isonly(all, "-0123456789 "))
		return ("Arguments must be numbers only");
	error->split = ft_split(all, ' ');
	free(all);
	return (check_error2(error->split));
}

int	main(int argc, char **argv)
{
	t_stack	**stack;
	t_error	*struct_error;
	char	*error;

	if (argc == 1)
		return (1);
	stack = ft_calloc(2, sizeof(t_stack *));
	struct_error = malloc(sizeof(t_error));
	error = check_error(argv, struct_error);
	if (error)
	{
		ft_freeall(stack, struct_error);
		ft_printf("Error\n%s\n", error);
		return (1);
	}
	stack[A] = init(argv);
	stack[B] = NULL;
	if (ft_check_sort(stack[A]))
		return (ft_freeall(stack, struct_error), 0);
	sort(stack);
	ft_freeall(stack, struct_error);
	return (0);
}
