/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:21:20 by lprates           #+#    #+#             */
/*   Updated: 2021/09/29 19:49:05 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(int *stack, char *stk)
{
	if (stack[1])
		swap(&stack[0], &stack[1]);
	printf("%s\n", stk);
}

/*
void	swap_stack(int *stack_a)
{
	if (stack_a[1])
		swap(stack_a[0], stack_a[1]);
}*/