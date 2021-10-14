/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:39:11 by lprates           #+#    #+#             */
/*   Updated: 2021/10/10 21:09:05 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack *stacks)
{
	int	size;
	int	num;
	int	i;
	int	j;

	size = stacks->size_a;
	i = -1;
	while (!check_sorted(stacks))
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

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	error_handler(int error)
{
	ft_putstr_fd("Error\n", 2);
	exit(error);
}

int	main(int argc, char *argv[])
{
	t_stack	*stacks;
	int		count;
	//int tmp;

	//tmp = 0;
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
	if (check_sorted(stacks))
		exit(0);
	ft_indexing(stacks);
	big_sort(stacks);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks->sorted);
	free(stacks);
	/*while(tmp < stacks->size_a || tmp < stacks->size_b)
	{
		if (tmp < stacks->size_a)
			printf("%i", stacks->stack_a[tmp]);
		else
			printf(" ");
		if (tmp < stacks->size_a)
			printf(" %i\n", stacks->sorted[tmp]);
		else
			printf("\n");
		tmp++;
	}
	printf("_ _\na b\n");*/
}
