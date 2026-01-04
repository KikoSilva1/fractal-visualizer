# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 16:11:08 by framiran          #+#    #+#              #
#    Updated: 2025/10/14 15:55:19 by framiran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iminilibx-linux
LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd

NAME = fractol

SRCS = main.c fractal.c generate_image_helpers.c \
       main_helpers.c fractal_helpers.c helpers.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
