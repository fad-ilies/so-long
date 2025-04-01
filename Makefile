CC = cc
CFLAGS = -Werror -Wextra -Wall -MMD -g3 -fPIC
INCLUDES = -Iincludes -I./lib/ft_printf -I./lib/libft -I./minilibx-linux
SRC_DIR = src
OBJ_DIR = objs.
MLX = minilibx-linux
MLXFLAGS = -L$(MLX) -lmlx -lXext -lX11 -lm
LIBPRINTF = lib/ft_printf/libftprintf.a
LIBFT = lib/libft/libft.a

SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(notdir $(basename $(SRCS)))))

DEPENDS = $(OBJS:.o=.d)

NAME = so_long
-include $(DEPEND)

.PHONY: all
all: $(MLX) $(NAME)

$(NAME): $(OBJS) $(LIBPRINTF) $(LIBFT)
			$(MAKE) -C $(MLX)
			$(CC) $^ -o $@ $(MLXFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBPRINTF):
	$(MAKE) -C lib/ft_printf

$(LIBFT):
	$(MAKE) -C lib/libft

$(MLX):
	git clone https://github.com/42Paris/minilibx-linux.git $@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(MLX)
	$(MAKE) -C lib/ft_printf clean
	$(MAKE) -C lib/libft clean
.PHONY: fclean
fclean: clean
	rm -rf $(NAME)
	rm -rf $(MLX)
	$(MAKE) -C lib/ft_printf fclean
	$(MAKE) -C lib/libft fclean

.PHONY:
re: fclean all

