/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:05:37 by lprates           #+#    #+#             */
/*   Updated: 2021/10/17 10:23:21 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	closest_above(t_stack *stacks, int n)
{
	int	k;
	int	i;

	if (stacks->size_a == 0 || n > max(stacks))
		return (n);
	i = 0;
	k = max(stacks);
	while (i < stacks->size_a)
	{
		if (stacks->stack_a[i] > n && stacks->stack_a[i] < k)
			k = stacks->stack_a[i];
		i++;
	}
	return (k);
}

static void	run_n(char *op, t_stack *stacks, int n)
{
	if (n <= 0)
		return ;
	rotate_handler(stacks, op);
	run_n(op, stacks, n - 1);
}

void	smart_rotate(t_stack *stacks, int n)
{
	int	find;
	int	top;

	find = stacks->size_a - 1;
	top = stacks->size_a - 1;
	while (find >= 0 && stacks->stack_a[top - find] != n)
		find--;
	if (find < 0)
		return ;
	else if (find < top / 2)
		run_n("rra", stacks, find + 1);
	else
		run_n("ra", stacks, top - find);
}

void	put_top_in_position(t_stack *stacks)
{
	int	top_b;
	int	to_move;

	top_b = stacks->stack_b[0];
	to_move = closest_above(stacks, top_b);
	if (to_move == top_b)
		to_move = min(stacks);
	smart_rotate(stacks, to_move);
	push_top(stacks, "pa");
}
