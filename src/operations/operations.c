/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 22:47:13 by lprates           #+#    #+#             */
/*   Updated: 2021/10/16 17:01:52 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(int *stack)
{
	swap(&stack[0], &stack[1]);
	return ;
}

void	rotate_stack(int *stack, int size)
{
	int	tmp;
	int	count;

	count = -1;
	tmp = stack[0];
	while (++count < size - 1)
		stack[count] = stack[count + 1];
	stack[count] = tmp;
}

void	r_rotate_stack(int *stack, int size)
{
	int	tmp;
	int	count;

	tmp = stack[size - 1];
	count = size;
	while (--count > 0)
		stack[count] = stack[count - 1];
	stack[0] = tmp;
}

void	push_top_stacks(int *from, int *to, int *fsize, int *tsize)
{
	int	tmp;
	int	i;

	tmp = ++(*fsize);
	while (--tmp > 0)
		from[tmp] = from[tmp - 1];
	from[0] = to[0];
	tmp = *tsize;
	i = -1;
	while (++i < tmp)
		to[i] = to[i + 1];
	(*tsize)--;
}

void	push_top(t_stack *stacks, char *stk)
{
	if (!ft_strcmp(stk, "pa"))
		push_top_stacks(stacks->stack_a, stacks->stack_b,
			&stacks->size_a, &stacks->size_b);
	if (!ft_strcmp(stk, "pb"))
		push_top_stacks(stacks->stack_b, stacks->stack_a,
			&stacks->size_b, &stacks->size_a);
	ft_putstr_fd(stk, 1);
	ft_putstr_fd("\n", 1);
}
