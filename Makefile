# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 22:51:44 by omiroshn          #+#    #+#              #
#    Updated: 2018/01/31 22:51:44 by omiroshn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
CC = clang
FILES = ft_printf

SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
OBJ_LIST = $(addsuffix .o, $(FILES))
# FLAGS = -Wall -Wextra -Werror -g
HEADERS = -I./includes/ -I./libft/includes/
MAKELIB = --no-print-directory -j3 -C

all: $(NAME)

.PHONY: all clean fclean re
.NOTPARALLEL: all $(NAME) clean fclean re 

# $(NAME): $(OBJ)
# 	@echo "\033[36mLinking...\033[0m"
# 	@ar rc $(NAME) $(OBJ)
# 	@ranlib $(NAME)
# 	@echo "\033[32m[ ✔ ] Binary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(NAME): $(OBJ) libft/libft.a
	@$(CC) $(OBJ) $(FLAGS) libft/libft.a $(HEADERS) -o $(NAME)
	@echo "."
libft/libft.a:
	@make $(MAKELIB) libft/
obj/%.o: src/%.c
	@$(CC) -o $@ $(FLAGS) $(HEADERS) -c $^
	@echo "\033[37mCompilation of \033[97m$(notdir $<) \033[0m\033[37mdone. \033[0m"
clean:
	@rm -rf $(OBJ)
	@echo "\033[31m[ ✔ ] Objects files \033[91m$(OBJ_LIST) \033[0m\033[31mremoved. \033[0m"
fclean: clean
	@make fclean $(MAKELIB) libft/
	@rm -rf $(NAME)
	@echo "\033[31m[ ✔ ] Binary \033[1;31m$(NAME) \033[1;0m\033[31mremoved.\033[0m"
re: fclean all