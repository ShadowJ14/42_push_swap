/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:06:19 by lprates           #+#    #+#             */
/*   Updated: 2021/10/16 15:07:07 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort(int start, int end, int *a)
{
	int	key;
	int	i;
	int	j;

	key = start;
	i = start + 1;
	j = end;
	if (start >= end)
		return ;
	while (i <= j)
	{
		while (i <= end && a[i] <= a[key])
			i++;
		while (j > start && a[j] >= a[key])
			j--;
		if (i > j)
			swap(&a[key], &a[j]);
		else
			swap(&a[i], &a[j]);
	}
	quicksort(start, j - 1, a);
	quicksort(j + 1, end, a);
}

int	check_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (++i < size)
		if (stack[i - 1] > stack[i])
			return (0);
	return (1);
}

void	check_repetition(t_stack *stacks)
{
	int	i;

	i = 0;
	while (++i < stacks->size_a)
		if (stacks->sorted[i - 1] == stacks->sorted[i])
			error_handler(-3);
	return ;
}

void	ft_indexing(t_stack *stacks)
{
	int	i;
	int	j;

	i = -1;
	quicksort(0, stacks->size_a - 1, stacks->sorted);
	check_repetition(stacks);
	while (++i < stacks->size_a)
	{
		j = -1;
		while (++j < stacks->size_a)
		{
			if (stacks->stack_a[i] == stacks->sorted[j])
			{
				stacks->stack_a[i] = j;
				break ;
			}
		}
	}
}

void	sort_picker(t_stack *stacks)
{
	if (stacks->size_a <= 5)
		small_sort(stacks);
	else
		big_sort(stacks);
}
