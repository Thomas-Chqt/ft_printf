# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 19:15:34 by tchoquet          #+#    #+#              #
#    Updated: 2023/05/30 21:29:09 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT			= .
SRCS_DIR		= ${ROOT}/sources
INCLUDES_DIR	= ${ROOT}/includes
LIBFT_DIR		= ${ROOT}/Libft

SRC	= ${wildcard ${SRCS_DIR}/*.c}

OBJ = ${SRC:.c=.o}

NAME = libftprintf.a
LIBFT	= ${LIBFT_DIR}/libft.a

CC					= cc
CFLAGS				= -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${LIBFT} ${OBJ}
	ar rc "$@" $^

clean:
	cd ${LIBFT_DIR} && make clean
	rm -rf ${OBJ}

fclean: clean
	cd ${LIBFT_DIR} && make fclean
	rm -rf ${NAME}

re: fclean all


%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $< -I${INCLUDES_DIR}

${LIBFT}:
	cd ${LIBFT_DIR} && make all
