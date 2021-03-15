# Colors
GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m
WHITE= \x1b[37m

NAME		=		checker
PATH_SRC	=		srcs/
PATH_OBJ	=		objs/
SRC			=		main.c					get_next_line.c\
					list_utils.c			check_error.c\
					op_swap_push.c			list_utils_add.c\
					list_utils_delete.c		op_exec.c\
					op_rotate_reverse.c
OBJ			=		$(addprefix $(PATH_OBJ), ${SRC:.c=.o})
HEADER		=		includes/checker.h

LIBFT		=		../libft/libft.a
LIB			= 		libft.a

CC			=		gcc
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
					@echo "$(YELLOW)checker  \t:\t$(GREEN)[OK]$(WHITE)"

clean:
					@make clean -C ../libft/
					@echo "${RED}[CLEAN]:\t$(YELLOW)libft/objs"
					@echo "${RED}[CLEAN]:\t$(YELLOW)checker/objs"
					@$(RM) $(PATH_OBJ)

fclean:				clean
					@make fclean -C ../libft/
					@echo "${RED}[CLEAN]:\t$(YELLOW)libft.a"
					@echo "${RED}[CLEAN]:\t$(YELLOW)checker"
					@$(RM) $(NAME)

re:					fclean all

.PHONY: 			all clean fclean re