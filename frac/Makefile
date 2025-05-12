NAME        = fractol
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O3

SRCDIR      = src
OBJDIR      = obj
LIBFTDIR    = libft
# MLXFLAGS    = -lm -lmlx -framework OpenGL -framework AppKit
MLXFLAGS = -lmlx -lXext -lX11 -lm
INCLUDES    = -I$(SRCDIR) -I$(LIBFTDIR)

# Source files
SRCS = main.c fractol.c zoom.c zoom2.c arg.c \
       render.c color.c event.c help.c parse.c \
       img.c initialize.c

# Object files
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

# Libft
LIBFT = $(LIBFTDIR)/libft.a

.PHONY: all clean fclean re bonus

# Default: mandatory build
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Libft build
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

# Bonus build (optional: use _bonus.c files if added later)
bonus: all

# Cleaning rules
clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all
