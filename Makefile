# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elemarch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 14:22:58 by elemarch          #+#    #+#              #
#    Updated: 2015/03/09 16:41:15 by elemarch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lst
SRC =	lst_add.c		lst_create.c	lst_error.c		lst_find.c\
		lst_move.c		lst_clear.c
SRCD = ./
OBJ = $(SRC:.c=.o)
SRCF = $(addprefix $(SRCD), $(SRC))

all: $(NAME)

$(NAME):
	@echo "\033[1;33mStarting compilation...\033[0;0m"
	@gcc -Wall -Werror -Wextra -g -c $(SRCF)
	@echo "\033[0;31mCreating library...\033[0;0m"
	@ar rc lib$(NAME).a $(OBJ)
	@echo "\033[0;31mGenerating index...\033[0;0m"
	@ranlib lib$(NAME).a

clean:
	@echo "\033[1;33mRemoving objects files...\033[0;0m"
	@rm -rf $(OBJ)

fclean: clean
	@echo "\033[1;33mRemoving .a file...\033[0;0m"
	@rm -rf lib$(NAME).a

re: fclean all

test: all
	gcc main.c libft.a liblst.a
	./a.out
