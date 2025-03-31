NAME = fractol
SRC_DIR = src
INC_DIR = includes
MLX_DIR = minilibx-linux

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/utils1.c $(SRC_DIR)/utils2.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -I $(MLX_DIR)
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L $(MLX_DIR) -lmlx -L/usr/X11/lib -lX11 -lXext -lm
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

%.o: %.c $(INC_DIR)/fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all
