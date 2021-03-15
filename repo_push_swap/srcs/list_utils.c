#include "../includes/push_swap.h"

int			ft_list_size(t_stack *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack		*ft_list_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack		*ft_list_find(t_stack *lst, int order)
{
	int	i;

	i = 0;
	if (!lst || order < 0)
		return (NULL);
	while (i < order)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

void	free_malloc_fail(t_stack **stack_a, t_stack **stack_b)
{
	ft_list_clear(stack_a);
	ft_list_clear(stack_b);
	exit(1);
}
