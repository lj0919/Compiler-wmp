/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include "node.h"
#include <sstream>
#include"var_info.h"
#include<map>
using namespace std;
Node* node;
void yyerror(const char*);
extern int yylex();
void dfs(Node* node,int depth);
int sti(string s);
double stf(string s);
double toDouble(int i);
void printNode(Node* node,int indent);
int judgeType(Node* node);
string tostr(int a);
string tostr(double b);
string deal(Node* arg1,Node* arg2,int oparg);
map<string,var_info*> var_list;
var_info* get(string s);
#define YYSTYPE Node* 


#line 95 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NEWLINE = 258,
    IDENTIFIER = 259,
    INTEGER = 260,
    FLOAT = 261,
    CHARVAL = 262,
    CHARS = 263,
    IF = 264,
    ELSE = 265,
    WHILE = 266,
    DO = 267,
    BREAK = 268,
    CONTINUE = 269,
    TYPE = 270,
    FOR = 271,
    RETURN = 272,
    READ = 273,
    WRITE = 274,
    GOTO = 275,
    ENDSTMT = 276,
    LBRACE = 277,
    RBRACE = 278,
    SQM = 279,
    MORE = 280,
    ASSIGN = 281,
    COLON = 282,
    QUEST = 283,
    OR = 284,
    AND = 285,
    BITOR = 286,
    XOR = 287,
    BITAND = 288,
    EQ = 289,
    NE = 290,
    SHL = 291,
    SHR = 292,
    RT = 293,
    RE = 294,
    LT = 295,
    LE = 296,
    PLUS = 297,
    MINUS = 298,
    MUL = 299,
    DIV = 300,
    MOD = 301,
    _UMINUS = 302,
    TPLUS = 303,
    TMINUS = 304,
    _VAL = 305,
    _ADDR = 306,
    NOT = 307,
    BITNOT = 308,
    LBRACKET = 309,
    RBRACKET = 310,
    LPAREN = 311,
    RPAREN = 312,
    _IF = 313,
    _ELSE = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 206 "parser.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    65,    68,    69,    73,    74,    77,    78,
      81,    82,    83,    84,    85,    88,    89,    92,    94,    98,
     101,   102,   105,   107,   110,   115,   119,   120,   123,   124,
     125,   126,   131,   132,   133,   134,   135,   141,   143,   145,
     149,   152,   155,   158,   161,   163,   166,   169,   172,   175,
     178,   182,   213,   225,   238,   250,   262,   274,   288,   295,
     302,   309,   317,   326,   338,   339,   340,   343,   346,   354,
     368,   378,   379,   380,   383,   391,   397,   405,   413,   414,
     417,   420,   421,   422,   423,   424,   429,   430,   431,   435,
     436,   439,   442,   443,   459,   460,   471,   475,   476,   477
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NEWLINE", "IDENTIFIER", "INTEGER",
  "FLOAT", "CHARVAL", "CHARS", "IF", "ELSE", "WHILE", "DO", "BREAK",
  "CONTINUE", "TYPE", "FOR", "RETURN", "READ", "WRITE", "GOTO", "ENDSTMT",
  "LBRACE", "RBRACE", "SQM", "MORE", "ASSIGN", "COLON", "QUEST", "OR",
  "AND", "BITOR", "XOR", "BITAND", "EQ", "NE", "SHL", "SHR", "RT", "RE",
  "LT", "LE", "PLUS", "MINUS", "MUL", "DIV", "MOD", "_UMINUS", "TPLUS",
  "TMINUS", "_VAL", "_ADDR", "NOT", "BITNOT", "LBRACKET", "RBRACKET",
  "LPAREN", "RPAREN", "_IF", "_ELSE", "$accept", "translationUnits",
  "translationUnit", "statement", "statementList", "simpleStatement",
  "compoundStatement", "readStatement", "writeStatement",
  "declarationStatement", "declarationList", "declaration", "declarator",
  "initializer", "expressionStatement", "expression", "operation",
  "logicOperation", "arithmeticOperation", "assignmentOperation",
  "relationOperation", "bitOperation", "controlStatement",
  "selectionStatement", "ifStatement", "loopStatement", "forStatement",
  "whileStatement", "doWhileStatement", "jumpStatement",
  "functionDefinition", "expressionList", "parameter", "parameterList",
  "identifier", "type", "number", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF -132

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-132)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      40,  -132,    10,  -132,  -132,  -132,    11,  -132,  -132,  -132,
      11,    15,  -132,    43,   -26,    13,  -132,    11,   336,   -10,
    -132,  -132,  -132,  -132,  -132,  -132,   336,   336,   336,   336,
     336,   336,   336,  -132,   364,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,    17,    53,  -132,   -16,    11,   -27,   -27,
     -27,   -27,   -27,   -27,   364,   -12,    13,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,  -132,  -132,    53,   177,
    -132,    40,    53,  -132,   336,  -132,   364,   384,   403,   169,
     420,   436,   450,   450,   -11,   -11,   -11,   -11,   -11,   -11,
      38,    38,   -27,   -27,   -27,  -132,    21,    22,   230,    59,
      67,    33,   283,    34,    60,  -132,  -132,   230,    92,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,    18,    11,  -132,  -132,   364,   302,   302,
     109,  -132,  -132,   249,  -132,   336,    47,    11,    11,  -132,
    -132,  -132,    64,    -9,    65,    -8,    69,   317,   317,    -7,
    -132,    66,    75,   230,   230,   230,   230,   336,   107,   123,
     105,  -132,  -132,  -132,   124,  -132,  -132,    -6,   230,    -5,
     230,     3,  -132,   230,   112,  -132,   230,  -132,   230,  -132,
    -132,  -132,  -132
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    96,     0,     2,     5,     4,     0,     1,     3,    95,
       0,     0,    20,    22,    24,     0,    19,     0,     0,     0,
      94,    21,    24,    97,    98,    99,     0,     0,     0,     0,
       0,     0,     0,    23,    25,    28,    32,    33,    34,    35,
      36,    29,    30,    96,     0,    92,     0,     0,    46,    45,
      47,    49,    39,    61,    89,     0,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    50,     0,     0,
      86,     0,     0,    91,     0,    31,    51,    37,    38,    59,
      60,    58,    52,    57,    62,    63,    54,    53,    56,    55,
      40,    41,    42,    43,    44,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    15,     8,     0,     6,
       7,    13,    14,    10,    11,    12,    64,    67,    65,    71,
      72,    73,    66,     0,     0,    93,    88,    90,     0,     0,
       0,    85,    81,     0,    82,     0,     0,     0,     0,     9,
      16,    27,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    17,    18,    70,    68,    79,    78,     0,     0,     0,
       0,     0,    84,     0,     0,    77,     0,    75,     0,    69,
      80,    76,    74
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,   133,  -107,    19,  -132,   -36,  -132,  -132,     0,
    -132,     7,  -132,  -132,  -131,    35,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,   -21,    56,  -132,    -3,     4,  -132
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   117,   118,   119,   120,   121,   122,   123,
      11,    12,    13,    33,   124,    54,    35,    36,    37,    38,
      39,    40,   125,   126,   127,   128,   129,   130,   131,   132,
       5,   133,    45,    46,    41,   134,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       4,   140,     4,    14,     6,    43,     6,    15,    80,    81,
       7,    55,   158,    84,    22,     9,    84,    84,    84,    84,
      84,    76,    77,    47,    21,     1,   168,   169,    84,    56,
      19,    71,    72,    73,    74,    75,    16,    76,    77,   151,
      17,    82,   105,    84,    22,    85,   136,    44,   164,   166,
     170,   184,   186,    34,    83,     1,   173,   174,   175,   176,
     188,    48,    49,    50,    51,    52,    53,    10,   160,    18,
      20,   185,    84,   187,    78,    79,   189,   138,   139,   191,
     141,   192,    73,    74,    75,    47,    76,    77,   142,   143,
     147,   146,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     9,    23,    24,    25,   150,   148,   153,   155,   137,
     156,   163,   165,   171,   159,   167,   182,     9,    23,    24,
      25,    22,   172,   190,   183,     8,   149,   135,   152,   154,
       0,     0,    56,   157,   161,   162,   177,   179,   181,    26,
      27,     0,     0,     0,     0,    28,    29,     0,     0,    30,
      31,     0,     0,    32,   178,    26,    27,     0,     0,     0,
       0,    28,    29,     0,     0,    30,    31,     0,     0,    32,
     180,     9,    23,    24,    25,     0,   106,     0,   107,   108,
     109,   110,     1,   111,   112,   113,   114,     0,   115,    79,
     116,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     0,    76,    77,    26,
      27,     0,     0,     0,     0,    28,    29,     0,     0,    30,
      31,     0,     0,    32,     9,    23,    24,    25,     0,   106,
       0,   107,   108,   109,   110,     1,   111,   112,   113,   114,
       0,   115,    79,     9,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
     115,     0,    26,    27,     0,     0,     0,     0,    28,    29,
       0,     0,    30,    31,     0,     0,    32,     9,    23,    24,
      25,    26,    27,     0,     0,     0,     0,    28,    29,     0,
       0,    30,    31,     0,   144,    32,     9,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     9,    23,    24,    25,    26,    27,     0,     0,     0,
       0,    28,    29,     0,     0,    30,    31,     0,   115,   145,
       9,    23,    24,    25,    26,    27,     0,     0,     0,     0,
      28,    29,     0,     0,    30,    31,     0,     0,    32,    26,
      27,     0,     0,     0,     0,    28,    29,     0,     0,    30,
      31,     0,     0,    32,     0,     0,     0,     0,    26,    27,
       0,     0,     0,     0,    28,    29,     0,     0,    30,    31,
      57,     0,    32,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,    77,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,    77,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       0,    76,    77,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,    77,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,    77,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,    77
};

static const yytype_int16 yycheck[] =
{
       0,   108,     2,     6,     0,    15,     2,    10,    44,    25,
       0,    32,   143,    25,    17,     4,    25,    25,    25,    25,
      25,    48,    49,    19,    17,    15,   157,   158,    25,    32,
      56,    42,    43,    44,    45,    46,    21,    48,    49,    21,
      25,    57,    78,    25,    47,    57,    82,    57,    57,    57,
      57,    57,    57,    18,    47,    15,   163,   164,   165,   166,
      57,    26,    27,    28,    29,    30,    31,    56,    21,    26,
      57,   178,    25,   180,    57,    22,   183,    56,    56,   186,
      21,   188,    44,    45,    46,    81,    48,    49,    21,    56,
      56,   112,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     4,     5,     6,     7,    23,    56,   138,   139,    84,
      11,    57,    57,    57,   145,    56,    21,     4,     5,     6,
       7,   134,    57,    21,    10,     2,   117,    81,   138,   139,
      -1,    -1,   145,   143,   147,   148,   167,   168,   169,    42,
      43,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    52,
      53,    -1,    -1,    56,    57,    42,    43,    -1,    -1,    -1,
      -1,    48,    49,    -1,    -1,    52,    53,    -1,    -1,    56,
      57,     4,     5,     6,     7,    -1,     9,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22,
      23,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    42,
      43,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    52,
      53,    -1,    -1,    56,     4,     5,     6,     7,    -1,     9,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    21,    22,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      21,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    52,    53,    -1,    -1,    56,     4,     5,     6,
       7,    42,    43,    -1,    -1,    -1,    -1,    48,    49,    -1,
      -1,    52,    53,    -1,    21,    56,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,     4,     5,     6,     7,    42,    43,    -1,    -1,    -1,
      -1,    48,    49,    -1,    -1,    52,    53,    -1,    21,    56,
       4,     5,     6,     7,    42,    43,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    52,    53,    -1,    -1,    56,    42,
      43,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    52,
      53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    52,    53,
      26,    -1,    56,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    61,    62,    69,    90,    95,     0,    62,     4,
      56,    70,    71,    72,    94,    94,    21,    25,    26,    56,
      57,    71,    94,     5,     6,     7,    42,    43,    48,    49,
      52,    53,    56,    73,    75,    76,    77,    78,    79,    80,
      81,    94,    96,    15,    57,    92,    93,    95,    75,    75,
      75,    75,    75,    75,    75,    91,    94,    26,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    48,    49,    57,    22,
      66,    25,    57,    71,    25,    57,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    66,     9,    11,    12,    13,
      14,    16,    17,    18,    19,    21,    23,    63,    64,    65,
      66,    67,    68,    69,    74,    82,    83,    84,    85,    86,
      87,    88,    89,    91,    95,    92,    66,    75,    56,    56,
      63,    21,    21,    56,    21,    56,    91,    56,    56,    64,
      23,    21,    69,    91,    69,    91,    11,    69,    74,    91,
      21,    94,    94,    57,    57,    57,    57,    56,    74,    74,
      57,    57,    57,    63,    63,    63,    63,    91,    57,    91,
      57,    91,    21,    10,    57,    63,    57,    63,    57,    63,
      21,    63,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    66,    66,    67,    68,    69,
      70,    70,    71,    71,    72,    73,    74,    74,    75,    75,
      75,    75,    76,    76,    76,    76,    76,    77,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    80,    80,    80,    80,    80,    80,    81,    81,
      81,    81,    81,    81,    82,    82,    82,    83,    84,    84,
      84,    85,    85,    85,    86,    86,    86,    86,    87,    87,
      88,    89,    89,    89,    89,    89,    90,    90,    90,    91,
      91,    92,    93,    93,    94,    94,    95,    96,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     2,     3,     4,     4,     3,
       1,     3,     1,     3,     1,     1,     1,     2,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     3,     3,     2,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     1,     1,     1,     1,     5,     7,
       5,     1,     1,     1,     7,     6,     7,     6,     5,     5,
       7,     2,     2,     3,     5,     2,     5,     6,     6,     1,
       3,     2,     1,     3,     3,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 6:
#line 73 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1486 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 74 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1492 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 77 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[0]),5,"STMT");}
#line 1498 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 78 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-1]),1,"COMP_STMT");(yyval)->addAllChild((yyvsp[0]));}
#line 1504 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 81 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1510 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 82 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1516 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 83 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1522 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 84 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1528 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 85 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1534 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 88 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node(1,"STMT_EMPTY");}
#line 1540 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 89 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1546 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 92 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-1]),1,"STMT READ");}
#line 1552 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 94 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-1]),1,"STMT WRITE");}
#line 1558 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 98 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[-1]),1,"STMT DECLARE");}
#line 1564 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 101 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[0]),1,"DECLARE_LIST");}
#line 1570 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 102 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node(1,"DECLARE_LIST");(yyval)->addAllChild((yyvsp[-2]));(yyval)->addChild((yyvsp[0]));}
#line 1576 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 105 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[0]),2,"EXPR DECLARE_VAR");}
#line 1582 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 107 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),2,"EXPR DECLARE_ASSIGN");}
#line 1588 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 110 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1594 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 115 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1600 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 119 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node(1,"STMT_EMPTY");}
#line 1606 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 120 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1612 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 123 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1618 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 124 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1624 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 125 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1630 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 126 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1636 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 131 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1642 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 132 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1648 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1654 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 134 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1660 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 135 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1666 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 141 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),"int",2,"EXPR_OR");}
#line 1672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 143 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),"int",2,"EXPR_AND");}
#line 1678 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[0]),"int",2,"EXPR_NOT");}
#line 1684 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 149 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),2,"EXPR_PLUS");}
#line 1690 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 152 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),2,"EXPR_MINUS");}
#line 1696 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 155 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),2,"EXPR_MUL");}
#line 1702 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 158 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),2,"EXPR_DIV");}
#line 1708 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),"int",2,"EXPR_MOD");}
#line 1714 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 163 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[0]),2,"EXPR_minus expr");}
#line 1720 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 166 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[0]),2,"EXPR_plus expr");}
#line 1726 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 169 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[0]),2,"EXPR_tplus expr");}
#line 1732 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 172 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-1]),2,"EXPR_expr tplus");}
#line 1738 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[0]),2,"EXPR_tminus expr");}
#line 1744 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 178 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-1]),2,"EXPR_expr tminus");}
#line 1750 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 182 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),1,"STMT_ASSIGN");}
#line 1756 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval)=new Node((yyvsp[-2]),(yyvsp[0]),"int",2,"CMP_EQ");}
#line 1762 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 225 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),"int",2,"CMP_RE");}
#line 1768 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 238 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),"int",2,"CMP_RT");}
#line 1774 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 250 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),"int",2,"CMP_LE");}
#line 1780 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 262 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),"int",2,"CMP_LT");}
#line 1786 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval)=new Node((yyvsp[-2]),(yyvsp[0]),"int",2,"CMP_NE");}
#line 1792 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 288 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),"int",2,"EXPR_BITAND");}
#line 1798 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 295 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),"int",2,"EXPR_BITOR");}
#line 1804 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 302 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),"int",2,"EXPR_XOR");}
#line 1810 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 309 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[0]),"int",2,"EXPR_BITNOT");}
#line 1816 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 317 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),"int",2,"EXPR_SHL");}
#line 1822 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 326 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),"int",2,"EXPR_SHR");}
#line 1828 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 338 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1834 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 339 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1840 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 340 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1846 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 343 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1852 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 346 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->node_name=(yyvsp[-2])->node_name+"   CONDITION";
    node=new Node();
    node->type=1;
    node->node_name="STMT   null   IF  BRANCH";
    node->children.push_back((yyvsp[0]));
    (yyval)=new Node((yyvsp[-2]),node,1,"STMT_IF");
    }
#line 1865 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 354 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-4])->node_name=(yyvsp[-4])->node_name+"   CONDITION";
    Node* node1=new Node();
    node1->type=1;
    node1->node_name="STMT   null   IF  BRANCH";
    node1->children.push_back((yyvsp[-2]));
    Node* node2=new Node();
    node2->type=1;
    node2->node_name="STMT   null   ELSE  BRANCH";
    node2->children.clear();
    node2->children.push_back((yyvsp[0]));
    (yyval)=new Node((yyvsp[-4]),node1,1,"STMT_IF");
    (yyval)->children.push_back(node2);
  }
#line 1884 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 368 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->node_name=(yyvsp[-2])->node_name+"   CONDITION";
    node=new Node();
    node->type=1;
    node->node_name="STMT   null   IF  BRANCH";
    node->children.push_back((yyvsp[0]));
    (yyval)=new Node((yyvsp[-2]),node,1,"STMT_IF");
    }
#line 1897 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 378 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1903 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 379 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1909 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 380 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1915 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 383 "parser.y" /* yacc.c:1646  */
    {  
    (yyvsp[-4])->node_name=(yyvsp[-4])->node_name+"   START";
    (yyvsp[-3])->node_name=(yyvsp[-3])->node_name+"   CONDITION";
    (yyvsp[-2])->node_name=(yyvsp[-2])->node_name+"   ITERATOR";
    (yyval)=new Node((yyvsp[-4]),(yyvsp[-3]),1,"STMT_FOR");
    (yyval)->children.push_back((yyvsp[-2]));
    (yyval)->children.push_back((yyvsp[0]));
    }
#line 1928 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 391 "parser.y" /* yacc.c:1646  */
    {  
    (yyvsp[-3])->node_name=(yyvsp[-3])->node_name+"   START";
    (yyvsp[-2])->node_name=(yyvsp[-2])->node_name+"   CONDITION";
    (yyval)=new Node((yyvsp[-3]),(yyvsp[-2]),1,"STMT_FOR");
    (yyval)->children.push_back((yyvsp[0]));
    }
#line 1939 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 397 "parser.y" /* yacc.c:1646  */
    {  
    (yyvsp[-4])->node_name=(yyvsp[-4])->node_name+"   START";
    (yyvsp[-3])->node_name=(yyvsp[-3])->node_name+"   CONDITION";
    (yyvsp[-2])->node_name=(yyvsp[-2])->node_name+"   ITERATOR";
    (yyval)=new Node((yyvsp[-4]),(yyvsp[-3]),1,"STMT_FOR");
    (yyval)->children.push_back((yyvsp[-2]));
    (yyval)->children.push_back((yyvsp[0]));
    }
#line 1952 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 405 "parser.y" /* yacc.c:1646  */
    {  
    (yyvsp[-3])->node_name=(yyvsp[-3])->node_name+"   START";
    (yyvsp[-2])->node_name=(yyvsp[-2])->node_name+"   CONDITION";
    (yyval)=new Node((yyvsp[-3]),(yyvsp[-2]),1,"STMT_FOR");
    (yyval)->children.push_back((yyvsp[0]));
    }
#line 1963 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 413 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2])->node_name=(yyvsp[-2])->node_name+"   CONDITION";(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),1,"STMT_WHILE");}
#line 1969 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 414 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2])->node_name=(yyvsp[-2])->node_name+"   CONDITION";(yyval)=new Node((yyvsp[-2]),(yyvsp[0]),1,"STMT_WHILE");}
#line 1975 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 417 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2])->node_name=(yyvsp[-2])->node_name+"   CONDITION";(yyval)=new Node((yyvsp[-5]),(yyvsp[-2]),1,"STMT_DOWHILE");}
#line 1981 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 420 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node(1,"JUMP_STMT   CONTINUE");}
#line 1987 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 421 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node(1,"JUMP_STMT   RETURN");}
#line 1993 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 422 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-1]),1,"JUMP_STMT   RETURN");}
#line 1999 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 423 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[-2]),1,"JUMP_STMT   RETURN");}
#line 2005 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 424 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node(1,"JUMP_STMT   BREAK");}
#line 2011 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 429 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[0]),"Start");dfs((yyval),1);}
#line 2017 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 430 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[0]),"Start");dfs((yyval),1);}
#line 2023 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 431 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[0]),"Start");dfs((yyval),1);}
#line 2029 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 435 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2035 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 436 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node(1,"EXPRESSION_LIST");(yyval)->addAllChild((yyvsp[-2]));(yyval)->addChild((yyvsp[0]));}
#line 2041 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 459 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2047 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 460 "parser.y" /* yacc.c:1646  */
    { (yyval)=new Node((yyvsp[0]),4,"VAR");(yyval)->var_name=yylval->var_name;}
#line 2053 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 471 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node(6,"TYPE_"+yylval->var_name);}
#line 2059 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 475 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[0]),"int",3,"VAL");(yyval)->value=yylval->value;}
#line 2065 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 476 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[0]),"double",3,"VAL");(yyval)->value=yylval->value;}
#line 2071 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 477 "parser.y" /* yacc.c:1646  */
    {(yyval)=new Node((yyvsp[0]),"char",3,"VAL");(yyval)->value=yylval->value;}
#line 2077 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2081 "parser.cpp" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 480 "parser.y" /* yacc.c:1906  */

int judgeType(Node* node){
   if(node->type_name=="int"||node->type_name=="char"||node->type_name=="double"||node->type_name=="float"){
       return 4;
   }
   else{
   return -1;
   }
}
string deal(Node* arg1,Node* arg2,int oparg){
  if(oparg==1||oparg==2||oparg==9||oparg==10||oparg==3||oparg==4){
    if((arg1->type_name=="int"||arg1->type_name=="char")&&(arg2->type_name=="int"||arg2->type_name=="char")){
      return "int";
    }
    return "error";
  }
  else if(oparg==5||oparg==6||oparg==7||oparg==8){
    if((arg1->type_name=="int"&&arg2->type_name=="int")||(arg1->type_name=="int"&&arg2->type_name=="char")||(arg1->type_name=="char"&&arg2->type_name=="int")){
      return "int";
    }
    else if(arg1->type_name=="char"&&arg2->type_name=="char"){
      return "char";
    }
    else if(arg1->type_name=="double"||arg2->type_name=="double"){
      return "double";
    }
    else if(arg1->type_name=="float"||arg2->type_name=="float"){
      return "float";
    }
    else{
      return"error";
    }
  }
  else if(oparg==11||oparg==12||oparg==13||oparg==14||oparg==15||oparg==16||oparg==17||oparg==18){
    if((arg1->type_name!="int"&&arg1->type_name!="char"&&arg1->type_name!="float"&&arg1->type_name!="double")||(arg2->type_name!="int"&&arg2->type_name!="char"&&arg2->type_name!="float"&&arg2->type_name!="double")){
      return "error";
    }
    else{
      return "int";
    }
  }
    else{
      return "error";
    }
}
int  sti(string s){
  int a=atoi(s.c_str());
  return a;
}
double stf(string s){
  double b=atof(s.c_str());
  return b;
}
var_info* get(string s){
    map<string,var_info*>::iterator itor;
    itor=var_list.find(s);
    if(itor==var_list.end())
        return NULL;
    else
        return itor->second;
}
void dfs(Node* node,int depth)
{
		printNode(node,depth);
		for (int i=0;i<node->children.size();i++)
		{
			dfs(node->children[i],depth+1);
		}
}
string tostr(int a){
  ostringstream os;
  os<<a;
  return os.str();
}
string tostr(double b){
  ostringstream os;
  os<<b;
  return os.str();
}
void printNode(Node* node,int indent){
  for(int i=1;i<=(indent-1)*3;i++){
      cout<<" ";
    }
  if(node->type==3){
    cout<<"Val   ";
    if(node->type_name=="int"){
      cout<<node->type_name<<"   "<<node->value;
    }
    else if(node->type_name=="char"){
      cout<<node->type_name<<"   "<<node->value;
    }
    else if(node->type_name=="double"){
      cout<<node->type_name<<"   "<<node->value;
    }
    else if(node->type_name=="float"){
      cout<<node->type_name<<"   "<<node->value;
    }
  }
  else if(node->type==4){
   cout<<"Var   "<<node->var_name<<"    ";
  /* if(node->type_name=="int"){
     cout<<node->type_name<<"   "<<node->value;
   }
   else  if(node->type_name=="char"){
     cout<<node->type_name<<"   "<<node->value;
   }
   else  if(node->type_name=="double"||node->type_name=="float"){
     cout<<node->type_name<<"   "<<node->value;
   }
   else{
     cout<<node->type_name;
   }*/
  }
  else if(node->type==5){
  }
  else{
    cout<<node->node_name<<"     "<<node->value<<endl;
  }
}

