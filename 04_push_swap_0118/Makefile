# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 12:39:12 by layang            #+#    #+#              #
#    Updated: 2025/01/18 14:47:28 by layang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	./main.c\
		srcs/operations/pa_pb.c\
		srcs/operations/ra_rb_rr.c\
		srcs/operations/rra_rrb_rrr.c\
		srcs/operations/sa_sb_ss.c\
		srcs/utils/put_a_index.c\
		srcs/utils/sort_long.c\
		srcs/utils/sort_short.c

#OBJS = $(SRCS:.c=.o)

$(NAME) : $(SRCS)
	make bonus -C libft
	cc $(CFLAGS) $(SRCS) -Llibft -lft -o $(NAME) 

all : $(NAME)

fclean : clean
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

bonus : 
	make bonus -C libft
	gcc $(CFLAGS) $(SRCS_BONUS) -o checker