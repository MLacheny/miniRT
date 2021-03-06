SRCS =	srcs/pars/parsing.c							\
		srcs/pars/fill_scene.c						\
		srcs/pars/valid_arg.c						\
		srcs/pars/valid_arg2.c						\
		srcs/pars/valid_param.c						\
		srcs/pars/fill_arg.c						\
		srcs/pars/fill_arg2.c						\
		srcs/pars/ft_atonum.c						\
		srcs/get_next_line/get_next_line_utils.c	\
		srcs/get_next_line/get_next_line.c			\
		srcs/structs/set_structs.c					\
		srcs/structs/disp_arg.c						\
		srcs/structs/disp_objs.c					\
		srcs/rotations/transfo_mat.c				\
		srcs/rotations/objtocam.c					\
		srcs/vectors/vect_operations.c				\

NAME = miniRT

CC = clang

FLAGS = -Wall -Werror -Wextra

MINILIBX = minilibx

LIBFT = libft

INCLUDES = includes

OBJS = ${SRCS:.c=.o}

all : 		$(NAME)

%.o: %.c
			@$(CC) $(FLAGS) -c $< -I$(INCLUDES) -o $@

$(NAME) :	$(OBJS)
			@make -C $(MINILIBX) all
			@make -C $(LIBFT) all
			@make -C $(LIBFT) bonus
			@$(CC) $(FLAGS) $(SGFLAGS) -I$(INCLUDES) $(OBJS) minilibx/*.a -L -lmlx -lX11 -lXext -lm libft/libft.a -o $(NAME)

clean :	
			rm ${OBJS}
			@make -C ${MINILIBX} clean
			@make -C ${LIBFT} clean

fclean :	clean
			@rm ${NAME}
			@make -C ${LIBFT} fclean
		
re : fclean all
	
.PHONY : all clean re fclean
