CC = cc
CCARG = -Werror -Wextra -Wall
NAME = so_long
SRCs = main.c \
       srcs.d/img_new.c \
       srcs.d/map_new.c \
       srcs.d/player_move.c \
       srcs.d/player_new.c \
       srcs.d/sprites_init.c \
	   utils.d/frame_close.c \
	   utils.d/frame_create.c \
	   utils.d/paint2D.c \
	   libs.d/gnl.d/get_next_line_utils.c \
	   libs.d/gnl.d/get_next_line.c
OBJs = $(SRCs:.c=.o)
MLX_A = ./libs.d/mlx.d/libmlx.a
PRINTF_A = ./libs.d/ft_printf.d/libftprintf.a
VECTOR_A = ./libs.d/vector.d/libvector.a
LIBFT_A = ./libs.d/libft.d/libft.a
INCLUDES = -I./libs.d/ft_printf.d \
			-I./libs.d/gnl.d \
			-I./libs.d/libft.d \
			-I./libs.d/mlx.d \
			-I./libs.d/vector.d/includes.d \
			-I./includes.d
LIBS = -L./libs.d/mlx.d -lmlx \
	-L./libs.d/ft_printf.d -lftprintf \
	-L./libs.d/libft.d -lft \
	-L./libs.d/vector.d -lvector \
	-L/usr/lib -lXext -lX11 -lm -lz

all : $(NAME)
$(NAME) : $(MLX_A) $(PRINTF_A) $(VECTOR_A) $(LIBFT_A) $(OBJs)
	$(CC) $(CCARG) $(OBJs) $(LIBS) $(INCLUDES) -o $(NAME)
$(MLX_A) :
	make -C ./libs.d/mlx.d
$(PRINTF_A) :
	make -C ./libs.d/ft_printf.d
$(VECTOR_A) :
	make -C ./libs.d/vector.d
$(LIBFT_A) :
	make -C ./libs.d/libft.d
%.o: %.c
	$(CC) $(CCARG) $(INCLUDES) -c $< -o $@
clean:
	rm $(OBJs)
	make clean -C ./libs.d/mlx.d
	make clean -C ./libs.d/ft_printf.d
	make clean -C ./libs.d/vector.d
	make clean -C ./libs.d/libft.d
fclean: clean
	rm $(NAME)
	make fclean -C ./libs.d/mlx.d
	make fclean -C ./libs.d/ft_printf.d
	make fclean -C ./libs.d/vector.d
	make fclean -C ./libs.d/libft.d
re: fclean all
