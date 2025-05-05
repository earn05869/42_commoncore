NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast -funroll-loops
INCLUDES = -I./libft -I./fractol
LIBFT = ./libft/libft.a
MLX_FLAGS = -lmlx -lm -lXext -lX11
SRC_DIR = ./src
SRC = 	main.c help.c parse.c initialize.c arg.c \
		img.c color.c fractol.c render.c event.c \
		zoom.c zoom2.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(notdir $(OBJ)))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) $(INCLUDES) $(MLX_FLAGS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "Making libft..."
	@make -sC ./libft

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ_PATH)*.o

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re