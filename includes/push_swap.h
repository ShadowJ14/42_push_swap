/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:41:01 by lprates           #+#    #+#             */
/*   Updated: 2021/09/29 19:48:06 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "../libs/libft/libft.h"

void	swap(int *a, int *b);
void	swap_stack(int *stack, char *stk);

typedef	struct s_swap
{
	int	s_a_size;
}				t_swap;


#endif