# Colors
GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m
WHITE= \x1b[37m

NAME		=		push_swap
PATH_SRC	=		srcs/
PATH_OBJ	=		objs/
SRC			=		main.c					list_utils.c\
					check_error.c			algo_small_nb.c\
					operation_swap.c		list_utils_delete.c\
					list_utils_add.c		operation_push.c\
					operation_rotate.c		operation_reverse_rotate.c\
					sort_hundred.c			sort_utils.c\
					divide_stack.c			sort_five_hundred.c
OBJ			=		$(addprefix $(PATH_OBJ), ${SRC:.c=.o})
HEADER		=		includes/push_swap.h

LIBFT		=		../libft/libft.a
LIB			= 		libft.a

CC			=		clang
FLAGS		=		-Wall -Werror -Wextra
RM			=		rm -rf

all:				$(LIB) $(NAME)

$(PATH_OBJ)%.o:		$(PATH_SRC)%.c $(HEADER) $(LIBFT)
					@cp ../libft/libft.a ./$(NAME)
					@mkdir -p $(PATH_OBJ)
					@echo "$(GREEN)[Compiling]:\t$(CYAN)"$<
					@$(CC) $(FLAGS) -c $< -o $@

$(LIB):
					@make -C ../libft all

$(NAME):			$(OBJ) $(HEADER)
					@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
					@echo "$(YELLOW)push_swap  \t:\t$(GREEN)[OK]$(WHITE)"

clean:
					@make clean -C ../libft/
					@echo "${RED}[CLEAN]:\t$(YELLOW)libft/objs"
					@echo "${RED}[CLEAN]:\t$(YELLOW)push_swap/objs"
					@$(RM) $(PATH_OBJ)

fclean:				clean
					@make fclean -C ../libft/
					@echo "${RED}[CLEAN]:\t$(YELLOW)libft.a"
					@echo "${RED}[CLEAN]:\t$(YELLOW)push_swap"
					@$(RM) $(NAME)

re:					fclean all

.PHONY: 			all clean fclean re