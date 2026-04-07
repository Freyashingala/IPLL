CC = gcc
LEX = flex
TARGET = lexer
LEX_FILE = a3_roll.l
C_FILE = lex.yy.c

all: $(TARGET)

$(TARGET): $(C_FILE)
	$(CC) $(C_FILE) -o $(TARGET)

$(C_FILE): $(LEX_FILE)
	$(LEX) $(LEX_FILE)

clean:
	rm -f $(TARGET) $(C_FILE) a3_roll_token.txt a3_roll_st.txt