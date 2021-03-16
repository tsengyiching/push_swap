// #include "../includes/push_swap.h"

// int		sort_five_hundred(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_index		index;
// 	int			pos;

// 	pos = 1;
// 	init_index(*stack_a, &index);
// 	while (pos >= 0)
// 	{
// 		pos = is_smaller_value_exist((*stack_a), index.one_fourth);
// 		if (!(divide_stack(stack_a, stack_b, pos)))
// 			return (0);
// 	}
// 	index.size_b = ft_list_size(*stack_b);
// 	while (index.size_b > 0)
// 	{
// 		if (!(sort_stack_b(stack_a, stack_b, &index)))
// 			return (0);
// 		index.size_b = ft_list_size(*stack_b);
// 	}
// 	pos = 1;
// 	while (pos >= 0)
// 	{
// 		pos = is_middle_value_exist((*stack_a), index.one_fourth, index.mid);
// 		if (!(divide_stack(stack_a, stack_b, pos)))
// 			return (0);
// 	}
// 	if (!(sort_stack_a(stack_a)))
// 		return (0);
// 	index.size_b = ft_list_size(*stack_b);
// 	while (index.size_b > 0)
// 	{
// 		if (!(sort_stack_b(stack_a, stack_b, &index)))
// 			return (0);
// 		index.size_b = ft_list_size(*stack_b);
// 	}
// 	pos = 1;
// 	while (pos >= 0)
// 	{
// 		pos = is_middle_value_exist((*stack_a), index.mid, index.three_fourth);
// 		if (!(divide_stack(stack_a, stack_b, pos)))
// 			return (0);
// 	}
// 	if (!(sort_stack_a(stack_a)))
// 		return (0);
// 	index.size_b = ft_list_size(*stack_b);
// 	while (index.size_b > 0)
// 	{
// 		if (!(sort_stack_b(stack_a, stack_b, &index)))
// 			return (0);
// 		index.size_b = ft_list_size(*stack_b);
// 	}
// 	pos = 1;
// 	while (pos >= 0)
// 	{
// 		pos = is_bigger_value_exist((*stack_a), index.three_fourth);
// 		if (!(divide_stack(stack_a, stack_b, pos)))
// 			return (0);
// 	}
// 	if (!(sort_stack_a(stack_a)))
// 		return (0);
// 	index.size_b = ft_list_size(*stack_b);
// 	while (index.size_b > 0)
// 	{
// 		if (!(sort_stack_b(stack_a, stack_b, &index)))
// 			return (0);
// 		index.size_b = ft_list_size(*stack_b);
// 	}
// 	if (!(sort_stack_a(stack_a)))
// 		return (0);
// 	return (1);
// }
