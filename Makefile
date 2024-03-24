NAME        = push_swap
NAME_BONUS  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -f

LIBFT = libft_super/libft.a

SRCS_COMMON := check_errors.c \
free.c \
stack_init.c \
stack_utils.c \
sort_utils.c \
parsing.c \
swap_op.c \
rotate_op.c \
rev_rotate_op.c \
push_op.c \
sort_small.c \
quick_sort.c \
sort_three.c \
big_sort.c \

SRCS_MAIN := main.c 
SRCS_CHECKER := checker.c 


OBJS_MAIN := $(SRCS_COMMON:.c=.o) $(SRCS_MAIN:.c=.o)
OBJS_CHECKER :=  $(SRCS_COMMON:.c=.o) $(SRCS_CHECKER:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

/%.o: /%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS_MAIN)
	@[ -f $(LIBFT) ] || make -C libft_super/
	$(info ${BOLD}Creating  -> ${BLUE}libft.a${NO_COLOR})
	$(CC) $(OBJS_MAIN) -o $(NAME) $(LIBFT)
	echo "${BOLD}Creating  -> ${RED}$(NAME)${NO_COLOR}"
	${MAKE} spiderman

$(NAME_BONUS): $(OBJS_CHECKER)
	@[ -f $(LIBFT) ] || make -C libft_super/
	$(info ${BOLD}Creating  -> ${BLUE}libft.a${NO_COLOR})
	$(CC) $(OBJS_CHECKER) -o $(NAME_BONUS) $(LIBFT)
	echo "${BOLD}Creating  -> ${RED}$(NAME_BONUS)${NO_COLOR}"
	${MAKE} spiderman


clean:
	$(RM) $(OBJS) $(OBJS_CHECKER)
	echo "\n✅ ${RED}SUCCESS:${NO_COLOR} ${BOLD}Objs files have been deleted"

fclean: clean
	make clean -C libft_super/
	$(RM) $(NAME) $(NAME_BONUS)
	echo "\n✅ ${RED}SUCCESS:${NO_COLOR} ${BOLD}Objs files $(NAME) and $(NAME_BONUS) have been deleted\n"

re: fclean all

.PHONY: clean fclean re all bonus
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
