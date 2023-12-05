# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 12:14:44 by mdogadin          #+#    #+#              #
#    Updated: 2023/12/05 15:09:49 by mdogadin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	arg_check.c \
		utils.c \
		list.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		simple.c \
		sort.c \
		stack_index.c \
		swap.c \
		main.c \

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME} 
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}


fclean: clean
	@${RM} ${NAME}


re: fclean all

.PHONY: all clean fclean re

