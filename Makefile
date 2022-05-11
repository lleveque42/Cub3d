# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arudy <arudy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 17:33:37 by arudy             #+#    #+#              #
#    Updated: 2022/05/11 12:33:28 by arudy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${SRCS_MAIN} ${SRCS_UTILS} ${SRCS_PARSING}

SRCS_MAIN = $(addprefix srcs/, main.c)

SRCS_UTILS = $(addprefix srcs/utils/, garbage/ft_free.c garbage/ft_malloc.c gnl/get_next_line.c \
				gnl/get_next_line_utils.c ft_putstr_fd.c ft_strlen.c init.c)

SRCS_PARSING = $(addprefix srcs/parsing/, parsing.c)

OBJS = ${SRCS:.c=.o}

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: ${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -I/usr/include -Imlx -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o ${NAME}

.c.o:
	${CC} ${CFLAGS} -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

rc: fclean all
	${RM} ${OBJS} && clear

.PHONY: all clean fclean re
