SRCS	=	ft_printf.c  ft_putchar.c  ft_putnbr_base.c  ft_putnbr.c  ft_putptr_base.c  ft_putstr.c
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
LIBC	= ar rc
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
