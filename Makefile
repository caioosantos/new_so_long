NAME = so_long

# directories
SRC_DIR = src/
INCLUDE_DIR = includes/
MLX_DIR = lib/MLX42/
LIBFT_DIR = lib/libft/
PRINTF_DIR = printf/
OBJ_DIR = obj/

# files
SRC = $(wildcard $(SRC_DIR)*.c)

# flagscl
CC = gcc
C_FLAGS = -Wall -Wextra -Werror -g3 -fPIC
MLX_FLAGS = -ldl -lglfw -pthread -lm

# objects
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

# biblioteca
LIBFT = $(LIBFT_DIR)libft.a
PRINTF = $(PRINTF_DIR)libftprintf.a
MLX = $(MLX_DIR)build/libmlx42.a

OBJ_DIRS = $(sort $(dir $(OBJ) $(OBJ_BONUS)))

# rules
all: $(NAME)

$(OBJ_DIRS):
	mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIRS)
	$(CC) $(C_FLAGS) -c $< -o $@

$(MLX):
	@cmake $(MLX_DIR) -B $(MLX_DIR)build && make -C $(MLX_DIR)build -j4

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(C_FLAGS) -no-pie $(OBJ) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME) $(MLX_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

valgrind:
	valgrind --leak-check=full --suppressions=suppression_file.supp ./$(NAME) $(MAP)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	rm -rf $(MLX_DIR)build

re: fclean all

.PHONY: all clean fclean re
