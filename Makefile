CC			= gcc

NAME1		= save_tester

NAME2		= charge_tester

CFLAG		= -Wall -Wextra -Werror

SRC			=	error_gestion.c

SAVE_SRC	=	save.c	\
				putvar_to_file.c

CHARGE_SRC	=	charge.c	\
				readvar_from_file.c

TEST_SRC	=	list_func.c	\
				test_creation.c

MAIN1		=	main1.c

MAIN2		=	main2.c

OBJ1		= $(SRC:.c=.o) $(SAVE_SRC:.c=.o) $(TEST_SRC:.c=.o) $(MAIN1:.c=.o)

OBJ2		= $(SRC:.c=.o) $(CHARGE_SRC:.c=.o) $(TEST_SRC:.c=.o) $(MAIN2:.c=.o)

DOBJ		= ./objs

OBJS1		= $(addprefix $(DOBJ)/, $(OBJ1))

OBJS2		= $(addprefix $(DOBJ)/, $(OBJ2))

all		:	$(NAME1) $(NAME2)

vpath %.c ./srcs/:./srcs/charge/:./srcs/save:./srcs/test/

$(DOBJ)/%.o:%.c
	@mkdir $(DOBJ) 2> /dev/null || true
	@$(CC) -c $< -o $@ $(CFLAG) -I./includes/

$(NAME1):	$(OBJS1)
		@echo "Objects files creation for "$(NAME1)
		@$(CC) -o $(NAME1) $(OBJS1) -I./includes/

$(NAME2):	$(OBJS2)
		@echo "Objects files creation for "$(NAME2)
		@$(CC) -o $(NAME2) $(OBJS2) -I./includes/

clean	:
		@echo -n "Cleaning objects and temporaries files..."
		@rm -rf $(DOBJ)
		@rm -rf *~
		@rm -rf \#*\#
		@echo "OK"

fclean	:	clean
		@echo -n "Erase exec file..."
		@rm -rf $(NAME1)
		@rm -rf $(NAME2)
		@echo "OK"

re		:	fclean all
