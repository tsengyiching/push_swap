/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:11:38 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 19:15:11 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	second_party(int position, t_stack **stack_a, t_stack **stack_b)
{
	if (position == 2)
	{
		if (!(op_rotate_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
		if (!(op_push_a(stack_a, stack_b)))
			free_malloc_fail(stack_a, stack_b);
		op_swap_a(*stack_a);
		if (!(op_reverse_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
	}
	else if (position == 3 || position == 4)
	{
		if (!(op_push_a(stack_a, stack_b)))
			free_malloc_fail(stack_a, stack_b);
		if (!(op_rotate_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
	}
	else
		return (0);
	return (1);
}

int	first_party(int position, int size_a, t_stack **stack_a, t_stack **stack_b)
{
	if (position == 0)
	{
		if (!(op_push_a(stack_a, stack_b)))
			free_malloc_fail(stack_a, stack_b);
	}
	else if (position == 1)
	{
		if (!(op_push_a(stack_a, stack_b)))
			free_malloc_fail(stack_a, stack_b);
		op_swap_a(*stack_a);
	}
	else if ((position == 2 && size_a == 3) || (position == 3 && size_a == 4))
	{
		if (!(op_reverse_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
		if (!(op_push_a(stack_a, stack_b)))
			free_malloc_fail(stack_a, stack_b);
		if (!(op_rotate_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
		if (!(op_rotate_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
	}
	else
		return (0);
	return (1);
}

int	find_position(t_stack *stack_a, t_stack *stack_b)
{
	int		position;

	position = 0;
	while (stack_a)
	{
		if (stack_b->content > stack_a->content)
			position++;
		stack_a = stack_a->next;
	}
	return (position);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		position;
	int		size_a;

	i = 0;
	while (ft_list_size(*stack_a) > 3)
	{
		if (!(op_push_b(stack_a, stack_b)))
			free_malloc_fail(stack_a, stack_b);
		i++;
	}
	sort_three(stack_a, stack_b);
	while (i > 0)
	{
		size_a = ft_list_size(*stack_a);
		position = find_position(*stack_a, *stack_b);
		if (!first_party(position, size_a, stack_a, stack_b))
			second_party(position, stack_a, stack_b);
		i--;
	}
}
