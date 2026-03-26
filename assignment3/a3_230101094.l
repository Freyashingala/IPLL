%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int line_no = 1;
FILE *token_file;
FILE *st_file;

// Basic linked list for the Symbol Table
struct STNode {
    char *name;
    struct STNode *next;
};
struct STNode *st_head = NULL;

// Function to insert identifiers into the symbol table
void insert_st(char *name) {
    struct STNode *curr = st_head;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) return; // Ignore if already exists
        curr = curr->next;
    }
    struct STNode *new_node = (struct STNode *)malloc(sizeof(struct STNode));
    new_node->name = strdup(name);
    new_node->next = st_head;
    st_head = new_node;
}

// Function to print the symbol table to the file
void print_st() {
    struct STNode *curr = st_head;
    while (curr != NULL) {
        fprintf(st_file, "%s\n", curr->name);
        curr = curr->next;
    }
}
%}

/* Regular Expression Definitions */
DIGIT           [0-9]
NONZERO_DIGIT   [1-9]
NONDIGIT        [a-zA-Z_]
ID              {NONDIGIT}({NONDIGIT}|{DIGIT})*

INTEGER         {NONZERO_DIGIT}{DIGIT}*|0
FRACTIONAL      ({DIGIT}*\.{DIGIT}+|{DIGIT}+\.)
FLOAT           {FRACTIONAL}

ESCAPE          \\[\'\"\?\\abfnrtv]
CCHAR           ([^'\\\n]|{ESCAPE})
CHAR_CONST      \'{CCHAR}+\'

SCHAR           ([^\"\\\n]|{ESCAPE})
STRING_LITERAL  \"{SCHAR}*\"

%%

"/*"([^*]|\*+[^*/])*\*+"/" { 
    // Match multi-line comments and count newlines to maintain accurate line numbers
    for(int i = 0; yytext[i] != '\0'; i++) {
        if(yytext[i] == '\n') line_no++;
    }
}
"//".* { /* Ignore single-line comments */ }

\n              { line_no++; }
[ \t\r]+        { /* Ignore whitespace */ }

"break"|"default"|"return"|"void"|"case"|"float"|"short"|"double"|"char"|"for"|"signed"|"while"|"else"|"unsigned"|"long"|"_Bool"|"continue"|"if"|"static"|"do"|"int" { 
    fprintf(token_file, "<KEYWORD, %s>\n", yytext); 
}

"["|"]"|"("|")"|"{"|"}"|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|","|"#" { 
    fprintf(token_file, "<PUNCTUATOR, %s>\n", yytext); 
}

{ID}            { insert_st(yytext); fprintf(token_file, "<IDENTIFIER, %s>\n", yytext); }
{INTEGER}       { fprintf(token_file, "<INTEGER_CONST, %s>\n", yytext); }
{FLOAT}         { fprintf(token_file, "<FLOAT_CONST, %s>\n", yytext); }
{CHAR_CONST}    { fprintf(token_file, "<CHAR_CONST, %s>\n", yytext); }
{STRING_LITERAL} { fprintf(token_file, "<STRING_LITERAL, %s>\n", yytext); }

.               { printf("Error: Unrecognized token '%s' at line %d\n", yytext, line_no); }

%%

int yywrap() {
    return 1;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ./lexer <input_file>\n");
        return 1;
    }
    
    FILE *input = fopen(argv[1], "r");
    if (!input) {
        printf("Error opening input file.\n");
        return 1;
    }
    
    // Remember to rename these files to include your actual roll number!
    token_file = fopen("a3_roll_token.txt", "w");
    st_file = fopen("a3_roll_st.txt", "w");
    
    yyin = input;
    yylex();
    
    print_st();
    
    fclose(input);
    fclose(token_file);
    fclose(st_file);
    
    printf("Lexical analysis complete.\n");
    return 0;
}