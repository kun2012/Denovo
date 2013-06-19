/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 1 "syntax.y"

	#include <stdio.h>
	#include "include/tree.h"
	#include "include/type.h"
	#include <string.h> 
	struct treeNode *root = NULL;
	int syntaxError = 0;
	int semanticError = 0;
	void yyerror(const char *msg);


/* Line 268 of yacc.c  */
#line 83 "syntax.tab.c"

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

/* Line 293 of yacc.c  */
#line 13 "syntax.y"

	int tint;
	char tstring[MAX_STR_LEN];
	struct treeNode *tNode;



/* Line 293 of yacc.c  */
#line 171 "syntax.tab.c"
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


/* Line 343 of yacc.c  */
#line 196 "syntax.tab.c"

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1076

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNRULES -- Number of states.  */
#define YYNSTATES  324

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
     541,   544,   550,   554,   557,   562,   569,   573,   577,   580,
     582,   584,   586,   588,   592,   596,   600,   604,   607,   612,
     616,   621,   626,   630,   632,   633,   637,   641
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
      63,    -1,     6,    33,    63,    -1,     6,    53,    33,    63,
      -1,     6,    53,    -1,     6,    28,     6,    33,    63,    -1,
      26,    63,    27,    -1,    31,    63,    -1,     6,    26,    64,
      27,    -1,     6,    28,     6,    26,    64,    27,    -1,     6,
      28,     6,    -1,    16,     5,    54,    -1,    16,     5,    -1,
       6,    -1,     4,    -1,     3,    -1,    17,    -1,    63,    31,
       1,    -1,    63,    29,     1,    -1,    63,    32,     1,    -1,
      63,    30,     1,    -1,    31,     1,    -1,     6,    26,     1,
      27,    -1,     1,    26,    27,    -1,    16,     1,    26,    27,
      -1,     1,     5,    26,    27,    -1,    63,     8,    64,    -1,
      63,    -1,    -1,     1,     8,    64,    -1,    63,     1,    64,
      -1,    63,     8,     1,    -1
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
     571,   574,   577,   580,   585,   592,   599,   606,   613,   621,
     630,   637,   648,   655,   661,   670,   682,   691,   699,   706,
     712,   718,   724,   729,   732,   735,   738,   741,   744,   747,
     750,   753,   757,   764,   769,   770,   773,   776
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
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    64,    64,    64
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
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       2,     5,     3,     2,     4,     6,     3,     3,     2,     1,
       1,     1,     1,     3,     3,     3,     3,     2,     4,     3,
       4,     4,     3,     1,     0,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    10,    10,    10,     1,     2,
       0,     0,     0,     0,    11,     9,    20,    20,    20,    13,
      45,    47,     0,    13,     0,    15,     0,     0,     0,     0,
       0,    46,     5,    12,     0,    14,     0,     0,     6,     7,
       8,     4,    25,     0,    21,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,   130,   129,     0,   132,     0,     0,    19,    22,
      23,    24,    17,    37,     0,     0,     0,    38,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   120,     0,
     128,     0,   137,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   139,     0,     0,
       0,     0,   126,   118,     0,     0,     0,     0,   127,   122,
     134,   115,   136,   117,   133,   114,   135,   116,    34,    35,
      36,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,     0,     0,     0,     0,     0,     0,
       0,   141,    28,     0,   138,     0,     0,   124,     0,     0,
       0,   119,   140,     0,     0,    63,     0,     0,    68,    55,
      69,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,    18,    40,     0,    48,    64,    53,    41,
      42,    43,    44,    39,     0,   145,   146,   147,   142,     0,
     121,    27,    30,     0,    65,    85,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    67,    54,     0,
       0,     0,    52,    51,   125,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,   109,   107,   105,   103,    98,    96,    97,
     111,   112,   113,    95,    80,    86,    87,    99,   102,    89,
     110,    93,   108,    92,   106,    91,   104,    90,   100,    88,
      81,    82,     0,    57,    70,    71,    72,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    58,     0,     0,     0,     0,
      73,    74,    75,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    11,    22,    23,   140,    31,    88,   118,
      55,    25,   141,   142,   143,   144,   206,   237,   145,   111
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -233
static const yytype_int16 yypact[] =
{
     335,    51,     0,   128,   335,   135,   135,   135,  -233,  -233,
     111,   147,   171,     7,  -233,  -233,   200,   200,   200,   319,
     224,  -233,   187,   319,   144,  -233,   236,   250,   256,    98,
     264,   276,  -233,  -233,   294,  -233,   288,     8,  -233,  -233,
    -233,  -233,  -233,   278,   246,    88,   318,   318,   360,   893,
    -233,   893,   893,   897,   240,    95,   297,   100,    70,   130,
     146,  -233,  -233,   202,   255,  -233,   893,   926,   352,   352,
     352,   146,   352,  -233,    93,   320,   301,  -233,  -233,   316,
     342,    38,   314,   329,   893,   792,   367,   893,   181,   315,
     355,   483,   146,   334,   930,   934,   963,   967,   380,   401,
     361,   540,   540,   540,   540,   569,   381,  -233,   345,   148,
     209,   382,   140,   352,   893,   893,   384,   420,   403,  -233,
     146,   334,   146,  -233,   146,   334,   146,  -233,  -233,  -233,
    -233,  -233,   786,    57,    68,     5,    18,   971,    76,   598,
     168,   418,   406,  -233,   627,   252,   407,   429,   431,   714,
     434,  -233,  -233,   821,  -233,   821,   827,  -233,   821,   893,
     374,   352,  -233,   416,   454,  -233,   856,   385,  -233,  -233,
    -233,  -233,   860,   860,   438,   442,   138,   260,   438,   446,
     721,   439,  -233,   427,  -233,   750,  -233,  -233,  -233,  -233,
    -233,  -233,  -233,  -233,   162,  -233,  -233,   162,  -233,   443,
     352,  -233,  -233,   450,  -233,   146,   457,   352,   458,   396,
     475,   438,   186,   501,   228,    10,  -233,  -233,  -233,   253,
     270,    54,  -233,  -233,  -233,  -233,   438,   492,    26,   893,
     893,   893,   893,   893,   893,   438,   438,   293,   312,    74,
     110,  -233,   656,   438,   438,   893,  1000,  1004,  1008,  1037,
    1041,  1045,   656,   656,   685,   656,   656,   656,   656,   178,
     354,    39,   352,   352,   352,   352,   352,   352,  -233,   435,
    -233,  -233,  -233,  -233,   474,  -233,   435,   352,   146,   352,
     146,   352,   146,   352,   146,   352,   146,   352,   146,   352,
     476,   478,   757,   479,  -233,  -233,  -233,  -233,   889,   889,
     889,   889,   656,   656,   656,   656,   656,   459,   467,   470,
     472,  -233,  -233,  -233,  -233,  -233,   656,   656,   656,   656,
    -233,  -233,  -233,  -233
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -233,   496,  -233,   214,   448,  -233,   402,  -233,  -233,  -233,
     210,  -233,    44,   -90,  -233,  -232,  -166,   -20,   -49,   366
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -145
static const yytype_int16 yytable[] =
{
      68,     6,    69,    70,    72,     7,   172,   208,    18,    47,
     274,   253,   146,   147,   148,   150,   -18,    91,    93,   174,
     290,   291,   293,   294,   295,   296,   297,   238,    19,    61,
      62,   173,    63,   -18,    48,   108,   110,   254,   113,   104,
     300,    49,    64,    65,   175,   121,   123,   125,   127,   181,
     243,   244,   210,   107,   186,   257,     5,    67,   168,   105,
      26,    26,    26,    26,   301,   160,   161,    26,   211,   170,
     311,   312,   313,   314,   315,   272,    73,   178,    74,   243,
     244,   258,   169,   167,   320,   321,   322,   323,   177,    52,
      56,    56,    56,   171,   243,   244,   -16,    80,    20,    40,
     167,   273,   179,    75,   110,    21,   110,   110,    75,   110,
     200,   245,    14,   -16,   243,   244,    15,    91,    98,   100,
      41,    53,    76,   207,   207,   213,   213,    79,     8,   213,
     213,   167,   307,   308,   309,   310,   167,   119,    75,    94,
      95,    96,    97,    82,   246,   247,   248,   249,   250,   251,
      10,    82,    34,    82,   212,   215,   153,    81,   219,   221,
     213,   240,   213,   216,    83,   213,   158,    82,    16,    35,
     153,   213,    83,   159,    83,   154,    34,   213,   213,   240,
     262,   263,   264,   265,   266,   267,   213,   213,    83,   213,
     239,   241,    17,   182,   213,   213,   277,   279,   281,   283,
     285,   287,   289,   298,   114,    20,   259,   261,   239,    32,
     155,   213,    21,   242,   115,   268,   269,   156,   243,   244,
      12,    13,   -13,   275,   276,    84,   243,   244,    85,   209,
      86,    61,    62,    82,    63,    87,  -143,    36,    94,    95,
      96,    97,    37,   167,    64,    65,    73,    30,    74,   207,
     207,   207,   207,   187,   228,   252,    89,    57,    59,    67,
      90,   217,   229,   230,   231,   232,   233,   234,   235,   236,
     211,   209,    38,    61,    62,    82,    63,   188,    39,    51,
     255,    94,    95,    96,    97,   218,    64,    65,    42,    94,
      95,    96,    97,   243,   244,    44,   228,   256,    77,    43,
      45,    67,    50,    78,   229,   230,   231,   232,   233,   234,
     235,   236,   211,   209,    46,    61,    62,    82,    63,    54,
     270,    99,   101,    20,    20,    20,   -33,   -20,    64,    65,
      21,    21,    21,   243,   244,    -3,     1,   102,   228,   271,
     106,   116,     2,    67,   -20,   -33,   229,   230,   231,   232,
     233,   234,   235,   236,   211,   209,   107,    61,    62,    82,
      63,    58,   130,   103,    95,    20,    97,   131,   -33,   152,
      64,    65,    21,   112,    94,    95,    96,    97,   117,   299,
     228,    94,    95,    96,    97,    67,   128,   -33,   229,   230,
     231,   232,   233,   234,   235,   236,   211,   209,   201,    61,
      62,    82,    63,    94,    95,    96,    97,   129,   151,   157,
     204,   162,    64,    65,    94,    95,    96,    97,    24,    24,
      24,    24,   228,   163,   183,    24,   164,    67,   184,   189,
     229,   230,   231,   232,   233,   234,   235,   236,   211,   209,
     202,    61,    62,   214,    63,    61,    62,   220,    63,    61,
      62,   190,    63,   191,    64,    65,   193,   203,    64,    65,
      49,   223,    64,    65,   210,    27,    28,    29,   210,    67,
     224,    33,   210,    67,   225,   243,   238,    67,    61,    62,
     211,    63,   226,   227,   211,   302,   316,   303,   211,   304,
     306,    64,    65,   260,   317,    61,    62,   318,    63,   319,
       9,   210,   245,     0,     0,     0,    67,     0,    64,    65,
     119,     0,    94,    95,    96,    97,     0,   211,   210,   195,
       0,   196,   198,    67,   199,     0,     0,     0,     0,     0,
      94,    95,    96,    97,   211,   246,   247,   248,   249,   250,
     251,   132,     0,    61,    62,    20,    63,     0,   -20,   133,
     134,     0,    21,   135,   136,     0,    64,    65,   137,     0,
     138,   139,   -49,     0,     0,   -20,    66,     0,     0,     0,
     149,    67,    61,    62,    20,    63,     0,   -20,   133,   134,
       0,    21,   135,   136,     0,    64,    65,   137,     0,   138,
     139,   -49,     0,     0,   -20,    66,     0,     0,     0,   180,
      67,    61,    62,    20,    63,     0,   -20,   133,   134,     0,
      21,   135,   136,     0,    64,    65,   137,     0,   138,   139,
     -49,     0,     0,   -20,    66,     0,     0,     0,   185,    67,
      61,    62,    20,    63,     0,   -20,   133,   134,     0,    21,
     135,   136,     0,    64,    65,   137,     0,   138,   139,   -49,
       0,     0,   -20,    66,     0,     0,     0,   132,    67,    61,
      62,    20,    63,     0,   -20,   133,   134,     0,    21,   135,
     136,     0,    64,    65,   137,     0,   138,   139,     0,     0,
       0,   -20,    66,     0,     0,     0,   292,    67,    61,    62,
      20,    63,     0,   -20,   133,   134,     0,    21,   135,   136,
       0,    64,    65,   137,     0,   138,   139,     0,     0,     0,
     -20,    66,     0,     0,     0,    60,    67,    61,    62,    82,
      63,     0,    60,     0,    61,    62,    82,    63,     0,     0,
      64,    65,     0,     0,     0,     0,   192,    64,    65,   165,
     166,     0,     0,   222,     0,    67,   165,   166,     0,     0,
       0,    60,    67,    61,    62,    82,    63,     0,    60,     0,
      61,    62,    82,    63,     0,     0,    64,    65,   305,     0,
       0,     0,   -50,    64,    65,   165,   166,     0,     0,     0,
       0,    67,   165,   166,     0,     0,     0,    60,    67,    61,
      62,    82,    63,   109,     0,    61,    62,     0,    63,     0,
       0,     0,    64,    65,     0,     0,     0,     0,    64,    65,
       0,   165,   166,     0,     0,     0,     0,    67,    66,  -144,
       0,     0,   194,    67,    61,    62,     0,    63,   197,     0,
      61,    62,     0,    63,     0,     0,     0,    64,    65,     0,
       0,     0,     0,    64,    65,     0,     0,    66,  -144,     0,
       0,     0,    67,    66,  -144,     0,     0,    60,    67,    61,
      62,   205,    63,    61,    62,     0,    63,     0,     0,     0,
       0,     0,    64,    65,     0,     0,    64,    65,     0,     0,
       0,     0,    66,   107,     0,   -84,    66,    67,     0,     0,
     205,    67,    61,    62,    60,    63,    61,    62,    71,    63,
      61,    62,     0,    63,     0,    64,    65,     0,     0,    64,
      65,     0,     0,    64,    65,    66,   -84,     0,     0,    66,
      67,     0,     0,    66,    67,     0,     0,    92,    67,    61,
      62,   120,    63,    61,    62,   122,    63,    61,    62,     0,
      63,     0,    64,    65,     0,     0,    64,    65,     0,     0,
      64,    65,    66,     0,     0,     0,    66,    67,     0,     0,
      66,    67,     0,     0,   124,    67,    61,    62,   126,    63,
      61,    62,   176,    63,    61,    62,     0,    63,     0,    64,
      65,     0,     0,    64,    65,     0,     0,    64,    65,    66,
       0,     0,     0,    66,    67,     0,     0,    66,    67,     0,
       0,   278,    67,    61,    62,   280,    63,    61,    62,   282,
      63,    61,    62,     0,    63,     0,    64,    65,     0,     0,
      64,    65,     0,     0,    64,    65,    66,     0,     0,     0,
      66,    67,     0,     0,    66,    67,     0,     0,   284,    67,
      61,    62,   286,    63,    61,    62,   288,    63,    61,    62,
       0,    63,     0,    64,    65,     0,     0,    64,    65,     0,
       0,    64,    65,    66,     0,     0,     0,    66,    67,     0,
       0,    66,    67,     0,     0,     0,    67
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-233))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      49,     1,    51,    52,    53,     5,     1,   173,     1,     1,
     242,     1,   102,   103,   104,   105,     8,    66,    67,     1,
     252,   253,   254,   255,   256,   257,   258,     1,    21,     3,
       4,    26,     6,    25,    26,    84,    85,    27,    87,     1,
       1,    33,    16,    17,    26,    94,    95,    96,    97,   139,
      40,    41,    26,    27,   144,     1,     5,    31,     1,    21,
      16,    17,    18,    19,    25,   114,   115,    23,    42,     1,
     302,   303,   304,   305,   306,     1,     6,     1,     8,    40,
      41,    27,    25,   132,   316,   317,   318,   319,   137,     1,
      46,    47,    48,    25,    40,    41,     8,    27,     5,     1,
     149,    27,    26,     8,   153,    12,   155,   156,     8,   158,
     159,     1,     1,    25,    40,    41,     5,   166,    74,    75,
      22,    33,    27,   172,   173,   174,   175,    27,     0,   178,
     179,   180,   298,   299,   300,   301,   185,    27,     8,    29,
      30,    31,    32,     5,    34,    35,    36,    37,    38,    39,
      15,     5,     8,     5,   174,   175,     8,    27,   178,   179,
     209,   210,   211,    25,    26,   214,    26,     5,    21,    25,
       8,   220,    26,    33,    26,    27,     8,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,    26,   238,
     210,   211,    21,    25,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    25,    23,     5,   226,   227,   228,    22,
       1,   260,    12,    27,    33,   235,   236,     8,    40,    41,
       6,     7,    22,   243,   244,    23,    40,    41,    26,     1,
      28,     3,     4,     5,     6,    33,    27,     1,    29,    30,
      31,    32,     6,   292,    16,    17,     6,    23,     8,   298,
     299,   300,   301,     1,    26,    27,     1,    47,    48,    31,
       5,     1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     1,    22,     3,     4,     5,     6,    25,    22,    33,
      27,    29,    30,    31,    32,    25,    16,    17,    24,    29,
      30,    31,    32,    40,    41,     1,    26,    27,     1,    23,
       6,    31,    24,     6,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     1,    26,     3,     4,     5,     6,     1,
      27,     1,    21,     5,     5,     5,     8,     8,    16,    17,
      12,    12,    12,    40,    41,     0,     1,    21,    26,    27,
      26,    26,     7,    31,    25,    27,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     1,    27,     3,     4,     5,
       6,     1,     1,    21,    30,     5,    32,     6,     8,    24,
      16,    17,    12,     6,    29,    30,    31,    32,    23,    25,
      26,    29,    30,    31,    32,    31,     6,    27,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     1,    24,     3,
       4,     5,     6,    29,    30,    31,    32,     6,    27,    27,
      25,    27,    16,    17,    29,    30,    31,    32,    16,    17,
      18,    19,    26,     3,     6,    23,    23,    31,    22,    22,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     1,
      24,     3,     4,     1,     6,     3,     4,     1,     6,     3,
       4,    22,     6,    22,    16,    17,    22,     3,    16,    17,
      33,    22,    16,    17,    26,    17,    18,    19,    26,    31,
      27,    23,    26,    31,    24,    40,     1,    31,     3,     4,
      42,     6,    25,    25,    42,    11,    27,    11,    42,    11,
      11,    16,    17,     1,    27,     3,     4,    27,     6,    27,
       4,    26,     1,    -1,    -1,    -1,    31,    -1,    16,    17,
      27,    -1,    29,    30,    31,    32,    -1,    42,    26,   153,
      -1,   155,   156,    31,   158,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    42,    34,    35,    36,    37,    38,
      39,     1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
       1,    31,     3,     4,     5,     6,    -1,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    -1,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,     1,
      31,     3,     4,     5,     6,    -1,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,     1,    31,
       3,     4,     5,     6,    -1,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    -1,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,     1,    31,     3,
       4,     5,     6,    -1,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    26,    -1,    -1,    -1,     1,    31,     3,     4,
       5,     6,    -1,     8,     9,    10,    -1,    12,    13,    14,
      -1,    16,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    26,    -1,    -1,    -1,     1,    31,     3,     4,     5,
       6,    -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,
      16,    17,    -1,    -1,    -1,    -1,    22,    16,    17,    25,
      26,    -1,    -1,    22,    -1,    31,    25,    26,    -1,    -1,
      -1,     1,    31,     3,     4,     5,     6,    -1,     1,    -1,
       3,     4,     5,     6,    -1,    -1,    16,    17,    11,    -1,
      -1,    -1,    22,    16,    17,    25,    26,    -1,    -1,    -1,
      -1,    31,    25,    26,    -1,    -1,    -1,     1,    31,     3,
       4,     5,     6,     1,    -1,     3,     4,    -1,     6,    -1,
      -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    16,    17,
      -1,    25,    26,    -1,    -1,    -1,    -1,    31,    26,    27,
      -1,    -1,     1,    31,     3,     4,    -1,     6,     1,    -1,
       3,     4,    -1,     6,    -1,    -1,    -1,    16,    17,    -1,
      -1,    -1,    -1,    16,    17,    -1,    -1,    26,    27,    -1,
      -1,    -1,    31,    26,    27,    -1,    -1,     1,    31,     3,
       4,     1,     6,     3,     4,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    -1,    16,    17,    -1,    -1,
      -1,    -1,    26,    27,    -1,    25,    26,    31,    -1,    -1,
       1,    31,     3,     4,     1,     6,     3,     4,     1,     6,
       3,     4,    -1,     6,    -1,    16,    17,    -1,    -1,    16,
      17,    -1,    -1,    16,    17,    26,    27,    -1,    -1,    26,
      31,    -1,    -1,    26,    31,    -1,    -1,     1,    31,     3,
       4,     1,     6,     3,     4,     1,     6,     3,     4,    -1,
       6,    -1,    16,    17,    -1,    -1,    16,    17,    -1,    -1,
      16,    17,    26,    -1,    -1,    -1,    26,    31,    -1,    -1,
      26,    31,    -1,    -1,     1,    31,     3,     4,     1,     6,
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
      -1,    26,    31,    -1,    -1,    -1,    31
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
       1,     3,     4,     6,    16,    17,    26,    31,    63,    63,
      63,     1,    63,     6,     8,     8,    27,     1,     6,    27,
      27,    27,     5,    26,    23,    26,    28,    33,    53,     1,
       5,    63,     1,    63,    29,    30,    31,    32,    57,     1,
      57,    21,    21,    21,     1,    21,    26,    27,    63,     1,
      63,    64,     6,    63,    23,    33,    26,    23,    54,    27,
       1,    63,     1,    63,     1,    63,     1,    63,     6,     6,
       1,     6,     1,     9,    10,    13,    14,    18,    20,    21,
      51,    57,    58,    59,    60,    63,    58,    58,    58,     1,
      58,    27,    24,     8,    27,     1,     8,    27,    26,    33,
      63,    63,    27,     3,    23,    25,    26,    63,     1,    25,
       1,    25,     1,    26,     1,    26,     1,    63,     1,    26,
       1,    58,    25,     6,    22,     1,    58,     1,    25,    22,
      22,    22,    22,    22,     1,    64,    64,     1,    64,    64,
      63,    24,    24,     3,    25,     1,    61,    63,    61,     1,
      26,    42,    62,    63,     1,    62,    25,     1,    25,    62,
       1,    62,    22,    22,    27,    24,    25,    25,    26,    34,
      35,    36,    37,    38,    39,    40,    41,    62,     1,    62,
      63,    62,    27,    40,    41,     1,    34,    35,    36,    37,
      38,    39,    27,     1,    27,    27,    27,     1,    27,    62,
       1,    62,    63,    63,    63,    63,    63,    63,    62,    62,
      27,    27,     1,    27,    60,    62,    62,    63,     1,    63,
       1,    63,     1,    63,     1,    63,     1,    63,     1,    63,
      60,    60,     1,    60,    60,    60,    60,    60,    25,    25,
       1,    25,    11,    11,    11,    11,    11,    61,    61,    61,
      61,    60,    60,    60,    60,    60,    27,    27,    27,    27,
      60,    60,    60,    60
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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
    YYLTYPE yyerror_range[3];

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

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
  if (yypact_value_is_default (yyn))
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

/* Line 1806 of yacc.c  */
#line 44 "syntax.y"
    { 
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_program); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (2)].tNode);
			root = (yyval.tNode);
		      }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 51 "syntax.y"
    { (yyval.tNode) = NULL; }
    break;

  case 4:

/* Line 1806 of yacc.c  */
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
		}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 64 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (6)]).first_line, T_class); 
		}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 68 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (6)]).first_line, T_class); 
		}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 71 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (6)]).first_line, T_class);
		}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 74 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (6)]).first_line, T_class);
		}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 79 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_inherits); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_INHERITS); 
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_TYPE);
			strcpy((yyval.tNode)->ch[1]->strconst, (yyvsp[(2) - (2)].tstring)); 
		}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 86 "syntax.y"
    { (yyval.tNode) = NULL;}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 87 "syntax.y"
    {}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 89 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_features); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (2)].tNode);
		}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 95 "syntax.y"
    { (yyval.tNode) = NULL; }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 97 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_feature); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_SEMI); 
		}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 103 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (1)].tNode)->lineNum, T_feature); 
			(yyval.tNode)->childNum = 1;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (1)].tNode);
		}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 109 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_varDec); 
			(yyval.tNode)->childNum = 3;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_COMMA);
			(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[2]->strconst, (yyvsp[(3) - (3)].tstring));
		}
    break;

  case 17:

/* Line 1806 of yacc.c  */
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
		}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 127 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_varDec); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[1]->strconst, (yyvsp[(2) - (2)].tstring));
		}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 134 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (4)].tNode)->lineNum, T_varDec); 
			(yyval.tNode)->childNum = 4;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (4)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (4)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[1]->strconst, (yyvsp[(2) - (4)].tstring));
			(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (4)]).first_line, T_ASSIGN);
			(yyval.tNode)->ch[3] = (yyvsp[(4) - (4)].tNode);
		}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 143 "syntax.y"
    { (yyval.tNode) = NULL; }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 144 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_varDec); 
		}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 147 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (5)].tNode)->lineNum, T_varDec); 
		}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 150 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (5)].tNode)->lineNum, T_varDec); 
		}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 153 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (5)].tNode)->lineNum, T_varDec); 
		}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 157 "syntax.y"
    {
				(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_array); 
				(yyval.tNode)->childNum = 2;
				(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_LB);
				(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_RB);
			}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 163 "syntax.y"
    {
				(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_array); 
				(yyval.tNode)->childNum = 3;
				(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
				(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_LB);
				(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_RB);
			}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 171 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (4)].tNode)->lineNum, T_arrayExpr); 
			(yyval.tNode)->childNum = 4;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (4)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (4)]).first_line, T_LB);
			(yyval.tNode)->ch[2] = (yyvsp[(3) - (4)].tNode);
			(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (4)]).first_line, T_RB);
			}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 179 "syntax.y"
    { 
			(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_arrayExpr); 
			(yyval.tNode)->childNum = 3;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_LB);
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (3)].tNode);
			(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_RB);
		  }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 187 "syntax.y"
    {
				(yyval.tNode) = createTreeNode((yyvsp[(1) - (4)].tNode)->lineNum, T_arrayExprDec); 
				(yyval.tNode)->childNum = 4;
				(yyval.tNode)->ch[0] = (yyvsp[(1) - (4)].tNode);
				(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (4)]).first_line, T_LB);
				(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (4)]).first_line, T_INT);
				(yyval.tNode)->ch[2]->digit = (yyvsp[(3) - (4)].tint);
				(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (4)]).first_line, T_RB);
				}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 196 "syntax.y"
    { 
				(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_arrayExprDec); 
				(yyval.tNode)->childNum = 3;
				(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_LB);
				(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_INT);
				(yyval.tNode)->ch[1]->digit = (yyvsp[(2) - (3)].tint);
				(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_RB);
			  }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 205 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (4)].tNode)->lineNum, T_argDec); 
			(yyval.tNode)->childNum = 4;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (4)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (4)]).first_line, T_COMMA);
			(yyval.tNode)->ch[2] = (yyvsp[(3) - (4)].tNode);
			(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (4)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[3]->strconst, (yyvsp[(4) - (4)].tstring));
	}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 214 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_argDec); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[1]->strconst, (yyvsp[(2) - (2)].tstring));
	}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 221 "syntax.y"
    { (yyval.tNode) = NULL; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 222 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(2) - (4)]).first_line, T_argDec); 
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 225 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (4)].tNode)->lineNum, T_argDec); 
		}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 228 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (4)].tNode)->lineNum, T_argDec); 
		}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 231 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(2) - (2)]).first_line, T_argDec); 
		}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 234 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_argDec); 
		}
    break;

  case 39:

/* Line 1806 of yacc.c  */
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
		}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 251 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (8)].tNode)->lineNum, T_funDec); 
		}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 254 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (8)].tNode)->lineNum, T_funDec); 
		}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 257 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (8)].tNode)->lineNum, T_funDec); 
		}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 261 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (8)].tNode)->lineNum, T_funDec); 
		}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 264 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (8)].tNode)->lineNum, T_funDec); 
		}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 268 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (1)]).first_line, T_type); 
			(yyval.tNode)->childNum = 1;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (1)]).first_line, T_TYPE);
			strcpy((yyval.tNode)->strconst, (yyvsp[(1) - (1)].tstring));
			}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 274 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_type); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_TYPE);
			strcpy((yyval.tNode)->strconst, (yyvsp[(1) - (2)].tstring));
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (2)].tNode);
			}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 281 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (1)]).first_line, T_type); 
			(yyval.tNode)->childNum = 1;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (1)]).first_line, T_VOID);
			strcpy((yyval.tNode)->strconst, "void");
			}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 288 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_stmts); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (2)].tNode);
	}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 294 "syntax.y"
    { (yyval.tNode) = NULL; }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 295 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_stmts); 
		}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 299 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_compSt); 
			(yyval.tNode)->childNum = 3;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_LC);
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (3)].tNode);
			(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_RC);
		}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 306 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_compSt);
		}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 310 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_stmt); 
		(yyval.tNode)->childNum = 2;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_SEMI);
		}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 316 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_stmt); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_RETURN);
		(yyval.tNode)->ch[1] = (yyvsp[(2) - (3)].tNode);
		(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_SEMI);
		}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 323 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_stmt); 
		(yyval.tNode)->childNum = 2;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_BREAK);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_SEMI);
		}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 329 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_stmt); 
		(yyval.tNode)->childNum = 2;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_CONTINUE);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_SEMI);
		}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 335 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		(yyval.tNode)->childNum = 5;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (5)]).first_line, T_IF);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (5)]).first_line, T_LP);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (5)].tNode);
		(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (5)]).first_line, T_RP);
		(yyval.tNode)->ch[4] = (yyvsp[(5) - (5)].tNode);
		}
    break;

  case 58:

/* Line 1806 of yacc.c  */
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
		}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 355 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		(yyval.tNode)->childNum = 5;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (5)]).first_line, T_WHILE);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (5)]).first_line, T_LP);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (5)].tNode);
		(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (5)]).first_line, T_RP);
		(yyval.tNode)->ch[4] = (yyvsp[(5) - (5)].tNode);
		}
    break;

  case 60:

/* Line 1806 of yacc.c  */
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
		}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 377 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_stmt); 
		(yyval.tNode)->childNum = 2;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (2)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_SEMI);
		}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 383 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (1)].tNode)->lineNum, T_stmt); 
		(yyval.tNode)->childNum = 1;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (1)].tNode);
		}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 388 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_stmt); 
		}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 391 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (2)].tNode)->lineNum, T_stmt); 
		}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 394 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_stmt); 
		}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 397 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_stmt); 
		}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 400 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_stmt); 
		}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 403 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_stmt); 
		}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 406 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_stmt); 
		}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 409 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 412 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 415 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 418 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (9)]).first_line, T_stmt); 
		}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 421 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (9)]).first_line, T_stmt); 
		}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 424 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (9)]).first_line, T_stmt); 
		}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 427 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (7)]).first_line, T_stmt);
		}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 430 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (7)]).first_line, T_stmt);
		}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 433 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (7)]).first_line, T_stmt);
		}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 436 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (7)]).first_line, T_stmt);
		}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 439 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 442 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 445 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_stmt); 
		}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 449 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (1)].tNode)->lineNum, T_forexpr); 
		(yyval.tNode)->childNum = 1;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (1)].tNode);
		}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 454 "syntax.y"
    {(yyval.tNode) = NULL;}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 455 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (1)]).first_line, T_forexpr); 
		}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 460 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_AND);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 467 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_OR);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 474 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_NE);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 481 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_EQ);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 488 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_GE);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 495 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_LE);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 502 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_GT);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 509 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_LT);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 516 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_logexpr); 
		(yyval.tNode)->childNum = 2;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_NOT);
		(yyval.tNode)->ch[1] = (yyvsp[(2) - (2)].tNode);
		}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 522 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_LP);
		(yyval.tNode)->ch[1] = (yyvsp[(2) - (3)].tNode);
		(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_RP);
		}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 529 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr); 
		}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 532 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr); 
		}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 535 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 538 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 541 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 544 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 547 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 550 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 553 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 556 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 559 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 562 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 565 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 568 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 571 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr);
		}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 574 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr); 
		}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 577 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr); 
		}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 580 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_logexpr); 
		}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 585 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_MINUS);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 592 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_PLUS);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 599 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_MULT);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 606 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_DIV);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 613 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_expr); 
			(yyval.tNode)->childNum = 3;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[0]->strconst, (yyvsp[(1) - (3)].tstring));
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_ASSIGN);
			(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 621 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (4)]).first_line, T_expr); 
			(yyval.tNode)->childNum = 4;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (4)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[0]->strconst, (yyvsp[(1) - (4)].tstring));
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (4)].tNode);
			(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (4)]).first_line, T_ASSIGN);
			(yyval.tNode)->ch[3] = (yyvsp[(4) - (4)].tNode);
		}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 630 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_expr); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[0]->strconst, (yyvsp[(1) - (2)].tstring));
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (2)].tNode);
		}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 637 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (5)]).first_line, T_expr); 
			(yyval.tNode)->childNum = 5;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (5)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[0]->strconst, (yyvsp[(1) - (5)].tstring));
			(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (5)]).first_line, T_DOT);
			(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (5)]).first_line, T_ID);
			strcpy((yyval.tNode)->ch[2]->strconst, (yyvsp[(3) - (5)].tstring));
			(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (5)]).first_line, T_ASSIGN);
			(yyval.tNode)->ch[4] = (yyvsp[(5) - (5)].tNode);
		}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 648 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_expr); 
			(yyval.tNode)->childNum = 3;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_LP);
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (3)].tNode);
			(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_RP);
		}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 655 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_expr); 
			(yyval.tNode)->childNum = 2;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_MINUS);
			(yyval.tNode)->ch[1] = (yyvsp[(2) - (2)].tNode);
		}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 661 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (4)]).first_line, T_expr); 
		(yyval.tNode)->childNum = 4;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (4)]).first_line, T_ID);
		strcpy((yyval.tNode)->ch[0]->strconst, (yyvsp[(1) - (4)].tstring));
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (4)]).first_line, T_LP);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (4)].tNode);
		(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (4)]).first_line, T_RP);
		}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 670 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (6)]).first_line, T_expr); 
		(yyval.tNode)->childNum = 6;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (6)]).first_line, T_ID);
		strcpy((yyval.tNode)->ch[0]->strconst, (yyvsp[(1) - (6)].tstring));
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (6)]).first_line, T_DOT);
		(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (6)]).first_line, T_ID);
		strcpy((yyval.tNode)->ch[2]->strconst, (yyvsp[(3) - (6)].tstring));
		(yyval.tNode)->ch[3] = createTreeNode((yylsp[(4) - (6)]).first_line, T_LP);
		(yyval.tNode)->ch[4] = (yyvsp[(5) - (6)].tNode);
		(yyval.tNode)->ch[5] = createTreeNode((yylsp[(6) - (6)]).first_line, T_RP);
	}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 682 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_expr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_ID);
		strcpy((yyval.tNode)->ch[0]->strconst, (yyvsp[(1) - (3)].tstring));
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_DOT);
		(yyval.tNode)->ch[2] = createTreeNode((yylsp[(3) - (3)]).first_line, T_ID);
		strcpy((yyval.tNode)->ch[2]->strconst, (yyvsp[(3) - (3)].tstring));
	}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 691 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_expr); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (3)]).first_line, T_NEW);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_TYPE);
		strcpy((yyval.tNode)->ch[1]->strconst, (yyvsp[(2) - (3)].tstring));
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 699 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_expr); 
		(yyval.tNode)->childNum = 2;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (2)]).first_line, T_NEW);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (2)]).first_line, T_TYPE);
		strcpy((yyval.tNode)->ch[1]->strconst, (yyvsp[(2) - (2)].tstring));
		}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 706 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (1)]).first_line, T_expr); 
		(yyval.tNode)->childNum = 1;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (1)]).first_line, T_ID);
		strcpy((yyval.tNode)->ch[0]->strconst, (yyvsp[(1) - (1)].tstring));
		}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 712 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (1)]).first_line, T_expr); 
		(yyval.tNode)->childNum = 1;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (1)]).first_line, T_STR);
		strcpy((yyval.tNode)->ch[0]->strconst, (yyvsp[(1) - (1)].tstring));
		}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 718 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (1)]).first_line, T_expr); 
			(yyval.tNode)->childNum = 1;
			(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (1)]).first_line, T_INT);
			(yyval.tNode)->ch[0]->digit = (yyvsp[(1) - (1)].tint);
		}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 724 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (1)]).first_line, T_expr); 
		(yyval.tNode)->childNum = 1;
		(yyval.tNode)->ch[0] = createTreeNode((yylsp[(1) - (1)]).first_line, T_NUL);
		}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 729 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 732 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		}
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 735 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		}
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 738 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_expr); 
		}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 741 "syntax.y"
    {
			(yyval.tNode) = createTreeNode((yylsp[(1) - (2)]).first_line, T_expr); 
		}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 744 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (4)]).first_line, T_expr); 
		}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 747 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_expr); 
		}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 750 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (4)]).first_line, T_expr); 
		}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 753 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (4)]).first_line, T_expr); 
		}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 757 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_args); 
		(yyval.tNode)->childNum = 3;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (3)].tNode);
		(yyval.tNode)->ch[1] = createTreeNode((yylsp[(2) - (3)]).first_line, T_COMMA);
		(yyval.tNode)->ch[2] = (yyvsp[(3) - (3)].tNode);
		}
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 764 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (1)].tNode)->lineNum, T_args); 
		(yyval.tNode)->childNum = 1;
		(yyval.tNode)->ch[0] = (yyvsp[(1) - (1)].tNode);
		}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 769 "syntax.y"
    { (yyval.tNode) = NULL; }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 770 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yylsp[(1) - (3)]).first_line, T_args); 
		}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 773 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_args); 
		}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 776 "syntax.y"
    {
		(yyval.tNode) = createTreeNode((yyvsp[(1) - (3)].tNode)->lineNum, T_args); 
		}
    break;



/* Line 1806 of yacc.c  */
#line 3486 "syntax.tab.c"
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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

  yyerror_range[1] = yylsp[1-yylen];
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
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
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



/* Line 2067 of yacc.c  */
#line 780 "syntax.y"

#include "lex.yy.c"
void yyerror(const char *msg)
{
	printf("Line %d: %s\n", yylloc.first_line, msg);
	syntaxError = 1;
}



