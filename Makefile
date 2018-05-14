# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/06 17:03:50 by mrakhman          #+#    #+#              #
#    Updated: 2018/05/14 18:09:57 by mrakhman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c\
tetriminos.c \
readfile.c \

FLAGS = -Wall -Wextra -Werror

INC = -I .

OBJ = $(addsuffix .o,$(SRC))


LIBFT =	libft/libft.a

CC = gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
	$(CC) $(FLAGS) -c $(SRC)

$(LIBFT):
		make -C ./libft/

clean:
	rm -f $(OBJ)
			make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
			make fclean -C ./libft/

re: fclean all
