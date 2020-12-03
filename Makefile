##
## EPITECH PROJECT, 2020
## mk
## File description:
## mk
##

SRCS	=	main.c				\
			src/check_main.c 		\
			src/pa_pb_ra.c 		\

OBJS	=	$(SRCS:.c=.o)

NAME	=	push_swap

RM	=		rm -f

INC	=		-I./include

LIB	=		-L./lib/my -lmy

CC	=		gcc

CFLAGS	=	$(INC) -W -Wall -Wextra -g3

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C lib/my/
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIB)

clean:
			make clean -C ./lib/my/
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ./lib/my/
			$(RM) $(NAME)

re:			fclean all
