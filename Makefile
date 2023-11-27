# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 12:14:44 by mdogadin          #+#    #+#              #
#    Updated: 2023/11/27 11:51:54 by mdogadin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libft

SRCS =	arg_check.c \
		utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTNAME) .
	mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	ar -r $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	cd $(LIBFTDIR) && make clean
	
fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean
	
re: fclean all

