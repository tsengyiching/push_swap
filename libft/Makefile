# Colors
GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m
WHITE= \x1b[37m

PATH_SRCS	=	srcs/
PATH_OBJS	=	objs/
NAME		=	libft.a
SRCS		=	ft_atoi.c			ft_putstr_fd.c\
				get_next_line.c		get_next_line_utils.c\
				ft_isdigit.c		ft_strcmp.c\
				ft_calloc.c 		ft_bzero.c
CFLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(addprefix $(PATH_OBJS), ${SRCS:.c=.o})
HEAD		=	libft.h
CC			=	clang
RM			=	rm -rf


$(PATH_OBJS)%.o:$(PATH_SRCS)%.c		$(HEAD)
			@mkdir -p $(PATH_OBJS)
			@echo "$(GREEN)[Compiling]:\t$(CYAN)"$<
			@$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(HEAD)
			@ar rc $(NAME) $(OBJS)
			@echo "$(YELLOW)Libft  \t\t:\t$(GREEN)[OK]"
			@ranlib $(NAME)

clean:
			@$(RM) $(PATH_OBJS)
			@$(RM) $(BOBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re bonus