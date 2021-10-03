/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 22:47:13 by lprates           #+#    #+#             */
/*   Updated: 2021/10/03 02:10:31 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(int *stack)
{
	if (stack[1])
		swap(&stack[0], &stack[1]);
	return ;
}

void	rotate_stack(int *stack, int size)
{
	int	tmp;
	int	count;

	count = -1;
	tmp = stack[0];
	while(++count < size - 1)
		stack[count] = stack[count + 1];
	stack[count] = tmp;
}

void	r_rotate_stack(int *stack, int size)
{
	int	tmp;
	int	count;

	tmp = stack[size - 1];
	count = size;
	while(--count > 0)
		stack[count] = stack[count - 1];
	stack[0] = tmp;
}

void	push_top(t_stack *stacks, char *stk)
{
	int	tmp;
	int i;

	if (!ft_strcmp(stk, "pa"))
	{
		tmp = ++stacks->size_a;
		while(--tmp > 0)
			stacks->stack_a[tmp] = stacks->stack_a[tmp - 1];
		stacks->stack_a[0] = stacks->stack_b[0];
		tmp = stacks->size_b;
		i = -1;
		while(++i < tmp)
			stacks->stack_b[i] = stacks->stack_b[i + 1];
		stacks->size_b--;
	}
	if (!ft_strcmp(stk, "pb"))
	{
		tmp = ++stacks->size_b;
		while(--tmp > 0)
			stacks->stack_b[tmp] = stacks->stack_b[tmp - 1];
		stacks->stack_b[0] = stacks->stack_a[0];
		tmp = stacks->size_a;
		i = -1;
		while(++i < tmp)
			stacks->stack_a[i] = stacks->stack_a[i + 1];
		stacks->size_a--;
	}
	ft_putstr_fd(stk, 1);
	ft_putstr_fd("\n", 1);
}
