NAME = a3_230101094

all:
	flex $(NAME).l
	gcc lex.yy.c -lfl
	./a.out $(NAME)_test.nc

clean:
	rm -f a.out lex.yy.c $(NAME)_token.txt $(NAME)_st.txt