/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:21:20 by lprates           #+#    #+#             */
/*   Updated: 2021/10/16 14:33:04 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pswap_atoi(const char *str)
{
	long long	ret;
	int			sign;

	ret = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-')
		str++;
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		ret = ret * 10 + (sign * (*(str++) - '0'));
		if (ret > 2147483647)
			error_handler(-2);
		if (ret < -2147483648)
			error_handler(-2);
	}
	if ((*str && ft_isascii(*str)) || (*str && !ft_isdigit(*str)))
		error_handler(-2);
	return (ret);
}

void	swap_handler(t_stack *stacks, char *stk)
{
	if (!ft_strcmp(stk, "ss"))
	{
		swap_stack(stacks->stack_a);
		swap_stack(stacks->stack_b);
	}
	if (!ft_strcmp(stk, "sa"))
		swap_stack(stacks->stack_a);
	if (!ft_strcmp(stk, "sb"))
		swap_stack(stacks->stack_b);
	ft_putstr_fd(stk, 1);
	ft_putstr_fd("\n", 1);
	return ;
}

void	rotate_handler(t_stack *stacks, char *stk)
{
	if (!ft_strcmp(stk, "rr"))
	{
		rotate_stack(stacks->stack_a, stacks->size_a);
		rotate_stack(stacks->stack_b, stacks->size_b);
	}
	if (!ft_strcmp(stk, "ra"))
		rotate_stack(stacks->stack_a, stacks->size_a);
	if (!ft_strcmp(stk, "rb"))
		rotate_stack(stacks->stack_b, stacks->size_b);
	if (!ft_strcmp(stk, "rrr"))
	{
		r_rotate_stack(stacks->stack_a, stacks->size_a);
		r_rotate_stack(stacks->stack_b, stacks->size_b);
	}
	if (!ft_strcmp(stk, "rra"))
		r_rotate_stack(stacks->stack_a, stacks->size_a);
	if (!ft_strcmp(stk, "rrb"))
		r_rotate_stack(stacks->stack_b, stacks->size_b);
	ft_putstr_fd(stk, 1);
	ft_putstr_fd("\n", 1);
	return ;
}

int	check_stack(t_stack *stacks, int current)
{
	int	tmp;

	tmp = stacks->size_b;
	while (tmp-- > 0)
		if (stacks->stack_b[tmp] > current)
			return (1);
	return (0);
}
