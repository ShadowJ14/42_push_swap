/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:41:01 by lprates           #+#    #+#             */
/*   Updated: 2021/10/17 10:30:10 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "../libs/libft/libft.h"

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	*sorted;
	int	size_a;
	int	size_b;
}				t_stack;

// push_swap.c
void	clean_exit(int code, t_stack *stacks);

// error_handler.c
void	error_handler(int error, t_stack *stacks);

// init.c
t_stack	*init_stacks(int argc);

// operations.c
void	rotate_handler(t_stack *stacks, char *stk);
void	push_top(t_stack *stacks, char *stk);

// operations2.c
void	sort_picker(t_stack *stacks);

// push_swap_utils.c
void	swap(int *a, int *b);
void	swap_handler(t_stack *stacks, char *stk);
int		pswap_atoi(const char *str, t_stack *stacks);

// push_swap_utils2.c
void	quicksort(int start, int end, int *a);
int		check_sorted(int *stack, int size);
void	ft_indexing(t_stack *stacks);

// stack_utils.c
void	smart_rotate(t_stack *stacks, int n);
void	put_top_in_position(t_stack *stacks);

// stack_utils2.c
int		max(t_stack *stack);
int		min(t_stack *stacks);

#endif
