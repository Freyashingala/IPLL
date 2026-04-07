# Assignment - 3: Lexer for nanoC

**Name:** Freya Mitulbhai Shingala  
**Roll Number:** 230101094

## Objective
This project implements a lexical analyzer (lexer) for nanoC, a subset of the standard C programming language, using Flex. It reads a source file, generates a stream of tokens, and builds a symbol table of unique identifiers.

## Files Included
* a3_230101094.l
* a3_230101094.test.nc
* makefile
* README.md

## Compilation and Execution
1. `flex a3_230101094.l`
2. `gcc lex.yy.c -lfl`
3. `./a.out a3_230101094.test.nc`

## Files Generated
* a.out
* a3_230101094_st.txt
* a3_230101094_token.txt
* lex.yy.c

## Output
* In terminal:
    ```
    Error: Unrecognized token '@' at line 53
    Error: Unrecognized token '$' at line 54
    Error: Unrecognized token '`' at line 55
    Lexical analysis complete.
    ```
* In files:
    * a3_230101094_st.txt
    * a3_230101094_token.txt
