# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 17:32:59 by ktombola          #+#    #+#              #
#    Updated: 2025/06/06 17:50:29 by ktombola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRC = main.c pipex_utils.c pipex_utils2.c pipex_utils3.c
OBJ = $(SRC:.c=.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes -Ilibft

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	$(CC) $(CCFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

veryclean: fclean
	rm -f outfile

re: fclean all

debug: $(OBJ)
	$(CC) $(CCFLAGS) -g -fsanitize=address $(OBJ) -Llibft -lft -o $(NAME)

.PHONY: all clean fclean re libft debug