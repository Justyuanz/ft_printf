# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 10:55:26 by jinzhang          #+#    #+#              #
#    Updated: 2025/05/04 13:07:13 by jinzhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
COMPILER = cc
COMPILERFLAGS = -Wall -Wextra -Werror
SRCS = ft_prinft.c ft_put.c

all: $(NAME)

%.o: %.c
	$(COMPILER) $(COMPILERFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) .bonus

re: fclean all

bonus: .bonus

.bonus: $(NAME) $(BONUS_OBJS)
		ar rcs $(NAME) $(BONUS_OBJS)
		touch .bonus

.PHONY: all clean fclean re bonus
