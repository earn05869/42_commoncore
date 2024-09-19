SRCS	=	ft_isalnum.c  ft_isascii.c  ft_isprint.c  ft_strrchr.c  ft_toupper.c \
			ft_isalpha.c  ft_isdigit.c  ft_strchr.c   ft_tolower.c  ft_strlen.c \
			ft_strncmp.c  ft_memset.c  ft_bzero.c  ft_memchr.c  ft_memcpy.c \
			ft_memcmp.c  ft_strlcpy.c  ft_memmove.c  ft_strnstr.c  ft_strlcat.c \
			ft_atoi.c  ft_calloc.c  ft_strdup.c  ft_substr.c  ft_strjoin.c \
			ft_strtrim.c  ft_split.c  ft_itoa.c  ft_strmapi.c  ft_striteri.c \
			ft_putchar_fd.c  ft_putstr_fd.c  ft_putendl_fd.c  ft_putnbr_fd.c

BONUS_SRCS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS	= ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
NAME	= libft.a
LIBC	= ar rc
LIBR	= ranlib
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

bonus: ${BONUS_OBJS}
	${LIBC} ${NAME} ${BONUS_OBJS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

re: fclean all
