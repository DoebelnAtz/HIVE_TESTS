COMPILER = GCC

NAME = libftprintf.a

test:
	@ $(COMPILER) main.c $(NAME) -Wno-format -o test
	@./test 1 2 > output
	@cat output | sed 's/ft:..//g' | tail -n57 > printfout
	@cat output | sed 's/ft:..//g' | head -n58 | tail -n57 | cut -c -22 > ftout
	@rm output
	@diff printfout ftout > testoutput

norme:
	@norminette ./libft/
	@norminette $(HEADER)
	@norminette $(SRC)

clean:
	@rm printfout ftout output

.PHONY: clean