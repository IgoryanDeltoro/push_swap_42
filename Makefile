NAME = pushswap.a

FLAGS = -Wall -Wextra -Werror 

CC = cc $(FLAGS)

AR = ar rcs

RM = rm -rf

SRC =	./src/push_swap.c  ./src/utils/ft_atoi.c ./src/utils/ft_lstadd_front.c \
		./src/utils/ft_lstnew.c ./src/utils/ft_lstadd_back.c ./src/utils/ft_lstlast.c \
		./src/utils/ft_isdigit.c ./src/utils/ft_strcmp.c ./src/utils/has_duplicate.c \
		./src/utils/ft_lstclean.c ./src/utils/ft_lstsize.c ./src/utils/ft_split.c  \
		./src/actions/ft_ss.c ./src/actions/ft_ra.c ./src/actions/ft_rb.c \
		./src/actions/ft_rr.c ./src/actions/ft_rra.c ./src/actions/ft_rrb.c \
		./src/actions/ft_rrr.c ./src/actions/ft_pa.c ./src/actions/ft_pb.c \
		./src/actions/ft_sa.c  ./src/actions/ft_sb.c ./src/sort_3_num.c  \
		./src/sort_2_num.c ./src/utils/ft_strlcpy.c ./src/utils/ft_strlen.c \
		./src/utils/ft_count_words.c ./src/sort_huge_num.c ./src/sort_4_6_num.c \
		./src/actions/rotate_to_top.c ./src/actions/find_index.c ./src/utils/ft_swap.c \
		

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
