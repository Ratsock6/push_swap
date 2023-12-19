/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:48:29 by aallou-v          #+#    #+#             */
/*   Updated: 2023/12/02 16:55:07 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	long long		values;
	long long		index;
}					t_stack;

typedef struct s_error
{
	char	**split;
}					t_error;

enum e_stack
{
	A,
	B,
	BOTH
};

long long	ft_atoll(char *values);
t_stack		*ft_newstack(t_stack *prev, t_stack *next, long long integer);
t_stack		*ft_firststack(t_stack *stack);
t_stack		*ft_laststack(t_stack *stack);
int			ft_sizestack(t_stack *stack);
void		ft_freestack(t_stack *stack);
void		ft_freeall(t_stack **stack, t_error *error);
int			ft_check_sort(t_stack *stack);
void		sort(t_stack **stack);
int			get_min(t_stack **stack, enum e_stack type);
int			get_max(t_stack **stack, enum e_stack type);

/* FONCTION LIST */
void		rotate(t_stack **stack, enum e_stack type);
void		reverse_rotate(t_stack **stack, enum e_stack type);
void		push(t_stack **stack, enum e_stack type);
void		swap(t_stack **stack, enum e_stack type);

/* SORT FONCTION */
void		set_index(t_stack	**stack);
void		big_sort(t_stack **stack);
void		sort_three(t_stack **stack);
void		sort_four(t_stack **stack);
void		sort_five(t_stack **stack);
void		radix_sort(t_stack **stack);

#endif