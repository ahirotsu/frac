
NAME = fractol
CC = cc
FLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft/
LIBFT_NAME = libft.a
LIBFT = ${LIBFT_PATH}${LIBFT_NAME}

MLX_PATH = ./minilibx-linux/
MLX_NAME = libmlx.a
MLX = ${MLX_PATH}${MLX_NAME}
MLX_INC = -I/opt/X11/include -Imlx
MLX_FLAGS = -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit

SRCS = fc.c key_mouse.c main.c utils.c burning_ship.c check_ju.c

OBJS = ${SRCS:.c=.o}

RM = rm -f

all: ${LIBFT} ${MLX} ${NAME}

.c.o:
	$(CC) $(FLAGS) -c -o $@ $< $(MLX_INC)

$(MLX):
	@echo "Making MiniLibX......"
	make -sC $(MLX_PATH)

${LIBFT}:
	@echo "Making libft......"
	make -sC ${LIBFT_PATH}

${NAME}: ${OBJS}
	@echo "Making fractol......"
	${CC} ${FLAGS} -o ${NAME} ${OBJS} ${MLX} ${LIBFT} ${MLX_FLAGS}

clean:
	${RM} ${OBJS}
	make clean -C $(MLX_PATH)
	make clean -C ${LIBFT_PATH}

fclean: clean
	${RM} ${NAME}
	rm -f ${LIBFT_PATH}${LIBFT_NAME}

re: fclean all

.PHONY: all clean fclean re
