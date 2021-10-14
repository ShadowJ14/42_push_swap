/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 22:39:50 by lprates           #+#    #+#             */
/*   Updated: 2021/10/10 19:15:00 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stacks(int argc)
{
	t_stack	*stacks;

	stacks = malloc(sizeof(t_stack));
	if (!stacks)
		exit(-1);
	stacks->size_a = argc - 1;
	stacks->size_b = 0;
	stacks->stack_a = malloc(sizeof(int *) * stacks->size_a);
	stacks->stack_b = malloc(sizeof(int *) * stacks->size_a);
	stacks->sorted = malloc(sizeof(int *) * stacks->size_a);
	if (!stacks->stack_a || !stacks->stack_b || !stacks->sorted)
		exit(-2);
	return (stacks);
}
