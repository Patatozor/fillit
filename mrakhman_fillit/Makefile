# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/06 17:03:50 by mrakhman          #+#    #+#              #
#    Updated: 2018/05/14 16:27:43 by mrakhman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c\
tetriminos.c \
readfile.c \

FLAGS = -Wall -Wextra -Werror

INC = -I includes

OBJ = $(addsuffix .o,$(SRC))

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

SRC_PATH = src/

LIBFT =	src/libft/libft.a

CC = gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
	$(CC) $(FLAGS) -c $(SRC_POS)

$(LIBFT):
		make -C ./src/libft/

clean:
	rm -f $(OBJ)
			make clean -C ./src/libft/

fclean: clean
	rm -f $(NAME)
			make fclean -C ./src/libft/

re: fclean all
