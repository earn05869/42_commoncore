NAME        = fractol
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O3

SRCDIR      = src
OBJDIR      = obj
LIBFTDIR    = libft
# MLXFLAGS    = -lm -lmlx -framework OpenGL -framework AppKit
MLXFLAGS = -lmlx -lXext -lX11 -lm
INCLUDES    = -I$(SRCDIR) -I$(LIBFTDIR)

SRCS = main.c fractol.c zoom.c zoom2.c arg.c \
       render.c color.c event.c help.c parse.c \
       img.c initialize.c

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

LIBFT = $(LIBFTDIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

bonus: all

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus