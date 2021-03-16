/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:30:22 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 17:00:46 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int	top_min_pos;
	int	bottom_min_pos;

	top_min_pos = find_top_min_pos(*stack_a);
	bottom_min_pos = find_bottom_min_pos(*stack_a);
	if (top_min_pos <= bottom_min_pos)
	{
		while (top_min_pos > 0)
		{
			if (!(op_rotate_a(stack_a)))
				free_malloc_fail(stack_a, stack_b);
			top_min_pos--;
		}
	}
	else
	{
		while (bottom_min_pos > -1)
		{
			if (!(op_reverse_a(stack_a)))
				free_malloc_fail(stack_a, stack_b);
			bottom_min_pos--;
		}
	}
}

void	sort_nb_under_mid(t_stack **stack_a, t_stack **stack_b, t_index *index)
{
	int	pos;

	pos = 1;
	while (pos >= 0)
	{
		pos = is_smaller_value_exist((*stack_a), index->mid);
		divide_stack(stack_a, stack_b, pos);
	}
	index->size_b = ft_list_size(*stack_b);
	while (index->size_b > 0)
	{
		sort_stack_b(stack_a, stack_b, index);
		index->size_b = ft_list_size(*stack_b);
	}
}

void	sort_nb_pass_mid(t_stack **stack_a, t_stack **stack_b, t_index *index)
{
	int	pos;

	pos = 1;
	while (pos >= 0)
	{
		pos = is_bigger_value_exist((*stack_a), index->mid);
		divide_stack(stack_a, stack_b, pos);
	}
	index->size_b = ft_list_size(*stack_b);
	while (index->size_b > 0)
	{
		sort_stack_b(stack_a, stack_b, index);
		index->size_b = ft_list_size(*stack_b);
	}
}

void	sort_hundred(t_stack **stack_a, t_stack **stack_b)
{
	t_index	index;

	if (!(init_index(*stack_a, &index)))
		free_malloc_fail(stack_a, stack_b);
	sort_nb_under_mid(stack_a, stack_b, &index);
	sort_nb_pass_mid(stack_a, stack_b, &index);
	sort_stack_a(stack_a, stack_b);
}
