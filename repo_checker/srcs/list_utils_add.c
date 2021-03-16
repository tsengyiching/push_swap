/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:47:00 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 11:34:27 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack	*ft_list_new(int nb)
{
	t_stack		*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = nb;
	new->next = NULL;
	new->previous = NULL;
	new->head = new;
	return (new);
}

int	ft_list_addback(t_stack **alst, t_stack *new)
{
	t_stack		*ptr;

	if (!new || !alst)
		return (0);
	if (!(*alst))
		*alst = new;
	else
	{
		ptr = ft_list_last(*alst);
		new->previous = ptr;
		new->head = ptr->head;
		ptr->next = new;
	}
	return (1);
}

int	ft_list_addfront(t_stack **alst, t_stack *new)
{
	if (!new || !alst)
		return (0);
	if (!*alst)
	{
		*alst = new;
		return (1);
	}
	new->next = *alst;
	(*alst)->previous = new;
	(*alst)->head = new;
	*alst = new;
	return (1);
}

t_stack	*create_list(char **argv)
{
	int			i;
	t_stack		*new;
	t_stack		*lst;

	i = 1;
	lst = NULL;
	while (argv[i])
	{
		new = ft_list_new(ft_atoi(argv[i]));
		if (!(ft_list_addback(&lst, new)))
		{
			ft_list_clear(&lst);
			return (NULL);
		}
		i++;
	}
	return (lst);
}
