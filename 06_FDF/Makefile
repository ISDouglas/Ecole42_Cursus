# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 11:25:10 by layang            #+#    #+#              #
#    Updated: 2025/03/04 19:44:58 by layang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Werror -Wall -Wextra
DEBUG = -g

#CFLAGS_B = -Werror -Wall -Wextra -fsanitize=address -fPIC

RM = rm -rf

SRC_F = ./src/
SRC_C = draw_map_img.c\
        fdf.c\
        utils_color.c\
        draw_map_lines.c\
        hook_events.c\
        utils_math.c\
        draw_map_points.c\
        transforms.c\
        utils_transform.c

SRCS = $(addprefix $(SRC_F), $(SRC_C))

#SRCS_BONUS = pipex_bonus.c\
			pipex_utils.c\
			pipex_utils_bonus.c

LIBC =  -Llibft -Lminilibx-linux
LINKS = -lmlx -lft -lm -lpthread -lX11 -lXext

OBJS = $(SRCS:.c=.o)

CYAN = \033[0;36m
RESET = \033[0m

$(NAME) : $(OBJS)
	@echo ""
	@echo "${CYAN}Compiling libft and minilibx-linux...${RESET}"
	$(MAKE) bonus -C libft
	@echo ""
	$(MAKE) -C minilibx-linux
	@echo ""
	@echo "${CYAN}libft and minilibx-linux Created${RESET}"
	@echo ""
	@echo "${CYAN}Compiling $(NAME)...${RESET}"
	$(CC) $(CFLAGS) $(DEBUG) $(OBJS) -o $(NAME) $(LIBC) $(LINKS)
	@echo ""
	@echo "${CYAN}$(NAME) Created${RESET}"

all : $(NAME)

fclean : clean
	$(MAKE) fclean -C libft

clean :
	$(RM) $(NAME)
	$(MAKE) clean -C libft

re : fclean all

#bonus :
#	$(MAKE) bonus -C libft
#	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME) -Llibft -lft

.PHONY: all bonus clean fclean re