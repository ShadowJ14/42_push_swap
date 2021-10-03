/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:41:01 by lprates           #+#    #+#             */
/*   Updated: 2021/10/03 02:08:11 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "../libs/libft/libft.h"

typedef	struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}				t_stack;

void	swap(int *a, int *b);
void	swap_stack(int *stack);
void	swap_handler(t_stack *stacks, char *stk);
void	rotate_stack(int *stack, int size);
void	r_rotate_stack(int *stack, int size);
void	rotate_handler(t_stack *stacks, char *stk);
void	push_top(t_stack *stacks, char *stk);
//void	push_handler(t_stack *stacks, char *stk);
t_stack	*init_stacks(int argc);
void	sorting_test(t_stack *stacks);

#endif
