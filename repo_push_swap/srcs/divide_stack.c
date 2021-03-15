#include "../includes/push_swap.h"

int		is_smaller_value_exist(t_stack *stack_a, int value)
{
	int pos;

	pos = 0;
	while (stack_a)
	{
		if (stack_a->content <= value)
			return (pos);
		stack_a = stack_a->next;
		pos++;
	}
	return (-1);
}

int		is_middle_value_exist(t_stack *stack_a, int min, int max)
{
	int pos;

	pos = 0;
	while (stack_a)
	{
		if (stack_a->content > min && stack_a->content <= max)
			return (pos);
		stack_a = stack_a->next;
		pos++;
	}
	return (-1);
}

int		is_bigger_value_exist(t_stack *stack_a, int value)
{
	int pos;

	pos = 0;
	while (stack_a)
	{
		if (stack_a->content > value)
			return (pos);
		stack_a = stack_a->next;
		pos++;
	}
	return (-1);
}

int		divide_stack(t_stack **stack_a, t_stack **stack_b, int pos)
{
	if (pos == -1)
		return (1);
	while (pos > 0)
	{
		if (!(op_rotate_a(stack_a)))
			return (0);
		pos--;
	}
	if (!(op_push_b(stack_a, stack_b)))
		return (0);
	return (1);
}
