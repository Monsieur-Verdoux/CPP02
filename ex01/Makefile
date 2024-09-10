# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 16:09:27 by akovalev          #+#    #+#              #
#    Updated: 2024/09/10 16:09:30 by akovalev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Fixed
CFLAGS := -Wall -Wextra -Werror
SRC := main.cpp Fixed.cpp
OBJ := $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	@c++ $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@c++ $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re