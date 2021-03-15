#include "../includes/push_swap.h"

int		three_sort(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
		op_swap_a(*stack_a);
	if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
		op_swap_a(*stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content)
		op_swap_a(*stack_a);
	if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		if (!(op_reverse_a(stack_a)))
			return (0);
	}
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content)
	{
		if (!(op_rotate_a(stack_a)))
			return (0);
	}
	return (1);
}