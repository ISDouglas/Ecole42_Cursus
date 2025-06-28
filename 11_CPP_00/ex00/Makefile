# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: layang <layang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/26 16:23:39 by layang            #+#    #+#              #
#    Updated: 2025/06/28 12:38:35 by layang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** Color Definition ***** #

RED 	= \033[91m
YELLOW 	= \033[33m
GREEN 	= \033[92m
RESET 	= \033[0m

# **************************** #

NAME = megaphone

# Source Files
SRC_DIR 	= src
SRC     	= $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.cpp))

# Object Files
OBJS 		= $(SRC:.cpp=.o)

# Include and Flags
# INCLUDE 	= -Iincludes
CFLAGS 		= -Wall -Wextra -Werror -std=c++98
CC 			= c++

# Target
all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# $(NAME): $(OBJS)
# 	@echo "$(YELLOW) 🛠️  waiting for compilation...$(RESET)"
# 	@$(CC) $(OBJS) -o $(NAME) $(INCLUDE) $(CFLAGS)
# 	@echo "$(GREEN) 🤖  Compiled successful ✴️  $(NAME) ✴️$(RESET)"
$(NAME): $(OBJS)
	@echo "$(YELLOW) 🛠️  waiting for compilation...$(RESET)"
	@$(CC) $(OBJS) -o $(NAME) $(CFLAGS)
	@echo "$(GREEN) 🤖  Compiled successful ✴️  $(NAME) ✴️$(RESET)"

	
# Clean
clean:
	@$(RM) $(OBJS)
	@echo "$(RED) 🗑️  Deleted object files.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED) 🚽  Deleted ❄️  $(NAME) ❄️$(RESET)"

re: fclean all

bonus: re

.PHONY: all clean fclean re