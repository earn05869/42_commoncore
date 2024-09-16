SRCS	=	ft_printf.c  ft_putchar.c  ft_putnbr_base.c  ft_putnbr.c  ft_putptr_base.c  ft_putstr.c

# BONUS_SRCS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
# 				ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS	= ${SRCS:.c=.o}
# BONUS_OBJS = ${BONUS_SRCS:.c=.o}
NAME	= libftprintf.a
LIBC	= ar rc
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

# bonus: ${BONUS_OBJS}
# 	${LIBC} ${NAME} ${BONUS_OBJS}
# 	${LIBR} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
