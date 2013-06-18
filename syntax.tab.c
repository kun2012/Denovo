
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntax.y"

	#include <stdio.h>
	#include "include/tree.h"
	#include "include/type.h"
	#include <string.h> 
	struct treeNode *root = NULL;
	int syntaxError = 0;
	int semanticError = 0;
	void yyerror(const char *msg);


/* Line 189 of yacc.c  */
#line 85 "syntax.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     STRCONSTANT = 259,
     TYPE = 260,
     ID = 261,
     CLASS = 262,
     COMMA = 263,
     BREAK = 264,
     CONTINUE = 265,
     ELSE = 266,
     VOID = 267,
     FOR = 268,
     IF = 269,
     INHERITS = 270,
     NEW = 271,
     NUL = 272,
     RETURN = 273,
     TRUE = 274,
     WHILE = 275,
     LC = 276,
     RC = 277,
     LB = 278,
     RB = 279,
     SEMI = 280,
     LP = 281,
     RP = 282,
     DOT = 283,
     PLUS = 284,
     DIV = 285,
     MINUS = 286,
     MULT = 287,
     ASSIGN = 288,
     EQ = 289,
     LT = 290,
     GT = 291,
     LE = 292,
     GE = 293,
     NE = 294,
     AND = 295,
     OR = 296,
     NOT = 297,
     FALSE = 298,
     LOWER_THAN_ELSE = 299
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 13 "syntax.y"

	int tint;
	char tstring[MAX_STR_LEN];
	struct treeNode *tNode;



/* Line 214 of yacc.c  */
#line 173 "syntax.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 198 "syntax.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1023

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNRULES -- Number of states.  */
#define YYNSTATES  306

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    14,    21,    28,    35,    42,
      45,    46,    49,    52,    53,    56,    58,    62,    68,    71,
      76,    77,    81,    87,    93,    99,   102,   106,   111,   115,
     120,   124,   129,   132,   133,   138,   143,   148,   151,   154,
     163,   172,   181,   190,   199,   208,   210,   213,   215,   218,
     219,   222,   226,   230,   233,   237,   240,   243,   249,   257,
     263,   273,   276,   278,   281,   284,   288,   292,   296,   299,
     302,   308,   314,   320,   330,   340,   350,   358,   366,   374,
     382,   388,   394,   400,   402,   403,   405,   409,   413,   417,
     421,   425,   429,   433,   437,   440,   444,   448,   452,   456,
     460,   464,   468,   472,   476,   480,   484,   488,   492,   496,
     500,   504,   508,   512,   516,   520,   524,   528,   532,   536,
     539,   543,   547,   550,   555,   559,   562,   564,   566,   568,
     570,   574,   578,   582,   586,   589,   594,   598,   600,   601,
     605,   609
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    46,    -1,    -1,     7,     5,    48,
      21,    49,    22,    -1,     1,     5,    48,    21,    49,    22,
      -1,     7,     1,    48,    21,    49,    22,    -1,     7,     5,
      48,     1,    49,    22,    -1,     7,     5,    48,    21,    49,
       1,    -1,    15,     5,    -1,    -1,    15,     1,    -1,    50,
      49,    -1,    -1,    51,    25,    -1,    56,    -1,    51,     8,
       6,    -1,    51,     8,     6,    33,    63,    -1,    57,     6,
      -1,    57,     6,    33,    63,    -1,    -1,    51,     8,     1,
      -1,    51,     8,     1,    33,    63,    -1,    51,     8,     6,
       1,    63,    -1,    51,     8,     6,    33,     1,    -1,    23,
      24,    -1,    52,    23,    24,    -1,    53,    23,    63,    24,
      -1,    23,    63,    24,    -1,    54,    23,     3,    24,    -1,
      23,     3,    24,    -1,    55,     8,    57,     6,    -1,    57,
       6,    -1,    -1,     1,     8,    57,     6,    -1,    55,     8,
       1,     6,    -1,    55,     8,    57,     1,    -1,     1,     6,
      -1,    57,     1,    -1,    57,     6,    26,    55,    27,    21,
      58,    22,    -1,    57,     1,    26,    55,    27,    21,    58,
      22,    -1,    57,     6,     1,    55,    27,    21,    58,    22,
      -1,    57,     6,    26,     1,    27,    21,    58,    22,    -1,
      57,     6,    26,    55,    27,     1,    58,    22,    -1,    57,
       6,    26,    55,    27,    21,     1,    22,    -1,     5,    -1,
       5,    52,    -1,    12,    -1,    60,    58,    -1,    -1,    60,
       1,    -1,    21,    58,    22,    -1,    21,     1,    22,    -1,
      63,    25,    -1,    18,    63,    25,    -1,     9,    25,    -1,
      10,    25,    -1,    14,    26,    62,    27,    60,    -1,    14,
      26,    62,    27,    60,    11,    60,    -1,    20,    26,    62,
      27,    60,    -1,    13,    26,    61,    25,    62,    25,    61,
      27,    60,    -1,    51,    25,    -1,    59,    -1,     1,    25,
      -1,    63,     1,    -1,     1,    63,    25,    -1,    18,     1,
      25,    -1,    18,    63,     1,    -1,     9,     1,    -1,    10,
       1,    -1,    20,     1,    62,    27,    60,    -1,    20,    26,
       1,    27,    60,    -1,    20,    26,    62,     1,    60,    -1,
      13,     1,    61,    25,    62,    25,    61,    27,    60,    -1,
      13,    26,    61,    25,     1,    25,    61,    27,    60,    -1,
      13,    26,    61,    25,    62,     1,    61,    27,    60,    -1,
      14,     1,    62,    27,    60,    11,    60,    -1,    14,    26,
       1,    27,    60,    11,    60,    -1,    14,    26,    62,     1,
      60,    11,    60,    -1,    14,    26,    62,    27,     1,    11,
      60,    -1,    14,     1,    62,    27,    60,    -1,    14,    26,
       1,    27,    60,    -1,    14,    26,    62,     1,    60,    -1,
      63,    -1,    -1,     1,    -1,    62,    40,    62,    -1,    62,
      41,    62,    -1,    63,    39,    63,    -1,    63,    34,    63,
      -1,    63,    38,    63,    -1,    63,    37,    63,    -1,    63,
      36,    63,    -1,    63,    35,    63,    -1,    42,    62,    -1,
      26,    62,    27,    -1,     1,    40,    62,    -1,     1,    41,
      62,    -1,     1,    39,    63,    -1,    63,     1,    63,    -1,
      63,    39,     1,    -1,     1,    34,    63,    -1,    63,    34,
       1,    -1,     1,    38,    63,    -1,    63,    38,     1,    -1,
       1,    37,    63,    -1,    63,    37,     1,    -1,     1,    36,
      63,    -1,    63,    36,     1,    -1,     1,    35,    63,    -1,
      63,    35,     1,    -1,     1,    62,    27,    -1,    26,     1,
      27,    -1,    26,    62,     1,    -1,    63,    31,    63,    -1,
      63,    29,    63,    -1,    63,    32,    63,    -1,    63,    30,
      63,    -1,    63,    33,    63,    -1,     6,    53,    -1,    63,
      28,    63,    -1,    26,    63,    27,    -1,    31,    63,    -1,
       6,    26,    64,    27,    -1,    16,     5,    54,    -1,    16,
       5,    -1,     6,    -1,     4,    -1,     3,    -1,    17,    -1,
      63,    31,     1,    -1,    63,    29,     1,    -1,    63,    32,
       1,    -1,    63,    30,     1,    -1,    31,     1,    -1,     6,
      26,     1,    27,    -1,    63,     8,    64,    -1,    63,    -1,
      -1,     1,     8,    64,    -1,    63,     1,    64,    -1,    63,
       8,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    44,    44,    51,    53,    64,    68,    71,    74,    79,
      86,    87,    89,    95,    97,   103,   109,   117,   127,   134,
     143,   144,   147,   150,   153,   157,   163,   171,   179,   187,
     196,   205,   214,   221,   222,   225,   228,   231,   234,   238,
     251,   254,   257,   261,   264,   268,   274,   281,   288,   294,
     295,   299,   306,   310,   316,   323,   329,   335,   344,   355,
     364,   377,   383,   388,   391,   394,   397,   400,   403,   406,
     409,   412,   415,   418,   421,   424,   427,   430,   433,   436,
     439,   442,   445,   449,   454,   455,   460,   467,   474,   481,
     488,   495,   502,   509,   516,   522,   529,   532,   535,   538,
     541,   544,   547,   550,   553,   556,   559,   562,   565,   568,
     571,   574,   577,   580,   585,   592,   599,   606,   613,   620,
     627,   634,   641,   647,   656,   664,   671,   677,   683,   689,
     694,   697,   700,   703,   706,   709,   713,   720,   725,   726,
     729,   732
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "STRCONSTANT", "TYPE", "ID",
  "CLASS", "COMMA", "BREAK", "CONTINUE", "ELSE", "VOID", "FOR", "IF",
  "INHERITS", "NEW", "NUL", "RETURN", "TRUE", "WHILE", "LC", "RC", "LB",
  "RB", "SEMI", "LP", "RP", "DOT", "PLUS", "DIV", "MINUS", "MULT",
  "ASSIGN", "EQ", "LT", "GT", "LE", "GE", "NE", "AND", "OR", "NOT",
  "FALSE", "LOWER_THAN_ELSE", "$accept", "program", "class", "inherits",
  "features", "feature", "varDec", "array", "arrayExpr", "arrayExprDec",
  "argDec", "funDec", "type", "stmts", "compSt", "stmt", "forexpr",
  "logexpr", "expr", "args", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    47,    47,    47,    48,
      48,    48,    49,    49,    50,    50,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      56,    56,    56,    56,    56,    57,    57,    57,    58,    58,
      58,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    64,    64,
      64,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     6,     6,     6,     6,     6,     2,
       0,     2,     2,     0,     2,     1,     3,     5,     2,     4,
       0,     3,     5,     5,     5,     2,     3,     4,     3,     4,
       3,     4,     2,     0,     4,     4,     4,     2,     2,     8,
       8,     8,     8,     8,     8,     1,     2,     1,     2,     0,
       2,     3,     3,     2,     3,     2,     2,     5,     7,     5,
       9,     2,     1,     2,     2,     3,     3,     3,     2,     2,
       5,     5,     5,     9,     9,     9,     7,     7,     7,     7,
       5,     5,     5,     1,     0,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     2,     4,     3,     2,     1,     1,     1,     1,
       3,     3,     3,     3,     2,     4,     3,     1,     0,     3,
       3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    10,    10,    10,     1,     2,
       0,     0,     0,     0,    11,     9,    20,    20,    20,    13,
      45,    47,     0,    13,     0,    15,     0,     0,     0,     0,
       0,    46,     5,    12,     0,    14,     0,     0,     6,     7,
       8,     4,    25,     0,    21,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   127,   126,     0,   129,     0,     0,    19,    22,    23,
      24,    17,    37,     0,     0,     0,    38,    32,     0,     0,
       0,     0,     0,   119,   125,     0,   134,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,   121,
     120,   131,   115,   133,   117,   130,   114,   132,   116,   118,
      34,    35,    36,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,     0,     0,     0,     0,
       0,     0,     0,    28,     0,   135,     0,     0,   123,     0,
       0,     0,    63,     0,    68,    55,    69,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    18,
      40,    50,    48,    64,    53,    41,    42,    43,    44,    39,
       0,   139,   140,   141,   136,    27,    30,     0,    65,    85,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
      66,    67,    54,     0,     0,     0,    52,    51,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,   109,   107,   105,   103,    98,
      96,    97,   111,   112,   113,    95,    80,    86,    87,    99,
     102,    89,   110,    93,   108,    92,   106,    91,   104,    90,
     100,    88,    81,    82,     0,    57,    70,    71,    72,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    77,    78,    79,    58,     0,     0,
       0,     0,    73,    74,    75,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    11,    22,    23,   132,    31,    83,   108,
      55,    25,   133,   134,   135,   136,   190,   219,   137,   105
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -217
static const yytype_int16 yypact[] =
{
     205,    22,   196,    67,   205,    81,    81,    81,  -217,  -217,
     256,   127,   133,   131,  -217,  -217,   180,   180,   180,   128,
      84,  -217,   135,   128,    83,  -217,   237,   187,   202,    92,
     186,   207,  -217,  -217,   270,  -217,   214,     5,  -217,  -217,
    -217,  -217,  -217,   230,   227,    98,   129,   129,   269,   986,
    -217,   986,   986,   783,   113,    37,   279,    73,     1,    86,
    -217,  -217,   216,   267,  -217,   986,   787,   990,   990,   990,
    -217,   990,  -217,    51,   146,   261,  -217,  -217,   263,   280,
     149,   986,   481,   250,   286,   370,  -217,   361,   986,   791,
     820,   824,   828,   986,   312,   316,   318,   542,   542,   542,
     542,   571,   284,    97,   190,   296,   986,   323,   304,  -217,
    -217,  -217,   361,  -217,   310,  -217,   361,  -217,   310,   990,
    -217,  -217,  -217,  -217,   979,     0,    54,     9,    28,   857,
      35,   600,   110,   337,   322,  -217,   629,   234,   338,   344,
     358,   938,   368,  -217,   713,  -217,   713,   719,  -217,   317,
     359,   365,  -217,   326,  -217,  -217,  -217,  -217,   748,   748,
     420,   424,   371,   274,   420,   428,   955,   383,  -217,   373,
    -217,   979,  -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,
     399,  -217,  -217,   399,  -217,  -217,  -217,   384,  -217,  -217,
     385,   990,   386,   378,   457,   420,   159,   503,   210,    10,
    -217,  -217,  -217,   167,   252,    25,  -217,  -217,  -217,   420,
     474,   986,   986,   986,   986,   986,   986,   420,   420,   188,
     294,    33,   491,  -217,   658,   420,   420,   986,   861,   865,
     894,   898,   902,   931,   658,   658,   687,   658,   658,   658,
     658,   134,   336,    61,   990,   990,   990,   990,   990,   990,
    -217,   382,  -217,  -217,  -217,  -217,   422,  -217,   382,   990,
    -217,   990,  -217,   990,  -217,   990,  -217,   990,  -217,   990,
    -217,   990,   427,   431,   962,   432,  -217,  -217,  -217,  -217,
     754,   754,   754,   754,   658,   658,   658,   658,   658,   408,
     412,   421,   425,  -217,  -217,  -217,  -217,  -217,   658,   658,
     658,   658,  -217,  -217,  -217,  -217
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -217,   443,  -217,    52,   346,  -217,   369,  -217,  -217,  -217,
     142,  -217,    30,   -11,  -217,  -216,  -154,   -22,   -49,  -132
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -139
static const yytype_int16 yytable[] =
{
      67,   154,    68,    69,    71,   192,    47,    72,   256,    73,
     158,   235,   181,   -18,   182,   184,    85,    87,   272,   273,
     275,   276,   277,   278,   279,   155,   239,     5,    79,   160,
     -18,    48,   102,   104,   254,   159,   164,   236,    49,   110,
     112,   114,   116,   118,   119,    74,    26,    26,    26,    26,
     225,   226,   240,    26,   161,   156,    20,   149,    12,    13,
     255,   165,   282,    21,    75,   225,   226,     8,   293,   294,
     295,   296,   297,   225,   226,   153,    56,    56,    56,   157,
     163,    74,   302,   303,   304,   305,   283,   138,   139,   140,
     142,    34,   153,    40,    74,   104,    10,   104,   104,    52,
      78,   225,   226,    94,    96,   144,   -16,    30,    35,   191,
     191,   197,   197,    80,    41,   197,   197,   153,    34,    72,
     167,    73,   153,   -16,   145,   172,   289,   290,   291,   292,
      54,    53,    18,    20,    20,   168,   -20,   -33,   196,   199,
      21,    21,   203,   205,   197,   222,   197,    95,    16,   197,
     100,    20,    19,   -20,    17,   197,   -33,    32,    21,   280,
     197,   197,   244,   245,   246,   247,   248,   249,   197,   197,
     101,   197,   221,   223,   225,   226,   197,   197,   259,   261,
     263,   265,   267,   269,   271,    20,   224,   241,   243,    57,
      59,   146,    21,   197,   237,   250,   251,     6,   147,   225,
     226,     7,   -13,   257,   258,    -3,     1,   225,   226,    38,
      42,   193,     2,    60,    61,   252,    62,  -137,    88,    89,
      90,    91,    92,    93,    39,   153,    63,    64,   225,   226,
      43,   191,   191,   191,   191,   173,   194,   234,    36,    81,
      46,    66,    82,    37,   211,   212,   213,   214,   215,   216,
     217,   218,   195,   193,    50,    60,    61,    14,    62,   174,
      51,    15,    88,    89,    90,    91,    92,    93,    63,    64,
      58,    44,    84,   106,    20,   201,    45,   -33,   194,   238,
      76,    21,    97,    66,    98,    77,   211,   212,   213,   214,
     215,   216,   217,   218,   195,   193,   -33,    60,    61,   202,
      62,    99,    88,    89,    90,    91,    92,    93,   143,   107,
      63,    64,    88,    89,    90,    91,    92,    93,   120,   122,
     194,   253,   121,   148,   123,    66,   150,   151,   211,   212,
     213,   214,   215,   216,   217,   218,   195,   193,    88,    60,
      61,   185,    62,   169,   170,    88,    89,    90,    91,    92,
      93,   188,    63,    64,    88,    89,    90,    91,    92,    93,
     175,   281,   194,    27,    28,    29,   176,    66,   187,    33,
     211,   212,   213,   214,   215,   216,   217,   218,   195,   193,
     177,    60,    61,   186,    62,    24,    24,    24,    24,    88,
     179,    90,    24,    92,    63,    64,   200,   109,    88,    89,
      90,    91,    92,    93,   194,   207,    49,   144,   208,    66,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     195,   193,   225,    60,    61,   198,    62,    60,    61,   204,
      62,    60,    61,   284,    62,   298,    63,    64,   285,   299,
      63,    64,   286,   288,    63,    64,   194,     9,   300,     0,
     194,    66,   301,     0,   194,    66,     0,     0,   220,    66,
      60,    61,   195,    62,     0,     0,   195,     0,     0,     0,
     195,     0,     0,    63,    64,   242,     0,    60,    61,     0,
      62,     0,   103,   194,    60,    61,     0,    62,    66,     0,
      63,    64,   227,     0,     0,     0,     0,    63,    64,   195,
     194,     0,     0,     0,   227,    66,     0,    65,  -138,     0,
       0,     0,    66,     0,     0,     0,   195,     0,   109,    88,
      89,    90,    91,    92,    93,   228,   229,   230,   231,   232,
     233,    88,    89,    90,    91,    92,    93,   228,   229,   230,
     231,   232,   233,   124,     0,    60,    61,    20,    62,     0,
     -20,   125,   126,     0,    21,   127,   128,     0,    63,    64,
     129,     0,   130,   131,   -49,     0,     0,   -20,    65,     0,
       0,     0,   141,    66,    60,    61,    20,    62,     0,   -20,
     125,   126,     0,    21,   127,   128,     0,    63,    64,   129,
       0,   130,   131,   -49,     0,     0,   -20,    65,     0,     0,
       0,   166,    66,    60,    61,    20,    62,     0,   -20,   125,
     126,     0,    21,   127,   128,     0,    63,    64,   129,     0,
     130,   131,   -49,     0,     0,   -20,    65,     0,     0,     0,
     171,    66,    60,    61,    20,    62,     0,   -20,   125,   126,
       0,    21,   127,   128,     0,    63,    64,   129,     0,   130,
     131,   -49,     0,     0,   -20,    65,     0,     0,     0,   124,
      66,    60,    61,    20,    62,     0,   -20,   125,   126,     0,
      21,   127,   128,     0,    63,    64,   129,     0,   130,   131,
       0,     0,     0,   -20,    65,     0,     0,     0,   274,    66,
      60,    61,    20,    62,     0,   -20,   125,   126,     0,    21,
     127,   128,     0,    63,    64,   129,     0,   130,   131,     0,
       0,     0,   -20,    65,   180,     0,    60,    61,    66,    62,
     183,     0,    60,    61,     0,    62,     0,     0,     0,    63,
      64,     0,     0,     0,     0,    63,    64,     0,     0,    65,
    -138,     0,     0,     0,    66,    65,  -138,     0,     0,   189,
      66,    60,    61,     0,    62,   189,     0,    60,    61,     0,
      62,     0,     0,     0,    63,    64,     0,     0,     0,     0,
      63,    64,     0,   -84,    65,     0,     0,     0,     0,    66,
      65,   -84,     0,     0,    70,    66,    60,    61,    86,    62,
      60,    61,   111,    62,    60,    61,     0,    62,     0,    63,
      64,     0,     0,    63,    64,     0,     0,    63,    64,    65,
       0,     0,     0,    65,    66,     0,     0,    65,    66,     0,
       0,   113,    66,    60,    61,   115,    62,    60,    61,   117,
      62,    60,    61,     0,    62,     0,    63,    64,     0,     0,
      63,    64,     0,     0,    63,    64,    65,     0,     0,     0,
      65,    66,     0,     0,    65,    66,     0,     0,   162,    66,
      60,    61,   260,    62,    60,    61,   262,    62,    60,    61,
       0,    62,     0,    63,    64,     0,     0,    63,    64,     0,
       0,    63,    64,    65,     0,     0,     0,    65,    66,     0,
       0,    65,    66,     0,     0,   264,    66,    60,    61,   266,
      62,    60,    61,   268,    62,    60,    61,     0,    62,     0,
      63,    64,     0,     0,    63,    64,     0,     0,    63,    64,
      65,     0,     0,     0,    65,    66,     0,     0,    65,    66,
       0,     0,   270,    66,    60,    61,     0,    62,     0,     0,
       0,    60,    61,     0,    62,     0,     0,    63,    64,     0,
       0,     0,     0,     0,    63,    64,     0,    65,    60,    61,
     178,    62,    66,   152,    65,    60,    61,     0,    62,    66,
       0,    63,    64,   287,     0,     0,     0,   206,    63,    64,
     152,    65,    60,    61,     0,    62,    66,   152,    65,    60,
      61,     0,    62,    66,     0,    63,    64,     0,     0,     0,
       0,     0,    63,    64,   152,    65,     0,     0,     0,     0,
      66,     0,    65,     0,     0,     0,     0,    66,    88,    89,
      90,    91,    92,    93
};

static const yytype_int16 yycheck[] =
{
      49,     1,    51,    52,    53,   159,     1,     6,   224,     8,
       1,     1,   144,     8,   146,   147,    65,    66,   234,   235,
     236,   237,   238,   239,   240,    25,     1,     5,    27,     1,
      25,    26,    81,    82,     1,    26,     1,    27,    33,    88,
      89,    90,    91,    92,    93,     8,    16,    17,    18,    19,
      40,    41,    27,    23,    26,     1,     5,   106,     6,     7,
      27,    26,     1,    12,    27,    40,    41,     0,   284,   285,
     286,   287,   288,    40,    41,   124,    46,    47,    48,    25,
     129,     8,   298,   299,   300,   301,    25,    98,    99,   100,
     101,     8,   141,     1,     8,   144,    15,   146,   147,     1,
      27,    40,    41,    73,    74,     8,     8,    23,    25,   158,
     159,   160,   161,    27,    22,   164,   165,   166,     8,     6,
     131,     8,   171,    25,    27,   136,   280,   281,   282,   283,
       1,    33,     1,     5,     5,    25,     8,     8,   160,   161,
      12,    12,   164,   165,   193,   194,   195,     1,    21,   198,
       1,     5,    21,    25,    21,   204,    27,    22,    12,    25,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      21,   220,   194,   195,    40,    41,   225,   226,   227,   228,
     229,   230,   231,   232,   233,     5,    27,   209,   210,    47,
      48,     1,    12,   242,    27,   217,   218,     1,     8,    40,
      41,     5,    22,   225,   226,     0,     1,    40,    41,    22,
      24,     1,     7,     3,     4,    27,     6,    27,    28,    29,
      30,    31,    32,    33,    22,   274,    16,    17,    40,    41,
      23,   280,   281,   282,   283,     1,    26,    27,     1,    23,
      26,    31,    26,     6,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     1,    24,     3,     4,     1,     6,    25,
      33,     5,    28,    29,    30,    31,    32,    33,    16,    17,
       1,     1,     5,    23,     5,     1,     6,     8,    26,    27,
       1,    12,    21,    31,    21,     6,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     1,    27,     3,     4,    25,
       6,    21,    28,    29,    30,    31,    32,    33,    24,    23,
      16,    17,    28,    29,    30,    31,    32,    33,     6,     1,
      26,    27,     6,    27,     6,    31,     3,    23,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     1,    28,     3,
       4,    24,     6,     6,    22,    28,    29,    30,    31,    32,
      33,    25,    16,    17,    28,    29,    30,    31,    32,    33,
      22,    25,    26,    17,    18,    19,    22,    31,     3,    23,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     1,
      22,     3,     4,    24,     6,    16,    17,    18,    19,    28,
      22,    30,    23,    32,    16,    17,    25,    27,    28,    29,
      30,    31,    32,    33,    26,    22,    33,     8,    24,    31,
      25,    25,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     1,    40,     3,     4,     1,     6,     3,     4,     1,
       6,     3,     4,    11,     6,    27,    16,    17,    11,    27,
      16,    17,    11,    11,    16,    17,    26,     4,    27,    -1,
      26,    31,    27,    -1,    26,    31,    -1,    -1,     1,    31,
       3,     4,    42,     6,    -1,    -1,    42,    -1,    -1,    -1,
      42,    -1,    -1,    16,    17,     1,    -1,     3,     4,    -1,
       6,    -1,     1,    26,     3,     4,    -1,     6,    31,    -1,
      16,    17,     1,    -1,    -1,    -1,    -1,    16,    17,    42,
      26,    -1,    -1,    -1,     1,    31,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    42,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,     1,    31,     3,     4,     5,     6,    -1,     8,
       9,    10,    -1,    12,    13,    14,    -1,    16,    17,    18,
      -1,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
      -1,     1,    31,     3,     4,     5,     6,    -1,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
       1,    31,     3,     4,     5,     6,    -1,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,     1,
      31,     3,     4,     5,     6,    -1,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    26,    -1,    -1,    -1,     1,    31,
       3,     4,     5,     6,    -1,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    26,     1,    -1,     3,     4,    31,     6,
       1,    -1,     3,     4,    -1,     6,    -1,    -1,    -1,    16,
      17,    -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    26,
      27,    -1,    -1,    -1,    31,    26,    27,    -1,    -1,     1,
      31,     3,     4,    -1,     6,     1,    -1,     3,     4,    -1,
       6,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,
      16,    17,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,
      26,    27,    -1,    -1,     1,    31,     3,     4,     1,     6,
       3,     4,     1,     6,     3,     4,    -1,     6,    -1,    16,
      17,    -1,    -1,    16,    17,    -1,    -1,    16,    17,    26,
      -1,    -1,    -1,    26,    31,    -1,    -1,    26,    31,    -1,
      -1,     1,    31,     3,     4,     1,     6,     3,     4,     1,
       6,     3,     4,    -1,     6,    -1,    16,    17,    -1,    -1,
      16,    17,    -1,    -1,    16,    17,    26,    -1,    -1,    -1,
      26,    31,    -1,    -1,    26,    31,    -1,    -1,     1,    31,
       3,     4,     1,     6,     3,     4,     1,     6,     3,     4,
      -1,     6,    -1,    16,    17,    -1,    -1,    16,    17,    -1,
      -1,    16,    17,    26,    -1,    -1,    -1,    26,    31,    -1,
      -1,    26,    31,    -1,    -1,     1,    31,     3,     4,     1,
       6,     3,     4,     1,     6,     3,     4,    -1,     6,    -1,
      16,    17,    -1,    -1,    16,    17,    -1,    -1,    16,    17,
      26,    -1,    -1,    -1,    26,    31,    -1,    -1,    26,    31,
      -1,    -1,     1,    31,     3,     4,    -1,     6,    -1,    -1,
      -1,     3,     4,    -1,     6,    -1,    -1,    16,    17,    -1,
      -1,    -1,    -1,    -1,    16,    17,    -1,    26,     3,     4,
      22,     6,    31,    25,    26,     3,     4,    -1,     6,    31,
      -1,    16,    17,    11,    -1,    -1,    -1,    22,    16,    17,
      25,    26,     3,     4,    -1,     6,    31,    25,    26,     3,
       4,    -1,     6,    31,    -1,    16,    17,    -1,    -1,    -1,
      -1,    -1,    16,    17,    25,    26,    -1,    -1,    -1,    -1,
      31,    -1,    26,    -1,    -1,    -1,    -1,    31,    28,    29,
      30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,    46,    47,     5,     1,     5,     0,    46,
      15,    48,    48,    48,     1,     5,    21,    21,     1,    21,
       5,    12,    49,    50,    51,    56,    57,    49,    49,    49,
      23,    52,    22,    49,     8,    25,     1,     6,    22,    22,
       1,    22,    24,    23,     1,     6,    26,     1,    26,    33,
      24,    33,     1,    33,     1,    55,    57,    55,     1,    55,
       3,     4,     6,    16,    17,    26,    31,    63,    63,    63,
       1,    63,     6,     8,     8,    27,     1,     6,    27,    27,
      27,    23,    26,    53,     5,    63,     1,    63,    28,    29,
      30,    31,    32,    33,    57,     1,    57,    21,    21,    21,
       1,    21,    63,     1,    63,    64,    23,    23,    54,    27,
      63,     1,    63,     1,    63,     1,    63,     1,    63,    63,
       6,     6,     1,     6,     1,     9,    10,    13,    14,    18,
      20,    21,    51,    57,    58,    59,    60,    63,    58,    58,
      58,     1,    58,    24,     8,    27,     1,     8,    27,    63,
       3,    23,    25,    63,     1,    25,     1,    25,     1,    26,
       1,    26,     1,    63,     1,    26,     1,    58,    25,     6,
      22,     1,    58,     1,    25,    22,    22,    22,    22,    22,
       1,    64,    64,     1,    64,    24,    24,     3,    25,     1,
      61,    63,    61,     1,    26,    42,    62,    63,     1,    62,
      25,     1,    25,    62,     1,    62,    22,    22,    24,    25,
      25,    34,    35,    36,    37,    38,    39,    40,    41,    62,
       1,    62,    63,    62,    27,    40,    41,     1,    34,    35,
      36,    37,    38,    39,    27,     1,    27,    27,    27,     1,
      27,    62,     1,    62,    63,    63,    63,    63,    63,    63,
      62,    62,    27,    27,     1,    27,    60,    62,    62,    63,
       1,    63,     1,    63,     1,    63,     1,    63,     1,    63,
       1,    63,    60,    60,     1,    60,    60,    60,    60,    60,
      25,    25,     1,    25,    11,    11,    11,    11,    11,    61,
      61,    61,    61,    60,    60,    60,    60,    60,    27,    27,
      27,    27,    60,    60,    60,    60
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
# if YYLTYPE_IS_TRIVIAL
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 44 "syntax.y"
    { 
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_program); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (2)].tNode);
			root = (yyval.tNode);
		      ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 51 "syntax.y"
    { (yyval.tNode) = NULL; ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 53 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (6)]).first_line, T_class); 
			(yyval.tNode)->childNum = 6;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (6)]).first_line, T_CLASS);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (6)]).first_line, T_TYPE);
			strcpy((yyval.tNode)->ch[1]->strconst, (yyvsp[(2) - (6)].tstring));
			(yyval.tNode)->ch[2] = (yyvsp[(3) - (6)].tNode);
			(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (6)]).first_line, T_LC);
			(yyval.tNode)->ch[4] = (yyvsp[(5) - (6)].tNode);
			(yyval.tNode)->ch[5] = createTreeNode((yylsp[(6) - (6)]).first_line, T_RC);
		;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 64 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (6)]).first_line, T_class); 
		;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 68 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (6)]).first_line, T_class); 
		;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 71 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (6)]).first_line, T_class);
		;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 74 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (6)]).first_line, T_class);
		;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 79 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_inherits); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_INHERITS); 
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_TYPE);
			strcpy((yyval.tNode)->ch[1]->strconst, (yyvsp[(2) - (2)].tstring)); 
		;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 86 "syntax.y"
    { (yyval.tNode) = NULL;;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 87 "syntax.y"
    {;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 89 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_features); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (2)].tNode);
		;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 95 "syntax.y"
    { (yyval.tNode) = NULL; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 97 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_feature); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_SEMI); 
		;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 103 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (1)].tNode)->lineNum, T_feature); 
			(yyval.tNode)->childNum = 1;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (1)].tNode);
		;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 109 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_varDec); 
			(yyval.tNode)->childNum = 3;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_COMMA);
			(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[2]->strconst, (yyvsp[(3) - (3)].tstring));
		;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 117 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (5)].tNode)->lineNum, T_varDec); 
			(yyval.tNode)->childNum = 5;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (5)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (5)]).first_line, T_COMMA);
			(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (5)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[2]->strconst, (yyvsp[(3) - (5)].tstring));
			(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (5)]).first_line, T_ASSIGN);
			(yyval.tNode)->ch[4] = (yyvsp[(5) - (5)].tNode);
		;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 127 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_varDec); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[1]->strconst, (yyvsp[(2) - (2)].tstring));
		;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 134 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (4)].tNode)->lineNum, T_varDec); 
			(yyval.tNode)->childNum = 4;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (4)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (4)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[1]->strconst, (yyvsp[(2) - (4)].tstring));
			(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (4)]).first_line, T_ASSIGN);
			(yyval.tNode)->ch[3] = (yyvsp[(4) - (4)].tNode);
		;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 143 "syntax.y"
    { (yyval.tNode) = NULL; ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 144 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_varDec); 
		;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 147 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (5)].tNode)->lineNum, T_varDec); 
		;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 150 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (5)].tNode)->lineNum, T_varDec); 
		;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 153 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (5)].tNode)->lineNum, T_varDec); 
		;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 157 "syntax.y"
    {
				(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_array); 
				(yyval.tNode)->childNum = 2;
				(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_LB);
				(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_RB);
			;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 163 "syntax.y"
    {
				(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_array); 
				(yyval.tNode)->childNum = 3;
				(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
				(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_LB);
				(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_RB);
			;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 171 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (4)].tNode)->lineNum, T_arrayExpr); 
			(yyval.tNode)->childNum = 4;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (4)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (4)]).first_line, T_LB);
			(yyval.tNode)->ch[2] = (yyvsp[(3) - (4)].tNode);
			(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (4)]).first_line, T_RB);
			;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 179 "syntax.y"
    { 
			(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_arrayExpr); 
			(yyval.tNode)->childNum = 3;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_LB);
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (3)].tNode);
			(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_RB);
		  ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 187 "syntax.y"
    {
				(yyval.tNode) = createTreeNode((yyvsp[(1) - (4)].tNode)->lineNum, T_arrayExprDec); 
				(yyval.tNode)->childNum = 4;
				(yyval.tNode)->ch[0] = (yyvsp[(1) - (4)].tNode);
				(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (4)]).first_line, T_LB);
				(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (4)]).first_line, T_INT);
				(yyval.tNode)->ch[2]->digit = (yyvsp[(3) - (4)].tint);
				(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (4)]).first_line, T_RB);
				;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 196 "syntax.y"
    { 
				(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_arrayExprDec); 
				(yyval.tNode)->childNum = 3;
				(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_LB);
				(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_INT);
				(yyval.tNode)->ch[1]->digit = (yyvsp[(2) - (3)].tint);
				(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_RB);
			  ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 205 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (4)].tNode)->lineNum, T_argDec); 
			(yyval.tNode)->childNum = 4;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (4)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (4)]).first_line, T_COMMA);
			(yyval.tNode)->ch[2] = (yyvsp[(3) - (4)].tNode);
			(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (4)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[3]->strconst, (yyvsp[(4) - (4)].tstring));
	;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 214 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_argDec); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[1]->strconst, (yyvsp[(2) - (2)].tstring));
	;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 221 "syntax.y"
    { (yyval.tNode) = NULL; ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 222 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(2) - (4)]).first_line, T_argDec); 
		;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 225 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (4)].tNode)->lineNum, T_argDec); 
		;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 228 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (4)].tNode)->lineNum, T_argDec); 
		;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 231 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(2) - (2)]).first_line, T_argDec); 
		;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 234 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_argDec); 
		;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 238 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (8)].tNode)->lineNum, T_funDec); 
			(yyval.tNode)->childNum = 8;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (8)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (8)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[1]->strconst, (yyvsp[(2) - (8)].tstring));
			(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (8)]).first_line, T_LP);
			(yyval.tNode)->ch[3] = (yyvsp[(4) - (8)].tNode);
			(yyval.tNode)->ch[4] = createTreeNode((yylsp[(5) - (8)]).first_line, T_RP);
			(yyval.tNode)->ch[5] = createTreeNode((yylsp[(6) - (8)]).first_line, T_LC);
			(yyval.tNode)->ch[6] = (yyvsp[(7) - (8)].tNode);
			(yyval.tNode)->ch[7] = createTreeNode((yylsp[(8) - (8)]).first_line, T_RC);
		;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 251 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (8)].tNode)->lineNum, T_funDec); 
		;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 254 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (8)].tNode)->lineNum, T_funDec); 
		;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 257 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (8)].tNode)->lineNum, T_funDec); 
		;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 261 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (8)].tNode)->lineNum, T_funDec); 
		;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 264 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (8)].tNode)->lineNum, T_funDec); 
		;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 268 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (1)]).first_line, T_type); 
			(yyval.tNode)->childNum = 1;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (1)]).first_line, T_TYPE);
			strcpy((yyval.tNode)->strconst, (yyvsp[(1) - (1)].tstring));
			;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 274 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_type); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_TYPE);
			strcpy((yyval.tNode)->strconst, (yyvsp[(1) - (2)].tstring));
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (2)].tNode);
			;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 281 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (1)]).first_line, T_type); 
			(yyval.tNode)->childNum = 1;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (1)]).first_line, T_VOID);
			strcpy((yyval.tNode)->strconst, "void");
			;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 288 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_stmts); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (2)].tNode);
	;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 294 "syntax.y"
    { (yyval.tNode) = NULL; ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 295 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_stmts); 
		;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 299 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_compSt); 
			(yyval.tNode)->childNum = 3;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_LC);
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (3)].tNode);
			(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_RC);
		;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 306 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_compSt);
		;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 310 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_stmt); 
		(yyval.tNode)->childNum = 2;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_SEMI);
		;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 316 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_stmt); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_RETURN);
		(yyval.tNode)->ch[1] = (yyvsp[(2) - (3)].tNode);
		(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_SEMI);
		;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 323 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_stmt); 
		(yyval.tNode)->childNum = 2;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_BREAK);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_SEMI);
		;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 329 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_stmt); 
		(yyval.tNode)->childNum = 2;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_CONTINUE);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_SEMI);
		;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 335 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		(yyval.tNode)->childNum = 5;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (5)]).first_line, T_IF);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (5)]).first_line, T_LP);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (5)].tNode);
		(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (5)]).first_line, T_RP);
		(yyval.tNode)->ch[4] = (yyvsp[(5) - (5)].tNode);
		;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 344 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (7)]).first_line, T_stmt); 
		(yyval.tNode)->childNum = 7;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (7)]).first_line, T_IF);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (7)]).first_line, T_LP);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (7)].tNode);
		(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (7)]).first_line, T_RP);
		(yyval.tNode)->ch[4] = (yyvsp[(5) - (7)].tNode);
		(yyval.tNode)->ch[5] = createTreeNode((yylsp[(6) - (7)]).first_line, T_ELSE);
		(yyval.tNode)->ch[6] = (yyvsp[(7) - (7)].tNode);
		;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 355 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		(yyval.tNode)->childNum = 5;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (5)]).first_line, T_WHILE);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (5)]).first_line, T_LP);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (5)].tNode);
		(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (5)]).first_line, T_RP);
		(yyval.tNode)->ch[4] = (yyvsp[(5) - (5)].tNode);
		;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 364 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (9)]).first_line, T_stmt); 
		(yyval.tNode)->childNum = 9;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (9)]).first_line, T_FOR);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (9)]).first_line, T_LP);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (9)].tNode);
		(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (9)]).first_line, T_SEMI);
		(yyval.tNode)->ch[4] = (yyvsp[(5) - (9)].tNode);
		(yyval.tNode)->ch[5] = createTreeNode((yylsp[(6) - (9)]).first_line, T_SEMI);
		(yyval.tNode)->ch[6] = (yyvsp[(7) - (9)].tNode);
		(yyval.tNode)->ch[7] = createTreeNode((yylsp[(8) - (9)]).first_line, T_RP);
		(yyval.tNode)->ch[8] = (yyvsp[(9) - (9)].tNode);
		;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 377 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_stmt); 
		(yyval.tNode)->childNum = 2;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_SEMI);
		;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 383 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (1)].tNode)->lineNum, T_stmt); 
		(yyval.tNode)->childNum = 1;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (1)].tNode);
		;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 388 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_stmt); 
		;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 391 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_stmt); 
		;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 394 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_stmt); 
		;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 397 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_stmt); 
		;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 400 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_stmt); 
		;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 403 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_stmt); 
		;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 406 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_stmt); 
		;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 409 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 412 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 415 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 418 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (9)]).first_line, T_stmt); 
		;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 421 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (9)]).first_line, T_stmt); 
		;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 424 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (9)]).first_line, T_stmt); 
		;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 427 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (7)]).first_line, T_stmt);
		;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 430 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (7)]).first_line, T_stmt);
		;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 433 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (7)]).first_line, T_stmt);
		;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 436 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (7)]).first_line, T_stmt);
		;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 439 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 442 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 445 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 449 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (1)].tNode)->lineNum, T_forexpr); 
		(yyval.tNode)->childNum = 1;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (1)].tNode);
		;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 454 "syntax.y"
    {(yyval.tNode) = NULL;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 455 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (1)]).first_line, T_forexpr); 
		;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 460 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_AND);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 467 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_OR);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 474 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_NE);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 481 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_EQ);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 488 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_GE);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 495 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_LE);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 502 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_GT);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 509 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_LT);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 516 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_logexpr); 
		(yyval.tNode)->childNum = 2;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_NOT);
		(yyval.tNode)->ch[1] = (yyvsp[(2) - (2)].tNode);
		;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 522 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_LP);
		(yyval.tNode)->ch[1] = (yyvsp[(2) - (3)].tNode);
		(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_RP);
		;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 529 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr); 
		;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 532 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr); 
		;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 535 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 538 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 541 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 544 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 547 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 550 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 553 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 556 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 559 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 562 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 565 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 568 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 571 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 574 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr); 
		;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 577 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr); 
		;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 580 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr); 
		;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 585 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_MINUS);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 592 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_PLUS);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 599 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_MULT);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 606 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_DIV);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 613 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
			(yyval.tNode)->childNum = 3;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_ASSIGN);
			(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 620 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_expr); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[0]->strconst, (yyvsp[(1) - (2)].tstring));
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (2)].tNode);
		;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 627 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
			(yyval.tNode)->childNum = 3;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_DOT);
			(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 634 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_expr); 
			(yyval.tNode)->childNum = 3;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_LP);
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (3)].tNode);
			(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_RP);
		;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 641 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_expr); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_MINUS);
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (2)].tNode);
		;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 647 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (4)]).first_line, T_expr); 
		(yyval.tNode)->childNum = 4;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (4)]).first_line, T_ID);
		strcpy((yyval.tNode)->ch[0]->strconst, (yyvsp[(1) - (4)].tstring));
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (4)]).first_line, T_LP);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (4)].tNode);
		(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (4)]).first_line, T_RP);
		;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 656 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_expr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_NEW);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_TYPE);
		strcpy((yyval.tNode)->ch[1]->strconst, (yyvsp[(2) - (3)].tstring));
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 664 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_expr); 
		(yyval.tNode)->childNum = 2;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_NEW);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_TYPE);
		strcpy((yyval.tNode)->ch[1]->strconst, (yyvsp[(2) - (2)].tstring));
		;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 671 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (1)]).first_line, T_expr); 
		(yyval.tNode)->childNum = 1;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (1)]).first_line, T_ID);
		strcpy((yyval.tNode)->ch[0]->strconst, (yyvsp[(1) - (1)].tstring));
		;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 677 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (1)]).first_line, T_expr); 
		(yyval.tNode)->childNum = 1;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (1)]).first_line, T_STR);
		strcpy((yyval.tNode)->ch[0]->strconst, (yyvsp[(1) - (1)].tstring));
		;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 683 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (1)]).first_line, T_expr); 
			(yyval.tNode)->childNum = 1;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (1)]).first_line, T_INT);
			(yyval.tNode)->ch[0]->digit = (yyvsp[(1) - (1)].tint);
		;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 689 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (1)]).first_line, T_expr); 
		(yyval.tNode)->childNum = 1;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (1)]).first_line, T_NUL);
		;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 694 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 697 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 700 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 703 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 706 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_expr); 
		;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 709 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (4)]).first_line, T_expr); 
		;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 713 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_args); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_COMMA);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 720 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (1)].tNode)->lineNum, T_args); 
		(yyval.tNode)->childNum = 1;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (1)].tNode);
		;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 725 "syntax.y"
    { (yyval.tNode) = NULL; ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 726 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_args); 
		;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 729 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_args); 
		;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 732 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_args); 
		;}
    break;



/* Line 1455 of yacc.c  */
#line 3348 "syntax.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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



/* Line 1675 of yacc.c  */
#line 736 "syntax.y"

#include "lex.yy.c"
void yyerror(const char *msg)
{
	printf("Line %d: %s\n", yylloc.first_line, msg);
	syntaxError = 1;
}



