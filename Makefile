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



FLAGS = -Wall -Wextra -Werror -I.

O_FILE = $(addsuffix .o,$(FUNCTIONS))

LIBFT =	libft/libft.a

CC = gcc

all: $(NAME)

$(NAME): $(LIBFT) $(O_FILE)
	$(CC) $(FLAGS) $(O_FILE) $(LIBFT) -o $(NAME)

$(O_FILE): $(LIBFT)
	$(CC) $(FLAGS) -c $(FUNCTIONS)

$(LIBFT):
		make -C ./libft/

clean:
	rm -f $(O_FILE)
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME) $(O_FILE)
	make fclean -C ./libft/

re: fclean all
