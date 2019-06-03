#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naali <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 17:26:53 by naali             #+#    #+#              #
#    Updated: 2019/05/30 18:18:02 by naali            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC		= gcc

NAME	= file_tester

CFLAG	= -Wall -Wextra

SRC		= test.c

OBJ		= $(SRC:.c=.o)

DOBJ	= ./objs

OBJS	= $(addprefix $(DOBJ)/, $(OBJ))


all		:	$(NAME)

vpath %.c ./:./srcs/

$(DOBJ)/%.o:%.c
	@mkdir $(DOBJ) 2> /dev/null || true
	@$(CC) -c $< -o $@ $(CFLAG)

$(NAME)	:	$(OBJS)
		@echo -n "Objects files creation..."
		@$(CC) -o $(NAME) $(OBJS)
		@echo "OK"

clean	:
		@echo -n "Cleaning objects and temporaries files..."
		@rm -rf $(DOBJ)
		@rm -rf *~
		@rm -rf \#*\#
		@echo "OK"

fclean	:	clean
		@echo -n "Erase exec file..."
		@rm -rf $(NAME)
		@echo "OK"

re		:	fclean all
