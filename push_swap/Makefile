SRCS			= push_swap.c \
					security.c \
					tableaua.c \
					securityint.c \
					entry.c \
					swap.c \
					push.c \
					reverse.c \
					rotate.c \
					find_index.c \
					find_value.c \
					last_value.c \
					algo_infdix.c \
					utilitiesone.c \




OBJ			= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

NAME			= push_swap

CC			= gcc
CFLAGS			= -Wall -Werror -Wextra

#CFLAGS += -fPIE -Wall -Werror -Wextra

OBJ_DIR		= obj


LIBFT_DIR	=	libft
LIBFT_A	= ${LIBFT_DIR}/libft.a

#TARGET		= a.out

all: $(OBJ_DIR) ${NAME}

${NAME} : ${LIBFT_A} ${OBJ}
		${CC} ${CFLAGS} ${OBJ} ${LIBFT_A} -o ${NAME}

${LIBFT_A}:
		@make -C ${LIBFT_DIR}

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
		${CC} ${CFLAGS} -c $< -o $@ 

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

clean:
		rm -rf ${OBJ_DIR}
		@make -C ${LIBFT_DIR} clean


fclean: clean
		rm -rf ${NAME}
		@make -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all clean fclean re