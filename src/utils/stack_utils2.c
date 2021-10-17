/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 04:14:06 by lprates           #+#    #+#             */
/*   Updated: 2021/10/17 04:14:35 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_max(int *array, size_t len)
{
	int	m;

	if (len == 1)
		return (array[0]);
	m = _max(array, len - 1);
	if (array[len - 1] > m)
		m = array[len - 1];
	return (m);
}

int	max(t_stack *stacks)
{
	return (_max(stacks->stack_a, stacks->size_a));
}

static int	_min(int *array, size_t len)
{
	int	m;

	if (len == 1)
		return (array[0]);
	m = _min(array, len - 1);
	if (array[len - 1] < m)
		m = array[len - 1];
	return (m);
}

int	min(t_stack *stacks)
{
	return (_min(stacks->stack_a, stacks->size_a));
}
