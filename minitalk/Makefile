${NAME} = Minitalk


SRC_CLIENT	= client.c



SRC_SERVER	= server.c

OBJ_DIR_CLIENT	= obj_client
OBJ_DIR_SERVER	= obj_server

OBJ_CLIENT	=$(addprefix $(OBJ_DIR_CLIENT)/, $(notdir $(SRC_CLIENT:.c=.o)))
OBJ_SERVER	=$(addprefix $(OBJ_DIR_SERVER)/, $(notdir $(SRC_SERVER:.c=.o)))

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra


CLIENT_EXE	= client
SERVER_EXE	= server

PRINTF_DIR	= printf
PRINTF_A	= ${PRINTF_A}/printf.a


all: ${NAME}

${NAME}	: ${SERVER_EXE} ${CLIENT_EXE}

$(CLIENT_EXE): $(OBJ_CLIENT) $(PRINTF_A)
		$(CC) $(CFLAGS) -o $@ $^

$(SERVER_EXE): $(OBJ_SERVER) $(PRINTF_A)
		$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR_CLIENT)/%.o: %.c
		@mkdir -p $(OBJ_DIR_CLIENT)
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_SERVER)/%.o: %.c
		@mkdir -p $(OBJ_DIR_SERVER)
		$(CC) $(CFLAGS) -c $< -o $@


${PRINTF_A}	:
		@make -C ${PRINTF_DIR}

clean: rm -rf ${OBJ_CLIENT} ${OBJ_SERVER} ${CLIENT_EXE} ${SERVER_EXE}
		@make -C ${PRINTF_DIR} clean

fclean: clean
		rm -rf ${NAME}
		@make -C ${PRINTF_DIR} fclean

re: fclean all

.PHONY : all clean fclean re