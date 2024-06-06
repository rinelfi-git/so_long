CC		=	cc
CFLAGS	=	-Werror -Wextra -Wall
AR		=	ar rcs
NAME	=	libvector.a
HEADER	=	vector.h
DEL		=	rm -rf
SOURCES	=	node.d/detach.c \
			node.d/find.c \
			node.d/get.c \
			node.d/index_of.c \
			node.d/new.c \
			node.d/remove.c \
			object.d/char.c \
			object.d/int.c \
			object.d/long.c \
			object.d/string.c \
			vector.d/add_at.c \
			vector.d/add.c \
			vector.d/create.c \
			vector.d/destruct.c \
			vector.d/filter.c \
			vector.d/for_each.c \
			vector.d/size.c
OBJECTS	=	$(SOURCES:.c=.o)

all : $(NAME)

$(NAME)	: $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o	: %.c
	$(CC) $(CFLAGS) -I./includes.d -o $@ -c $<

clean :
	$(DEL) $(OBJECTS)

main : main.c $(NAME)
	$(CC) $(CFLAGS) -I./includes.d main.c -L. -lvector -o main

fclean : clean
	$(DEL) $(NAME)

re	: fclean all
