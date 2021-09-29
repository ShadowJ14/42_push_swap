/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:39:11 by lprates           #+#    #+#             */
/*   Updated: 2021/09/29 19:56:41 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;
	static int count = 0;

	temp = *a;
	*a = *b;
	*b = temp;
	printf("sa\n");
	printf("%i\n", ++count);
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
	int	stack_a[argc - 1];
	//int	stack_b[argc - 1];
	int count;
	int tmp;

	count = -1;
	tmp = 0;
	if (argc < 2)
		error_handler(-1);
	while(*argv)
		stack_a[count++] = ft_atoi(*argv++);
	quicksort(0, count - 1, stack_a);
	//swap_stack(stack_a, "sa");
	while(tmp < count)
		printf("Aqui: %i\n", stack_a[tmp++]);

	//printf("%i\n", argc);
}