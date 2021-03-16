/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:11:46 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 12:11:47 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
		op_swap_a(*stack_a);
	if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
		op_swap_a(*stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content)
		op_swap_a(*stack_a);
	if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
		if (!(op_reverse_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content)
		if (!(op_rotate_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
}
