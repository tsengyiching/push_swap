/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:11:22 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 12:11:24 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_list_clear(t_stack **lst)
{
	t_stack	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->previous = NULL;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
	return (0);
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

int	ft_list_del_one(t_stack **lst, int order)
{
	int	size;

	size = ft_list_size(*lst);
	if (!size)
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

int	ft_list_del_num(t_stack **lst, int number)
{
	int			size;
	int			pos;
	t_stack		*current;

	size = ft_list_size(*lst);
	pos = find_top_list_index(*lst, number);
	if (pos == 0)
		delete_first(lst);
	else if (pos == (size - 1))
		delete_last(lst, size);
	else
	{
		current = ft_list_find(*lst, pos);
		current->previous->next = current->next;
		current->next->previous = current->previous;
		free(current);
	}
	return (1);
}
