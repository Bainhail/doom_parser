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
	@$(CC) -c $< -o $@ $(CFLAG) -I./includes/

$(NAME)	:	$(OBJS)
		@echo -n "Objects files creation..."
		@$(CC) -o $(NAME) $(OBJS) -I./includes/
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
