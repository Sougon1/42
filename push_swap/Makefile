SRCS			= ${SRCPS} 


OBJ			= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

NAME			= ps.a

CC			= gcc
CFLAGS			= -Wall -Werror -Wextra

#CFLAGS += -fPIE -Wall -Werror -Wextra
#LDFLAGS += -fPIE

SRCPS		= /src/*.c
OBJDIR		= obj


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

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
		${CC} ${CFLAGS} -c $< -o $@

${OBJ_DIR}:
		mkdir -p $@

clean:
		rm -rf ${OBJ_DIR} ${TARGET}
		@make -C ${LIBFT_DIR} ${PRINTF_DIR} clean

fclean: clean
		rm -rf ${NAME}
		@make -C ${LIBFT_DIR} ${PRINTF_DIR} fclean

re: fclean all

.PHONY: all clean fclean re
