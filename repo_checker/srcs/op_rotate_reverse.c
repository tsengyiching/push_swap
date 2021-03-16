/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:47:28 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 11:38:38 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	op_rotate(t_stack **stack)
{
	int			size;
	t_stack		*new;

	size = ft_list_size(*stack);
	if (size == 0 || size == 1)
		return (1);
	new = ft_list_new((*stack)->content);
	if (!new)
		return (0);
	ft_list_del_one(stack, FIRST);
	if (!(ft_list_addback(stack, new)))
		return (0);
	return (1);
}

int	op_rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	if (!(op_rotate(stack_a)))
		return (0);
	if (!(op_rotate(stack_b)))
		return (0);
	return (1);
}

int	op_reverse(t_stack **stack)
{
	int			size;
	t_stack		*new;
	t_stack		*last;

	size = ft_list_size(*stack);
	if (size == 0 || size == 1)
		return (1);
	last = ft_list_last(*stack);
	new = ft_list_new(last->content);
	if (!new)
		return (0);
	ft_list_del_one(stack, LAST);
	if (!(ft_list_addfront(stack, new)))
		return (0);
	return (1);
}

int	op_reverse_all(t_stack **stack_a, t_stack **stack_b)
{
	if (!(op_reverse(stack_a)))
		return (0);
	if (!(op_reverse(stack_b)))
		return (0);
	return (1);
}
