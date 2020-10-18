SRCS =	srcs/pars/parsing.c							\
		srcs/get_next_line/get_next_line.c			\
		srcs/get_next_line/get_next_line_utils.c	\

NAME = miniRT

CC = clang

FLAGS = -Wall -Werror -Wextra

MINILIBX = minilibx

LIBFT = libft

INCLUDES = includes

OBJS = ${SRCS:.c=.o}

all : 		$(NAME)

%.o: %.c
			$(CC) $(FLAGS) -c $< -I$(INCLUDES) -o $@

$(NAME) :	$(OBJS)
			@make -C $(MINILIBX) all
			@make -C $(LIBFT) all
			@$(CC) $(FLAGS) $(SGFLAGS) -I$(INCLUDES) $(OBJS) minilibx/*.a -L -lmlx -lX11 -lXext -lm libft/libft.a -o $(NAME)

clean :	
			rm ${OBJS}
			@make -C ${MINILIBX} clean
			@make -C ${LIBFT} clean

fclean :	clean
			rm ${NAME}
			make -C ${LIBFT} fclean
		
re :
			clean
			fclean
	
.PHONY : all clean re fclean
