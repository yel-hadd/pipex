NAME = pipex
HEADER = pipex.h
SRC := main.c \
	utils/count_words.c \
	utils/ft_bzero.c \
	utils/ft_lstclear.c \
	utils/ft_memcpy.c \
	utils/ft_strjoin.c \
	utils/get_path.c \
	utils/print_error.c \
	utils/execute_node.c \
	utils/ft_calloc.c \
	utils/ft_lstdelone.c \
	utils/ft_memset.c \
	utils/ft_strlen.c \
	utils/get_path_dirs.c \
	utils/split.c \
	utils/free_2d.c \
	utils/ft_lstadd_back.c \
	utils/ft_lstnew.c \
	utils/ft_strdup.c \
	utils/ft_strncmp.c \
	utils/is_valid.c

OBJ        := $(SRC:.c=.o)

%.o : %.c ${HEADER}
	gcc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) 
	@gcc -Wall -Werror -Wextra $(OBJ) -o pipex

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re