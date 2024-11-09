
NAME=filosofs

CFLAGS= -Wall -Werror -Wextra -MMD -MP

SRC_DIR = ./src
INC_DIR = ./includes
BIN_DIR = ./bin
OBJ_DIR = ./obj
PTHREAD_FLAG = -pthread

SRC = 	main.c 		\
		filosof.c	\
		forquilla.c	\
		taula.c 	\
		utilitats.c	\

OBJS = $(patsubst %.c,${OBJ_DIR}/%.o, ${SRC})
DEPS = $(patsubst %.c,${OBJ_DIR}/%.d, ${SRC})

all: ${BIN_DIR}/${NAME}

${BIN_DIR}/${NAME}: ${BIN_DIR} ${OBJ_DIR} ${OBJS}
	gcc ${CFLAGS} ${PTHREAD_FLAG} -o ${BIN_DIR}/${NAME} ${OBJS}

${BIN_DIR}:
	mkdir -p ${BIN_DIR}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c Makefile
	gcc ${CFLAGS} -I ${INC_DIR} -c $< -o $@

clean:
	rm -rf ${OBJ_DIR}


fclean: clean 
	rm -rf ${BIN_DIR}

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re