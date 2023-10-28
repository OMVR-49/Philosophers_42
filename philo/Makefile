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

SRC = main.c utils.c routine.c util_lst.c time.c dead.c

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread
CC = cc
NAME = philo
BONUS_NAME = philo_bonus
RM = rm -fr
BNS = philo_bonus.c
OBJ = $(SRC:.c=.o)
OBJBNS = $(BNS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(OBJBNS)
	@$(CC) $(CFLAGS) $(OBJBNS) -o $(BONUS_NAME)

$(OBJ) : philosophers.h
$(OBJBNS) : philosophers_bonus.h

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@$(RM) $(OBJBNS)

re : fclean all