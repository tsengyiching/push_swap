/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:47:22 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 10:48:33 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	exec_op_swap(char *buffer, t_stack **stack_a, t_stack **stack_b)
{
	if (!(ft_strcmp(buffer, "sa")))
		op_swap(*stack_a);
	else if (!(ft_strcmp(buffer, "sb")))
		op_swap(*stack_b);
	else if (!(ft_strcmp(buffer, "ss")))
		op_swap_all(*stack_a, *stack_b);
	else
		free_all_malloc(buffer, stack_a, stack_b);
}

void	exec_op_push(char *buffer, t_stack **stack_a, t_stack **stack_b)
{
	if (!(ft_strcmp(buffer, "pa")))
	{
		if (!(op_push_a(stack_a, stack_b)))
			free_malloc_fail(buffer, stack_a, stack_b);
	}
	else if (!(ft_strcmp(buffer, "pb")))
	{
		if (!(op_push_b(stack_a, stack_b)))
			free_malloc_fail(buffer, stack_a, stack_b);
	}
	else
		free_all_malloc(buffer, stack_a, stack_b);
}

void	exec_op_rotate(char *buffer, t_stack **stack_a, t_stack **stack_b)
{
	if (!(ft_strcmp(buffer, "ra")))
	{
		if (!(op_rotate(stack_a)))
			free_malloc_fail(buffer, stack_a, stack_b);
	}
	else if (!(ft_strcmp(buffer, "rb")))
	{
		if (!(op_rotate(stack_b)))
			free_malloc_fail(buffer, stack_a, stack_b);
	}
	else if (!(ft_strcmp(buffer, "rr")))
	{
		if (!(op_rotate_all(stack_a, stack_b)))
			free_malloc_fail(buffer, stack_a, stack_b);
	}
	else
		free_all_malloc(buffer, stack_a, stack_b);
}

void	exec_op_reverse(char *buffer, t_stack **stack_a, t_stack **stack_b)
{
	if (!(ft_strcmp(buffer, "rra")))
	{
		if (!(op_reverse(stack_a)))
			free_malloc_fail(buffer, stack_a, stack_b);
	}
	else if (!(ft_strcmp(buffer, "rrb")))
	{
		if (!(op_reverse(stack_b)))
			free_malloc_fail(buffer, stack_a, stack_b);
	}
	else if (!(ft_strcmp(buffer, "rrr")))
	{
		if (!(op_reverse_all(stack_a, stack_b)))
			free_malloc_fail(buffer, stack_a, stack_b);
	}
	else
		free_all_malloc(buffer, stack_a, stack_b);
}

void	exec_op(char *buffer, t_stack **stack_a, t_stack **stack_b)
{
	int	size_char;

	size_char = ft_strlen(buffer);
	if (size_char == 0)
		return ;
	if (size_char == 1 || size_char > 3)
		free_all_malloc(buffer, stack_a, stack_b);
	if (buffer[0] == 's')
		exec_op_swap(buffer, stack_a, stack_b);
	else if (buffer[0] == 'p')
		exec_op_push(buffer, stack_a, stack_b);
	else if (buffer[0] == 'r' && size_char == 2)
		exec_op_rotate(buffer, stack_a, stack_b);
	else if (buffer[0] == 'r' && size_char == 3)
		exec_op_reverse(buffer, stack_a, stack_b);
	else
		free_all_malloc(buffer, stack_a, stack_b);
}
