/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:14:24 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 16:28:33 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../libft/libft.h"

#define FIRST 0
#define	LAST 1
#define	OK 0
#define KO 1
#define MAX_TOP 1
#define MIN_TOP 2
#define MAX_BOTTOM 3
#define MIN_BOTTOM 4

/*
** LINKED LIST
*/
typedef struct		s_stack
{
	int				content;
	struct			s_stack *previous;
	struct			s_stack *head;
	struct			s_stack *next;
}					t_stack;

typedef struct		s_index
{
	int				min;
	int				max;
	int				one_fourth;
	int				mid;
	int				three_fourth;
	int				size_b;
	int				top_min_pos;
	int				bottom_min_pos;
	int				top_max_pos;
	int				bottom_max_pos;
}					t_index;


t_stack		*ft_list_new(int nb);
t_stack	    *ft_list_last(t_stack *lst);
int			ft_list_addback(t_stack **alst, t_stack *new);
int			ft_list_addfront(t_stack **alst, t_stack *new);
int			ft_list_clear(t_stack **lst);
int			ft_list_size(t_stack *lst);
int			ft_list_del_one(t_stack **lst, int order);
t_stack		*create_list(char **argv);
t_stack		*ft_list_find(t_stack *lst, int order);
int			ft_list_del_num(t_stack **lst, int number);
/*
** OPERATION FUNCTIONS
*/
void		op_swap_a(t_stack *stack_a);
void		op_swap_b(t_stack *stack_b);
void		op_swap_all(t_stack *stack_a, t_stack *stack_b);
int			op_push_a(t_stack **stack_a, t_stack **stack_b);
int			op_push_b(t_stack **stack_a, t_stack **stack_b);
int			op_rotate_a(t_stack **stack_a);
int			op_rotate_b(t_stack **stack_b);
int			op_rotate_all(t_stack **stack_a, t_stack **stack_b);
int			op_reverse_a(t_stack **stack_a);
int			op_reverse_b(t_stack **stack_b);
int			op_reverse_all(t_stack **stack_a, t_stack **stack_b);
/*
** CHECK_ERROR_C
*/
int			return_error(void);
int			check_error_nb(char **argv);
int			is_in_order(t_stack *stack_a);
void		free_malloc_fail(t_stack **stack_a, t_stack **stack_b);
/*
** ALGO
*/
void		sort_three(t_stack **stack_a, t_stack **stack_b);
void		sort_five(t_stack **stack_a, t_stack **stack_b);
void			sort_hundred(t_stack **stack_a, t_stack **stack_b);
//int			sort_five_hundred(t_stack **stack_a, t_stack **stack_b);
int			find_max_nb(t_stack *stack);
int			find_min_nb(t_stack *stack);
int			find_top_list_index(t_stack *stack, int nb);
int			find_bottom_list_index(t_stack *stack, int nb);
int			find_top_max_pos(t_stack *stack);
int			find_bottom_max_pos(t_stack *stack);
int			find_top_min_pos(t_stack *stack);
int			find_bottom_min_pos(t_stack *stack);
int			find_top_list_index(t_stack *stack, int nb);
int			is_smaller_value_exist(t_stack *stack_a, int value);
int			is_middle_value_exist(t_stack *stack_a, int min, int max);
int			is_bigger_value_exist(t_stack *stack_a, int value);
void		divide_stack(t_stack **stack_a, t_stack **stack_b, int pos);
int			init_index(t_stack *stack_a, t_index *index);
void		sort_stack_b(t_stack **stack_a, t_stack **stack_b, t_index *index);
void		sort_stack_a(t_stack **stack_a, t_stack **stack_b);
int			find_quick_way(t_index *index, t_stack *stack_b);
#endif