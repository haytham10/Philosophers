# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/12 09:04:08 by hmokhtar          #+#    #+#              #
#    Updated: 2022/06/18 14:29:22 by hmokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

BONUS_EXE = philo_bonus

SRC_PATH = ./src

SRC = philo.c init.c utils.c

SRC_INC = ./src/philo.h

BONUS_PATH = ./bonus

BONUS = check_args.c check_death.c data_fill.c end_program.c \
		monitor.c philo_bonus.c print.c utils.c \

BONUS_INC = ./bonus/philo_bonus.h

FLAGS = -Wall -Wextra -Werror

CC = cc

SRC_NAME = $(addprefix $(SRC_PATH)/, $(SRC))

SRC_OBJ = $(SRC_NAME:.c=.o)

BONUS_NAME = $(addprefix $(BONUS_PATH)/, $(BONUS))

BONUS_OBJ = $(BONUS_NAME:.c=.o)

all: $(NAME)

$(NAME): $(SRC_NAME) $(SRC_OBJ) $(SRC_INC)
	@$(CC) $(FLAGS) $(SRC_OBJ) -o $(NAME)

bonus: $(BONUS_EXE)

$(BONUS_EXE): $(BONUS_NAME) $(BONUS_OBJ) $(BONUS_INC)
	@$(CC) $(FLAGS) $(BONUS_OBJ) -o $(BONUS_EXE)

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(SRC_OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -rf $(NAME) $(BONUS_EXE)

re: fclean all