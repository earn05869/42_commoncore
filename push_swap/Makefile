NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCDIR		= src
OBJDIR		= obj
INCDIR		= $(SRCDIR)
LIBFTDIR	= libft

SRCS =  main.c best_move.c lis.c medain.c \
		op_p.c op_r.c op_rr.c op_s.c \
		parse.c parse_utils.c push_chunk.c \
		push_swap_utils.c sort.c sort_large_utils.c sort_utils.c

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

LIBFT = $(LIBFTDIR)/libft.a

INCLUDES = -I$(INCDIR) -I$(LIBFTDIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR) bonus

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re