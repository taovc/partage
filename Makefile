##
## EPITECH PROJECT, 2020
## mk
## File description:
## mk
##

SRCS	=	src/main.c	\
			src/find_binaire.c 	\
			src/creat_env.c 	\

OBJS	=	$(SRCS:.c=.o)

NAME	=	mysh

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
			$(RM) *.gcno
			$(RM) *.gcda
			$(RM) -f *.o
			$(RM) unit_tests

re:			fclean all