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

CPPFLAGS	+=	-I include/

SRC		=	src/main.c		\
			src/strtoftab.c		\
			src/clear_stdin.c		\
			src/drive_car.c

OBJ		=	$(SRC:.c=.o)

NAME		=	ai

RUN_DIR		=	run/

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
		cp $(NAME) run && cd run && ./pipes.sh && cd ..

.PHONY:		all clean fclean re run
