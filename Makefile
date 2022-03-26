NAME = push_swap
INC = push_swap.h
BONUS_NAME = checker
SRCS = assign_functions.c utils2.c utils1.c basic_tests.c ft_sort_big_stack.c ft_sort_medium_stack.c insert_element_to_stack.c  push.c reverse_rotate.c rotate.c swap.c main.c Fonctions_utils/ft_split.c Fonctions_utils/ft_strjoin.c Fonctions_utils/ft_strlcpy.c \

BONUS_SRCS = assign_functions.c utils1.c utils2.c basic_tests.c ft_sort_big_stack.c ft_sort_medium_stack.c insert_element_to_stack.c push.c reverse_rotate.c rotate.c swap.c checker.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c  \

OBJ = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(FLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

%.o: %.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)
bonus : $(BONUS_NAME)
clean :
	rm -f $(BONUS_OBJ) $(OBJ)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re : clean fclean all