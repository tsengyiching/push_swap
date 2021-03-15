/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:45:57 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/15 10:46:04 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../../libft/libft.h"

# define FIRST		0
# define LAST		1
# define OK			0
# define KO			1

/*
** LINKED LIST
*/
typedef	struct		s_stack
{
	int				content;
	struct s_stack	*previous;
	struct s_stack	*head;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_list_new(int nb);
t_stack				*ft_list_last(t_stack *lst);
int					ft_list_addback(t_stack **alst, t_stack *new);
int					ft_list_addfront(t_stack **alst, t_stack *new);
int					ft_list_clear(t_stack **lst);
int					ft_list_size(t_stack *lst);
int					ft_list_del_one(t_stack **lst, int order);
t_stack				*create_list(char **argv);
t_stack				*ft_list_find(t_stack *lst, int order);
void				free_all_malloc(char *buffer, t_stack **stack_a,
					t_stack **stack_b);
void				free_malloc_fail(char *buffer, t_stack **stack_a,
					t_stack **stack_b);

/*
** OPERATION FUNCTIONS
*/
void				op_swap(t_stack *stack);
void				op_swap_all(t_stack *stack_a, t_stack *stack_b);
int					op_push_a(t_stack **stack_a, t_stack **stack_b);
int					op_push_b(t_stack **stack_a, t_stack **stack_b);
int					op_rotate(t_stack **stack);
int					op_rotate_all(t_stack **stack_a, t_stack **stack_b);
int					op_reverse(t_stack **stack);
int					op_reverse_all(t_stack **stack_a, t_stack **stack_b);
void				exec_op(char *buffer, t_stack **stack_a, t_stack **stack_b);

/*
** GET_NEXT_LINE_C
*/
int					get_next_line(int fd, char **line);

/*
** CHECK_ERROR_C
*/
int					return_error(void);
int					check_error_nb(char **argv);
#endif
