#include "../includes/push_swap.h"

int		op_reverse(t_stack **stack)
{
	int			size;
	t_stack		*new;
	t_stack		*last;

	size = ft_list_size(*stack);
	if (size == 0 || size == 1)
		return (1);
	last = ft_list_last(*stack);
	if (!(new = ft_list_new(last->content)))
		return (0);
	ft_list_del_one(stack, LAST);
	if (!(ft_list_addfront(stack, new)))
		return (0);
	return (1);
}

int		op_reverse_a(t_stack **stack_a)
{
	if (!(op_reverse(stack_a)))
		return (0);
	write(1, "rra\n", 4);
	return (1);
}

int		op_reverse_b(t_stack **stack_b)
{
	if (!(op_reverse(stack_b)))
		return (0);
	write(1, "rrb\n", 4);
	return (1);
}

int		op_reverse_all(t_stack **stack_a, t_stack **stack_b)
{
	if (!(op_reverse(stack_a)))
		return (0);
	if (!(op_reverse(stack_b)))
		return (0);
	write (1, "rrr\n", 4);
	return (1);
}
