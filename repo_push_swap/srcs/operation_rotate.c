#include "../includes/push_swap.h"

int		op_rotate(t_stack **stack)
{
	int			size;
	t_stack		*new;

	size = ft_list_size(*stack);
	if (size == 0 || size == 1)
		return (1);
	if (!(new = ft_list_new((*stack)->content)))
		return (0);
	ft_list_del_one(stack, FIRST);
	if (!(ft_list_addback(stack, new)))
		return (0);
	return (1);
}

int		op_rotate_a(t_stack **stack_a)
{
	if (!(op_rotate(stack_a)))
		return (0);
	write(1, "ra\n", 3);
	return (1);
}

int		op_rotate_b(t_stack **stack_b)
{
	if (!(op_rotate(stack_b)))
		return (0);
	write(1, "rb\n", 3);
	return (1);
}

int		op_rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	if (!(op_rotate(stack_a)))
		return (0);
	if (!(op_rotate(stack_b)))
		return (0);
	write(1, "rr\n", 3);
	return (1);
}
