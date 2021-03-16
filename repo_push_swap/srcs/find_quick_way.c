/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_quick_way.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:29:44 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 16:29:46 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compare_min_top_max_smaller(t_index *index)
{
	if (index->top_min_pos <= index->bottom_min_pos)
	{
		if (index->top_max_pos <= index->top_min_pos)
			return (MAX_TOP);
		else
			return (MIN_TOP);
	}
	else
	{
		if (index->top_max_pos <= index->bottom_min_pos)
			return (MAX_TOP);
		else
			return (MIN_BOTTOM);
	}
}

int	compare_min_bottom_max_bigger(t_index *index)
{
	if (index->top_min_pos <= index->bottom_min_pos)
	{
		if (index->top_min_pos <= index->bottom_max_pos)
			return (MIN_TOP);
		else
			return (MAX_BOTTOM);
	}
	else
	{
		if (index->bottom_max_pos <= index->bottom_min_pos)
			return (MAX_BOTTOM);
		else
			return (MIN_BOTTOM);
	}
}

int	find_quick_way(t_index *index, t_stack *stack_b)
{
	int	way;

	index->top_min_pos = find_top_min_pos(stack_b);
	index->bottom_min_pos = find_bottom_min_pos(stack_b);
	index->top_max_pos = find_top_max_pos(stack_b);
	index->bottom_max_pos = find_bottom_max_pos(stack_b);
	if (index->size_b == 1)
		return (MAX_TOP);
	if (index->top_max_pos <= index->bottom_max_pos)
	{	
		way = compare_min_top_max_smaller(index);
		return (way);
	}
	else
	{
		way = compare_min_bottom_max_bigger(index);
		return (way);
	}
}
