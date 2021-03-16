/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:51:21 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 15:51:22 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_max_nb(t_stack *stack)
{
	int	max;

	max = stack->content;
	stack = stack->next;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int	find_min_nb(t_stack *stack)
{
	int	min;

	min = stack->content;
	stack = stack->next;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	find_top_list_index(t_stack *stack, int nb)
{
	int	i;

	i = 0;
	if (!stack)
		return (-1);
	while (stack)
	{
		if (stack->content == nb)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

int	find_bottom_list_index(t_stack *stack, int nb)
{
	int		i;
	t_stack	*last;

	i = 0;
	if (!stack)
		return (-1);
	last = ft_list_last(stack);
	while (last)
	{
		if (last->content == nb)
			return (i);
		last = last->previous;
		i++;
	}
	return (-1);
}
