# Project
NAME        = Cub3D
CC          = cc
CFLAGS      = -MMD -MP
RM          = rm -f

# Libs
LIBFT_DIR   = utils/Libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

MLX_DIR     = mlx
MLX_A       = $(MLX_DIR)/libmlx.a

# macOS MiniLibX link flags
FRAMEWORK   = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Link libraries (order matters: objects first, then libs)
LDLIBS      = $(LIBFT_A) $(FRAMEWORK)

# Sources (alphabetical)
SRC = \
	srcs/checkers.c \
	srcs/checkers_helpers.c \
	srcs/checkers_helpers2.c \
	srcs/colors.c \
	srcs/clean1.c \
	srcs/draw_utils.c \
	srcs/handlers.c \
	srcs/hundle_C_T.c \
	srcs/hundle_map.c \
	srcs/init.c \
	srcs/init2.c \
	srcs/init3.c \
	srcs/main.c \
	srcs/map.c \
	srcs/map_utils.c \
	srcs/minimap/draw_minimap_map.c \
	srcs/minimap/draw_minimap_player.c \
	srcs/minimap/draw_minimap_rays.c \
	srcs/minimap/minimap.c \
	srcs/movements.c \
	srcs/movements_utils.c \
	srcs/parser.c \
	srcs/parser_utils.c \
	srcs/player_position.c \
	srcs/raycasting/calc.c \
	srcs/raycasting/dda.c \
	srcs/raycasting/draw.c \
	srcs/raycasting/frame.c \
	srcs/raycasting/render.c \
	srcs/raycasting/textures.c \
	srcs/texture.c \
	srcs/textures.c \
	srcs/utils_norm.c \
	utils/GNL/get_next_line.c \
	utils/GNL/get_next_line_utils.c \
	utils/utils.c

OBJ  = $(SRC:.c=.o)
DEPS = $(OBJ:.o=.d)
HEADS = includes/game.h includes/parser.h
.PHONY: all clean fclean re libft mlx norm

# Build everything
all: $(NAME)

# Final binary (relinks if libft/mlx change)
$(NAME): mlx libft $(OBJ)
	@echo "🔗 Linking $(NAME)"
	@$(CC) $(OBJ) -o $@ $(LDLIBS)

# Object build (quiet, with dep files)
%.o: %.c
	@printf "[CC] %s\n" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Always build sub-libs (they no-op if up to date)
libft:
	@$(MAKE) -C $(LIBFT_DIR)

mlx:
	@$(MAKE) -C $(MLX_DIR)

# Clean objects/deps here and in sublibs
clean:
	@$(RM) $(OBJ) $(DEPS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean || true

# Full clean
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild from scratch
re: fclean all

# Norminette (on sources; add headers if you want)
norm:
	@echo "Running norminette..."
	@norminette $(SRC) $(HEADS)

# Include auto-generated dep files
-include $(DEPS)
