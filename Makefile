# Project
NAME        = Cub3D
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Libs
LIBFT_DIR   = utils/Libft
LIBFT_A     = $(LIBFT_DIR)/libft.a
MLX_A       = mlx/libmlx.a
FRAMEWORK   = -Lmlx -lmlx -framework OpenGL -framework AppKit
INCLUDES    = $(MLX_A) $(LIBFT_A)

# Sources / Objects
SRC = srcs/main.c 								\
      srcs/init.c								\
      srcs/init2.c								\
      srcs/init3.c 								\
      srcs/handlers.c 							\
      srcs/map.c 								\
      srcs/raycasting/calc.c 					\
      srcs/raycasting/dda.c 					\
      srcs/raycasting/textures.c 				\
      srcs/raycasting/render.c 					\
      srcs/raycasting/draw.c 					\
      srcs/raycasting/frame.c 					\
      srcs/draw_utils.c 						\
      srcs/movements.c 							\
      srcs/movements_utils.c 					\
      srcs/textures.c 							\
      srcs/minimap/draw_minimap_map.c 			\
      srcs/minimap/draw_minimap_player.c 		\
      srcs/minimap/draw_minimap_rays.c 			\
      srcs/minimap/minimap.c 					\
      srcs/parser.c 							\
      srcs/parser_utils.c 						\
      srcs/colors.c 							\
      srcs/texture.c 							\
      srcs/hundle_C_T.c 						\
      srcs/hundle_map.c 						\
      srcs/map_utils.c 							\
      srcs/checkers.c 							\
      srcs/checkers_helpers.c 					\
      srcs/checkers_helpers2.c 					\
      srcs/player_position.c 					\
      utils/GNL/get_next_line.c 				\
      utils/GNL/get_next_line_utils.c 			\
      utils/utils.c 							\
      srcs/utils_norm.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re libft

# Build everything
all: libft $(NAME)

# Link final binary; relink if libft.a changed
$(NAME): $(OBJ) $(LIBFT_A) $(MLX_A)
	$(CC) $(OBJ) -o $(NAME) $(INCLUDES) $(FRAMEWORK)

# Compile objects
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Always run sub-make; it will no-op if nothing changed
libft:
	$(MAKE) -C $(LIBFT_DIR)

# Clean objects (both here and in libft)
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Full clean
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
