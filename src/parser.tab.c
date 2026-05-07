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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

class ASTNode;   

extern int yylex();
void yyerror(const char *s);

ASTNode* root;

#line 85 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_KW = 3,                     /* INT_KW  */
  YYSYMBOL_FLOAT_KW = 4,                   /* FLOAT_KW  */
  YYSYMBOL_IF_KW = 5,                      /* IF_KW  */
  YYSYMBOL_ELSE_KW = 6,                    /* ELSE_KW  */
  YYSYMBOL_WHILE_KW = 7,                   /* WHILE_KW  */
  YYSYMBOL_RETURN_KW = 8,                  /* RETURN_KW  */
  YYSYMBOL_FUNCTION_KW = 9,                /* FUNCTION_KW  */
  YYSYMBOL_PRINT = 10,                     /* PRINT  */
  YYSYMBOL_PLUS = 11,                      /* PLUS  */
  YYSYMBOL_MINUS = 12,                     /* MINUS  */
  YYSYMBOL_MULT = 13,                      /* MULT  */
  YYSYMBOL_DIV = 14,                       /* DIV  */
  YYSYMBOL_MOD = 15,                       /* MOD  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_EQ = 17,                        /* EQ  */
  YYSYMBOL_NEQ = 18,                       /* NEQ  */
  YYSYMBOL_LT = 19,                        /* LT  */
  YYSYMBOL_GT = 20,                        /* GT  */
  YYSYMBOL_LTE = 21,                       /* LTE  */
  YYSYMBOL_GTE = 22,                       /* GTE  */
  YYSYMBOL_LPAREN = 23,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 24,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 25,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 26,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 27,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_NUMBER = 29,                    /* NUMBER  */
  YYSYMBOL_FLOATNUM = 30,                  /* FLOATNUM  */
  YYSYMBOL_ID = 31,                        /* ID  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_statements = 34,                /* statements  */
  YYSYMBOL_statement = 35,                 /* statement  */
  YYSYMBOL_decl_stmt = 36,                 /* decl_stmt  */
  YYSYMBOL_assignment = 37,                /* assignment  */
  YYSYMBOL_print_stmt = 38,                /* print_stmt  */
  YYSYMBOL_if_stmt = 39,                   /* if_stmt  */
  YYSYMBOL_else_part = 40,                 /* else_part  */
  YYSYMBOL_while_stmt = 41,                /* while_stmt  */
  YYSYMBOL_block = 42,                     /* block  */
  YYSYMBOL_func_decl = 43,                 /* func_decl  */
  YYSYMBOL_param_list = 44,                /* param_list  */
  YYSYMBOL_return_stmt = 45,               /* return_stmt  */
  YYSYMBOL_func_call = 46,                 /* func_call  */
  YYSYMBOL_arg_list = 47,                  /* arg_list  */
  YYSYMBOL_logical_or = 48,                /* logical_or  */
  YYSYMBOL_logical_and = 49,               /* logical_and  */
  YYSYMBOL_comparison = 50,                /* comparison  */
  YYSYMBOL_expr = 51,                      /* expr  */
  YYSYMBOL_term = 52,                      /* term  */
  YYSYMBOL_factor = 53                     /* factor  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    40,    40,    47,    52,    60,    64,    68,    72,    76,
      80,    84,    91,    97,   104,   110,   120,   130,   139,   147,
     157,   163,   170,   176,   183,   193,   199,   207,   215,   225,
     233,   241,   248,   258,   264,   272,   279,   288,   294,   302,
     306,   316,   320,   330,   337,   344,   351,   358,   365,   372,
     379,   386,   390,   396,   400,   404,   408,   415,   422,   429,
     436,   443
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
  "\"end of file\"", "error", "\"invalid token\"", "INT_KW", "FLOAT_KW",
  "IF_KW", "ELSE_KW", "WHILE_KW", "RETURN_KW", "FUNCTION_KW", "PRINT",
  "PLUS", "MINUS", "MULT", "DIV", "MOD", "ASSIGN", "EQ", "NEQ", "LT", "GT",
  "LTE", "GTE", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON",
  "COMMA", "NUMBER", "FLOATNUM", "ID", "$accept", "program", "statements",
  "statement", "decl_stmt", "assignment", "print_stmt", "if_stmt",
  "else_part", "while_stmt", "block", "func_decl", "param_list",
  "return_stmt", "func_call", "arg_list", "logical_or", "logical_and",
  "comparison", "expr", "term", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      71,   -29,   -19,    -6,     5,    61,    22,    49,    20,    77,
      71,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,    -9,
      21,    92,    92,    92,   -66,   -66,   -66,   110,   -66,     4,
     117,   107,   111,    92,    92,   -66,   -66,    92,   -66,    92,
     -66,     3,    83,   -66,    74,    45,    43,    89,    92,    92,
     -66,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      10,    59,    11,    13,    30,    92,     1,    92,     1,   -66,
     -66,    65,    74,   117,   117,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   104,   105,   112,    73,    87,   -66,
     -66,   -66,    83,    42,   -66,   132,   -66,   -66,   -66,   -66,
      92,   -66,   -66,   -66,   112,    91,   -66,   -66,    56,     1,
     -66,    74,   -66,   108,   109,   -66,   -66,   -66,   -66,   -66
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     4,     5,     6,     7,     8,     9,    10,    11,     0,
       0,     0,     0,     0,    34,    51,    52,    53,    54,     0,
      46,    50,     0,     0,     0,     1,     3,     0,    12,     0,
      14,     0,    39,    41,    43,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      36,     0,    37,    44,    45,    47,    48,    49,    60,    61,
      56,    57,    58,    59,     0,     0,     0,     0,     0,    16,
      13,    15,    40,     0,    19,    22,    42,    24,    23,    35,
       0,    29,    30,    28,     0,     0,    17,    26,     0,     0,
      18,    38,    27,     0,     0,    25,    21,    20,    31,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,    48,   -10,   -66,   -66,   -66,   -66,   -66,   -66,
     -65,   -66,   -66,   -66,   -66,   -66,   120,    78,    79,    -4,
      68,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     9,    10,    11,    12,    13,    14,    15,   110,    16,
      95,    17,    87,    18,    28,    71,    41,    42,    43,    44,
      30,    31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    29,    19,    98,     1,     2,     3,    37,     4,     5,
       6,     7,    20,    84,    85,    48,    49,    21,    38,    46,
      65,   103,    48,    49,    48,    49,    93,    66,    22,    61,
      62,    50,     8,    63,    86,    64,    34,    39,    89,   112,
      90,    48,    49,    72,   117,     1,     2,     3,    40,     4,
       5,     6,     7,    32,    48,    49,    94,    91,    97,     1,
       2,     3,    65,     4,     5,     6,     7,    69,   107,    68,
      48,    49,    33,     8,     1,     2,     3,    35,     4,     5,
       6,     7,   115,    88,    23,    48,    49,     8,    24,    99,
      25,    26,    27,   100,   113,   114,   111,   104,    36,   116,
      67,   105,     8,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    23,    70,   106,    23,    73,    74,    25,    26,
      27,    25,    26,    27,    54,    55,    56,    57,    58,    59,
      51,    52,    53,    47,    60,   101,   102,    93,   109,   118,
     119,   108,    45,    92,     0,     0,    96
};

static const yytype_int8 yycheck[] =
{
      10,     5,    31,    68,     3,     4,     5,    16,     7,     8,
       9,    10,    31,     3,     4,    11,    12,    23,    27,    23,
      17,    86,    11,    12,    11,    12,    25,    24,    23,    33,
      34,    27,    31,    37,    24,    39,    16,    16,    27,   104,
      27,    11,    12,    47,   109,     3,     4,     5,    27,     7,
       8,     9,    10,    31,    11,    12,    66,    27,    68,     3,
       4,     5,    17,     7,     8,     9,    10,    24,    26,    24,
      11,    12,    23,    31,     3,     4,     5,     0,     7,     8,
       9,    10,    26,    24,    23,    11,    12,    31,    27,    24,
      29,    30,    31,    28,     3,     4,   100,    24,   108,   109,
      17,    28,    31,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    23,    24,    27,    23,    48,    49,    29,    30,
      31,    29,    30,    31,    17,    18,    19,    20,    21,    22,
      13,    14,    15,    23,    23,    31,    31,    25,     6,    31,
      31,    93,    22,    65,    -1,    -1,    67
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    10,    31,    33,
      34,    35,    36,    37,    38,    39,    41,    43,    45,    31,
      31,    23,    23,    23,    27,    29,    30,    31,    46,    51,
      52,    53,    31,    23,    16,     0,    35,    16,    27,    16,
      27,    48,    49,    50,    51,    48,    51,    23,    11,    12,
      27,    13,    14,    15,    17,    18,    19,    20,    21,    22,
      23,    51,    51,    51,    51,    17,    24,    17,    24,    24,
      24,    47,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,     3,     4,    24,    44,    24,    27,
      27,    27,    49,    25,    35,    42,    50,    35,    42,    24,
      28,    31,    31,    42,    24,    28,    27,    26,    34,     6,
      40,    51,    42,     3,     4,    26,    35,    42,    31,    31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    35,    36,    36,    36,    36,    37,    38,    39,    39,
      40,    40,    40,    41,    41,    42,    42,    43,    43,    44,
      44,    44,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    49,    49,    50,    51,    51,    51,    52,    52,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     5,     3,     5,     4,     5,     6,     5,
       2,     2,     0,     5,     5,     3,     2,     6,     5,     2,
       2,     4,     4,     3,     2,     4,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3
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
  case 2: /* program: statements  */
#line 41 "parser.y"
    {
        root = (yyvsp[0].node);
    }
#line 1206 "parser.tab.c"
    break;

  case 3: /* statements: statements statement  */
#line 48 "parser.y"
      {
          (yyval.node) = (yyvsp[-1].node);
          (yyval.node)->addChild((yyvsp[0].node));
      }
#line 1215 "parser.tab.c"
    break;

  case 4: /* statements: statement  */
#line 53 "parser.y"
      {
          (yyval.node) = new ASTNode("STATEMENTS");
          (yyval.node)->addChild((yyvsp[0].node));
      }
#line 1224 "parser.tab.c"
    break;

  case 5: /* statement: decl_stmt  */
#line 61 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1232 "parser.tab.c"
    break;

  case 6: /* statement: assignment  */
#line 65 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1240 "parser.tab.c"
    break;

  case 7: /* statement: print_stmt  */
#line 69 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1248 "parser.tab.c"
    break;

  case 8: /* statement: if_stmt  */
#line 73 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1256 "parser.tab.c"
    break;

  case 9: /* statement: while_stmt  */
#line 77 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1264 "parser.tab.c"
    break;

  case 10: /* statement: func_decl  */
#line 81 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1272 "parser.tab.c"
    break;

  case 11: /* statement: return_stmt  */
#line 85 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1280 "parser.tab.c"
    break;

  case 12: /* decl_stmt: INT_KW ID SEMICOLON  */
#line 92 "parser.y"
    {
        ASTNode* node = new ASTNode("DECL_INT");
        node->addChild(new ASTNode("ID", (yyvsp[-1].strVal)));
        (yyval.node) = node;
    }
#line 1290 "parser.tab.c"
    break;

  case 13: /* decl_stmt: INT_KW ID ASSIGN expr SEMICOLON  */
#line 98 "parser.y"
    {
        ASTNode* node = new ASTNode("DECL_INT");
        node->addChild(new ASTNode("ID", (yyvsp[-3].strVal)));
        node->addChild((yyvsp[-1].node));
        (yyval.node) = node;
    }
#line 1301 "parser.tab.c"
    break;

  case 14: /* decl_stmt: FLOAT_KW ID SEMICOLON  */
#line 105 "parser.y"
    {
        ASTNode* node = new ASTNode("DECL_FLOAT");
        node->addChild(new ASTNode("ID", (yyvsp[-1].strVal)));
        (yyval.node) = node;
    }
#line 1311 "parser.tab.c"
    break;

  case 15: /* decl_stmt: FLOAT_KW ID ASSIGN expr SEMICOLON  */
#line 111 "parser.y"
    {
        ASTNode* node = new ASTNode("DECL_FLOAT");
        node->addChild(new ASTNode("ID", (yyvsp[-3].strVal)));
        node->addChild((yyvsp[-1].node));
        (yyval.node) = node;
    }
#line 1322 "parser.tab.c"
    break;

  case 16: /* assignment: ID ASSIGN expr SEMICOLON  */
#line 121 "parser.y"
    {
        ASTNode* node = new ASTNode("ASSIGN");
        node->addChild(new ASTNode("ID", (yyvsp[-3].strVal)));
        node->addChild((yyvsp[-1].node));
        (yyval.node) = node;
    }
#line 1333 "parser.tab.c"
    break;

  case 17: /* print_stmt: PRINT LPAREN expr RPAREN SEMICOLON  */
#line 131 "parser.y"
    {
        ASTNode* node = new ASTNode("PRINT");
        node->addChild((yyvsp[-2].node));
        (yyval.node) = node;
    }
#line 1343 "parser.tab.c"
    break;

  case 18: /* if_stmt: IF_KW LPAREN logical_or RPAREN block else_part  */
#line 140 "parser.y"
    {
        ASTNode* node = new ASTNode("IF");
        node->addChild((yyvsp[-3].node));
        node->addChild((yyvsp[-1].node));
        if((yyvsp[0].node)) node->addChild((yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1355 "parser.tab.c"
    break;

  case 19: /* if_stmt: IF_KW LPAREN logical_or RPAREN statement  */
#line 148 "parser.y"
    {
        ASTNode* node = new ASTNode("IF");
        node->addChild((yyvsp[-2].node));
        node->addChild((yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1366 "parser.tab.c"
    break;

  case 20: /* else_part: ELSE_KW block  */
#line 158 "parser.y"
    {
        ASTNode* node = new ASTNode("ELSE");
        node->addChild((yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1376 "parser.tab.c"
    break;

  case 21: /* else_part: ELSE_KW statement  */
#line 164 "parser.y"
    {
        ASTNode* node = new ASTNode("ELSE");
        node->addChild((yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1386 "parser.tab.c"
    break;

  case 22: /* else_part: %empty  */
#line 170 "parser.y"
    {
        (yyval.node) = nullptr;
    }
#line 1394 "parser.tab.c"
    break;

  case 23: /* while_stmt: WHILE_KW LPAREN logical_or RPAREN block  */
#line 177 "parser.y"
    {
        ASTNode* node = new ASTNode("WHILE");
        node->addChild((yyvsp[-2].node));
        node->addChild((yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1405 "parser.tab.c"
    break;

  case 24: /* while_stmt: WHILE_KW LPAREN logical_or RPAREN statement  */
#line 184 "parser.y"
    {
        ASTNode* node = new ASTNode("WHILE");
        node->addChild((yyvsp[-2].node));
        node->addChild((yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1416 "parser.tab.c"
    break;

  case 25: /* block: LBRACE statements RBRACE  */
#line 194 "parser.y"
    {
        ASTNode* node = new ASTNode("BLOCK");
        node->addChild((yyvsp[-1].node));
        (yyval.node) = node;
    }
#line 1426 "parser.tab.c"
    break;

  case 26: /* block: LBRACE RBRACE  */
#line 200 "parser.y"
    {
        ASTNode* node = new ASTNode("BLOCK");
        (yyval.node) = node;
    }
#line 1435 "parser.tab.c"
    break;

  case 27: /* func_decl: FUNCTION_KW ID LPAREN param_list RPAREN block  */
#line 208 "parser.y"
    {
        ASTNode* node = new ASTNode("FUNC_DECL");
        node->addChild(new ASTNode("ID", (yyvsp[-4].strVal)));
        if((yyvsp[-2].node)) node->addChild((yyvsp[-2].node));
        node->addChild((yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1447 "parser.tab.c"
    break;

  case 28: /* func_decl: FUNCTION_KW ID LPAREN RPAREN block  */
#line 216 "parser.y"
    {
        ASTNode* node = new ASTNode("FUNC_DECL");
        node->addChild(new ASTNode("ID", (yyvsp[-3].strVal)));
        node->addChild((yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1458 "parser.tab.c"
    break;

  case 29: /* param_list: INT_KW ID  */
#line 226 "parser.y"
    {
        ASTNode* node = new ASTNode("PARAMS");
        ASTNode* param = new ASTNode("PARAM_INT");
        param->addChild(new ASTNode("ID", (yyvsp[0].strVal)));
        node->addChild(param);
        (yyval.node) = node;
    }
#line 1470 "parser.tab.c"
    break;

  case 30: /* param_list: FLOAT_KW ID  */
#line 234 "parser.y"
    {
        ASTNode* node = new ASTNode("PARAMS");
        ASTNode* param = new ASTNode("PARAM_FLOAT");
        param->addChild(new ASTNode("ID", (yyvsp[0].strVal)));
        node->addChild(param);
        (yyval.node) = node;
    }
#line 1482 "parser.tab.c"
    break;

  case 31: /* param_list: param_list COMMA INT_KW ID  */
#line 242 "parser.y"
    {
        ASTNode* param = new ASTNode("PARAM_INT");
        param->addChild(new ASTNode("ID", (yyvsp[0].strVal)));
        (yyvsp[-3].node)->addChild(param);
        (yyval.node) = (yyvsp[-3].node);
    }
#line 1493 "parser.tab.c"
    break;

  case 32: /* param_list: param_list COMMA FLOAT_KW ID  */
#line 249 "parser.y"
    {
        ASTNode* param = new ASTNode("PARAM_FLOAT");
        param->addChild(new ASTNode("ID", (yyvsp[0].strVal)));
        (yyvsp[-3].node)->addChild(param);
        (yyval.node) = (yyvsp[-3].node);
    }
#line 1504 "parser.tab.c"
    break;

  case 33: /* return_stmt: RETURN_KW expr SEMICOLON  */
#line 259 "parser.y"
    {
        ASTNode* node = new ASTNode("RETURN");
        node->addChild((yyvsp[-1].node));
        (yyval.node) = node;
    }
#line 1514 "parser.tab.c"
    break;

  case 34: /* return_stmt: RETURN_KW SEMICOLON  */
#line 265 "parser.y"
    {
        ASTNode* node = new ASTNode("RETURN");
        (yyval.node) = node;
    }
#line 1523 "parser.tab.c"
    break;

  case 35: /* func_call: ID LPAREN arg_list RPAREN  */
#line 273 "parser.y"
    {
        ASTNode* node = new ASTNode("FUNC_CALL");
        node->addChild(new ASTNode("ID", (yyvsp[-3].strVal)));
        if((yyvsp[-1].node)) node->addChild((yyvsp[-1].node));
        (yyval.node) = node;
    }
#line 1534 "parser.tab.c"
    break;

  case 36: /* func_call: ID LPAREN RPAREN  */
#line 280 "parser.y"
    {
        ASTNode* node = new ASTNode("FUNC_CALL");
        node->addChild(new ASTNode("ID", (yyvsp[-2].strVal)));
        (yyval.node) = node;
    }
#line 1544 "parser.tab.c"
    break;

  case 37: /* arg_list: expr  */
#line 289 "parser.y"
    {
        ASTNode* node = new ASTNode("ARGS");
        node->addChild((yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1554 "parser.tab.c"
    break;

  case 38: /* arg_list: arg_list COMMA expr  */
#line 295 "parser.y"
    {
        (yyvsp[-2].node)->addChild((yyvsp[0].node));
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1563 "parser.tab.c"
    break;

  case 39: /* logical_or: logical_and  */
#line 303 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1571 "parser.tab.c"
    break;

  case 40: /* logical_or: logical_or EQ logical_and  */
#line 307 "parser.y"
    {
        ASTNode* node = new ASTNode("LOGI_OR");
        node->addChild((yyvsp[-2].node));
        node->addChild((yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1582 "parser.tab.c"
    break;

  case 41: /* logical_and: comparison  */
#line 317 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1590 "parser.tab.c"
    break;

  case 42: /* logical_and: logical_and EQ comparison  */
#line 321 "parser.y"
    {
        ASTNode* node = new ASTNode("LOGI_AND");
        node->addChild((yyvsp[-2].node));
        node->addChild((yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1601 "parser.tab.c"
    break;

  case 43: /* comparison: expr  */
#line 331 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1609 "parser.tab.c"
    break;

  case 44: /* expr: expr PLUS term  */
#line 338 "parser.y"
      {
          ASTNode* node = new ASTNode("ADD");
          node->addChild((yyvsp[-2].node));
          node->addChild((yyvsp[0].node));
          (yyval.node) = node;
      }
#line 1620 "parser.tab.c"
    break;

  case 45: /* expr: expr MINUS term  */
#line 345 "parser.y"
      {
          ASTNode* node = new ASTNode("SUB");
          node->addChild((yyvsp[-2].node));
          node->addChild((yyvsp[0].node));
          (yyval.node) = node;
      }
#line 1631 "parser.tab.c"
    break;

  case 46: /* expr: term  */
#line 352 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1639 "parser.tab.c"
    break;

  case 47: /* term: term MULT factor  */
#line 359 "parser.y"
      {
          ASTNode* node = new ASTNode("MUL");
          node->addChild((yyvsp[-2].node));
          node->addChild((yyvsp[0].node));
          (yyval.node) = node;
      }
#line 1650 "parser.tab.c"
    break;

  case 48: /* term: term DIV factor  */
#line 366 "parser.y"
      {
          ASTNode* node = new ASTNode("DIV");
          node->addChild((yyvsp[-2].node));
          node->addChild((yyvsp[0].node));
          (yyval.node) = node;
      }
#line 1661 "parser.tab.c"
    break;

  case 49: /* term: term MOD factor  */
#line 373 "parser.y"
      {
          ASTNode* node = new ASTNode("MOD");
          node->addChild((yyvsp[-2].node));
          node->addChild((yyvsp[0].node));
          (yyval.node) = node;
      }
#line 1672 "parser.tab.c"
    break;

  case 50: /* term: factor  */
#line 380 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1680 "parser.tab.c"
    break;

  case 51: /* factor: NUMBER  */
#line 387 "parser.y"
      {
          (yyval.node) = new ASTNode("NUMBER", std::to_string((yyvsp[0].intVal)));
      }
#line 1688 "parser.tab.c"
    break;

  case 52: /* factor: FLOATNUM  */
#line 391 "parser.y"
      {
          char buffer[32];
          snprintf(buffer, sizeof(buffer), "%f", (yyvsp[0].floatVal));
          (yyval.node) = new ASTNode("FLOATNUM", buffer);
      }
#line 1698 "parser.tab.c"
    break;

  case 53: /* factor: ID  */
#line 397 "parser.y"
      {
          (yyval.node) = new ASTNode("ID", (yyvsp[0].strVal));
      }
#line 1706 "parser.tab.c"
    break;

  case 54: /* factor: func_call  */
#line 401 "parser.y"
      {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1714 "parser.tab.c"
    break;

  case 55: /* factor: LPAREN expr RPAREN  */
#line 405 "parser.y"
      {
          (yyval.node) = (yyvsp[-1].node);
      }
#line 1722 "parser.tab.c"
    break;

  case 56: /* factor: factor LT factor  */
#line 409 "parser.y"
      {
          ASTNode* node = new ASTNode("LT");
          node->addChild((yyvsp[-2].node));
          node->addChild((yyvsp[0].node));
          (yyval.node) = node;
      }
#line 1733 "parser.tab.c"
    break;

  case 57: /* factor: factor GT factor  */
#line 416 "parser.y"
      {
          ASTNode* node = new ASTNode("GT");
          node->addChild((yyvsp[-2].node));
          node->addChild((yyvsp[0].node));
          (yyval.node) = node;
      }
#line 1744 "parser.tab.c"
    break;

  case 58: /* factor: factor LTE factor  */
#line 423 "parser.y"
      {
          ASTNode* node = new ASTNode("LTE");
          node->addChild((yyvsp[-2].node));
          node->addChild((yyvsp[0].node));
          (yyval.node) = node;
      }
#line 1755 "parser.tab.c"
    break;

  case 59: /* factor: factor GTE factor  */
#line 430 "parser.y"
      {
          ASTNode* node = new ASTNode("GTE");
          node->addChild((yyvsp[-2].node));
          node->addChild((yyvsp[0].node));
          (yyval.node) = node;
      }
#line 1766 "parser.tab.c"
    break;

  case 60: /* factor: factor EQ factor  */
#line 437 "parser.y"
      {
          ASTNode* node = new ASTNode("EQ");
          node->addChild((yyvsp[-2].node));
          node->addChild((yyvsp[0].node));
          (yyval.node) = node;
      }
#line 1777 "parser.tab.c"
    break;

  case 61: /* factor: factor NEQ factor  */
#line 444 "parser.y"
      {
          ASTNode* node = new ASTNode("NEQ");
          node->addChild((yyvsp[-2].node));
          node->addChild((yyvsp[0].node));
          (yyval.node) = node;
      }
#line 1788 "parser.tab.c"
    break;


#line 1792 "parser.tab.c"

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

#line 452 "parser.y"


void yyerror(const char *s)
{
    printf("Syntax Error: %s\n", s);
}
