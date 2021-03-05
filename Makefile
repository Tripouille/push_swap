#VARIABLES#
HEADERS_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

PUSH_SWAP_EXECUTABLE = push_swap
PUSH_SWAP_HEADERS = $(addprefix $(HEADERS_DIR)/, )
PUSH_SWAP_SRCS = $(addprefix $(SRCS_DIR)/, push_swap.c list.c)
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

CHECKER_EXECUTABLE = checker
CHECKER_HEADERS = $(addprefix $(HEADERS_DIR)/, checker.h)
CHECKER_SRCS = $(addprefix $(SRCS_DIR)/, checker.c utils_str.c utils_nb.c)
CHECKER_OBJS = $(CHECKER_SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(HEADERS_DIR)
RM = rm -rf

#RULES#
all: $(CHECKER_EXECUTABLE) $(PUSH_SWAP_EXECUTABLE)

$(CHECKER_EXECUTABLE): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	@tput setaf 2 && echo "$@ done."

$(PUSH_SWAP_EXECUTABLE): $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	@tput setaf 2 && echo "$@ done."

$(CHECKER_OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(CHECKER_HEADERS)
	@tput setaf 4
	$(CC) $(CFLAGS) -c $< -o $@

$(PUSH_SWAP_OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(PUSH_SWAP_HEADERS)
	@tput setaf 4
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@tput setaf 1
	$(RM) $(CHECKER_OBJS) $(PUSH_SWAP_OBJS)

fclean: clean
	$(RM) $(CHECKER_EXECUTABLE) $(PUSH_SWAP_EXECUTABLE)

re: fclean all

.PHONY: clean fclean re