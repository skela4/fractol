# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/04 07:02:38 by aahizi-e          #+#    #+#              #
#    Updated: 2019/10/02 07:24:57 by aahizi-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fractol

SRCS = main.c\
		hook_functions.c\
		fractals.c\
		fractals2.c\
		helper.c\
		complex_calculator.c

FLAGS = -Wall -Wextra -Werror -O2

LIBFT = libft/libft.a

LIBMLX = minilibx_macos/libmlx.a

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) fractol.h 
	make -C libft/
	make -C minilibx_macos/
	$(CC) $(FLAGS) $(LIBFT) $(LIBMLX) $(OBJS) -o $@ -framework OpenGl -framework AppKit -lm -lpthread

clean:
	rm -rf $(OBJS)
	make clean -C libft/
	make clean -C minilibx_macos/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all
