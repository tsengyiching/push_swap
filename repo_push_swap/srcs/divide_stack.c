/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:51:38 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 15:51:39 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_smaller_value_exist(t_stack *stack_a, int value)
{
	int	pos;

	pos = 0;
	while (stack_a)
	{
		if (stack_a->content <= value)
			return (pos);
		stack_a = stack_a->next;
		pos++;
	}
	return (-1);
}

int	is_middle_value_exist(t_stack *stack_a, int min, int max)
{
	int	pos;

	pos = 0;
	while (stack_a)
	{
		if (stack_a->content > min && stack_a->content <= max)
			return (pos);
		stack_a = stack_a->next;
		pos++;
	}
	return (-1);
}

int	is_bigger_value_exist(t_stack *stack_a, int value)
{
	int	pos;

	pos = 0;
	while (stack_a)
	{
		if (stack_a->content > value)
			return (pos);
		stack_a = stack_a->next;
		pos++;
	}
	return (-1);
}

void	divide_stack(t_stack **stack_a, t_stack **stack_b, int pos)
{
	if (pos == -1)
		return ;
	while (pos > 0)
	{
		if (!(op_rotate_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
		pos--;
	}
	if (!(op_push_b(stack_a, stack_b)))
		free_malloc_fail(stack_a, stack_b);
}
