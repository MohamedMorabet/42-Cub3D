# Compiler and flags
CC     = cc
CFLAGS = -Wall -Wextra -Werror

# Project name
NAME = Cub3D

# Directories
LIBFT_DIR = utils/libft
LIBFT_A = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

# Source files
SRCS = main.c \
	parsing/parser.c \
	parsing/parser_utils.c \
	parsing/colors.c \
	parsing/texture.c \
	parsing/hundle_C_T.c \
	parsing/hundle_map.c \
	parsing/map_utils.c \
	parsing/checkers.c \
	parsing/checkers_helpers.c \
	parsing/checkers_helpers2.c \
	parsing/player_position.c \
	utils/GNL/get_next_line.c \
	utils/GNL/get_next_line_utils.c \
	utils/utils.c

OBJS = $(SRCS:.c=.o)

# All target
all: $(LIBFT_A) $(NAME)

# Link your project with libft
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT_A)

# Build libft before building the project
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

# Clean project objects
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Full clean
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Recompile all
re: fclean all
