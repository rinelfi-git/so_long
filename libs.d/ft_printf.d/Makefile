CC			=	cc
CFLAGS		=	-Werror -Wextra -Wall
AR			=	ar rcs
NAME		=	libftprintf.a
HEADER		=	ft_printf.h
DEL			=	rm -rf
SOURCES		=	ft_printf.c \
				ft_printchar.c \
				ft_printint.c \
				ft_printpointer.c \
				ft_printuint.c \
				ft_printhex.c \
				ft_printstr.c
OBJECTS		=	$(SOURCES:.c=.o)

all					: $(NAME)

$(NAME)				: $(HEADER) $(OBJECTS) $(LIBS)
	$(AR) $(NAME) $(OBJECTS)

%.o					: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean 				:
	$(DEL) $(OBJECTS)

fclean				: clean
	$(DEL) $(NAME)

re					: fclean all