NAME=libft.a
CC=gcc
IDIR=include
CFLAGS=-I. -g -Wall -Werror -Wextra
CFLAGS_SPEED=-finline-functions -Ofast
DEPS=libft.h

vpath %.c src obj

OBJ = $(subst .c,.o,$(subst src/*,obj,$(shell find . -name *.c)))

obj/%.o: %.c
	@mkdir -p obj
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	ar rcs $@ $^
	ranlib $(NAME)
	

.PHONY: clean re fclean all
all: $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) obj/

re : fclean $(NAME)

test: $(NAME)
	$(CC) $(CFLAGS) test.c $(NAME)
	./a.out

norm:
	norminette src/. libft.h
