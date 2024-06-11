NAME			= so_long

SRCS			= main.c \
					map.c \
					map_security.c \
					map_utilities.c \
					map_check.c \
					# so_long.c \
				




OBJ_DIR		= obj
OBJ			= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

MLX_DIR	= minilibx-linux
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_INC	= -I$(MLX_DIR)


LIBFT_DIR	=	libft
LIBFT_A	= ${LIBFT_DIR}/libft.a

CC			= gcc
CFLAGS			= -Wall -Werror -Wextra

#CFLAGS += -fPIE -Wall -Werror -Wextra



all: $(OBJ_DIR) ${NAME}

${NAME} : ${LIBFT_A} ${OBJ}
		$(MAKE) -C $(MLX_DIR)
		${CC} ${CFLAGS} ${OBJ} ${LIBFT_A} -o ${NAME} $(MLX_LIB)

${LIBFT_A}:
		@make -C ${LIBFT_DIR}

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@


$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

clean:
		rm -rf ${OBJ_DIR}
		$(MAKE) -C $(MLX_DIR) clean
		@make -C ${LIBFT_DIR} clean


fclean: clean
		rm -rf ${NAME}
		@make -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all clean fclean re