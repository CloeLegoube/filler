# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 16:55:10 by jjaouen           #+#    #+#              #
#    Updated: 2017/04/05 18:18:26 by clegoube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCF = gcc -Wall -Wextra -Werror

NAME = clegoube.filler

HEAD = filler.h

SRC = main.c get_next_line.c ft_stock.c ft_game.c ft_resize_piece.c

LIB = ./libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@Make -C ./libft/
	@$(GCCF) $(SRC) $(LIB) -I $(HEAD) -o $(NAME)

%.o: %.c
	@$(GCCF) -c $<

clean:
	@Make clean -C ./libft/
	@rm -Rf $(OBJ)

fclean: clean
	@rm -rf $(LIB)
	@rm -rf $(NAME)
	@rm -rf players/$(NAME)

re: fclean all

run: re
	cp $(NAME) players/$(NAME)

.PHONY: all clean
