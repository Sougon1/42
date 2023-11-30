SRCS			= ft_libft.c \



OBJ			= $(SRCS:.c=.o)

NAME			= libftprintf.a

CC			= cc
CFLAGS			= -WALL -WERROR -WEXTRA

all: ${NAME}

${NAME} : ${OBJ}
		ar crs $@ $^

clean:
		rm -rf ${OBJ}

fclean: clean
		rm -rf ${NAME}

re:
		fclean all

.PHONY: all clean fclean re
