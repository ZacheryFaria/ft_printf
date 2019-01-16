CC=clang
CFLAGS=-Werror -Wextra -Wall -std=c89 -I libft/includes -I include
LIBFLAGS=-L libft/ -lft
TESTFLAGS=-I include test/test.c -o test/test -g
WANTFLAGS=-I include test/want.c -o test/want -g
NAME=libftprintf.a
SRC=ft_printf.c fmt.c digit.c character.c
OBJ=$(SRC:%.c=%.o)

.PHONY: clean fclean all re norm norme debug

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

test: re
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
