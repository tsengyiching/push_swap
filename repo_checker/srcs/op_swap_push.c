/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:47:34 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/15 10:47:35 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	op_swap(t_stack *stack)
{
	int		size;
	int		tmp;

	size = ft_list_size(stack);
	if (size == 1 || size == 0)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

void	op_swap_all(t_stack *stack_a, t_stack *stack_b)
{
	op_swap(stack_a);
	op_swap(stack_b);
}

int		op_push_a(t_stack **stack_a, t_stack **stack_b)
{
	int			size_b;
	t_stack		*new;

	size_b = ft_list_size(*stack_b);
	if (size_b == 0)
		return (1);
	new = ft_list_new((*stack_b)->content);
	if (!(ft_list_addfront(stack_a, new)))
		return (0);
	ft_list_del_one(stack_b, FIRST);
	return (1);
}

int		op_push_b(t_stack **stack_a, t_stack **stack_b)
{
	int			size_a;
	t_stack		*new;

	size_a = ft_list_size(*stack_a);
	if (size_a == 0)
		return (1);
	new = ft_list_new((*stack_a)->content);
	if (!(ft_list_addfront(stack_b, new)))
		return (0);
	ft_list_del_one(stack_a, FIRST);
	return (1);
}
