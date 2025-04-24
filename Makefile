# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 02:37:02 by willda-s          #+#    #+#              #
#    Updated: 2025/04/24 19:17:59 by willda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

INCLUDE = pushswap.h

CC	= cc

CFLAGS	= -Wall -Wextra -Werror -I $(INCLUDE) -g3

ALGO_DIR = algo/

ALGO_FILES = algo_twothree.c\
			algo_fourfive.c\
			algorithm.c\
			tri_index.c

PARSING_DIR = parsing/

PARSING_FILES = parsing_digit.c\
				parsing_double.c\
				parsing_overflow.c\
				parsing_utils.c\
				parsing.c

INSTRUCTIONS_DIR = instructions/

INSTRUCTIONS_FILES =	instructions.c\
						instructions2.c\
						instructions3.c

UTILS_DIR = utils/

UTILS_FILES = 	ft_lst.c\
				lst_utils.c\
				function_free.c


MAIN = 	main.c


FILE = 	$(addprefix $(ALGO_DIR), $(ALGO_FILES))\
		$(addprefix $(PARSING_DIR), $(PARSING_FILES))\
		$(addprefix $(INSTRUCTIONS_DIR), $(INSTRUCTIONS_FILES))\
		$(addprefix $(UTILS_DIR), $(UTILS_FILES))\
		$(MAIN)
		
OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(FILE:.c=.o))
DEPD = $(addprefix $(OBJ_DIR), $(FILE:.c=.d))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

$(OBJ_DIR)%.o : %.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@
		
all:	$(NAME)	$(LIBFT) $(PRINTF)

$(LIBFT) : force
		$(MAKE) -C $(LIBFT_DIR)

$(PRINTF) : force
		$(MAKE) -C $(PRINTF_DIR)

$(NAME) : $(OBJ) $(LIBFT) $(PRINTF) $(INCLUDE)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(PRINTF)
	
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:	clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

force :

re:	fclean all

-include $(DEPS)

.PHONY : all, clean, fclean, re, force
