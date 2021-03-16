/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_divide_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:37:32 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 14:57:05 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*copy_stack_a(t_stack *stack_a)
{
	t_stack	*lst;
	t_stack	*new;

	lst = NULL;
	while (stack_a)
	{
		new = ft_list_new(stack_a->content);
		if (!(ft_list_addback(&lst, new)))
		{
			ft_list_clear(&lst);
			return (NULL);
		}
		stack_a = stack_a->next;
	}
	return (lst);
}

int	get_correct_value(t_stack **copy, int *total, int size)
{
	int	min;

	min = 0;
	while ((*total) > size)
	{
		min = find_min_nb(*copy);
		ft_list_del_num(copy, min);
		(*total) = ft_list_size(*copy);
	}
	return (min);
}

void	divide_four_value(t_stack **copy, t_index *index)
{
	int	size_total;
	int	size_first;
	int	size_second;
	int	size_third;

	size_total = ft_list_size(*copy);
	size_second = size_total / 2;
	size_third = size_second / 2;
	size_first = size_third + size_second;
	index->one_fourth = get_correct_value(copy, &size_total, size_first);
	index->mid = get_correct_value(copy, &size_total, size_second);
	index->three_fourth = get_correct_value(copy, &size_total, size_third);
	ft_list_clear(copy);
}

void	divide_two_value(t_stack **copy, t_index *index)
{
	int	size_total;
	int	mid;

	size_total = ft_list_size(*copy);
	mid = size_total / 2;
	index->mid = get_correct_value(copy, &size_total, mid);
	ft_list_clear(copy);
}

int	init_index(t_stack *stack_a, t_index *index)
{
	t_stack	*copy;
	int		size_a;

	size_a = ft_list_size(stack_a);
	index->min = find_min_nb(stack_a);
	index->max = find_max_nb(stack_a);
	copy = copy_stack_a(stack_a);
	if (!copy)
		return (0);
	if (size_a <= 100)
		divide_two_value(&copy, index);
	else
		divide_four_value(&copy, index);
	index->top_min_pos = 0;
	index->bottom_min_pos = 0;
	index->top_max_pos = 0;
	index->bottom_max_pos = 0;
	index->size_b = 0;
	return (1);
}
