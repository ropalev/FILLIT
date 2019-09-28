NAME := fillit
CC := gcc

SRC := main.c map.c parser.c print_shape.c solver.c structe.c tetramino_function.c ft_sqrt.c
OBJ := $(patsubst %.c, %.o, $(SRC))

LIB_FLAG := -Llibft/ -lft
CFLAGS := -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c fillit.h
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo $(patsubst %.c, %, $<)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) $(CFLAGS) $(LIB_FLAG) $(OBJ)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean $(NAME)