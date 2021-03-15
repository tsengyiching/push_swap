#include "../includes/push_swap.h"

int		op_push_a(t_stack **stack_a, t_stack **stack_b)
{
	int			size_b;
	t_stack		*new;

	size_b = ft_list_size(*stack_b);
	if (size_b == 0)
		return (1);
	if (!(new = ft_list_new((*stack_b)->content)))
		return (0);
	if (!(ft_list_addfront(stack_a, new)))
		return (0);
	ft_list_del_one(stack_b, FIRST);
	write(1, "pa\n", 3);
	return (1);
}

int		op_push_b(t_stack **stack_a, t_stack **stack_b)
{
	int			size_a;
	t_stack		*new;

	size_a = ft_list_size(*stack_a);
	if (size_a == 0)
		return (1);
	if (!(new = ft_list_new((*stack_a)->content)))
		return (0);
	if (!(ft_list_addfront(stack_b, new)))
		return (0);
	ft_list_del_one(stack_a, FIRST);
	write(1, "pb\n", 3);
	return (1);
}
