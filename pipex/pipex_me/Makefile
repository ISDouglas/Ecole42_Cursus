# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 11:53:48 by layang            #+#    #+#              #
#    Updated: 2025/02/05 13:39:24 by layang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Werror -Wall -Wextra

#CFLAGS_B = -Werror -Wall -Wextra -fsanitize=address -fPIC
#CFLAGS = -Werror -Wall -Wextra
#-fsanitize=address

RM = rm -rf

SRCS = 	./pipex.c\
		pipex_utils.c

#SRCS_BONUS = srcs_bonus/checker.c\
			srcs_bonus/checker_utils.c
			
#OBJS = $(SRCS:.c=.o)

$(NAME) : $(SRCS)
	make bonus -C libft
	cc $(CFLAGS) $(SRCS) -o $(NAME) -Llibft -lft

all : $(NAME)

fclean : clean
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

#bonus : 
#	gcc $(CFLAGS) $(SRCS_BONUS) -Llibft -lft -o checker
	
.PHONY: all bonus clean fclean re