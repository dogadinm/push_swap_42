# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 12:14:44 by mdogadin          #+#    #+#              #
#    Updated: 2023/11/28 13:59:36 by mdogadin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = push_swap.a
# LIBFTNAME = libft.a
# CC = cc
# CFLAGS = -Wall -Werror -Wextra
# LIBFTDIR = ./libft

# SRCS =	arg_check.c \
# 		utils.c \
# 		list.c \
# 		push.c \
# 		radix.c \
# 		reverseRotate.c \
# 		rotate.c \
# 		simple.c \
# 		sort.c \
# 		stack_index.c \
# 		swap.c \


# OBJS = $(SRCS:.c=.o)

# all: $(NAME)

# makelibft:
# 	make -C $(LIBFTDIR)
# 	cp $(LIBFTDIR)/$(LIBFTNAME) .
# 	mv $(LIBFTNAME) $(NAME)

# $(NAME): makelibft $(OBJS)
# 	ar -r $(NAME) $(OBJS)

# clean:
# 	rm -f $(OBJS)
# 	cd $(LIBFTDIR) && make clean
	
# fclean: clean
# 	rm -f $(NAME)
# 	cd $(LIBFTDIR) && make fclean
	
# re: fclean all

NAME = push_swap
CHECK = checker

SRCS =	arg_check.c \
		utils.c \
		list.c \
		push.c \
		radix.c \
		reverseRotate.c \
		rotate.c \
		simple.c \
		sort.c \
		stack_index.c \
		swap.c \
		main.c \

# SRCS =  $(wildcard src/*.c utils/*.c)
CHECK_SRCS = $(wildcard utils/*.c) src/instructions.c checker.c

OBJS = ${SRCS:.c=.o}
CHECK_OBJS = ${CHECK_SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME} ${CHECK}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

${CHECK}: ${CHECK_OBJS} 
	@${CC} ${CFLAGS} ${CHECK_OBJS} ./libft/libft.a -o ${CHECK}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}

re: fclean all

.PHONY: all clean fclean re

