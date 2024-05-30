# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 12:48:38 by fvizcaya          #+#    #+#              #
#    Updated: 2024/05/28 14:05:58 by fvizcaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror

NAME = minitalk
SRC = client.c server.c utils.c
SRC_BONUS = client_bonus.c server_bonus.c utils_bonus.c
PRINTF_LIB = ft_printf/libftprintf.a
PRINTF_DIR = ft_printf/
FOO = .minitalk
FOO_BONUS = .minitalk_bonus

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(FOO) 
	
$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(FOO): $(OBJ) $(PRINTF_LIB)
	$(CC) client.o utils.o $(PRINTF_LIB) -o client
	$(CC) server.o utils.o $(PRINTF_LIB) -o server
	@touch .minitalk

bonus: $(FOO_BONUS)

$(FOO_BONUS): $(OBJ_BONUS) $(PRINTF_LIB)
	$(CC) client_bonus.o utils_bonus.o $(PRINTF_LIB) -o client_bonus
	$(CC) server_bonus.o utils_bonus.o $(PRINTF_LIB) -o server_bonus
	@touch .minitalk_bonus

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
	make clean -C $(PRINTF_DIR) 

fclean: clean
	rm -rf client server client_bonus server_bonus 
	@ rm -f .minitalk .minitalk_bonus
	make fclean -C $(PRINTF_DIR)
	
re: fclean all

.PHONY: all clean fclean re bonus