/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:39:11 by lprates           #+#    #+#             */
/*   Updated: 2021/10/17 04:14:38 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(int error)
{
	ft_putstr_fd("Error\n", 2);
	exit(error);
}

int	main(int argc, char *argv[])
{
	t_stack	*stacks;
	int		count;

	count = -1;
	stacks = init_stacks(argc);
	if (argc < 2)
		exit(-1);
	while (++count < argc - 1)
	{
		argv++;
		stacks->sorted[count] = pswap_atoi(*argv);
		stacks->stack_a[count] = pswap_atoi(*argv);
	}
	ft_indexing(stacks);
	if (check_sorted(stacks->stack_a, stacks->size_a))
		exit(0);
	sort_picker(stacks);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks->sorted);
	free(stacks);
}
