/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:24:01 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 17:28:21 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_nb_first(t_stack **stack_a, t_stack **stack_b, t_index *index)
{
	int	pos;

	pos = 1;
	while (pos >= 0)
	{
		pos = is_smaller_value_exist((*stack_a), index->one_fourth);
		divide_stack(stack_a, stack_b, pos);
	}
	index->size_b = ft_list_size(*stack_b);
	while (index->size_b > 0)
	{
		sort_stack_b(stack_a, stack_b, index);
		index->size_b = ft_list_size(*stack_b);
	}
}

void	sort_nb_second(t_stack **stack_a, t_stack **stack_b, t_index *index)
{
	int	pos;

	pos = 1;
	while (pos >= 0)
	{
		pos = is_middle_value_exist((*stack_a), index->one_fourth, index->mid);
		divide_stack(stack_a, stack_b, pos);
	}
	sort_stack_a(stack_a, stack_b);
	index->size_b = ft_list_size(*stack_b);
	while (index->size_b > 0)
	{
		sort_stack_b(stack_a, stack_b, index);
		index->size_b = ft_list_size(*stack_b);
	}
}

void	sort_nb_third(t_stack **stack_a, t_stack **stack_b, t_index *index)
{
	int	pos;

	pos = 1;
	while (pos >= 0)
	{
		pos = is_middle_value_exist(
				(*stack_a), index->mid, index->three_fourth);
		divide_stack(stack_a, stack_b, pos);
	}
	sort_stack_a(stack_a, stack_b);
	index->size_b = ft_list_size(*stack_b);
	while (index->size_b > 0)
	{
		sort_stack_b(stack_a, stack_b, index);
		index->size_b = ft_list_size(*stack_b);
	}
}

void	sort_nb_fourth(t_stack **stack_a, t_stack **stack_b, t_index *index)
{
	int	pos;

	pos = 1;
	while (pos >= 0)
	{
		pos = is_bigger_value_exist((*stack_a), index->three_fourth);
		divide_stack(stack_a, stack_b, pos);
	}
	sort_stack_a(stack_a, stack_b);
	index->size_b = ft_list_size(*stack_b);
	while (index->size_b > 0)
	{
		sort_stack_b(stack_a, stack_b, index);
		index->size_b = ft_list_size(*stack_b);
	}
}

void	sort_five_hundred(t_stack **stack_a, t_stack **stack_b)
{
	t_index		index;

	init_index(*stack_a, &index);
	sort_nb_first(stack_a, stack_b, &index);
	sort_nb_second(stack_a, stack_b, &index);
	sort_nb_third(stack_a, stack_b, &index);
	sort_nb_fourth(stack_a, stack_b, &index);
	sort_stack_a(stack_a, stack_b);
}
