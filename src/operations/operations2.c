/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:12:49 by lprates           #+#    #+#             */
/*   Updated: 2021/10/17 06:14:31 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	trinity_sort(t_stack *stacks)
{
	int	*arr;

	arr = stacks->stack_a;
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		swap_handler(stacks, "sa");
	else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		swap_handler(stacks, "sa");
		rotate_handler(stacks, "rra");
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		rotate_handler(stacks, "ra");
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
	{
		swap_handler(stacks, "sa");
		rotate_handler(stacks, "ra");
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
		rotate_handler(stacks, "rra");
}

static void	four_five_sort(t_stack *stacks)
{
	int	cnt;

	cnt = 0;
	while (stacks->size_a != 3)
		push_top(stacks, "pb");
	trinity_sort(stacks);
	while (stacks->size_b > 0)
		put_top_in_position(stacks);
	smart_rotate(stacks, 0);
}

void	big_sort(t_stack *stacks)
{
	int	size;
	int	num;
	int	i;
	int	j;

	size = stacks->size_a;
	i = -1;
	while (!check_sorted(stacks->stack_a, stacks->size_a))
	{
		++i;
		j = -1;
		while (++j < size)
		{
			num = stacks->stack_a[0];
			if ((num >> i) & 1)
				rotate_handler(stacks, "ra");
			else
				push_top(stacks, "pb");
		}
		while (stacks->size_b != 0)
			push_top(stacks, "pa");
	}
}

void	small_sort(t_stack *stacks)
{
	if (stacks->size_a == 2)
		swap_handler(stacks, "sa");
	else if (stacks->size_a == 3)
		trinity_sort(stacks);
	else
		four_five_sort(stacks);
}
