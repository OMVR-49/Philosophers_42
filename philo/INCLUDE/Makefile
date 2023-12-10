# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 16:12:02 by ojebbari          #+#    #+#              #
#    Updated: 2023/10/04 14:37:06 by ojebbari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ../SRC/main.c ./SRC/utils.c ./SRC/routine.c ./SRC/util_lst.c ./SRC/time.c
	 ../SRC/dead.c

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread
CC = cc
NAME = philo
RM = rm -fr
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ) : philosophers.h

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all