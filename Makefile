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
PRINTFLIB = liftprintf.a
CC = clang
FILES = ft_printf
FILES_LIBFT = ft_atoi ft_bzero ft_countwords ft_isalpha ft_isdigit ft_isprint \
ft_itoa ft_itoa_base ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter \
ft_lstmap ft_memset ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_memalloc \
ft_memdel ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr_fd ft_putnbr \
ft_putstr ft_putstr_fd ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strncat \
ft_strlcat ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strcmp ft_strncmp ft_toupper \
ft_tolower ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strmap ft_strmapi \
ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim ft_strsplit get_next_line \
ft_atoi_base rgb_to_int rgb_smooth

SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
SRC_LIBFT = $(addprefix libft/, $(addsuffix .c, $(FILES_LIBFT)))
OBJ_LIBFT = $(addprefix libft/obj/, $(addsuffix .o, $(FILES_LIBFT)))
OBJ_LIBFT_LIST = $(addsuffix .o, $(FILES_LIBFT))
OBJ_LIST = $(addsuffix .o, $(FILES))
# FLAGS = -Wall -Wextra -Werror -g
HEADERS = -I./includes/
HEADERS_LIB = -I./libft/includes/
MAKELIB = --no-print-directory -j3 -C

all: $(PRINTFLIB)

.PHONY: all clean fclean re
.NOTPARALLEL: all $(PRINTFLIB) clean fclean re 

$(PRINTFLIB): $(OBJ) $(OBJ_LIBFT)
	ar rcs $(PRINTFLIB) $(OBJ) $(OBJ_LIBFT)
	ranlib $(PRINTFLIB)
	@echo  "\033[1;32m$(PRINTFLIB) \033[1;0m\033[32mis done! \033[0m"

# $(NAME): $(OBJ) libft/libft.a
# 	@$(CC) $(OBJ) $(FLAGS) libft/libft.a $(HEADERS) -o $(NAME)
# 	@echo "."

$(OBJ): obj/%.o: src/%.c
	$(CC) -o $@ $(FLAGS) $(HEADERS) -c $^
	@echo "\033[37mCompilation of \033[97m$(notdir $<) \033[0m\033[37mdone. \033[0m"

$(OBJ_LIBFT): libft/obj/%.o: libft/%.c
	$(CC) -o $@ $(FLAGS) $(HEADERS_LIB) -c $^
	@echo "\033[37mCompilation of \033[97m$(notdir $<) \033[0m\033[37mdone. \033[0m"

clean:
	rm -rf $(OBJ)
	@echo "\033[31m[ ✔ ] Objects files \033[91m$(OBJ) \033[0m\033[31mremoved. \033[0m"
	rm -rf $(OBJ_LIBFT)
	@echo "\033[31m[ ✔ ] Objects files \033[91m$(OBJ_LIST) \033[0m\033[31mremoved. \033[0m"
fclean: clean
	rm -rf $(PRINTFLIB)
	@echo "\033[31m[ ✔ ] Binary \033[1;31m$(PRINTFLIB) \033[1;0m\033[31mremoved.\033[0m"
re: fclean all