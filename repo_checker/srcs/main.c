/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:47:17 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/15 10:47:17 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		display_checker(int result, t_stack **stack_a, t_stack **stack_b)
{
	ft_list_clear(stack_a);
	ft_list_clear(stack_b);
	if (result == OK)
	{
		ft_putstr_fd("OK\n", 1);
		return (0);
	}
	else
	{
		ft_putstr_fd("KO\n", 1);
		return (1);
	}
}

int		check_order(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*current;
	int			size_a;
	int			size_b;

	size_a = ft_list_size(*stack_a);
	size_b = ft_list_size(*stack_b);
	if (size_b != 0)
		return (display_checker(KO, stack_a, stack_b));
	if (size_a == 1 || size_a == 0)
		return (display_checker(OK, stack_a, stack_b));
	current = (*stack_a);
	while (current->next)
	{
		if (current->content > current->next->content)
			return (display_checker(KO, stack_a, stack_b));
		current = current->next;
	}
	return (display_checker(OK, stack_a, stack_b));
}

int		main(int argc, char **argv)
{
	int			i;
	char		*buffer;
	t_stack		*stack_a;
	t_stack		*stack_b;

	i = 1;
	buffer = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (!(check_error_nb(argv)))
		return (return_error());
	if (!(stack_a = create_list(argv)))
		return (1);
	while (get_next_line(0, &buffer) > 0)
	{
		exec_op(buffer, &stack_a, &stack_b);
		free(buffer);
	}
	return (check_order(&stack_a, &stack_b));
}
