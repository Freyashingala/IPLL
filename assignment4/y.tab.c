/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "a4_230101094.y"

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int line_no;
extern char* yytext;

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d: %s near '%s'\n", line_no, s, yytext);
}

#line 84 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_CHAR = 4,                       /* CHAR  */
  YYSYMBOL_SHORT = 5,                      /* SHORT  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_LONG = 7,                       /* LONG  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_DOUBLE = 9,                     /* DOUBLE  */
  YYSYMBOL_SIGNED = 10,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 11,                  /* UNSIGNED  */
  YYSYMBOL_BOOL = 12,                      /* BOOL  */
  YYSYMBOL_STATIC = 13,                    /* STATIC  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_DO = 17,                        /* DO  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_CONTINUE = 19,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 20,                     /* BREAK  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_CASE = 22,                      /* CASE  */
  YYSYMBOL_DEFAULT = 23,                   /* DEFAULT  */
  YYSYMBOL_IDENTIFIER = 24,                /* IDENTIFIER  */
  YYSYMBOL_CONSTANT = 25,                  /* CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 26,            /* STRING_LITERAL  */
  YYSYMBOL_INC_OP = 27,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 28,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 29,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 30,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 31,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 32,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 33,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 34,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 35,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 36,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 37,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 38,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 39,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 40,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 41,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 42,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 43,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 44,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 45,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 46,                 /* OR_ASSIGN  */
  YYSYMBOL_47_ = 47,                       /* '('  */
  YYSYMBOL_48_ = 48,                       /* ')'  */
  YYSYMBOL_49_ = 49,                       /* '['  */
  YYSYMBOL_50_ = 50,                       /* ']'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* '&'  */
  YYSYMBOL_53_ = 53,                       /* '*'  */
  YYSYMBOL_54_ = 54,                       /* '+'  */
  YYSYMBOL_55_ = 55,                       /* '-'  */
  YYSYMBOL_56_ = 56,                       /* '~'  */
  YYSYMBOL_57_ = 57,                       /* '!'  */
  YYSYMBOL_58_ = 58,                       /* '/'  */
  YYSYMBOL_59_ = 59,                       /* '%'  */
  YYSYMBOL_60_ = 60,                       /* '<'  */
  YYSYMBOL_61_ = 61,                       /* '>'  */
  YYSYMBOL_62_ = 62,                       /* '^'  */
  YYSYMBOL_63_ = 63,                       /* '|'  */
  YYSYMBOL_64_ = 64,                       /* '?'  */
  YYSYMBOL_65_ = 65,                       /* ':'  */
  YYSYMBOL_66_ = 66,                       /* '='  */
  YYSYMBOL_67_ = 67,                       /* ';'  */
  YYSYMBOL_68_ = 68,                       /* '{'  */
  YYSYMBOL_69_ = 69,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_primary_expression = 71,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 72,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list_opt = 73, /* argument_expression_list_opt  */
  YYSYMBOL_argument_expression_list = 74,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 75,          /* unary_expression  */
  YYSYMBOL_unary_operator = 76,            /* unary_operator  */
  YYSYMBOL_cast_expression = 77,           /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 78, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 79,       /* additive_expression  */
  YYSYMBOL_shift_expression = 80,          /* shift_expression  */
  YYSYMBOL_relational_expression = 81,     /* relational_expression  */
  YYSYMBOL_equality_expression = 82,       /* equality_expression  */
  YYSYMBOL_AND_expression = 83,            /* AND_expression  */
  YYSYMBOL_exclusive_OR_expression = 84,   /* exclusive_OR_expression  */
  YYSYMBOL_inclusive_OR_expression = 85,   /* inclusive_OR_expression  */
  YYSYMBOL_logical_AND_expression = 86,    /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 87,     /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 88,    /* conditional_expression  */
  YYSYMBOL_assignment_expression = 89,     /* assignment_expression  */
  YYSYMBOL_assignment_operator = 90,       /* assignment_operator  */
  YYSYMBOL_expression = 91,                /* expression  */
  YYSYMBOL_expression_opt = 92,            /* expression_opt  */
  YYSYMBOL_constant_expression = 93,       /* constant_expression  */
  YYSYMBOL_declaration = 94,               /* declaration  */
  YYSYMBOL_init_declarator_list_opt = 95,  /* init_declarator_list_opt  */
  YYSYMBOL_declaration_specifiers = 96,    /* declaration_specifiers  */
  YYSYMBOL_declaration_specifiers_opt = 97, /* declaration_specifiers_opt  */
  YYSYMBOL_init_declarator_list = 98,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 99,           /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 100,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 101,           /* type_specifier  */
  YYSYMBOL_declarator = 102,               /* declarator  */
  YYSYMBOL_direct_declarator = 103,        /* direct_declarator  */
  YYSYMBOL_assignment_expression_opt = 104, /* assignment_expression_opt  */
  YYSYMBOL_identifier_list_opt = 105,      /* identifier_list_opt  */
  YYSYMBOL_parameter_type_list = 106,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 107,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 108,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 109,          /* identifier_list  */
  YYSYMBOL_initializer = 110,              /* initializer  */
  YYSYMBOL_initializer_list = 111,         /* initializer_list  */
  YYSYMBOL_designation_opt = 112,          /* designation_opt  */
  YYSYMBOL_designation = 113,              /* designation  */
  YYSYMBOL_designator_list = 114,          /* designator_list  */
  YYSYMBOL_designator = 115,               /* designator  */
  YYSYMBOL_statement = 116,                /* statement  */
  YYSYMBOL_labeled_statement = 117,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 118,       /* compound_statement  */
  YYSYMBOL_block_item_list_opt = 119,      /* block_item_list_opt  */
  YYSYMBOL_block_item_list = 120,          /* block_item_list  */
  YYSYMBOL_block_item = 121,               /* block_item  */
  YYSYMBOL_expression_statement = 122,     /* expression_statement  */
  YYSYMBOL_selection_statement = 123,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 124,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 125,           /* jump_statement  */
  YYSYMBOL_translation_unit = 126,         /* translation_unit  */
  YYSYMBOL_external_declaration = 127,     /* external_declaration  */
  YYSYMBOL_function_definition = 128       /* function_definition  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   436

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  249

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,     2,     2,    59,    52,     2,
      47,    48,    53,    54,    51,    55,     2,    58,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    65,    67,
      60,    66,    61,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,    62,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,    63,    69,    56,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    33,    33,    34,    35,    36,    40,    41,    42,    43,
      44,    48,    49,    53,    54,    58,    59,    60,    61,    65,
      65,    65,    65,    65,    65,    69,    73,    74,    75,    76,
      80,    81,    82,    86,    87,    88,    92,    93,    94,    95,
      96,   100,   101,   102,   106,   107,   111,   112,   116,   117,
     121,   122,   126,   127,   131,   132,   136,   137,   141,   141,
     141,   141,   141,   142,   142,   142,   142,   143,   143,   147,
     148,   152,   153,   157,   162,   166,   167,   171,   172,   176,
     177,   181,   182,   186,   187,   191,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   199,   203,   204,   205,
     206,   207,   211,   212,   216,   217,   221,   225,   226,   230,
     231,   235,   236,   240,   241,   242,   246,   247,   251,   252,
     256,   260,   261,   265,   270,   271,   272,   273,   274,   275,
     279,   280,   281,   285,   289,   290,   294,   295,   299,   300,
     304,   308,   309,   313,   314,   315,   316,   320,   321,   322,
     326,   327,   331,   332,   336
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "CHAR",
  "SHORT", "INT", "LONG", "FLOAT", "DOUBLE", "SIGNED", "UNSIGNED", "BOOL",
  "STATIC", "IF", "ELSE", "WHILE", "DO", "FOR", "CONTINUE", "BREAK",
  "RETURN", "CASE", "DEFAULT", "IDENTIFIER", "CONSTANT", "STRING_LITERAL",
  "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "'('", "')'", "'['", "']'", "','", "'&'",
  "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'",
  "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression",
  "argument_expression_list_opt", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "AND_expression",
  "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "expression_opt", "constant_expression", "declaration",
  "init_declarator_list_opt", "declaration_specifiers",
  "declaration_specifiers_opt", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "declarator",
  "direct_declarator", "assignment_expression_opt", "identifier_list_opt",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "initializer", "initializer_list", "designation_opt",
  "designation", "designator_list", "designator", "statement",
  "labeled_statement", "compound_statement", "block_item_list_opt",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-136)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     411,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -12,   411,   411,   292,   -91,   -91,   -91,
     -12,   -54,   -28,   -91,    13,    45,   -91,   -91,   -91,   -91,
     -91,   -22,   -91,   -12,     4,   196,   -91,   222,   379,   -91,
     -91,    -1,   -91,   -91,   -91,   379,   379,   379,   -91,   -91,
     -91,   -91,   -91,   -91,     5,   -91,    -3,   102,   379,   -91,
       9,    16,    66,   -23,    65,    28,    21,    70,    56,   -21,
     -91,   -91,   -91,    81,    87,   345,    89,    82,    83,   379,
     379,    72,    90,   -91,   105,    91,   -91,   -12,   -91,   -91,
     -91,    88,   263,   -91,   -91,   -91,   -91,   -91,   -91,   -12,
     111,   112,   110,   -91,   113,   -91,   117,   -91,   -91,    -9,
     379,   -24,     4,   -91,    -2,   -91,   -91,   -91,   379,   379,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   379,   -91,   -91,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   146,   330,   -91,   -91,   103,
     -91,   104,   345,   345,   379,   -91,   -91,   -91,   -91,   -91,
     -91,   411,   147,   -91,   -91,   125,   -33,   -91,   -91,   -91,
     -91,   128,   126,   -91,    50,   -91,   -91,   -91,   -91,     9,
       9,    16,    16,    66,    66,    66,    66,   -23,   -23,    65,
      28,    21,    70,    56,   -17,     1,     2,   131,   114,   379,
     -91,   345,   -91,   -91,   -91,   -91,   -91,   -91,   -91,     4,
     -91,   379,   -91,   379,   345,   345,   379,   379,   115,   -91,
     -91,   -91,   -91,   164,   -91,    18,   116,   379,   345,   119,
     379,   136,   -91,   -91,   140,   345,   345,   -91,   -91
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    85,   153,    75,    79,    79,     0,   150,   152,    97,
       0,     0,    76,    81,    83,    96,    80,    77,    78,     1,
     151,     0,    74,     0,     0,    71,   154,   104,   102,    98,
      82,    83,     2,     3,     4,     0,     0,     0,    19,    20,
      21,    22,    23,    24,   118,     6,    15,    25,     0,    26,
      30,    33,    36,    41,    44,    46,    48,    50,    52,    54,
      56,   113,    84,     0,     0,    71,     0,     0,     0,    71,
       0,     0,     2,    69,    72,     0,   138,    75,   139,   124,
     125,     0,    71,   136,   126,   127,   128,   129,   111,   110,
       0,     0,   106,   107,   105,   103,     0,    16,    17,     0,
       0,     0,     0,   119,     0,   121,     9,    10,    11,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      58,     0,    25,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,   147,   148,     0,
      73,     0,    71,    71,     0,   140,   133,   137,   109,   101,
     100,     0,     0,    99,     5,     0,   118,   114,   116,   120,
     122,     0,    12,    13,     0,    57,    27,    28,    29,    31,
      32,    34,    35,    39,    40,    37,    38,    42,    43,    45,
      47,    49,    51,    53,     0,     0,     0,     0,     0,    71,
     149,    71,   132,   130,    70,   108,   112,   123,   115,     0,
       8,     0,     7,     0,    71,    71,     0,    71,     0,   131,
     117,    14,    55,   141,   143,     0,     0,    71,    71,     0,
      71,     0,   142,   144,     0,    71,    71,   146,   145
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   -91,   -91,   -91,   -25,   -91,   -48,   -35,    -8,
     -67,   -41,    42,    43,    41,    44,    46,   -91,   -69,   -34,
     -91,   -46,   -74,    85,   -29,   -91,     3,   177,   -91,   160,
     -91,   -91,    -6,   -91,   -91,   -91,   -91,   -91,    25,   -91,
     -90,   -91,    35,   -91,   -91,   122,   -73,   -91,   213,   -91,
     -91,   148,   -91,   -91,   -91,   -91,   -91,   223,   -91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    55,    56,   181,   182,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    83,
     131,    84,    85,   161,    12,    21,    87,    27,    22,    23,
      14,    15,    41,    25,   106,   100,   101,   102,   103,   104,
      72,   111,   112,   113,   114,   115,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    16,    17,    18
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,   109,   155,    13,   105,   159,    86,    24,   141,   142,
     133,   160,    19,    32,    31,   151,   110,    26,    26,    13,
     107,   108,   178,    33,   116,   117,    39,   176,    42,    43,
      44,    45,    46,   132,   164,    20,   218,   143,   144,   174,
      99,   160,   164,   152,   118,   177,   119,   110,   223,   224,
     225,    47,   164,   164,   110,   132,    48,    49,    50,    51,
      52,    53,   134,    86,   179,    34,   239,   135,   136,   164,
     137,   138,    54,   184,   193,   194,   195,   196,    71,    34,
     147,    35,   208,   148,   183,   132,   186,   187,   188,   212,
     213,   150,    37,   168,    38,   139,   140,   185,   145,   146,
     222,   164,   189,   190,   197,   198,   204,   205,   206,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   209,   153,   230,
     214,   191,   192,   149,   154,   228,   156,   162,   229,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   157,
     158,   233,   234,   236,   232,   163,   164,   166,   165,   169,
     170,   171,   207,   241,   172,   242,   244,   173,   130,   211,
     210,   216,   247,   248,    99,   217,   220,   221,   226,   238,
     235,   227,   237,   240,   245,    71,   243,   231,   246,   199,
     201,   200,    28,    40,   202,   175,   215,   203,   132,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      73,   219,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    43,    44,    45,    46,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,   180,    36,     0,    30,
     167,     0,     0,    47,     0,     0,    98,     0,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    35,  -134,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    73,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    43,    44,
      45,    46,    29,     0,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,     0,     0,     0,
      47,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,  -135,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    43,    44,    45,    46,    73,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      43,    44,    45,    46,     0,     0,     0,    47,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,    47,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,    42,    43,    44,    45,    46,     0,     0,
       0,     0,     0,    35,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,    47,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53
};

static const yytype_int16 yycheck[] =
{
      34,    47,    75,     0,    38,    79,    35,    13,    31,    32,
      58,    80,    24,    67,    20,    36,    49,    14,    15,    16,
      45,    46,   112,    51,    27,    28,    48,    51,    24,    25,
      26,    27,    28,    58,    51,    47,    69,    60,    61,    48,
      37,   110,    51,    64,    47,    69,    49,    49,    65,    48,
      48,    47,    51,    51,    49,    80,    52,    53,    54,    55,
      56,    57,    53,    92,    66,    66,    48,    58,    59,    51,
      54,    55,    68,   119,   141,   142,   143,   144,   112,    66,
      52,    68,   156,    62,   118,   110,   134,   135,   136,   162,
     163,    35,    47,    99,    49,    29,    30,   131,    33,    34,
      50,    51,   137,   138,   145,   146,   152,   153,   154,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   156,    47,   219,
     164,   139,   140,    63,    47,   209,    47,    65,   211,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    67,
      67,   224,   225,   227,   223,    65,    51,    69,    67,    48,
      48,    51,    16,   237,    51,   238,   240,    50,    66,    65,
      67,    24,   245,   246,   171,    50,    48,    51,    47,    15,
     226,    67,    67,    67,    48,   219,    67,   221,    48,   147,
     149,   148,    15,    33,   150,   110,   171,   151,   223,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,   176,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,   114,    24,    -1,    16,
      92,    -1,    -1,    47,    -1,    -1,    24,    -1,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,    54,
      55,    56,    57,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    68,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    94,    96,   100,   101,   126,   127,   128,    24,
      47,    95,    98,    99,   102,   103,    96,    97,    97,     0,
     127,   102,    67,    51,    66,    68,   118,    47,    49,    48,
      99,   102,    24,    25,    26,    27,    28,    47,    52,    53,
      54,    55,    56,    57,    68,    71,    72,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,   110,    14,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    89,    91,    92,    94,    96,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    24,    96,
     105,   106,   107,   108,   109,    89,   104,    75,    75,    91,
      49,   111,   112,   113,   114,   115,    27,    28,    47,    49,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      66,    90,    75,    77,    53,    58,    59,    54,    55,    29,
      30,    31,    32,    60,    61,    33,    34,    52,    62,    63,
      35,    36,    64,    47,    47,   116,    47,    67,    67,    92,
      88,    93,    65,    65,    51,    67,    69,   121,   102,    48,
      48,    51,    51,    50,    48,    93,    51,    69,   110,    66,
     115,    73,    74,    89,    91,    89,    77,    77,    77,    78,
      78,    79,    79,    80,    80,    80,    80,    81,    81,    82,
      83,    84,    85,    86,    91,    91,    91,    16,    92,    94,
      67,    65,   116,   116,    89,   108,    24,    50,    69,   112,
      48,    51,    50,    65,    48,    48,    47,    67,    92,   116,
     110,    89,    88,   116,   116,    91,    92,    67,    15,    48,
      67,    92,   116,    67,    92,    48,    48,   116,   116
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    71,    71,    71,    72,    72,    72,    72,
      72,    73,    73,    74,    74,    75,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    77,    78,    78,    78,    78,
      79,    79,    79,    80,    80,    80,    81,    81,    81,    81,
      81,    82,    82,    82,    83,    83,    84,    84,    85,    85,
      86,    86,    87,    87,    88,    88,    89,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    91,
      91,    92,    92,    93,    94,    95,    95,    96,    96,    97,
      97,    98,    98,    99,    99,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   103,   103,   103,
     103,   103,   104,   104,   105,   105,   106,   107,   107,   108,
     108,   109,   109,   110,   110,   110,   111,   111,   112,   112,
     113,   114,   114,   115,   116,   116,   116,   116,   116,   116,
     117,   117,   117,   118,   119,   119,   120,   120,   121,   121,
     122,   123,   123,   124,   124,   124,   124,   125,   125,   125,
     126,   126,   127,   127,   128
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     4,     2,
       2,     0,     1,     1,     3,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     1,     1,     3,     0,     1,     2,     2,     0,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       4,     4,     0,     1,     0,     1,     1,     1,     3,     2,
       1,     1,     3,     1,     3,     4,     2,     4,     0,     1,
       2,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     3,     0,     1,     1,     2,     1,     1,
       2,     5,     7,     5,     7,     9,     8,     2,     2,     3,
       1,     2,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {

#line 1561 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 339 "a4_230101094.y"


int main(int argc, char **argv) {
    int result = yyparse();
    if (result == 0) {
        printf("Parsing successful!\n");
    } else {
        printf("Parsing failed.\n");
    }
    return result;
}
