#include "../includes/push_swap.h"

int		find_quick_way(t_index *index)
{
	if (index->size_b == 1)
		return (1);
	if (index->top_max_pos <= index->bottom_max_pos)
	{	
		if (index->top_min_pos <= index->bottom_min_pos)
		{
			if (index->top_max_pos <= index->top_min_pos)
				return (MAX_TOP);
			else
				return (MIN_TOP);
		}
		else
		{
			if (index->top_max_pos <= index->bottom_min_pos)
				return (MAX_TOP);
			else
				return (MIN_BOTTOM);
		}
	}
	else
	{
		if (index->top_min_pos <= index->bottom_min_pos)
		{
			if (index->top_min_pos <= index->bottom_max_pos)
				return (MIN_TOP);
			else
				return (MAX_BOTTOM);
		}
		else
		{
			if (index->bottom_max_pos <= index->bottom_min_pos)
				return (MAX_BOTTOM);
			else
				return (MIN_BOTTOM);
		}
	}
	return (0);
}

int		sort_stack_b(t_stack **stack_a, t_stack **stack_b, t_index *index)
{
	int	quick;

	index->top_min_pos = find_top_min_pos(*stack_b);
	index->bottom_min_pos = find_bottom_min_pos(*stack_b);
	index->top_max_pos = find_top_max_pos(*stack_b);
	index->bottom_max_pos = find_bottom_max_pos(*stack_b);
	quick = find_quick_way(index);
	if (quick == MAX_TOP)
	{
		while (index->top_max_pos > 0)
		{
			if (!(op_rotate_b(stack_b)))
				return (0);
			index->top_max_pos--;
		}
		if (!(op_push_a(stack_a, stack_b)))
			return (0);
	}
	else if (quick == MAX_BOTTOM)
	{
		while (index->bottom_max_pos > -1)
		{
			if (!(op_reverse_b(stack_b)))
				return (0);
			index->bottom_max_pos--;
		}
		if (!(op_push_a(stack_a, stack_b)))
			return (0);
	}
	else if (quick == MIN_TOP)
	{
		while (index->top_min_pos > 0)
		{
			if (!(op_rotate_b(stack_b)))
				return (0);
			index->top_min_pos--;
		}
		if (!(op_push_a(stack_a, stack_b)))
			return (0);
		if (!(op_rotate_a(stack_a)))
			return (0);
	}
	else if (quick == MIN_BOTTOM)
	{
		while (index->bottom_min_pos > -1)
		{
			if (!(op_reverse_b(stack_b)))
				return (0);
			index->bottom_min_pos--;
		}
		if (!(op_push_a(stack_a, stack_b)))
			return (0);
		if (!(op_rotate_a(stack_a)))
			return (0);
	}
	return (1);
}

int		sort_stack_a(t_stack **stack_a)
{
	int top_min_pos;
	int bottom_min_pos;

	top_min_pos = find_top_min_pos(*stack_a);
	bottom_min_pos = find_bottom_min_pos(*stack_a);
	if (top_min_pos <= bottom_min_pos)
	{
		while (top_min_pos > 0)
		{
			if (!(op_rotate_a(stack_a)))
				return (0);
			top_min_pos--;
		}
	}
	else
	{
		while (bottom_min_pos > -1)
		{
			if (!(op_reverse_a(stack_a)))
				return (0);
			bottom_min_pos--;
		}
	}
	return (1);
}

t_stack		*copy_stack_a(t_stack *stack_a)
{
	t_stack *lst;
	t_stack	*new;

	lst = NULL;
	while (stack_a)
	{
		new = ft_list_new(stack_a->content);
		if (!(ft_list_addback(&lst, new)))
		{
			ft_list_clear(&lst);
			return (NULL);
		}
		stack_a = stack_a->next;
	}
	return (lst);
}

void	divide_four_value(t_stack **copy, t_index *index)
{
	int	size_total;
	int	size_first;
	int	size_second;
	int	size_third;

	size_total = ft_list_size(*copy);
	size_second = size_total / 2;
	size_third =  size_second / 2;
	size_first = size_third + size_second;
	while (size_total > size_first)
	{
		index->one_fourth = find_min_nb(*copy);
		ft_list_del_num(copy, index->one_fourth);
		size_total = ft_list_size(*copy);	
	}
	while (size_total > size_second)
	{
		index->mid = find_min_nb(*copy);
		ft_list_del_num(copy, index->mid);
		size_total = ft_list_size(*copy);	
	}
	while (size_total > size_third)
	{
		index->three_fourth = find_min_nb(*copy);
		ft_list_del_num(copy, index->three_fourth);
		size_total = ft_list_size(*copy);	
	}
	ft_list_clear(copy);
}

void	divide_two_value(t_stack **copy, t_index *index)
{
	int	size_total;
	int	mid;

	size_total = ft_list_size(*copy);
	mid = size_total / 2;
	while (size_total > mid)
	{
		index->mid = find_min_nb(*copy);
		ft_list_del_num(copy, index->mid);
		size_total = ft_list_size(*copy);
	}
	ft_list_clear(copy);
}

int		init_index(t_stack *stack_a, t_index *index)
{
	t_stack *copy;
	int		size_a;

	size_a = ft_list_size(stack_a);
	index->min = find_min_nb(stack_a);
	index->max = find_max_nb(stack_a);
	if (!(copy = copy_stack_a(stack_a)))
		return (0);
	if (size_a <= 100)
		divide_two_value(&copy, index);
	else
		divide_four_value(&copy, index);
	index->top_min_pos = 0;
	index->bottom_min_pos = 0;
	index->top_max_pos = 0;
	index->bottom_max_pos = 0;
	index->size_b = 0;
	return (1);
}

int		sort_hundred(t_stack **stack_a, t_stack **stack_b)
{
	t_index		index;
	int			pos;

	pos = 1;
	if (!(init_index(*stack_a, &index)))
		return (0);
	while (pos >= 0)
	{
		pos = is_smaller_value_exist((*stack_a), index.mid);
		if (!(divide_stack(stack_a, stack_b, pos)))
			return (0);
	}
	index.size_b = ft_list_size(*stack_b);
	while (index.size_b > 0)
	{
		if (!(sort_stack_b(stack_a, stack_b, &index)))
			return (0);
		index.size_b = ft_list_size(*stack_b);
	}
	pos = 1;
	while (pos >= 0)
	{
		pos = is_bigger_value_exist((*stack_a), index.mid);
		if (!(divide_stack(stack_a, stack_b, pos)))
			return (0);
	}
	index.size_b = ft_list_size(*stack_b);
	while (index.size_b > 0)
	{
		if (!(sort_stack_b(stack_a, stack_b, &index)))
			return (0);
		index.size_b = ft_list_size(*stack_b);
	}
	if (!(sort_stack_a(stack_a)))
		return (0);
	return (1);
}
