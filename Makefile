NAME = push_swap
CC = cc
CFLAGS = -Wextra -Werror -Wall -g
RM = rm -f

LIBFT = libft_super/libft.a

SRC = main.c \
error_free.c \
stack_init.c \
stack_utils.c \
parsing.c \
swap_op.c \
rotate_op.c \
rev_rotate_op.c \
push_op.c

OBJ = $(SRC:.c=.o)

all: spiderman $(NAME)

$(NAME): lib_comp comp

lib_comp:
	make -C libft_super/

comp:
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	make clean -C libft_super/
	$(RM) $(NAME)

re: fclean all

spiderman:
	@echo '⠀⠀⠀⢀⣤⠶⢞⠉⢉⡽⠁⠈⡗⠶⢤⣀⠀⠀⠀⠀'
	@echo '⠀⢀⡴⢻⠁⠀⢼⠉⠀⢰⠀⠀⡷⢄⠀⠹⠷⡄⠀⠀'
	@echo '⠀⡎⡀⠼⠉⠀⢨⠤⠐⢸⠀⠠⣧⠀⠈⡟⠄⣘⡄⠀'
	@echo '⠸⣿⡀⠀⠧⠊⠀⠆⠀⣸⡀⢀⠀⠀⠲⠀⠀⣼⣱⠀'
	@echo '⣶⣿⣿⣎⡀⢡⠄⠚⠁⢸⠀⠙⠂⣴⠁⣠⣾⣿⣿⡄'
	@echo '⣿⣿⠈⠛⢿⣥⡐⡤⢓⢹⢁⠣⡔⣠⣿⠟⠋⢸⣿⡇'
	@echo '⡏⣿⠀⠀⠀⠙⢿⣦⣾⣽⣽⣮⣾⠟⠁⠀⠀⢸⡿⡇'
	@echo '⢹⠿⣧⠀⠀⠀⠀⣹⣿⣿⣿⣿⡁⠀⠀⠀⢠⣿⢿⠃'
	@echo '⢸⣇⠻⣷⣤⣤⣾⡿⢻⢽⠼⠻⣿⣦⣤⣴⡿⠇⣿⠀'
	@echo '⠈⡏⢢⡨⠛⢉⡔⠉⠆⢠⠄⢓⠉⢢⡝⠛⢤⠊⡎⠀'
	@echo '⠀⠘⣼⠁⢠⠊⠈⡾⠠⢠⡠⠔⠏⠀⢱⡄⢉⡾⠀⠀'
	@echo '⠀⠀⠈⢲⣾⠀⢰⠅⠀⢈⢀⡀⠼⠎⢁⣷⡝⠁⠀⠀'
	@echo '⠀⠀⠀⠀⠙⢌⢺⠄⢀⠈⢁⣀⠤⣟⡵⠋⠀⠀⠀⠀'
	@echo '⠀⠀⠀⠀⠀⠀⠈⠂⠤⠬⠭⠤⠚⠁⠀⠀⠀⠀⠀⠀'
