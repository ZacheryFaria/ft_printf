CC=gcc
CFLAGS=-Werror -g -Wextra -Wall -std=c89 -I libft -I . -fsanitize=address
LIBFLAGS=-g -L libft/ -lft -fsanitize=address
TESTFLAGS=-g -I. test/test.c -o test/test -fsanitize=address
NAME=libftprintf.a
SRC=$(wildcard src/*)
OBJ=$(SRC:src/%.c=%.o)

.PHONY: clean fclean all re norm norme debug test

VPATH = src obj libft/includes include

$(NAME): update $(OBJ)
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

update:
	@./update.sh
	
norm:
	norminette src/. include/.

norme: norm
