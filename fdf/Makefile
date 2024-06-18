NAME = fdf
CC = cc
FLAGS = -Wall -Wextra -Werror 
MLX_DIR = ./minilibx
INCLUDES = ./includes/
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGl -framework AppKit
SRCS_DIR = ./sources/

SRCS = colors.c draw_segments.c hooks.c mlx_utils.c palette.c utils.c \
		draw.c errors.c hooks_suite.c  map_tools.c  mouse_hooks.c  parse_file.c fdf.c \
		memory_utils.c

OBJS = $(SRCS:%.c=$(SRCS_DIR)%.o)

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c
		$(CC) $(FLAGS) -I$(INCLUDES) -I$(MLX_DIR) -c $< -o $@

$(NAME): $(OBJS)
		make re -C ./libft
		make -C $(MLX_DIR)
		$(CC) $(FLAGS) $(OBJS) -L./libft -lft -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME)
		@cp $(MLX_DIR)/libmlx.dylib libmlx.dylib

all: $(NAME)

clean:
		make clean -C ./libft
		make clean -C $(MLX_DIR)
		rm -rf $(OBJS)

fclean: clean
		make fclean -C ./libft
		rm -rf $(NAME) libmlx.dylib

re: fclean all

.PHONY: all clean fclean re
