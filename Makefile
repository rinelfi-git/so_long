CC = cc
CCARG = -Werror -Wextra -Wall
NAME = so_long
SRCs = main.c \
       srcs.d/player_move.c \
	   utils.d/frame_close.c \
	   utils.d/frame_create.c
OBJs = $(SRCs:.c=.o)
MLX_A = ./libs.s/mlx.d/libmlx.a
PRINTF_A = ./libs.s/ft_printf.d/libftprintf.a
LIB_ARG = -L./libs.d/mlx.d -lmlx \
	-L./libs.d/ft_printf.d -lftprintf \
	-L/usr/lib -lXext -lX11 -lm -lz \
	-I./libs.d/mlx.d \
	-I./libs.d/ft_printf.d \
	-I./includes.d

all : $(NAME)
$(NAME) : main.c $(MLX_A) $(PRINTF_A) $(OBJs)
	$(CC) $(CCARG) $(OBJs) $(LIB_ARG) -o $(NAME)
$(MLX_A) :
	make -C ./libs.d/mlx.d
$(PRINTF_A) :
	make -C ./libs.d/ft_printf.d
%.o: %.c
	$(CC) $(CCARG) $(LIB_ARG) -c $< -o $@
clean:
	rm $(OBJs)
	make clean -C ./libs.d/mlx.d
	make clean -C ./libs.d/ft_printf.d
fclean: clean
	rm $(NAME)
	make fclean -C ./libs.d/mlx.d
	make fclean -C ./libs.d/ft_printf.d
re: fclean all
