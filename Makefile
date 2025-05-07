# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 10:55:26 by jinzhang          #+#    #+#              #
#    Updated: 2025/05/07 14:11:21 by jinzhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
COMPILER = cc
COMPILERFLAGS = -Wall -Wextra -Werror
SRCS = ft_prinft.c ft_put.c ft_basenbr.c

all: $(NAME)

%.o: %.c
	$(COMPILER) $(COMPILERFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re 