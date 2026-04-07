%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int line_no = 1;
FILE *token_file;
FILE *st_file;

// linked list for the SymTab
struct STNode {
    char *name;
    struct STNode *next;
};
struct STNode *st_head = NULL;

// insert identifiers into the symbol table
void insert_st(char *name) {
    struct STNode *curr = st_head;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) return; // ignore if already present in the table
        curr = curr->next;
    }
    struct STNode *new_node = (struct STNode *)malloc(sizeof(struct STNode));   // assigning space for the new node
    new_node->name = strdup(name);
    new_node->next = st_head;
    st_head = new_node; // setting new node as the head
}

// print the symbol table to file
void print_st() {
    struct STNode *curr = st_head;
    while (curr != NULL) {
        fprintf(st_file, "%s\n", curr->name);
        curr = curr->next;
    }
}
%}

/* lexical grammar */
/* 3. Identifiers */
DIGIT               [0-9]
NONDIGIT            [_a-zA-Z]
IDENTIFIER          {NONDIGIT}({NONDIGIT}|{DIGIT})*

/* 4. Constants */
NONZERO-DIGIT       [1-9]
INTEGER-CONSTANT    {NONZERO-DIGIT}{DIGIT}*|0

DIGIT-SEQUENCE      {DIGIT}+
SIGN                [+-]
FRACTIONAL-CONSTANT ({DIGIT-SEQUENCE}?\.{DIGIT-SEQUENCE}|{DIGIT-SEQUENCE}\.)
FLOATING-CONSTANT   {FRACTIONAL-CONSTANT}

C-CHAR              ([^'\\\n]|{ESCAPE-SEQUENCE})
C-CHAR-SEQUENCE     {C-CHAR}+
CHARACTER-CONSTANT  \'{C-CHAR-SEQUENCE}\'
ESCAPE-SEQUENCE     \\[\'\"\?\\abfnrtv]

/* 5. String Literals */
S-CHAR              ([^\"\\\n]|{ESCAPE-SEQUENCE})
S-CHAR-SEQUENCE     {S-CHAR}*
STRING-LITERAL      \"{S-CHAR-SEQUENCE}\"

%%
 /* Rules */
 /* 2. Keywords */
"break"|"default"|"return"|"void"|"case"|"float"|"short"|"double"|"char"|"for"|"signed"|"while"|"else"|"unsigned"|"long"|"_Bool"|"continue"|"if"|"static"|"do"|"int" { 
    fprintf(token_file, "<KEYWORD, %s>\n", yytext); 
}

 /* 3, 4, 5. Identifiers, Constants, and Strings */
{IDENTIFIER}          { insert_st(yytext); fprintf(token_file, "<IDENTIFIER, %s>\n", yytext); }
{INTEGER-CONSTANT}    { fprintf(token_file, "<INTEGER-CONST, %s>\n", yytext); }
{FLOATING-CONSTANT}   { fprintf(token_file, "<FLOAT-CONST, %s>\n", yytext); }
{CHARACTER-CONSTANT}  { fprintf(token_file, "<CHAR-CONST, %s>\n", yytext); }
{STRING-LITERAL}      { fprintf(token_file, "<STRING-LITERAL, %s>\n", yytext); }

 /* 6. Punctuators */
"["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|","|"#" { 
    fprintf(token_file, "<PUNCTUATOR, %s>\n", yytext); 
}

 /* 7. Comments */
"/*"([^*]|\*+[^*/])*\*+"/" { 
    for(int i = 0; yytext[i] != '\0'; i++) {
        if(yytext[i] == '\n') line_no++;    // counting newlines in multi-line comments to maintain correct line number
    }
}

 /* Ignore single-line comment */ 
"//".*   {}

\n       { line_no++; }

 /* Ignore whitespace */ 
[ \t\r]+ {}

 /* Catch-all for unrecognized tokens */
.        { printf("Error: Unrecognized token '%s' at line %d\n", yytext, line_no); }

%%

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ./a.out <input_file>\n");
        return 1;
    }
    
    FILE *input = fopen(argv[1], "r");
    if (!input) {
        printf("Error opening input file.\n");
        return 1;
    }
    
    token_file = fopen("a3_230101094_token.txt", "w");
    st_file = fopen("a3_230101094_st.txt", "w");
    
    yyin = input;
    yylex();
    
    print_st();
    
    fclose(input);
    fclose(token_file);
    fclose(st_file);
    
    printf("Lexical analysis complete.\n");
    return 0;
}