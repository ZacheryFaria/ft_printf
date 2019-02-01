CC=gcc
CFLAGS=-Werror -Wextra -Wall -std=c89 -I libft/includes -I include
LIBFLAGS=-L libft/ -lft
TESTFLAGS=-I include test/test.c -o test/test
NAME=libftprintf.a
SRC=$(wildcard src/*)
OBJ=$(SRC:src/%.c=%.o)

.PHONY: clean fclean all re norm norme debug test

VPATH = src obj libft/includes include

$(NAME): $(OBJ)
	@make -C libft
	@ar -r $(NAME) obj/*
	@ranlib $(NAME)

all: $(NAME)

%.o: %.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o obj/$@ -c $<

clean:
	@make -C libft/ clean
	@rm -rf obj/

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

test: $(NAME)
	@$(CC) $(TESTFLAGS) -L . -lftprintf $(LIBFLAGS) 
	@./test/test
	@rm -f test/test
	
norm:
	norminette src/. include/.

norme: norm
