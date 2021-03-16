/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:51:32 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 15:51:34 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_top_max_pos(t_stack *stack)
{
	int	max;
	int	pos;

	max = find_max_nb(stack);
	pos = find_top_list_index(stack, max);
	return (pos);
}

int	find_bottom_max_pos(t_stack *stack)
{
	int	max;
	int	pos;

	max = find_max_nb(stack);
	pos = find_bottom_list_index(stack, max);
	return (pos);
}

int	find_top_min_pos(t_stack *stack)
{
	int	min;
	int	pos;

	min = find_min_nb(stack);
	pos = find_top_list_index(stack, min);
	return (pos);
}

int	find_bottom_min_pos(t_stack *stack)
{
	int	min;
	int	pos;

	min = find_min_nb(stack);
	pos = find_bottom_list_index(stack, min);
	return (pos);
}
