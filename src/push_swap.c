/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:39:11 by lprates           #+#    #+#             */
/*   Updated: 2021/10/17 06:56:10 by lprates          ###   ########.fr       */
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

void	clean_exit(int code, t_stack *stacks)
{
	if( stacks->stack_a)
		free(stacks->stack_a);
	if (stacks->stack_b)
		free(stacks->stack_b);
	if (stacks->sorted)
		free(stacks->sorted);
	if (stacks)
		free(stacks);
	exit(code);
}

int	main(int argc, char *argv[])
{
	t_stack	*stacks;
	int		count;

	count = -1;
	if (argc < 2)
		exit(1);
	stacks = init_stacks(argc);
	while (++count < argc - 1)
	{
		argv++;
		stacks->sorted[count] = pswap_atoi(*argv, stacks);
		stacks->stack_a[count] = pswap_atoi(*argv, stacks);
	}
	ft_indexing(stacks);
	if (check_sorted(stacks->stack_a, stacks->size_a))
		clean_exit(0, stacks);
	sort_picker(stacks);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks->sorted);
	free(stacks);
}
