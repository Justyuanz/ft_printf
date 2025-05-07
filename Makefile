# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 10:55:26 by jinzhang          #+#    #+#              #
#    Updated: 2025/05/07 23:19:49 by jinzhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
COMPILER = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

HEADER = ft_printf.h
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a
SRCS = ft_printf.c ft_put.c ft_basenbr.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)
	
$(NAME): $(OBJS) $(LIBFT_A)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) 
	make fclean -C $(LIBFT_DIR)
	
re: fclean all

.PHONY: all clean fclean re 