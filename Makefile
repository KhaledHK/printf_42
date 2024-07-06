SRCS		= ft_printf.c			\
		printchar.c		\
		printhexa.c		\
		printint.c		\
		printpointer.c		\
		printstr.c		\
		printunsignd.c		

OBJS		= ${SRCS:.c=.o}
NAME		= libftprintf.a
CC			= gcc -Wall -Wextra -Werror

%.o: %.c ft_printf.h
			${CC} -I. -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME):	${OBJS} ft_printf.h
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
