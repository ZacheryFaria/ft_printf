CC=gcc
CFLAGS=-Werror -g -Wextra -Wall -I libft -I include 
LIBFLAGS=-g -L libft/ -lft 
TESTFLAGS=-g -Iinclude test/test.c -o test/test 
NAME=libftprintf.a
SRC=$(wildcard src/*)
OBJ=$(SRC:src/%.c=%.o)

.PHONY: clean fclean all re norm norme debug test

VPATH = src obj libft/includes include

$(NAME): $(OBJ)
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@ar -rc $(NAME) obj/*
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
	
norm:
	norminette src/. include/.

norme: norm
