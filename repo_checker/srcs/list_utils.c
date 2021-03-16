/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:47:12 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 11:35:06 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_list_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*ft_list_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_list_find(t_stack *lst, int order)
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
