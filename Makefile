# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 19:15:34 by tchoquet          #+#    #+#              #
#    Updated: 2023/06/05 12:27:35 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT			= .
SRCS_DIR		= ${ROOT}/sources
INCLUDES_DIR 	= ${ROOT}/includes
BUILD_DIR		= ${ROOT}/build

EXPORT_INCLUDE_DIR	= ${MY_C_INCLUDE_PATH}
EXPORT_LIB_DIR		= ${MY_LIBRARY_PATH}

RELEASE_SRC	= ${wildcard ${SRCS_DIR}/*.c}
DEBUG_SRC 	= ${ROOT}/main_for_test.c

RELEASE_OBJ = ${patsubst ${SRCS_DIR}%, ${BUILD_DIR}%, ${RELEASE_SRC:.c=.o}}
DEBUG_OBJ	= ${RELEASE_OBJ:.o=_debug.o} ${patsubst ${ROOT}%, ${BUILD_DIR}%, ${DEBUG_SRC:.c=.o}}

CC					= gcc
CFLAGS				= -Wall -Wextra -Werror
alldebug: CFLAGS	= -g

LIBFT			= ${MY_LIBRARY_PATH}/libft.a

NAME			= ${EXPORT_LIB_DIR}/libftprintf.a
EXPORT_INCLUDE	= ${EXPORT_INCLUDE_DIR}/ft_printf.h

DEBUG_EXE 		= ${ROOT}/Debug.out

vpath %.c ${ROOT} ${SRCS_DIR}

.PHONY: all clean fclean re bonus alldebug cleandebug fcleandebug redebug test


all: ${NAME} ${EXPORT_INCLUDE}

bonus: all

${NAME}: ${RELEASE_OBJ} | ${EXPORT_LIB_DIR}
	cp ${LIBFT} ${NAME}
	ar rc "$@" $^

${EXPORT_INCLUDE_DIR}/%.h: ${INCLUDES_DIR}/%.h | ${EXPORT_INCLUDE_DIR}
	cp $< "$@"

clean:
	rm -rf ${RELEASE_OBJ}

fclean: clean
	rm -rf ${NAME} ${EXPORT_INCLUDE}

re: fclean all



alldebug: ${DEBUG_EXE}

${DEBUG_EXE}: ${DEBUG_OBJ}
	${CC} -o $@ $^ ${LIBFT}

cleandebug:
	rm -rf ${DEBUG_OBJ}

fcleandebug: cleandebug
	rm -rf ${DEBUG_EXE}

redebug: fcleandebug alldebug



#All targets
${BUILD_DIR}/%_debug.o: %.c | ${BUILD_DIR}
	${CC} ${CFLAGS} -o $@ -c $< -I${INCLUDES_DIR}

${BUILD_DIR}/%.o: %.c | ${BUILD_DIR}
	${CC} ${CFLAGS} -o $@ -c $< -I${INCLUDES_DIR}



#folders
${EXPORT_INCLUDE_DIR} ${EXPORT_LIB_DIR} ${BUILD_DIR}:
	mkdir -p "$@"

