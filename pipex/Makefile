NAME        = pipex
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Directories
SRCDIR      = src
BONUSDIR    = bonus
OBJDIR      = obj
LIBFTDIR    = libft
INCDIRS     = -I$(SRCDIR) -I$(BONUSDIR) -I$(LIBFTDIR)

# Mandatory
MANDATORY_SRCS = command.c init.c pipex.c utils_pipex.c
MANDATORY_OBJS = $(addprefix $(OBJDIR)/, $(MANDATORY_SRCS:.c=.o))

# Bonus
BONUS_SRCS = command_bonus.c init_bonus.c pipex_bonus.c utils_pipex.c
BONUS_OBJS = $(addprefix $(OBJDIR)/, $(BONUS_SRCS:.c=.o))

LIBFT       = $(LIBFTDIR)/libft.a

.PHONY: all clean fclean re bonus

# === Default: Mandatory Build ===
all: $(LIBFT) $(NAME)

$(NAME): $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(INCDIRS) $(MANDATORY_OBJS) $(LIBFT) -o $(NAME)

# === Bonus Build ===
bonus: $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCDIRS) $(BONUS_OBJS) $(LIBFT) -o $(NAME)

# === Object Compilation Rules ===
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCDIRS) -c $< -o $@

$(OBJDIR)/%.o: $(BONUSDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCDIRS) -c $< -o $@

# === Build Libft ===
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

# === Cleaning Rules ===
clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all
