
NAME=filosofs

CFLAGS= -Wall -Werror -Wextra
SRC_DIR = ./src
INC_DIR = ./includes

OBJS = main.o filosof.o forquilla.o taula.o utilitats.o

all: ${NAME}

${NAME}: ${OBJS}
	gcc ${CFLAGS} -o ${NAME} ${OBJS}

%.o: ${SRC_DIR}/%.c
	gcc ${CFLAGS} -I ${INC_DIR} -c $< -o $@

clean:
	rm -rf ${OBJS}

fclean: clean 
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re