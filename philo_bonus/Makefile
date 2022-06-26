# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/12 09:04:08 by hmokhtar          #+#    #+#              #
#    Updated: 2022/06/26 12:02:10 by hmokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRC = ./check_args.c ./check_death.c ./data_fill.c ./end_program.c \
		./monitor.c ./philo_bonus.c ./print.c ./utils.c \

BONUS_INC = ./philo_bonus.h

FLAGS = -Wall -Wextra -Werror

CC = cc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJ) $(BONUS_INC)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(BONUS_INC)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all