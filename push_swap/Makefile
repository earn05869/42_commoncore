NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC =	src/main.c \
		src/parse.c \
		src/parse_utils.c \
		src/push_swap_utils.c \
		src/op_p.c \
		src/op_s.c \
		src/op_r.c \
		src/op_rr.c \
		src/sort.c \
		src/sort_utils.c \
		src/sort_large_utils.c \
		src/medain.c \
		src/lis.c \
		src/best_move.c \
		src/push_chunk.c \
		libft/ft_isalnum.c  libft/ft_isascii.c  libft/ft_isprint.c  libft/ft_strrchr.c  libft/ft_toupper.c \
			libft/ft_isalpha.c  libft/ft_isdigit.c  libft/ft_strchr.c   libft/ft_tolower.c  libft/ft_strlen.c \
			libft/ft_strncmp.c  libft/ft_memset.c  libft/ft_bzero.c  libft/ft_memchr.c  libft/ft_memcpy.c \
			libft/ft_memcmp.c  libft/ft_strlcpy.c  libft/ft_memmove.c  libft/ft_strnstr.c  libft/ft_strlcat.c \
			libft/ft_atoi.c  libft/ft_calloc.c  libft/ft_strdup.c  libft/ft_substr.c  libft/ft_strjoin.c \
			libft/ft_strtrim.c  libft/ft_split.c  libft/ft_itoa.c  libft/ft_strmapi.c  libft/ft_striteri.c \
			libft/ft_putchar_fd.c  libft/ft_putstr_fd.c  libft/ft_putendl_fd.c  libft/ft_putnbr_fd.c \
			libft/ft_lstadd_back_bonus.c libft/ft_lstnew_bonus.c libft/ft_lstlast_bonus.c libft/ft_lstsize_bonus.c \
			libft/ft_lstclear_bonus.c
OBJ = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re