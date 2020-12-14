##
## EPITECH PROJECT, 2020
## mk
## File description:
## mk
##

SRCS	=	src/main.c	\
			src/player.c 			\
			src/creat_check_map.c  	\
			src/setsignal.c 		\
			src/print_map.c 		\
			src/send_pos.c 			\
			src/attack.c	\
			src/connection.c

SRCS_two =  get_table1.c	\

SRCS_UNIT =     tests/test_pushswap.c		\

OBJS	=	$(SRCS:.c=.o)

NAME	=	navy

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

tests_run:	fclean
			gcc -o unit_tests $(SRCS_two) $(SRCS_UNIT) $(INC) --coverage -lcriterion
			./unit_tests
			gcovr