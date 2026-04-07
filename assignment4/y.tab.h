/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VOID = 258,                    /* VOID  */
    CHAR = 259,                    /* CHAR  */
    SHORT = 260,                   /* SHORT  */
    INT = 261,                     /* INT  */
    LONG = 262,                    /* LONG  */
    FLOAT = 263,                   /* FLOAT  */
    DOUBLE = 264,                  /* DOUBLE  */
    SIGNED = 265,                  /* SIGNED  */
    UNSIGNED = 266,                /* UNSIGNED  */
    BOOL = 267,                    /* BOOL  */
    STATIC = 268,                  /* STATIC  */
    IF = 269,                      /* IF  */
    ELSE = 270,                    /* ELSE  */
    WHILE = 271,                   /* WHILE  */
    DO = 272,                      /* DO  */
    FOR = 273,                     /* FOR  */
    CONTINUE = 274,                /* CONTINUE  */
    BREAK = 275,                   /* BREAK  */
    RETURN = 276,                  /* RETURN  */
    CASE = 277,                    /* CASE  */
    DEFAULT = 278,                 /* DEFAULT  */
    IDENTIFIER = 279,              /* IDENTIFIER  */
    CONSTANT = 280,                /* CONSTANT  */
    STRING_LITERAL = 281,          /* STRING_LITERAL  */
    INC_OP = 282,                  /* INC_OP  */
    DEC_OP = 283,                  /* DEC_OP  */
    LEFT_OP = 284,                 /* LEFT_OP  */
    RIGHT_OP = 285,                /* RIGHT_OP  */
    LE_OP = 286,                   /* LE_OP  */
    GE_OP = 287,                   /* GE_OP  */
    EQ_OP = 288,                   /* EQ_OP  */
    NE_OP = 289,                   /* NE_OP  */
    AND_OP = 290,                  /* AND_OP  */
    OR_OP = 291,                   /* OR_OP  */
    MUL_ASSIGN = 292,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 293,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 294,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 295,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 296,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 297,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 298,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 299,              /* AND_ASSIGN  */
    XOR_ASSIGN = 300,              /* XOR_ASSIGN  */
    OR_ASSIGN = 301                /* OR_ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define VOID 258
#define CHAR 259
#define SHORT 260
#define INT 261
#define LONG 262
#define FLOAT 263
#define DOUBLE 264
#define SIGNED 265
#define UNSIGNED 266
#define BOOL 267
#define STATIC 268
#define IF 269
#define ELSE 270
#define WHILE 271
#define DO 272
#define FOR 273
#define CONTINUE 274
#define BREAK 275
#define RETURN 276
#define CASE 277
#define DEFAULT 278
#define IDENTIFIER 279
#define CONSTANT 280
#define STRING_LITERAL 281
#define INC_OP 282
#define DEC_OP 283
#define LEFT_OP 284
#define RIGHT_OP 285
#define LE_OP 286
#define GE_OP 287
#define EQ_OP 288
#define NE_OP 289
#define AND_OP 290
#define OR_OP 291
#define MUL_ASSIGN 292
#define DIV_ASSIGN 293
#define MOD_ASSIGN 294
#define ADD_ASSIGN 295
#define SUB_ASSIGN 296
#define LEFT_ASSIGN 297
#define RIGHT_ASSIGN 298
#define AND_ASSIGN 299
#define XOR_ASSIGN 300
#define OR_ASSIGN 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
