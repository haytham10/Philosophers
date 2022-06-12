# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/12 09:04:08 by hmokhtar          #+#    #+#              #
#    Updated: 2022/06/12 09:20:31 by hmokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher

SRC = philo.c init.c utils.c

OBJ = $(SRC:.c=.o)

INC = philo.h

FLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(SRC) $(OBJ) $(INC)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all