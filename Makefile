# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/06 17:03:50 by mrakhman          #+#    #+#              #
#    Updated: 2018/05/14 18:19:00 by mrakhman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FUNCTIONS = main \
tetrimino_is_valid \


FLAGS = -Wall -Wextra -Werror

INC = -I.

OBJ = $(addsuffix .o,$(FUNCTIONS))


LIBFT =	libft/libft.a

CC = gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
	$(CC) $(FLAGS) -c $(FUNCTIONS)

$(LIBFT):
		make -C ./libft/

clean:
	rm -f $(OBJ)
			make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
			make fclean -C ./libft/

re: fclean all
