# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 19:07:24 by willda-s          #+#    #+#              #
#    Updated: 2025/04/26 03:34:51 by willda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDE = -Iincludes

ALGO_DIR = algo/

ALGO_FILES = 	algo_twothree.c \
				algo_fourfive.c \
				algorithm.c \
				tri_index.c

PARSING_DIR = parsing/

PARSING_FILES = parsing_digit.c \
				parsing_double.c \
				parsing_overflow.c \
				parsing_utils.c \
				parsing.c

INSTRUCTIONS_DIR = instructions/

INSTRUCTIONS_FILES =	instructions.c \
						instructions2.c \
						instructions3.c

UTILS_DIR = utils/

UTILS_FILES = 	ft_lst.c \
				lst_utils.c \
				function_free.c \
				main.c

MAKEFLAGS += --no-print-directory

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -MMD -g3

FILE = 	$(addprefix $(ALGO_DIR), $(ALGO_FILES))\
		$(addprefix $(PARSING_DIR), $(PARSING_FILES))\
		$(addprefix $(INSTRUCTIONS_DIR), $(INSTRUCTIONS_FILES))\
		$(addprefix $(UTILS_DIR), $(UTILS_FILES))
		
OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(FILE:.c=.o))
DEPD = $(addprefix $(OBJ_DIR), $(FILE:.c=.d))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: lib $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ_DIR)%.o: %.c Makefile
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

-include $(DEPD)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:	clean
	$(MAKE) -C $(LIBFT_DIR) fclean	
	rm -f $(NAME)      

lib:
	$(MAKE) -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re lib
