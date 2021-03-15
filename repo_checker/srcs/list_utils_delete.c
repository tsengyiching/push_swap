/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:47:07 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/15 10:47:08 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_all_malloc(char *buffer, t_stack **stack_a, t_stack **stack_b)
{
	ft_list_clear(stack_a);
	ft_list_clear(stack_b);
	free(buffer);
	buffer = NULL;
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

void	free_malloc_fail(char *buffer, t_stack **stack_a, t_stack **stack_b)
{
	ft_list_clear(stack_a);
	ft_list_clear(stack_b);
	free(buffer);
	buffer = NULL;
	exit(1);
}

void	delete_first(t_stack **lst)
{
	t_stack	*current;

	current = *lst;
	(*lst) = (*lst)->next;
	(*lst)->head = (*lst);
	(*lst)->previous = NULL;
	free(current);
}

void	delete_last(t_stack **lst, int size)
{
	t_stack	*current;
	t_stack	*new_last;

	current = ft_list_last(*lst);
	new_last = ft_list_find(*lst, size - 2);
	new_last->next = NULL;
	free(current);
}

int		ft_list_del_one(t_stack **lst, int order)
{
	int		size;

	if (!(size = ft_list_size(*lst)))
		return (0);
	if (size == 1)
		ft_list_clear(lst);
	else if (order == FIRST || order == LAST)
	{
		if (order == FIRST)
			delete_first(lst);
		else
			delete_last(lst, size);
	}
	return (1);
}
