NAME = push_swap
NAMEC = checker
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = main.c get_next_line.c get_next_line_utils.c ft_atoi.c ft_split.c operations.c \
       parsing.c sorting.c sorting_part_two.c sorting_part_three.c parsing_two.c \
	   longest_increasing_subsequence.c
SRCSB = checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c ft_atoi_bonus.c ft_split_bonus.c \
       parsing_bonus.c init_bonus.c chekers_operations_bonus.c parsing_two_bonus.c \
	   operations_bonus.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
HEADER = push_swap.h
HEADERB = push_swap_bonus.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAMEC): $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) -o $(NAMEC)

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSB): %.o: %.c $(HEADERB)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAMEC)

clean:
	rm -rf $(OBJS) 
	rm -rf $(OBJSB)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAMEC)

re: fclean all

.PHONY: all clean fclean re