/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:39:11 by lprates           #+#    #+#             */
/*   Updated: 2021/10/03 02:28:16 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;
	//static int count = 0;

	temp = *a;
	*a = *b;
	*b = temp;
	//printf("%i\n", ++count);
}

void	quicksort(int start, int end, int *a)
{
	int	key;
	int	i;
	int	j;
	//int temp;

	key = start;
	i = start + 1;
	j = end;
	if (start >= end)
		return ;
	while(i <= j)
	{
		while(i <= end && a[i] <= a[key])
			i++;
		while(j > start && a[j]>= a[key])
			j--;
		if (i > j)
			swap(&a[key], &a[j]);
		else
			swap(&a[i], &a[j]);
	}
	quicksort(start, j - 1, a);
	quicksort(j + 1, end, a);
}

void	error_handler(int error)
{
	printf("%s\n", "Error");
	exit(error);
}

int	main(int argc, char *argv[])
{
	t_stack *stacks;
	int count;
	int tmp;

	count = -1;
	tmp = 0;
	stacks = init_stacks(argc);
	if (argc < 2)
		error_handler(-1);
	while(++count < argc - 1)
		stacks->stack_a[count] = ft_atoi(*++argv);
	//quicksort(0, count - 1, stacks->stack_a);
	sorting_test(stacks);
	rotate_handler(stacks, "rrb");
	while(tmp < stacks->size_a || tmp < stacks->size_b)
	{
		if (tmp < stacks->size_a)
			printf("%i", stacks->stack_a[tmp]);
		else
			printf(" ");
		if (tmp < stacks->size_b)
			printf(" %i\n", stacks->stack_b[tmp]);
		else
			printf("\n");
		tmp++;
	}
	printf("_ _\na b\n");

	//printf("%i\n", argc);
}
