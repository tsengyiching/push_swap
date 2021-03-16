/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:11:56 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 15:45:46 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_order_reverse(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}

void	sort_stack_a_reverse(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->next)
	{
		if (!(op_reverse_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
		if (!(op_push_b(stack_a, stack_b)))
			free_malloc_fail(stack_a, stack_b);
	}
	while (*stack_b)
	{
		if (!(op_push_a(stack_a, stack_b)))
			free_malloc_fail(stack_a, stack_b);
	}
}

int	start_algo(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = ft_list_size(*stack_a);
	if (size == 2)
		op_swap_a(*stack_a);
	else if (size == 3)
		sort_three(stack_a, stack_b);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
	{
		if (is_order_reverse(*stack_a))
		{
			sort_stack_a_reverse(stack_a, stack_b);
			return (1);
		}
		if (size <= 100)
			sort_hundred(stack_a, stack_b);
		// else if (size > 100)
		// 	sort_five_hundred(stack_a, stack_b);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (!(check_error_nb(argv)))
		return (return_error());
	stack_a = create_list(argv);
	if (!stack_a)
		return (1);
	if (is_in_order(stack_a))
		return (ft_list_clear(&stack_a));
	if (!(start_algo(&stack_a, &stack_b)))
		return (1);
	return (ft_list_clear(&stack_a));
}
