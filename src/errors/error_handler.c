/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:42:14 by lprates           #+#    #+#             */
/*   Updated: 2021/10/17 07:50:07 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(int error, t_stack *stacks)
{
	ft_putstr_fd("Error\n", 2);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks->sorted);
	free(stacks);
	exit(error);
}
