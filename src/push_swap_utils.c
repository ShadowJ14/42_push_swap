/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:21:20 by lprates           #+#    #+#             */
/*   Updated: 2021/10/03 02:21:41 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_handler(t_stack *stacks, char *stk)
{
	if (!ft_strcmp(stk, "ss"))
	{
		swap_stack(stacks->stack_a);
		swap_stack(stacks->stack_b);
	}
	if (!ft_strcmp(stk, "sa"))
		swap_stack(stacks->stack_a);
	if (!ft_strcmp(stk, "sb"))
		swap_stack(stacks->stack_b);
	ft_putstr_fd(stk, 1);
	ft_putstr_fd("\n", 1);
	return ;
}

void	rotate_handler(t_stack *stacks, char *stk)
{
	if (!ft_strcmp(stk, "rr"))
	{
		rotate_stack(stacks->stack_a, stacks->size_a);
		rotate_stack(stacks->stack_b, stacks->size_b);
	}
	if (!ft_strcmp(stk, "ra"))
		rotate_stack(stacks->stack_a, stacks->size_a);
	if (!ft_strcmp(stk, "rb"))
		rotate_stack(stacks->stack_b, stacks->size_b);
	if (!ft_strcmp(stk, "rrr"))
	{
		r_rotate_stack(stacks->stack_a, stacks->size_a);
		r_rotate_stack(stacks->stack_b, stacks->size_b);
	}
	if (!ft_strcmp(stk, "rra"))
		r_rotate_stack(stacks->stack_a, stacks->size_a);
	if (!ft_strcmp(stk, "rrb"))
		r_rotate_stack(stacks->stack_b, stacks->size_b);
	ft_putstr_fd(stk, 1);
	ft_putstr_fd("\n", 1);
	return ;
}

int	check_stack(t_stack *stacks, int current)
{
	int	tmp;
	
	tmp = stacks->size_b;
	while (tmp-- > 0)
		if (stacks->stack_b[tmp] > current)
			return (1);
	return (0);
}

void	sorting_test(t_stack *stacks)
{
	int	i;
	int	tmp;
	int	j;

	i = -1;
	tmp = 0;
	j = stacks->size_b;
	while(++i < stacks->size_a)
		if (tmp < stacks->stack_a[i])
			tmp = stacks->stack_a[i];
	tmp /= 2;
	while(--i > 0)
	{
		if (tmp > stacks->stack_a[0])
		{
			if (check_stack(stacks, stacks->stack_a[0]))
				while (stacks->stack_a[0] > stacks->stack_b[0] && j--)
					rotate_handler(stacks, "rb");
			push_top(stacks, "pb");
		}
		else
			rotate_handler(stacks, "ra");
		j = stacks->size_b;
	}
}
