#include "../includes/push_swap.h"

int		check_order_reverse(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			stack_a = stack_a->next;
		else
			return (KO);
	}
	return (OK);
}

int		sort_stack_a_reverse(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->next)
	{
		if (!(op_reverse_a(stack_a)))
			return (0);
		if (!(op_push_b(stack_a, stack_b)))
			return (0);
	}
	while (*stack_b)
	{
		if (!(op_push_a(stack_a, stack_b)))
			return (0);
	}
	return (1);
}

int		start_algo(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = ft_list_size(*stack_a);
	if (size == 2)
		op_swap_a(*stack_a);
	else if (size == 3)
	{
		if (!(three_sort(stack_a)))
			return (0);
	}
	else if (size <= 5)
	{
		if (!(five_sort(stack_a, stack_b)))
			return (0);
	}
	// if (!(check_order_reverse(*stack_a)))
	// {
	// 	if (!(sort_stack_a_reverse(stack_a, stack_b)))
	// 		return (0);
	// 	return (1);
	// }
	else if (size <= 100)
	{
		if (!(sort_hundred(stack_a, stack_b)))
			return (0);
	}
	else if (size > 100)
	{
		if (!(sort_five_hundred(stack_a, stack_b)))
			return (0);
	}
	return (1);
}

int     main(int argc, char **argv)
{
	t_stack 	*stack_a;
	t_stack		*stack_b;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (!(check_error_nb(argv)))
		return (return_error());
	if (!(stack_a = create_list(argv)))
		return (1);
	if (is_in_order(stack_a))
		return (ft_list_clear(&stack_a));
	if (!(start_algo(&stack_a, &stack_b)))
		return (1);
	return (ft_list_clear(&stack_a));
}
