CC			= cc
CCARG		= -Werror -Wextra -Wall
NAME		= so_long
SRCs		= \
	main.c \
	srcs.d/exit_new.c \
	srcs.d/img_new.c \
	srcs.d/map.d/check_outlines.c \
	srcs.d/map.d/check_road.c \
	srcs.d/map.d/check_shape.c \
	srcs.d/map.d/check_unique.c \
	srcs.d/map.d/is_valid.c \
	srcs.d/map.d/new.c \
	srcs.d/player_move.c \
	srcs.d/player_new.c \
	srcs.d/open_door.c \
	srcs.d/sprites_init.c \
	utils.d/exception.c \
	utils.d/element_locate.c \
	utils.d/frame_close.c \
	utils.d/frame_create.c \
	utils.d/frame_open.c \
	utils.d/frame_repaint.c \
	libs.d/gnl.d/get_next_line_utils.c \
	libs.d/gnl.d/get_next_line.c
OBJs		= $(SRCs:.c=.o)
MLX_A		= ./libs.d/mlx.d/libmlx.a
PRINTF_A	= ./libs.d/ft_printf.d/libftprintf.a
VECTOR_A	= ./libs.d/vector.d/libvector.a
LIBFT_A		= ./libs.d/libft.d/libft.a
INCLUDES	= \
	-I./libs.d/ft_printf.d \
	-I./libs.d/gnl.d \
	-I./libs.d/libft.d \
	-I./libs.d/mlx.d \
	-I./libs.d/vector.d/includes.d \
	-I./includes.d
LIBS = \
	-L./libs.d/mlx.d -lmlx \
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
	$(CC) $(CCARG) $(INCLUDES) -O3 -c $< -o $@
clean:
	rm -rf $(OBJs)
	make -C ./libs.d/mlx.d clean
	make -C ./libs.d/ft_printf.d clean
	make -C ./libs.d/vector.d clean
	make -C ./libs.d/libft.d clean
fclean: clean
	rm -rf $(NAME)
	make -C ./libs.d/ft_printf.d fclean
	make -C ./libs.d/vector.d fclean
	make -C ./libs.d/libft.d fclean
re: fclean all
