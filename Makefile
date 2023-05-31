# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 19:15:34 by tchoquet          #+#    #+#              #
#    Updated: 2023/05/31 22:27:29 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT			= .
SRCS_DIR		= ${ROOT}/sources
INCLUDES_DIR 	= ${ROOT}/includes
BUILD_DIR		= ${ROOT}/build

EXPORT_INCLUDE_DIR	= ${ROOT}/product/include
EXPORT_LIB_DIR		= ${ROOT}#/product/lib

EXTERN_INCLUDE_DIR	= /Users/tchoquet/Documents/Libraries/include
EXTERN_LIB_DIR		= /Users/tchoquet/Documents/Libraries/lib

RELEASE_SRC	= ${wildcard ${SRCS_DIR}/*.c}
DEBUG_SRC 	= ${ROOT}/main_for_test.c

RELEASE_OBJ = ${patsubst ${SRCS_DIR}%, ${BUILD_DIR}%, ${RELEASE_SRC:.c=.o}}
DEBUG_OBJ	= ${RELEASE_OBJ:.o=_debug.o} ${patsubst ${ROOT}%, ${BUILD_DIR}%, ${DEBUG_SRC:.c=.o}}

CC					= gcc
CFLAGS				= -Wall -Wextra -Werror
alldebug: CFLAGS	= -g

USED_EXTERN_LIBS = ft

NAME			= ${EXPORT_LIB_DIR}/libftprintf.a
EXPORT_INCLUDE	= ${EXPORT_INCLUDE_DIR}/ft_printf.h

DEBUG_EXE 		= ${ROOT}/Debug.out

vpath %.c ${ROOT} ${SRCS_DIR}

.PHONY: all clean fclean re alldebug cleandebug fcleandebug redebug



all: ${NAME} ${EXPORT_INCLUDE}

${NAME}: ${RELEASE_OBJ} | ${EXPORT_LIB_DIR}
	cp "/Users/thomas/Library/Mobile Documents/com~apple~CloudDocs/Libraries/C/lib/libft.a" ${NAME}
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
	${CC} -o $@ $^ -L${EXTERN_LIB_DIR} -l${USED_EXTERN_LIBS}

cleandebug:
	rm -rf ${DEBUG_OBJ}

fcleandebug: cleandebug
	rm -rf ${DEBUG_EXE}

redebug: fcleandebug alldebug



#All targets
${BUILD_DIR}/%_debug.o: %.c | ${BUILD_DIR}
	${CC} ${CFLAGS} -o $@ -c $< -I${INCLUDES_DIR} -I${EXTERN_INCLUDE_DIR}

${BUILD_DIR}/%.o: %.c | ${BUILD_DIR}
	${CC} ${CFLAGS} -o $@ -c $< -I${INCLUDES_DIR} -I${EXTERN_INCLUDE_DIR}



#folders
${EXPORT_INCLUDE_DIR} ${EXPORT_LIB_DIR} ${BUILD_DIR}:
	mkdir -p "$@"

