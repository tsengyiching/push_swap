/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:30:09 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 16:30:11 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_max_top(t_stack **stack_a, t_stack **stack_b, t_index *index)
{
	while (index->top_max_pos > 0)
	{
		if (!(op_rotate_b(stack_b)))
			free_malloc_fail(stack_a, stack_b);
		index->top_max_pos--;
	}
	if (!(op_push_a(stack_a, stack_b)))
		free_malloc_fail(stack_a, stack_b);
}

void	do_max_bottom(t_stack **stack_a, t_stack **stack_b, t_index *index)
{
	while (index->bottom_max_pos > -1)
	{
		if (!(op_reverse_b(stack_b)))
			free_malloc_fail(stack_a, stack_b);
		index->bottom_max_pos--;
	}
	if (!(op_push_a(stack_a, stack_b)))
		free_malloc_fail(stack_a, stack_b);
}

void	do_min_top(t_stack **stack_a, t_stack **stack_b, t_index *index)
{
	while (index->top_min_pos > 0)
	{
		if (!(op_rotate_b(stack_b)))
			free_malloc_fail(stack_a, stack_b);
		index->top_min_pos--;
	}
	if (!(op_push_a(stack_a, stack_b)))
		free_malloc_fail(stack_a, stack_b);
	if (!(op_rotate_a(stack_a)))
		free_malloc_fail(stack_a, stack_b);
}

void	do_min_bottom(t_stack **stack_a, t_stack **stack_b, t_index *index)
{
	while (index->bottom_min_pos > -1)
	{
		if (!(op_reverse_b(stack_b)))
			free_malloc_fail(stack_a, stack_b);
		index->bottom_min_pos--;
	}
	if (!(op_push_a(stack_a, stack_b)))
		free_malloc_fail(stack_a, stack_b);
	if (!(op_rotate_a(stack_a)))
		free_malloc_fail(stack_a, stack_b);
}

void	sort_stack_b(t_stack **stack_a, t_stack **stack_b, t_index *index)
{
	int	quick;

	quick = find_quick_way(index, *stack_b);
	if (quick == MAX_TOP)
		do_max_top(stack_a, stack_b, index);
	else if (quick == MAX_BOTTOM)
		do_max_bottom(stack_a, stack_b, index);
	else if (quick == MIN_TOP)
		do_min_top(stack_a, stack_b, index);
	else if (quick == MIN_BOTTOM)
		do_min_bottom(stack_a, stack_b, index);
}
