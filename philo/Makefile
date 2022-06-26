# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/12 09:04:08 by hmokhtar          #+#    #+#              #
#    Updated: 2022/06/26 11:59:52 by hmokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = ./philo.c ./allocate.c ./check_args.c ./free_all.c ./manage.c \
		./print.c ./thread_init.c \

SRC_INC = philo.h

FLAGS = -Wall -Wextra -Werror

CC = cc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJ) $(SRC_INC)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(SRC_INC)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all