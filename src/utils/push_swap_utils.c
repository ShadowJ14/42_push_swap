/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:21:20 by lprates           #+#    #+#             */
/*   Updated: 2021/10/17 10:19:33 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	swap_stack(int *stack)
{
	swap(&stack[0], &stack[1]);
	return ;
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

int	pswap_atoi(const char *str, t_stack *stacks)
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
	if (!*str)
		error_handler(-2, stacks);
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (sign * (*(str++) - '0'));
		if (ret > 2147483647 || ret < -2147483648)
			error_handler(-2, stacks);
	}
	if ((*str && ft_isascii(*str)) || (*str && !ft_isdigit(*str)))
		error_handler(-2, stacks);
	return (ret);
}
