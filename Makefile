# TARGET
NAME=leak_killer.a

# VARIABLES
SRC=exit_error.c free_heap.c get_head.c get_node.c lfmalloc.c lfree.c set_head.c track_memory.c
OBJ=$(SRC:.c=.o)
HEADER=leak_killer.h

# PHONY RULES
.PHONY: all
all: $(NAME)

.PHONY: re
re: fclean $(NAME)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: clean
clean:
	rm -rf $(OBJ)

# KITCHEN
$(NAME): $(OBJ) $(HEADER) clean

%.o: %.c $(HEADER)
	cc -Wall -Wextra -Werror -c $< -o $@
	ar -rcs $(NAME) $@

# MADE BY JETBLACK.