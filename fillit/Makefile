# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/10 16:16:49 by rfumeron          #+#    #+#              #
#    Updated: 2018/05/14 16:27:44 by mrakhman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fillit

# directories
SRCDIR	:=	.
INCDIR	:=	.
CC		:=	clang
CFLAGS	:= 	-Werror -Wall -Wextra -I$(INCDIR) -o
RM		:=	/bin/rm -f

# Files :
SRC		:=	
OBJ		:=	$(SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
