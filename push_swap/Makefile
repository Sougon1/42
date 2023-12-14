SRCS			= push_swap.c \



OBJ			= $(SRCS:.c=.o)

NAME			= ps.a

CC			= cc
CFLAGS			= -Wall -Werror -Wextra

#CFLAGS += -fPIE -Wall -Werror -Wextra
#LDFLAGS += -fPIE

LIBFT_DIR	=	../Libft
LIBFT_A	= ${LIBFT_DIR}/libft.a
PRINTF_DIR = ../printf
PRINTF_A = ${PRINTF_DIR}/libftprintf.a
TARGET		= a.out

all: ${NAME}

${NAME} : ${OBJ} ${LIBFT_A} ${PRINTF_A}
		cp ${LIBFT_A} ${PRINTF_A} ${NAME}
		ar crs $@ $^

${PRINTF_A}:
		@make -C ${PRINTF_DIR}

${LIBFT_A}:
		@make -C ${LIBFT_DIR}

clean:
		rm -rf ${OBJ} ${TARGET}
		@make -C ${LIBFT_DIR} ${PRINTF_DIR} clean

fclean: clean
		rm -rf ${NAME}
		@make -C ${LIBFT_DIR} ${PRINTF_DIR} fclean

re: fclean all

.PHONY: all clean fclean re
