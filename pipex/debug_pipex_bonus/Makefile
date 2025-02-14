# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 11:53:48 by layang            #+#    #+#              #
#    Updated: 2025/02/14 10:42:38 by layang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Werror -Wall -Wextra -fsanitize=address -fPIC

#CFLAGS_B = -Werror -Wall -Wextra -fsanitize=address -fPIC

RM = rm -rf

SRCS = 	./pipex.c\
		pipex_utils.c

SRCS_BONUS = ./pipex_bonus.c\
			pipex_utils.c\
			pipex_utils_bonus.c

$(NAME) : 
	$(RM) $(NAME)
	$(MAKE) fclean
	$(MAKE) bonus -C libft
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
	$(MAKE) clean
	$(MAKE) bonus -C libft
	cc $(CFLAGS) $(SRCS_BONUS) -o $(NAME) -Llibft -lft

tester1:
	git clone git@github.com:michmos/42_pipex_tester.git || true
	cd 42_pipex_tester && bash run.sh

tester2:
	git clone git@github.com:Yoo0lh/pipex_tester_42.git || true
	cd pipex_tester_42 && ./pipex_tester.sh a

.PHONY: all bonus clean fclean re