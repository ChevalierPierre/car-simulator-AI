##
## EPITECH PROJECT, 2017
## minishell1
## File description:
## Makefile
##

SHELL		=	/bin/sh

RM		+=	-r

CP		?=	cp

MAKE		?=	make

CC		?=	gcc

CFLAGS		+=	-Wall -Wextra -Wshadow -O3

CPPFLAGS	+=	-I.

SRC		=	main.c		\
			joystick.c

OBJ		=	$(SRC:.c=.o)

NAME		=	ai

RUN_DIR		=	../../run/

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)
		$(RM) $(RUN_DIR)$(NAME)

re:		fclean all

run:		all
		cp $(NAME) $(RUN_DIR) && cd $(RUN_DIR) && ./pipes.sh

.PHONY:		all clean fclean re run
