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
	int size;
	//int max_num;
	//int max_bits;
	int	num;
	size = stacks->size_a;
	//max_num = size - 1;
	//max_bits = 0;
	//while ((max_num >> max_bits) != 0)
	//	++max_bits;
	for (int i = 0 ; !check_sorted(stacks) ; ++i) // repeat for max_bits times
	{
    	for(int j = 0 ; j < size ; ++j)
    	{
        	num = stacks->stack_a[0]; // top number of A
			if ((num >> i)&1)
				rotate_handler(stacks, "ra");
			// if the (i + 1)-th bit is 1, leave in stack a
			else
				push_top(stacks, "pb");
        	// otherwise push to stack b
    	}
    // put into boxes done
    	while (stacks->size_b != 0)
			push_top(stacks, "pa"); // while stack b is not empty, do pa
    // connect numbers done
	}
}

void	swap(int *a, int *b)
{
	int	temp;
	//static int count = 0;

	temp = *a;
	*a = *b;
	*b = temp;
	//printf("%i\n", ++count);
}

void	error_handler(int error)
{
	ft_putstr_fd("Error\n", 2);
	//printf("%s\n", "Error");
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
		exit(-1);
	while(++count < argc - 1)
	{
		argv++;
		stacks->sorted[count] = pswap_atoi(*argv);
		stacks->stack_a[count] = pswap_atoi(*argv);
	}
	if (check_sorted(stacks))
		exit(0);
	//count = 0;
	//while(++count < argc - 1)
	ft_indexing(stacks);
	//sorting_test(stacks);
	//rotate_handler(stacks, "rrb");
	big_sort(stacks);
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

	//printf("%i\n", argc);
}
