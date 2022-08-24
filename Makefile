NAME = so_long

SRCS  = so_long.c do_move.c funcs_help.c parser.c render.c do_move_help.c

OBJ  = $(patsubst %.c,%.o,$(SRCS))

LIBFT_HDR 	= -I./libft

LIB_BINARY	= -L./libft -lft

LIBFT		= ./libft/libft.a

HDR  = -I mlx 

CC   = gcc

%.o: %.c so_long.h
	$(CC) -Wall -Wextra -Werror -Imlx $(HDR) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIB_BINARY) -o $@

all: $(LIBFT) ./libft/libft.a $(NAME)

FORCE:		;

$(LIBFT):	FORCE
			make -C ./libft

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re