/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:40:58 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 17:40:59 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_swap(t_stack *stack)
{
	int		size;
	int		tmp;

	size = ft_list_size(stack);
	if (size == 1 || size == 0)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

void	op_swap_a(t_stack *stack_a)
{
	op_swap(stack_a);
	write(1, "sa\n", 3);
}

void	op_swap_b(t_stack *stack_b)
{
	op_swap(stack_b);
	write(1, "sb\n", 3);
}

void	op_swap_all(t_stack *stack_a, t_stack *stack_b)
{
	op_swap(stack_a);
	op_swap(stack_b);
	write(1, "ss\n", 3);
}
