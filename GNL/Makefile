NAME = test_gnl


all: $(NAME)

$(NAME):
	@make -C libft/
	@clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	@clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	@clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

test: all
	./test_gnl a b c d
	@diff -U3 output correct
	@rm output

clean:
	@make -C libft/ clean
	@rm -rf *.o

fclean: clean
	rm test_gnl

re: fclean all