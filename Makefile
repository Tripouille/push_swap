#VARIABLES#
HEADERS_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

PUSH_SWAP_EXECUTABLE = push_swap
PUSH_SWAP_HEADERS = $(addprefix $(HEADERS_DIR)/, algorithms.h benchmark.h)
PUSH_SWAP_SRCS = $(addprefix $(SRCS_DIR)/, push_swap.c \
										$(addprefix algorithms/, algorithms.c franky_sort.c quick_sort.c selection_sort.c) \
										$(addprefix benchmark/, benchmark.c benchmark_utils.c))

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

CHECKER_EXECUTABLE = checker
CHECKER_HEADERS = $(addprefix $(HEADERS_DIR)/, checker.h)
CHECKER_SRCS = $(addprefix $(SRCS_DIR)/, checker.c)
CHECKER_OBJS = $(CHECKER_SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

UTILS_HEADERS = $(addprefix $(HEADERS_DIR)/, utils.h ilist.h slist.h instructions.h stacks.h)
UTILS_SRCS = $(addprefix $(SRCS_DIR)/,	$(addprefix utils/, utils.c utils_numbers.c utils_str.c get_numbers.c stacks.c) \
										$(addprefix ilist/, ilist.c ilist_utils.c ilist_handling.c ilist_infos.c ilist_sort.c) \
										$(addprefix slist/, slist.c slist_utils.c slist_infos.c) \
										$(addprefix instructions/, instructions.c instructions_swap.c instructions_push.c \
																	instructions_rotate.c instructions_reverse_rotate.c))
UTILS_OBJS = $(UTILS_SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(HEADERS_DIR) -g3 -fsanitize=address
RM = rm -rf

#RULES#
all: $(CHECKER_EXECUTABLE) $(PUSH_SWAP_EXECUTABLE)

$(CHECKER_EXECUTABLE): $(CHECKER_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	@tput setaf 2 && echo "$@ done."
	@tput sgr0

$(PUSH_SWAP_EXECUTABLE): $(PUSH_SWAP_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	@tput setaf 2 && echo "$@ done."
	@tput sgr0

$(CHECKER_OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(CHECKER_HEADERS)
	@tput setaf 4
	$(CC) $(CFLAGS) -c $< -o $@

$(PUSH_SWAP_OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(PUSH_SWAP_HEADERS)
	@tput setaf 4
	$(CC) $(CFLAGS) -c $< -o $@

$(UTILS_OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(UTILS_HEADERS)
	@tput setaf 4
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@tput setaf 1
	$(RM) $(CHECKER_OBJS) $(PUSH_SWAP_OBJS) $(UTILS_OBJS)

fclean: clean
	$(RM) $(CHECKER_EXECUTABLE) $(PUSH_SWAP_EXECUTABLE)

re: fclean all

.PHONY: clean fclean re