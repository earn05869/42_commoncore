# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = src
OBJDIR = obj
INCDIR = includes
LIBFTDIR = $(SRCDIR)/libft
PIPEXDIR = $(SRCDIR)/pipex

# Files
LIBFT = $(LIBFTDIR)/ft_atoi.c $(LIBFTDIR)/ft_bzero.c $(LIBFTDIR)/ft_calloc.c \
	$(LIBFTDIR)/ft_isalnum.c $(LIBFTDIR)/ft_isalpha.c $(LIBFTDIR)/ft_isascii.c \
	$(LIBFTDIR)/ft_isdigit.c $(LIBFTDIR)/ft_isprint.c $(LIBFTDIR)/ft_itoa.c \
	$(LIBFTDIR)/ft_memchr.c \
	$(LIBFTDIR)/ft_memcmp.c $(LIBFTDIR)/ft_memcpy.c $(LIBFTDIR)/ft_memmove.c \
	$(LIBFTDIR)/ft_memset.c $(LIBFTDIR)/ft_putchar_fd.c $(LIBFTDIR)/ft_putendl_fd.c \
	$(LIBFTDIR)/ft_putnbr_fd.c $(LIBFTDIR)/ft_putstr_fd.c $(LIBFTDIR)/ft_split.c \
	$(LIBFTDIR)/ft_strchr.c $(LIBFTDIR)/ft_strdup.c $(LIBFTDIR)/ft_striteri.c \
	$(LIBFTDIR)/ft_strjoin.c $(LIBFTDIR)/ft_strlcat.c $(LIBFTDIR)/ft_strlcpy.c \
	$(LIBFTDIR)/ft_strlen.c $(LIBFTDIR)/ft_strmapi.c $(LIBFTDIR)/ft_strncmp.c \
	$(LIBFTDIR)/ft_strnstr.c $(LIBFTDIR)/ft_strrchr.c $(LIBFTDIR)/ft_strtrim.c \
	$(LIBFTDIR)/ft_substr.c $(LIBFTDIR)/ft_tolower.c $(LIBFTDIR)/ft_toupper.c \
	$(LIBFTDIR)/get_next_line.c $(LIBFTDIR)/get_next_line_utils.c \

PIPEX = $(PIPEXDIR)/command.c $(PIPEXDIR)/init.c $(PIPEXDIR)/pipex.c $(PIPEXDIR)/utils_pipex.c

# Output file
NAME = pipex

# Objects with new directory structure
LIBFT_OBJS = $(LIBFT:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
PIPEX_OBJS = $(PIPEX:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Targets
all: $(NAME)

bonus: all
# Make sure obj directories exist
$(OBJDIR)/libft:
	mkdir -p $(OBJDIR)/libft

$(OBJDIR)/pipex:
	mkdir -p $(OBJDIR)/pipex

# Link the final executable
$(NAME): $(LIBFT_OBJS) $(PIPEX_OBJS)
	$(CC) $(CFLAGS) $(LIBFT_OBJS) $(PIPEX_OBJS) -o $(NAME)

# Compile libft source files
$(OBJDIR)/libft/%.o: $(LIBFTDIR)/%.c | $(OBJDIR)/libft
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Compile pipex source files
$(OBJDIR)/pipex/%.o: $(PIPEXDIR)/%.c | $(OBJDIR)/pipex
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Clean object files
clean:
	rm -rf $(OBJDIR)

# Remove all generated files
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re $(OBJDIR)/libft $(OBJDIR)/pipex