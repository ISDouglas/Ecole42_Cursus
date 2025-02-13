# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 11:53:48 by layang            #+#    #+#              #
#    Updated: 2025/02/13 11:10:26 by layang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Werror -Wall -Wextra

#CFLAGS_B = -Werror -Wall -Wextra -fsanitize=address -fPIC
#CFLAGS = -Werror -Wall -Wextra
#-fsanitize=address

RM = rm -rf

SRCS = 	./pipex.c\
		pipex_utils.c\
		pipex_utils_bonus.c

SRCS_BONUS = ./pipex_bonus.c\
			pipex_utils.c\
			pipex_utils_bonus.c

$(NAME) : 
	$(RM) $(NAME)
	make fclean
	make bonus -C libft
	cc $(CFLAGS) $(SRCS) -o $(NAME) -Llibft -lft

all : $(NAME)

fclean : clean
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

bonus :
	$(RM) $(NAME)
	make fclean
	make bonus -C libft
	cc $(CFLAGS) $(SRCS_BONUS) -o $(NAME) -Llibft -lft
	
.PHONY: all bonus clean fclean re