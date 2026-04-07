NAME = a4_230101094

all:
	flex $(NAME).l
	yacc -d $(NAME).y
	gcc lex.yy.c y.tab.c
	./a.out < $(NAME)_test.nc

clean:
	rm -f a.out lex.yy.c y.tab.c y.tab.h $(NAME)_token.txt $(NAME)_st.txt