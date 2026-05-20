# **************************************************************************** #
#                                                                              #
#                                                        ::::::::              #
#    Makefile                                          :+:    :+:              #
#                                                     +:+                      #
#    By: tvan-kop <tvan-kop@student.codam.nl>        +#+                       #
#                                                   +#+                        #
#    Created: 2026/04/10 15:03:48 by tvan-kop     #+#    #+#                   #
#    Updated: 2026/04/10 15:03:48 by tvan-kop     ########   odam.nl           #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CC = cc
CFLAGS = -Wextra -Wall -Werror -O3
SOURCE = *.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCE) -o $(NAME)

clean:
	@echo "Nothing to clean!"

fclean:
	rm -f $(NAME)

re: fclean all

debug:
	$(CC) -Wextra -Wall -O0 -g $(SOURCE) -o $(NAME)
	gdb ./push_swap

help:
	@echo "\
Usage:\n\
make help	Shows this help menu.\n\
make all	Makes the $(NAME) program.\n\
make		Same as make all.\n\
make clean	Does not delete anything..?\n\
make fclean	Removes $(NAME).\n\
make re		Does fclean, then remakes the program.\n\
make debug	Remakes the $(NAME) program in debug mode.\n\
"

.PHONY: all clean fclean re program help
