#include "../includes/push_swap.h"

int		find_position(t_stack *stack_a, t_stack *stack_b)
{
	int		position;

	position = 0;
	while (stack_a)
	{
		if (stack_b->content > stack_a->content)
			position++;
		stack_a = stack_a->next;
	}
	return (position);
}

int		five_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		position;
	int		size_a;

	i = 0;
	while (ft_list_size(*stack_a) > 3)
	{
		if (!(op_push_b(stack_a, stack_b)))
			return (0);
		i++;
	}
	if (!(three_sort(stack_a)))
		return (0);
	while (i > 0)
	{
		size_a = ft_list_size(*stack_a);
		position = find_position(*stack_a, *stack_b);
		if (position == 0)
		{
			if (!(op_push_a(stack_a, stack_b)))
				return (0);
		}
		else if (position == 1)
		{
			if (!(op_push_a(stack_a, stack_b)))
				return (0);
			op_swap_a(*stack_a);
		}
		else if ((position == 2 && size_a == 3) || (position == 3 && size_a == 4))
		{
			if (!(op_reverse_a(stack_a)))
				return (0);
			if (!(op_push_a(stack_a, stack_b)))
				return (0);
			if (!(op_rotate_a(stack_a)))
				return (0);
			if (!(op_rotate_a(stack_a)))
				return (0);
		}
		else if (position == 2)
		{
			if (!(op_rotate_a(stack_a)))
				return (0);
			if (!(op_push_a(stack_a, stack_b)))
				return (0);
			op_swap_a(*stack_a);
			if (!(op_reverse_a(stack_a)))
				return (0);
		}
		else if (position == 3 || position == 4)
		{
			if (!(op_push_a(stack_a, stack_b)))
				return (0);
			if (!(op_rotate_a(stack_a)))
				return (0);
		}
		i--;
	}
	return (1);
}

int		three_sort(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content && (*stack_a)->content > (*stack_a)->next->next->content && (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		op_swap_a(*stack_a);
	}
	if ((*stack_a)->content < (*stack_a)->next->content && (*stack_a)->content < (*stack_a)->next->next->content && (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		op_swap_a(*stack_a);
	}
	if ((*stack_a)->content > (*stack_a)->next->content && (*stack_a)->content < (*stack_a)->next->next->content && (*stack_a)->next->content < (*stack_a)->next->next->content)
	{
		op_swap_a(*stack_a);
	}
	if ((*stack_a)->content < (*stack_a)->next->content && (*stack_a)->content > (*stack_a)->next->next->content && (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		if (!(op_reverse_a(stack_a)))
			return (0);
	}
	if ((*stack_a)->content > (*stack_a)->next->content && (*stack_a)->content > (*stack_a)->next->next->content && (*stack_a)->next->content < (*stack_a)->next->next->content)
	{
		if (!(op_rotate_a(stack_a)))
			return (0);
	}
	return (1);
}

