SRCS			= ft_printf.c \
					ft_printf_utils.c \
					ft_printf_c.c \



OBJ			= $(SRCS:.c=.o)

NAME			= libftprintf.a

CC			= cc
CFLAGS			= -Wall -Werror -Wextra

LIBFT_DIR	=	Libft
LIBFT_A	= ${LIBFT_DIR}/libft.a


all: ${NAME}

${NAME} : ${OBJ} ${LIBFT_A} 
		cp ${LIBFT_A} ${NAME}
		ar crs $@ $^

${LIBFT_A}:
		@make -C ${LIBFT_DIR}

clean:
		rm -rf ${OBJ}
		@make -C ${LIBFT_DIR} clean

fclean: clean
		rm -rf ${NAME}
		@make -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all clean fclean re
