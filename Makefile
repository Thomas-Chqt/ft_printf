# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 19:15:34 by tchoquet          #+#    #+#              #
#    Updated: 2023/06/05 12:07:53 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT			= .
SRCS_DIR		= ${ROOT}/sources
INCLUDES_DIR	= ${ROOT}/includes
LIBFT_DIR		= ${ROOT}/Libft

SRC	= ${wildcard ${SRCS_DIR}/*.c}

OBJ = ${SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
LIBFT = ${ROOT}/libft.a

.PHONY: all clean fclean re bonus


all: ${NAME}

bonus: all

${NAME}: ${OBJ}
	make -C ${LIBFT_DIR} all
	cp ${LIBFT_DIR}/libft.a ${NAME}
	ar rc "$@" $^

clean:
	make -C ${LIBFT_DIR} clean
	rm -rf ${OBJ}

fclean: clean
	make -C ${LIBFT_DIR} fclean
	rm -rf ${ROOT}/libft.a
	rm -rf ${NAME}

re: fclean all


%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $< -I${INCLUDES_DIR} -I${LIBFT_DIR}