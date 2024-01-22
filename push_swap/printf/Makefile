SRCS			= ft_printf.c \
					ft_printf_utils.c \
					ft_printf_c.c \
					ft_printf_s.c \
					ft_printf_p.c \
					ft_printf_d.c \
					ft_printf_i.c \
					ft_printf_u.c \
					ft_printf_x.c \
					ft_printf_xx.c \

OBJ			= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
OBJ_DIR 	= obj
#OBJ			= $(SRCS:.c=.o)


NAME			= libftprintf.a

CC			= cc
CFLAGS			= -Wall -Werror -Wextra

#CFLAGS += -fPIE -Wall -Werror -Wextra
#LDFLAGS += -fPIE

TARGET		= a.out

all: ${NAME}

${NAME} : ${OBJ} 
		ar crs $@ $^

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
		${CC} ${CFLAGS} -c $< -o $@

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

clean:
		rm -rf ${OBJ_DIR} ${TARGET}

fclean: clean
		rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
