# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tvan-kop <tvan-kop@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/04/10 15:03:48 by tvan-kop      #+#    #+#                  #
#    Updated: 2026/05/22 12:15:57 by andjajas      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
GREEN_BOLD = \033[1;32m
RED = \033[0;91m
RESET = \033[0;0m

NAME = push_swap
CC = cc
CFLAGS = -Wextra -Wall -Werror -O3
SOURCE = assign_rank.c \
convert_to_lst.c \
ft_printf_bench.c \
ft_printf_bench_utils.c \
ft_supersplit.c \
ft_supersplit_utils.c \
libft_functions1.c \
libft_functions2.c \
main.c \
medium_assign_chunks.c \
medium_needed_rotations.c \
ops_push.c \
ops_put_operation.c \
ops_rev_rotate.c \
ops_rotate.c \
ops_swap.c \
print_bench.c \
push_swap.c \
set_settings.c \
solve_complex.c \
solve_medium.c \
solve_simple.c \
solve_super_ez.c \
stack_utils.c

OBJECT_FILES = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	@echo "Linking object files and making the program..."
	@$(CC) $(OBJECT_FILES) -o $(NAME)
	@echo "$(GREEN_BOLD)Done$(RESET)"

%.o: %.c
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECT_FILES)
	@echo "$(RED)Removed all object files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed the progam.$(RESET)"

re: fclean all

program: all clean

debug:
	$(CC) -Wextra -Wall -O0 -g $(SOURCE) -o $(NAME)
	gdb ./$(NAME)

help:
	@echo "\
Usage:\n\
make help	Shows this help menu.\n\
make all	Makes the $(NAME) program, along with all of its object files.\n\
make		Same as make all.\n\
make clean	Removes all object files (.o files).\n\
make fclean	Does clean and removes the binary progam $(NAME).\n\
make re		Does fclean, then remakes the program.\n\
make program	Does make all, then cleans up the object files.\n\
make debug	Remakes the $(NAME) program in debug mode, compiling with flags -O0 and -g.\
"

.PHONY: all clean fclean re program program debug help
