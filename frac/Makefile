NAME		:= fractol

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -Ofast

SRC_DIR		:= ./src
INC_DIR		:= ./include
LIBFT_DIR	:= ./libft
MLX_DIR		:= ./MLX42

LIBFT		:= $(LIBFT_DIR)/libft.a
MLX			:= $(MLX_DIR)/build/libmlx42.a
LIBS		:= $(MLX) $(LIBFT) -ldl -lglfw -pthread -lm

INCLUDES	:= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)/include

SRCS		:= $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS		:= $(SRCS:.c=.o)

MLX_GIT		:= https://github.com/codam-coding-college/MLX42.git

all: $(LIBFT) mlx42 $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "Built: $(NAME)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

mlx42: clone_mlx
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build > /dev/null
	@cmake --build $(MLX_DIR)/build -j4 > /dev/null

clone_mlx:
	@if [ ! -d $(MLX_DIR) ]; then \
		echo "Cloning MLX42 from GitHub..."; \
		git clone $(MLX_GIT) $(MLX_DIR); \
	fi

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@echo "Compiled: $<"

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(MLX_DIR)/build
	@echo "Clean done."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Full clean done."

re: fclean all

.PHONY: all clean fclean re mlx42 clone_mlx
