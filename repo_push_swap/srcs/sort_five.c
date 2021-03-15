#include "../includes/push_swap.h"

void	second_party(int position, t_stack **stack_a, t_stack **stack_b)
{
	if (position == 2)
	{
		if (!(op_rotate_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
		if (!(op_push_a(stack_a, stack_b)))
			free_malloc_fail(stack_a, stack_b);
		op_swap_a(*stack_a);
		if (!(op_reverse_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
	}
	else if (position == 3 || position == 4)
	{
		if (!(op_push_a(stack_a, stack_b)))
			free_malloc_fail(stack_a, stack_b);
		if (!(op_rotate_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
	}
}

void	first_party(int position, int size_a,
						t_stack **stack_a, t_stack **stack_b)
{
	if (position == 0)
	{
		if (!(op_push_a(stack_a, stack_b)))
			free_malloc_fail(stack_a, stack_b);
	}
	else if (position == 1)
	{
		if (!(op_push_a(stack_a, stack_b)))
			free_malloc_fail(stack_a, stack_b);
		op_swap_a(*stack_a);
	}
	else if ((position == 2 && size_a == 3) || (position == 3 && size_a == 4))
	{
		if (!(op_reverse_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
		if (!(op_push_a(stack_a, stack_b)))
			free_malloc_fail(stack_a, stack_b);
		if (!(op_rotate_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
		if (!(op_rotate_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
	}
}

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

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		position;
	int		size_a;

	i = 0;
	while (ft_list_size(*stack_a) > 3)
	{
		if (!(op_push_b(stack_a, stack_b)))
			free_malloc_fail(stack_a, stack_b);
		i++;
	}
	sort_three(stack_a, stack_b);
	while (i > 0)
	{
		size_a = ft_list_size(*stack_a);
		position = find_position(*stack_a, *stack_b);
		first_party(position, size_a, stack_a, stack_b);
		second_party(position, stack_a, stack_b);
		i--;
	}
}
