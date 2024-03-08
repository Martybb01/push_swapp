NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -f

LIBFT = libft_super/libft.a
SRC_DIR     = src
OBJ_DIR     = .dir

SRCS := main.c \
free.c \
check_errors.c \
stack_init.c \
stack_utils.c \
parsing.c \
swap_op.c \
rotate_op.c \
rev_rotate_op.c \
push_op.c \
sort_small.c \
quick_sort.c \
rdx_sort.c \
sort_three.c \

OBJS := $(SRCS:.c=.o)


all: $(NAME)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@[ -f $(LIBFT) ] || make -C libft_super/
	$(info ${BOLD}Creating  -> ${BLUE}libft.a${NO_COLOR})
	$(CC) $(OBJS) -o $(NAME) $(LIBFT)
	echo "${BOLD}Creating  -> ${RED}$(NAME)${NO_COLOR}"
	${MAKE} spiderman


clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) $(OBJS)

fclean: clean
	make clean -C libft_super/
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
.SILENT:

RED         := ${shell tput setaf 1}
BLUE        := ${shell tput setaf 4}
NO_COLOR    := ${shell tput sgr0}
BOLD        := ${shell tput bold}

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
