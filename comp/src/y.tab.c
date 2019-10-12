/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_BYTE = 258,
     KW_INT = 259,
     KW_LONG = 260,
     KW_FLOAT = 261,
     KW_BOOL = 262,
     KW_IF = 263,
     KW_THEN = 264,
     KW_ELSE = 265,
     KW_WHILE = 266,
     KW_FOR = 267,
     KW_READ = 268,
     KW_PRINT = 269,
     KW_RETURN = 270,
     KW_BREAK = 271,
     OPERATOR_LE = 272,
     OPERATOR_GE = 273,
     OPERATOR_EQ = 274,
     OPERATOR_DIF = 275,
     TK_IDENTIFIER = 276,
     LIT_INTEGER = 277,
     LIT_FLOAT = 278,
     LIT_TRUE = 279,
     LIT_FALSE = 280,
     LIT_CHAR = 281,
     LIT_STRING = 282
   };
#endif
/* Tokens.  */
#define KW_BYTE 258
#define KW_INT 259
#define KW_LONG 260
#define KW_FLOAT 261
#define KW_BOOL 262
#define KW_IF 263
#define KW_THEN 264
#define KW_ELSE 265
#define KW_WHILE 266
#define KW_FOR 267
#define KW_READ 268
#define KW_PRINT 269
#define KW_RETURN 270
#define KW_BREAK 271
#define OPERATOR_LE 272
#define OPERATOR_GE 273
#define OPERATOR_EQ 274
#define OPERATOR_DIF 275
#define TK_IDENTIFIER 276
#define LIT_INTEGER 277
#define LIT_FLOAT 278
#define LIT_TRUE 279
#define LIT_FALSE 280
#define LIT_CHAR 281
#define LIT_STRING 282




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include "lex.yy.h"
  #include "hash.h"
  #include "astree.h"
  #include "semantic.h"

  int yylex();
  int yyerror(char *message);
  extern int getLineNumber();

  AST *root;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 18 "parser.y"
{
  HASH_NODE *symbol;
  AST *ast;
}
/* Line 193 of yacc.c.  */
#line 171 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 184 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   313

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNRULES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,    43,    35,    33,    44,    34,    31,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    38,
      28,    37,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    30,     2,
       2,     2,     2,    45,     2,    46,    32,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    45,    53,    57,    58,    61,    62,    69,    72,    75,
      76,    79,    80,    84,    87,    90,    91,    95,   102,   105,
     108,   111,   114,   123,   130,   136,   148,   150,   152,   154,
     156,   157,   160,   164,   165,   168,   171,   172,   174,   176,
     178,   180,   182,   184,   188,   193,   198,   202,   206,   210,
     214,   218,   222,   226,   230,   234,   238,   242,   246
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    -1,    50,    49,    -1,    -1,    57,
      -1,    54,    -1,     7,    -1,     3,    -1,     4,    -1,     5,
      -1,     6,    -1,    22,    -1,    24,    -1,    25,    -1,    23,
      -1,    26,    -1,    22,    -1,    23,    -1,    26,    -1,    51,
      21,    37,    52,    38,    -1,    51,    21,    39,    22,    40,
      55,    38,    -1,    41,    53,    56,    -1,    -1,    53,    56,
      -1,    -1,    51,    21,    42,    59,    43,    61,    -1,    51,
      21,    -1,    58,    60,    -1,    -1,    44,    59,    -1,    -1,
      45,    66,    46,    -1,    27,    62,    -1,    70,    62,    -1,
      -1,    21,    37,    70,    -1,    21,    39,    70,    40,    37,
      70,    -1,    13,    21,    -1,    13,    53,    -1,    14,    62,
      -1,    15,    70,    -1,     8,    42,    70,    43,     9,    65,
      10,    65,    -1,     8,    42,    70,    43,     9,    65,    -1,
      11,    42,    70,    43,    65,    -1,    12,    42,    21,    37,
      70,    44,    70,    44,    70,    43,    65,    -1,    16,    -1,
      63,    -1,    64,    -1,    61,    -1,    -1,    65,    67,    -1,
      38,    65,    67,    -1,    -1,    70,    69,    -1,    44,    68,
      -1,    -1,    21,    -1,    22,    -1,    24,    -1,    25,    -1,
      23,    -1,    26,    -1,    42,    70,    43,    -1,    21,    39,
      70,    40,    -1,    21,    42,    68,    43,    -1,    70,    33,
      70,    -1,    70,    34,    70,    -1,    70,    35,    70,    -1,
      70,    36,    70,    -1,    70,    29,    70,    -1,    70,    28,
      70,    -1,    70,    30,    70,    -1,    70,    31,    70,    -1,
      70,    32,    70,    -1,    70,    17,    70,    -1,    70,    18,
      70,    -1,    70,    19,    70,    -1,    70,    20,    70,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    85,    85,    90,    91,    94,    95,    98,    99,   100,
     101,   102,   105,   106,   107,   108,   109,   112,   113,   114,
     118,   119,   122,   123,   126,   127,   130,   133,   136,   137,
     140,   141,   144,   147,   148,   149,   152,   153,   154,   155,
     156,   157,   160,   161,   162,   163,   164,   167,   168,   169,
     170,   173,   176,   177,   180,   183,   184,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_BYTE", "KW_INT", "KW_LONG",
  "KW_FLOAT", "KW_BOOL", "KW_IF", "KW_THEN", "KW_ELSE", "KW_WHILE",
  "KW_FOR", "KW_READ", "KW_PRINT", "KW_RETURN", "KW_BREAK", "OPERATOR_LE",
  "OPERATOR_GE", "OPERATOR_EQ", "OPERATOR_DIF", "TK_IDENTIFIER",
  "LIT_INTEGER", "LIT_FLOAT", "LIT_TRUE", "LIT_FALSE", "LIT_CHAR",
  "LIT_STRING", "'<'", "'>'", "'v'", "'.'", "'~'", "'+'", "'-'", "'*'",
  "'/'", "'='", "';'", "'['", "']'", "':'", "'('", "')'", "','", "'{'",
  "'}'", "$accept", "programa", "ldecl", "decl", "tipo", "initWithBool",
  "init", "global", "arrayInit", "listaLit", "fundec", "par", "parLista",
  "resto", "block", "printLista", "cmdSimples", "fluxo", "cmd", "lcmd",
  "cmdresto", "expParam", "expParamResto", "exp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    60,    62,
     118,    46,   126,    43,    45,    42,    47,    61,    59,    91,
      93,    58,    40,    41,    44,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    51,
      51,    51,    52,    52,    52,    52,    52,    53,    53,    53,
      54,    54,    55,    55,    56,    56,    57,    58,    59,    59,
      60,    60,    61,    62,    62,    62,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    64,    64,    65,    65,    65,
      65,    66,    67,    67,    68,    69,    69,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     7,     3,     0,     2,     0,     6,     2,     2,     0,
       2,     0,     3,     2,     2,     0,     3,     6,     2,     2,
       2,     2,     8,     6,     5,    11,     1,     1,     1,     1,
       0,     2,     3,     0,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     3,     4,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     8,     9,    10,    11,     7,     0,     2,     4,     0,
       6,     5,     1,     3,     0,     0,     0,    29,    12,    15,
      13,    14,    16,     0,     0,     0,    31,     0,    20,    23,
      27,    29,    28,     0,     0,     0,    30,    50,    26,    17,
      18,    19,    25,    21,     0,     0,     0,     0,    35,     0,
      46,     0,    49,    47,    48,    53,     0,    25,    22,     0,
       0,     0,    38,    39,    57,    58,    61,    59,    60,    62,
      35,     0,    40,    35,    41,     0,     0,    50,    51,    32,
      24,     0,     0,     0,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    36,     0,    53,     0,    50,     0,     0,     0,
      56,    63,    75,    76,    77,    78,    71,    70,    72,    73,
      74,    66,    67,    68,    69,     0,    52,    50,    44,     0,
      64,    65,     0,    54,     0,    43,     0,    55,    37,    50,
       0,    42,     0,     0,    50,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    23,    57,    10,    35,    58,
      11,    26,    27,    32,    52,    72,    53,    54,    55,    56,
      78,   109,   133,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -76
static const yytype_int16 yypact[] =
{
      50,   -76,   -76,   -76,   -76,   -76,     3,   -76,    50,    -8,
     -76,   -76,   -76,   -76,    -9,    72,    10,    50,   -76,   -76,
     -76,   -76,   -76,    -4,    23,    61,    48,    94,   -76,    77,
     -76,    50,   -76,    93,    90,   114,   -76,    -7,   -76,   -76,
     -76,   -76,    90,   -76,   113,   115,   116,    58,   262,    -5,
     -76,    95,   -76,   -76,   -76,   118,   107,    90,   -76,    -5,
      -5,   152,   -76,   -76,    75,   -76,   -76,   -76,   -76,   -76,
     262,    -5,   -76,   198,   277,    -5,    -5,    -7,   -76,   -76,
     -76,   111,   131,   135,    -5,    -5,   -76,   151,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,   -76,   277,   218,   118,   166,    -7,    -5,   242,   133,
      42,   -76,   233,   233,   233,   233,   233,   233,    32,    32,
      32,   -12,   -12,   -76,   -76,   140,   -76,    -7,   -76,    71,
     -76,   -76,    -5,   -76,    -5,   168,    -5,   -76,   277,    -7,
      91,   -76,    -5,   171,    -7,   -76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   184,   -76,    -2,   -76,   -22,   -76,   -76,   136,
     -76,   -76,   164,   -76,   163,    63,   -76,   -76,   -75,   -76,
     104,    65,   -76,   -49
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      74,    44,   104,    12,    45,    46,    47,    48,    49,    50,
      81,    82,    42,    14,    51,    25,    64,    65,    66,    67,
      68,    69,    87,    99,   100,    63,   102,   103,    15,    25,
      16,   128,    24,    17,    28,   108,   110,    71,    37,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   135,     1,     2,     3,     4,     5,   129,    88,
      89,    90,    91,    29,   141,    97,    98,    99,   100,   145,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    62,
      39,    40,    30,   110,    41,   138,   132,   140,    88,    89,
      90,    91,    31,   143,    18,    19,    20,    21,    22,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    88,    89,
      90,    91,    39,    40,    84,   136,    41,    85,    34,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    88,    89,
      90,    91,    75,    86,    76,   142,   101,    33,    37,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    88,    89,
      90,    91,    43,    79,   105,    59,    77,    60,    61,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    88,    89,
      90,    91,   107,    83,   106,   127,   131,   134,   139,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    88,    89,
      90,    91,    13,    80,   111,    36,    38,   137,     0,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   126,     0,
       0,     0,     0,     0,   144,    88,    89,    90,    91,    64,
      65,    66,    67,    68,    69,    70,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    88,    89,    90,    91,     0,
      71,     0,     0,     0,     0,     0,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,     0,   125,    88,
      89,    90,    91,    94,    95,    96,    97,    98,    99,   100,
      92,    93,    94,    95,    96,    97,    98,    99,   100,     0,
       0,     0,   130,    64,    65,    66,    67,    68,    69,    70,
       0,     0,     0,     0,    88,    89,    90,    91,     0,     0,
       0,     0,     0,     0,    71,    92,    93,    94,    95,    96,
      97,    98,    99,   100
};

static const yytype_int16 yycheck[] =
{
      49,     8,    77,     0,    11,    12,    13,    14,    15,    16,
      59,    60,    34,    21,    21,    17,    21,    22,    23,    24,
      25,    26,    71,    35,    36,    47,    75,    76,    37,    31,
      39,   106,    22,    42,    38,    84,    85,    42,    45,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   127,     3,     4,     5,     6,     7,   107,    17,
      18,    19,    20,    40,   139,    33,    34,    35,    36,   144,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    21,
      22,    23,    21,   132,    26,   134,    44,   136,    17,    18,
      19,    20,    44,   142,    22,    23,    24,    25,    26,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    17,    18,
      19,    20,    22,    23,    39,    44,    26,    42,    41,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    17,    18,
      19,    20,    37,    70,    39,    44,    73,    43,    45,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    17,    18,
      19,    20,    38,    46,    43,    42,    38,    42,    42,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    17,    18,
      19,    20,    37,    21,    43,     9,    43,    37,    10,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    17,    18,
      19,    20,     8,    57,    43,    31,    33,   132,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,   104,    -1,
      -1,    -1,    -1,    -1,    43,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    17,    18,    19,    20,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    17,
      18,    19,    20,    30,    31,    32,    33,    34,    35,    36,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    28,    29,    30,    31,    32,
      33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    48,    49,    50,    51,
      54,    57,     0,    49,    21,    37,    39,    42,    22,    23,
      24,    25,    26,    52,    22,    51,    58,    59,    38,    40,
      21,    44,    60,    43,    41,    55,    59,    45,    61,    22,
      23,    26,    53,    38,     8,    11,    12,    13,    14,    15,
      16,    21,    61,    63,    64,    65,    66,    53,    56,    42,
      42,    42,    21,    53,    21,    22,    23,    24,    25,    26,
      27,    42,    62,    70,    70,    37,    39,    38,    67,    46,
      56,    70,    70,    21,    39,    42,    62,    70,    17,    18,
      19,    20,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    62,    70,    70,    65,    43,    43,    37,    70,    68,
      70,    43,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    40,    67,     9,    65,    70,
      40,    43,    44,    69,    37,    65,    44,    68,    70,    10,
      70,    65,    44,    70,    43,    65
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 85 "parser.y"
    {root=(yyval.ast);astreePrint(root, 0);

                                                                }
    break;

  case 3:
#line 90 "parser.y"
    {(yyval.ast)=astreeCreate(AST_LDECL, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 4:
#line 91 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 7:
#line 98 "parser.y"
    {(yyval.ast)=astreeCreate(AST_BOOL, 0, 0, 0, 0, 0);}
    break;

  case 8:
#line 99 "parser.y"
    {(yyval.ast)=astreeCreate(AST_BYTE, 0, 0, 0, 0, 0);}
    break;

  case 9:
#line 100 "parser.y"
    {(yyval.ast)=astreeCreate(AST_INT, 0, 0, 0, 0, 0);}
    break;

  case 10:
#line 101 "parser.y"
    {(yyval.ast)=astreeCreate(AST_LONG, 0, 0, 0, 0, 0);}
    break;

  case 11:
#line 102 "parser.y"
    {(yyval.ast)=astreeCreate(AST_FLOAT, 0, 0, 0, 0, 0);}
    break;

  case 12:
#line 105 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 13:
#line 106 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 14:
#line 107 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 15:
#line 108 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 16:
#line 109 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 17:
#line 112 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 18:
#line 113 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 19:
#line 114 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 20:
#line 118 "parser.y"
    {(yyval.ast)=astreeCreate(AST_ATRIB, (yyvsp[(2) - (5)].symbol), (yyvsp[(1) - (5)].ast), (yyvsp[(4) - (5)].ast), 0, 0);}
    break;

  case 21:
#line 119 "parser.y"
    {(yyval.ast)=astreeCreate(AST_VEC, (yyvsp[(2) - (7)].symbol), (yyvsp[(1) - (7)].ast), astreeCreate(AST_SYMBOL, (yyvsp[(4) - (7)].symbol), 0, 0, 0, 0), (yyvsp[(6) - (7)].ast), 0);}
    break;

  case 22:
#line 122 "parser.y"
    {(yyval.ast)=astreeCreate(AST_LIT, 0, (yyvsp[(2) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 23:
#line 123 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 24:
#line 126 "parser.y"
    {(yyval.ast)=astreeCreate(AST_LLIT, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 25:
#line 127 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 26:
#line 130 "parser.y"
    {(yyval.ast)=astreeCreate(AST_FUNC, (yyvsp[(2) - (6)].symbol), (yyvsp[(1) - (6)].ast), (yyvsp[(4) - (6)].ast), (yyvsp[(6) - (6)].ast), 0);}
    break;

  case 27:
#line 133 "parser.y"
    {(yyval.ast)=astreeCreate(AST_PARAM, (yyvsp[(2) - (2)].symbol), (yyvsp[(1) - (2)].ast), 0, 0, 0);}
    break;

  case 28:
#line 136 "parser.y"
    {(yyval.ast)=astreeCreate(AST_LPARAM, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 29:
#line 137 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 30:
#line 140 "parser.y"
    {(yyval.ast)=astreeCreate(AST_RESTO, 0, (yyvsp[(2) - (2)].ast), 0, 0, 0);}
    break;

  case 31:
#line 141 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 32:
#line 144 "parser.y"
    {(yyval.ast)=astreeCreate(AST_BLOCK, 0, (yyvsp[(2) - (3)].ast), 0, 0, 0);}
    break;

  case 33:
#line 147 "parser.y"
    {(yyval.ast)=astreeCreate(AST_LPRINT, 0, astreeCreate(AST_SYMBOL, (yyvsp[(1) - (2)].symbol), 0, 0, 0, 0), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 34:
#line 148 "parser.y"
    {(yyval.ast)=astreeCreate(AST_EXPPRINT, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 35:
#line 149 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 36:
#line 152 "parser.y"
    {(yyval.ast)=astreeCreate(AST_ID, (yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].ast), 0, 0, 0);}
    break;

  case 37:
#line 153 "parser.y"
    {(yyval.ast)=astreeCreate(AST_VECEXP, (yyvsp[(1) - (6)].symbol), (yyvsp[(3) - (6)].ast), (yyvsp[(6) - (6)].ast), 0, 0);}
    break;

  case 38:
#line 154 "parser.y"
    {(yyval.ast)=astreeCreate(AST_READID, 0, astreeCreate(AST_SYMBOL, (yyvsp[(2) - (2)].symbol), 0, 0, 0, 0), 0, 0, 0);}
    break;

  case 39:
#line 155 "parser.y"
    {(yyval.ast)=astreeCreate(AST_READINIT, 0, (yyvsp[(2) - (2)].ast), 0, 0, 0);}
    break;

  case 40:
#line 156 "parser.y"
    {(yyval.ast)=astreeCreate(AST_PRINT, 0, (yyvsp[(2) - (2)].ast), 0, 0, 0);}
    break;

  case 41:
#line 157 "parser.y"
    {(yyval.ast)=astreeCreate(AST_RET, 0, (yyvsp[(2) - (2)].ast), 0, 0, 0);}
    break;

  case 42:
#line 160 "parser.y"
    {(yyval.ast)=astreeCreate(AST_IFELSE, 0, (yyvsp[(3) - (8)].ast), (yyvsp[(6) - (8)].ast), (yyvsp[(8) - (8)].ast), 0);}
    break;

  case 43:
#line 161 "parser.y"
    {(yyval.ast)=astreeCreate(AST_IF, 0, (yyvsp[(3) - (6)].ast), (yyvsp[(6) - (6)].ast), 0, 0);}
    break;

  case 44:
#line 162 "parser.y"
    {(yyval.ast)=astreeCreate(AST_WHILE, 0, (yyvsp[(3) - (5)].ast), (yyvsp[(5) - (5)].ast), 0, 0);}
    break;

  case 45:
#line 163 "parser.y"
    {(yyval.ast)=astreeCreate(AST_FOR, (yyvsp[(3) - (11)].symbol), (yyvsp[(5) - (11)].ast), (yyvsp[(7) - (11)].ast), (yyvsp[(9) - (11)].ast), (yyvsp[(11) - (11)].ast));}
    break;

  case 46:
#line 164 "parser.y"
    {(yyval.ast)=astreeCreate(AST_BREAK, 0, 0, 0, 0, 0);}
    break;

  case 47:
#line 167 "parser.y"
    {(yyval.ast)=astreeCreate(AST_CMDS, 0, (yyvsp[(1) - (1)].ast), 0, 0, 0);}
    break;

  case 48:
#line 168 "parser.y"
    {(yyval.ast)=astreeCreate(AST_CFLUXO, 0, (yyvsp[(1) - (1)].ast), 0, 0, 0);}
    break;

  case 49:
#line 169 "parser.y"
    {(yyval.ast)=astreeCreate(AST_CBLOCK, 0, (yyvsp[(1) - (1)].ast), 0, 0, 0);}
    break;

  case 50:
#line 170 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 51:
#line 173 "parser.y"
    {(yyval.ast)=astreeCreate(AST_LCMD, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 52:
#line 176 "parser.y"
    {(yyval.ast)=astreeCreate(AST_CRESTO, 0, (yyvsp[(2) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 53:
#line 177 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 54:
#line 180 "parser.y"
    {(yyval.ast)=astreeCreate(AST_LEXPPARAM, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 55:
#line 183 "parser.y"
    {(yyval.ast)=astreeCreate(AST_EXPPARAM, 0, (yyvsp[(2) - (2)].ast), 0, 0, 0);}
    break;

  case 56:
#line 184 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 57:
#line 187 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 58:
#line 188 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 59:
#line 189 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 60:
#line 190 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 61:
#line 191 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 62:
#line 192 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 63:
#line 193 "parser.y"
    {(yyval.ast)=astreeCreate(AST_EXP, 0, (yyvsp[(2) - (3)].ast), 0, 0, 0);}
    break;

  case 64:
#line 194 "parser.y"
    {(yyval.ast)=astreeCreate(AST_EXPARRAY, (yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].ast), 0, 0, 0);}
    break;

  case 65:
#line 195 "parser.y"
    {(yyval.ast)=astreeCreate(AST_EXPEXP, (yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].ast), 0, 0, 0);}
    break;

  case 66:
#line 196 "parser.y"
    {(yyval.ast)=astreeCreate(AST_ADD, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 67:
#line 197 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SUB, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 68:
#line 198 "parser.y"
    {(yyval.ast)=astreeCreate(AST_MUL, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 69:
#line 199 "parser.y"
    {(yyval.ast)=astreeCreate(AST_DIV, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 70:
#line 200 "parser.y"
    {(yyval.ast)=astreeCreate(AST_GREATER, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 71:
#line 201 "parser.y"
    {(yyval.ast)=astreeCreate(AST_SMALLER, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 72:
#line 202 "parser.y"
    {(yyval.ast)=astreeCreate(AST_OR, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 73:
#line 203 "parser.y"
    {(yyval.ast)=astreeCreate(AST_AND, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 74:
#line 204 "parser.y"
    {(yyval.ast)=astreeCreate(AST_NOT, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 75:
#line 205 "parser.y"
    {(yyval.ast)=astreeCreate(AST_LE, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 76:
#line 206 "parser.y"
    {(yyval.ast)=astreeCreate(AST_GE, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 77:
#line 207 "parser.y"
    {(yyval.ast)=astreeCreate(AST_EQ, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 78:
#line 208 "parser.y"
    {(yyval.ast)=astreeCreate(AST_DIF, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;


/* Line 1267 of yacc.c.  */
#line 1916 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 211 "parser.y"


int yyerror(char *msg){
  fprintf(stderr, "Deu error de sintaxe!\n");
  printf("Linha %d [erro de sintaxe]: %s.\n", getLineNumber(), msg);
  exit(3);
}

AST* getAST(){
	return root;
}

