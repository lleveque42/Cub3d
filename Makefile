# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arudy <arudy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 17:33:37 by arudy             #+#    #+#              #
#    Updated: 2022/05/20 11:34:32 by arudy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${SRCS_MAIN} ${SRCS_UTILS} ${SRCS_PARSING} ${SRCS_LIBFT} ${SRCS_GAME}

SRCS_MAIN = $(addprefix srcs/, main.c)

SRCS_UTILS = $(addprefix srcs/utils/, garbage/ft_free.c garbage/ft_malloc.c \
				get_next_line.c init/init.c init/init_null.c \
				exit/ft_exit.c exit/ft_exit_message.c mlx_utils.c)

SRCS_LIBFT = $(addprefix srcs/libft/, ft_putstr_fd.c ft_strlen.c \
				ft_strncmp.c ft_substr.c ft_split.c \
				ft_strdup.c ft_is_whitespace.c ft_strchr.c ft_isalpha.c \
				ft_isdigit.c ft_calloc.c ft_bzero.c ft_strcmp.c \
				ft_strjoin.c ft_strjoin_char.c ft_strcdup.c \
				ft_atoll.c ft_itoa.c ft_atoi.c ft_strlcpy.c ft_strldup.c)

SRCS_PARSING = $(addprefix srcs/parsing/, parsing.c manage_textures.c utils.c \
				manage_rgb.c map_utils.c)

SRCS_GAME = $(addprefix srcs/game/, game.c moves.c rotates.c)

OBJS = ${SRCS:.c=.o}

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: ${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -I/usr/include -Imlx -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

rc: fclean all
	${RM} ${OBJS} && clear

n :
	norminette srcs include

.PHONY: all clean fclean re
