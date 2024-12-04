NAME = pushswap.a

FLAGS = -Wall -Wextra -Werror 

CC = cc $(FLAGS)

AR = ar rcs

RM = rm -rf

SRC =	./src/push_swap.c  ./src/utils/ft_atoi.c  ./src/actions/move_nodes.c \
		./src/utils/ft_lstnew.c ./src/utils/ft_lstadd_back.c ./src/utils/ft_lstlast.c \
		./src/utils/ft_strcmp.c ./src/utils/has_duplicate.c ./src/actions/set_curr_position.c\
		./src/utils/ft_lstclean.c ./src/utils/ft_lstsize.c ./src/utils/ft_split.c  \
		./src/actions/swap_node.c ./src/actions/rotate_node.c ./src/actions/reverse_rotate_node.c \
		./src/actions/push_node.c ./src/actions/handle_actions.c ./src/actions/print_actions.c \
		./src/sort_3_num.c  ./src/actions/get_smallest.c  ./src/actions/get_cheapest.c \
		./src/sort_2_num.c ./src/utils/ft_strlcpy.c ./src/utils/ft_strlen.c ./src/sort_huge_num.c \
		./src/actions/rotate_smallest.c ./src/actions/is_stack_sorted.c ./src/utils/ft_count_words.c  \
		
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

.c.o:
	@$(CC) -c $< -o $@

all: $(NAME)
	
clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all 
