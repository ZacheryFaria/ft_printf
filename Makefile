CC=clang
CFLAGS=-Werror -Wextra -Wall -std=c89 -I libft/includes -I include
LIBFLAGS=-L libft/ -lft
TESTFLAGS=-I include test/test.c -o test/test
TEST2FLAGS=-I include test2/test.c -o test2/test
WANTFLAGS=-I include test/want.c -o test/want
NAME=libftprintf.a
SRC=$(wildcard src/*)
OBJ=$(SRC:src/%.c=%.o)

.PHONY: clean fclean all re norm norme debug test test2

VPATH = src obj libft/includes include

$(NAME): $(OBJ)
	@make -C libft
	@ar -r $(NAME) obj/*
	@ranlib $(NAME)

all: $(NAME)

%.o: %.c
	@mkdir -p obj
	@clang $(CFLAGS) -o obj/$@ -c $<

clean:
	@make -C libft/ clean
	@rm -rf obj/

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

test2: $(NAME)
	@cc -L . -lftprintf $(LIBFLAGS) $(TEST2FLAGS)
	./test2/test
	@rm -f test2/test

test: $(NAME)
	@sed s/ft_printf/printf/g test/test.c > test/want.c
	@cc -L . -lftprintf $(LIBFLAGS) $(TESTFLAGS)
	@cc -L . -lftprintf $(LIBFLAGS) $(WANTFLAGS)
	@./test/test > test/test.out
	@./test/want > test/want.out
	@rm -rf test/{test,want}
	diff test/test.out test/want.out
	@echo %%%%%%%%%%%
	@echo % PASSED! %
	@echo %%%%%%%%%%%
	@rm -rf test/{test,test.out,want,want.c,want.out}
	
norm:
	norminette src/. include/.

norme: norm
