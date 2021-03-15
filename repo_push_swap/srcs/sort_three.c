#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a, t_stack **stack_b)
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
		if (!(op_reverse_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content)
		if (!(op_rotate_a(stack_a)))
			free_malloc_fail(stack_a, stack_b);
}
