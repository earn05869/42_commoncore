# **************************************************************************** #
#                               MINITALK - MAKEFILE                            #
# **************************************************************************** #

NAME_C	= client
NAME_S	= server

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC_C	= client.c
SRC_S	= server.c

OBJ_C	= $(SRC_C:.c=.o)
OBJ_S	= $(SRC_S:.c=.o)


all: $(NAME_C) $(NAME_S)

$(NAME_C): $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(NAME_C)

$(NAME_S): $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ_S) -o $(NAME_S)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_C) $(OBJ_S)

fclean: clean
	rm -f $(NAME_C) $(NAME_S)

re: fclean all

.PHONY: all clean fclean re client server