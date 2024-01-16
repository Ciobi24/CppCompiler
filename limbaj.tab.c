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
#line 1 "limbaj.y"

#include <iostream>
#include <vector>
#include <stack>
#include "Class.h"
using namespace std;
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class IdList ids;
vector<int>dimensionContainer;
IdInfo* temp = new IdInfo;
vector<IdInfo*>valueContainer;

stack<int>scopes;
int currScope = 0;
int maxScope = 0;

void incrementScope(){
     currScope=maxScope+1;
     scopes.push(currScope);
     ids.scope_path.push_back(currScope);
     maxScope = max(currScope, maxScope);
}
void decrementScope(){
     if(currScope < 0 || scopes.empty()){
          cout << "[ScopeManager]: error at decrementScope\n";
          return;
     }
     scopes.pop();
     ids.scope_path.pop_back();
     currScope=scopes.top();
}
FunctionTable functions;
vector<IdInfo>params;
int flag_func=0;

ObjectTable all_obj_class;
vector<IdInfo>fields;
vector<Function>methods;
IdInfo ret_val;

#line 116 "limbaj.tab.c"

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

#include "limbaj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BGIN = 3,                       /* BGIN  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_ASSIGN = 5,                     /* ASSIGN  */
  YYSYMBOL_OPENBRK = 6,                    /* OPENBRK  */
  YYSYMBOL_CLOSEDBRK = 7,                  /* CLOSEDBRK  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_CONST = 12,                     /* CONST  */
  YYSYMBOL_EVAL = 13,                      /* EVAL  */
  YYSYMBOL_TOF = 14,                       /* TOF  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_VOID = 16,                      /* VOID  */
  YYSYMBOL_CLASS = 17,                     /* CLASS  */
  YYSYMBOL_NEW = 18,                       /* NEW  */
  YYSYMBOL_ID = 19,                        /* ID  */
  YYSYMBOL_TYPE = 20,                      /* TYPE  */
  YYSYMBOL_STR = 21,                       /* STR  */
  YYSYMBOL_NR = 22,                        /* NR  */
  YYSYMBOL_BOO = 23,                       /* BOO  */
  YYSYMBOL_FLT = 24,                       /* FLT  */
  YYSYMBOL_CHR = 25,                       /* CHR  */
  YYSYMBOL_PLU = 26,                       /* "+"  */
  YYSYMBOL_MIN = 27,                       /* "-"  */
  YYSYMBOL_TIM = 28,                       /* "*"  */
  YYSYMBOL_DVD = 29,                       /* "/"  */
  YYSYMBOL_LT = 30,                        /* "<"  */
  YYSYMBOL_GT = 31,                        /* ">"  */
  YYSYMBOL_LET = 32,                       /* "<="  */
  YYSYMBOL_GET = 33,                       /* ">="  */
  YYSYMBOL_NOE = 34,                       /* "!="  */
  YYSYMBOL_NEG = 35,                       /* "!"  */
  YYSYMBOL_BEQ = 36,                       /* "=="  */
  YYSYMBOL_UMINUS = 37,                    /* UMINUS  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '['  */
  YYSYMBOL_42_ = 42,                       /* ']'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_progr = 45,                     /* progr  */
  YYSYMBOL_declarations = 46,              /* declarations  */
  YYSYMBOL_decl = 47,                      /* decl  */
  YYSYMBOL_assignation = 48,               /* assignation  */
  YYSYMBOL_func_decl = 49,                 /* func_decl  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_52_3 = 52,                      /* $@3  */
  YYSYMBOL_53_4 = 53,                      /* $@4  */
  YYSYMBOL_54_5 = 54,                      /* $@5  */
  YYSYMBOL_55_6 = 55,                      /* $@6  */
  YYSYMBOL_ret = 56,                       /* ret  */
  YYSYMBOL_f_declarations = 57,            /* f_declarations  */
  YYSYMBOL_control_statement = 58,         /* control_statement  */
  YYSYMBOL_condition_statement = 59,       /* condition_statement  */
  YYSYMBOL_if_statement = 60,              /* if_statement  */
  YYSYMBOL_61_7 = 61,                      /* $@7  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_else_statement = 63,            /* else_statement  */
  YYSYMBOL_64_9 = 64,                      /* $@9  */
  YYSYMBOL_65_10 = 65,                     /* $@10  */
  YYSYMBOL_66_11 = 66,                     /* $@11  */
  YYSYMBOL_while_statement = 67,           /* while_statement  */
  YYSYMBOL_68_12 = 68,                     /* $@12  */
  YYSYMBOL_69_13 = 69,                     /* $@13  */
  YYSYMBOL_for_statement = 70,             /* for_statement  */
  YYSYMBOL_71_14 = 71,                     /* $@14  */
  YYSYMBOL_72_15 = 72,                     /* $@15  */
  YYSYMBOL_for_init = 73,                  /* for_init  */
  YYSYMBOL_for_step = 74,                  /* for_step  */
  YYSYMBOL_expression = 75,                /* expression  */
  YYSYMBOL_dimension = 76,                 /* dimension  */
  YYSYMBOL_array_value = 77,               /* array_value  */
  YYSYMBOL_list_param = 78,                /* list_param  */
  YYSYMBOL_param = 79,                     /* param  */
  YYSYMBOL_block = 80,                     /* block  */
  YYSYMBOL_list = 81,                      /* list  */
  YYSYMBOL_statement = 82,                 /* statement  */
  YYSYMBOL_call_function = 83,             /* call_function  */
  YYSYMBOL_eval_stmt = 84,                 /* eval_stmt  */
  YYSYMBOL_typeOf_stmt = 85,               /* typeOf_stmt  */
  YYSYMBOL_call_list = 86                  /* call_list  */
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
#define YYLAST   432

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  234

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
      39,    40,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    78,    78,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    92,   146,   199,   205,   211,   228,   299,
     307,   307,   323,   323,   339,   339,   339,   351,   351,   351,
     364,   365,   366,   367,   368,   369,   371,   372,   373,   374,
     375,   376,   377,   378,   381,   382,   383,   386,   387,   391,
     391,   391,   405,   405,   405,   408,   408,   411,   411,   411,
     426,   426,   426,   441,   442,   445,   446,   449,   452,   455,
     458,   461,   464,   467,   470,   473,   476,   479,   482,   485,
     488,   491,   494,   497,   500,   503,   563,   625,   686,   718,
     751,   754,   759,   835,   836,   839,   843,   847,   848,   851,
     852,   853,   854,   855,   856,   858,   864,   871,   902,   933,
     934,   935,   936,   937,   938,   939,   940,   941,   942,   943,
     967
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
  "\"end of file\"", "error", "\"invalid token\"", "BGIN", "END",
  "ASSIGN", "OPENBRK", "CLOSEDBRK", "IF", "ELSE", "WHILE", "FOR", "CONST",
  "EVAL", "TOF", "RETURN", "VOID", "CLASS", "NEW", "ID", "TYPE", "STR",
  "NR", "BOO", "FLT", "CHR", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"<\"",
  "\">\"", "\"<=\"", "\">=\"", "\"!=\"", "\"!\"", "\"==\"", "UMINUS",
  "';'", "'('", "')'", "'['", "']'", "','", "$accept", "progr",
  "declarations", "decl", "assignation", "func_decl", "$@1", "$@2", "$@3",
  "$@4", "$@5", "$@6", "ret", "f_declarations", "control_statement",
  "condition_statement", "if_statement", "$@7", "$@8", "else_statement",
  "$@9", "$@10", "$@11", "while_statement", "$@12", "$@13",
  "for_statement", "$@14", "$@15", "for_init", "for_step", "expression",
  "dimension", "array_value", "list_param", "param", "block", "list",
  "statement", "call_function", "eval_stmt", "typeOf_stmt", "call_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-162)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     382,   -34,   -17,  -162,     8,    17,     6,    40,    30,   115,
      32,    33,  -162,  -162,  -162,    59,  -162,  -162,    35,    89,
      89,    52,    78,    60,    89,    -5,    79,    97,    10,  -162,
     369,    65,    66,  -162,  -162,  -162,    69,  -162,  -162,   103,
    -162,  -162,    -7,  -162,  -162,  -162,  -162,  -162,    89,    89,
      89,   206,   221,    11,   112,    80,   396,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,   -39,    77,    89,    89,    81,  -162,
      83,    90,   111,    99,   105,  -162,   128,  -162,   106,   107,
     108,  -162,  -162,  -162,  -162,   141,    53,   137,  -162,    37,
     242,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,   144,   154,  -162,   123,    89,   157,   145,  -162,   132,
     125,   396,  -162,   396,   161,   145,    89,    89,     1,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,   382,  -162,  -162,   -14,
     129,  -162,    67,    67,  -162,  -162,    37,    37,    37,    37,
      37,    37,  -162,  -162,    89,   396,  -162,   153,   135,   143,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,   149,   257,
     272,   303,  -162,   151,   382,   382,   340,   401,  -162,   178,
     145,   401,   190,  -162,  -162,  -162,   177,   317,   331,   183,
     167,   170,   401,  -162,   173,   401,  -162,    42,   401,  -162,
     171,  -162,  -162,     2,  -162,   174,  -162,  -162,   180,   185,
     208,  -162,   187,  -162,   401,   241,   395,  -162,  -162,  -162,
     224,  -162,  -162,  -162,  -162,   234,  -162,  -162,  -162,  -162,
    -162,  -162,   218,   241,   382,  -162,   251,   239,   345,  -162,
     252,  -162,  -162,  -162
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     9,    44,    47,    45,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     1,
       0,     0,     0,     8,    10,     2,     0,     3,     5,    55,
      48,    11,    85,    84,    80,    82,    81,    83,     0,     0,
       0,     0,     0,    64,    16,    24,    18,   119,   117,   109,
     113,   111,   115,   106,     0,     0,     0,     0,    20,    17,
       0,     0,     0,     0,     0,   102,     0,    97,     0,     0,
       0,     4,     6,    12,    52,     0,     0,     0,    79,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,   105,     0,
      91,    92,    19,    13,     0,     0,     0,     0,    15,    99,
     100,    96,    98,   101,   103,   104,     0,    56,    89,     0,
       0,    78,    67,    68,    69,    70,    71,    72,    73,    74,
      76,    75,    49,    57,     0,    14,    27,     0,     0,    93,
     120,   118,   110,   114,   112,   116,    90,    22,     0,     0,
       0,     0,    88,    86,     0,     0,     0,     0,    95,     0,
       0,     0,     0,   107,   108,    53,     0,     0,     0,    66,
       0,     0,    28,    40,     0,     0,    94,     0,     0,    54,
       0,    50,    58,     0,    65,     0,    36,    38,     0,     0,
       0,    41,     0,    42,    25,     0,     0,    87,    51,    59,
       0,    37,    39,    29,    43,     0,    30,    35,    31,    33,
      32,    34,     0,     0,     0,    26,     0,     0,     0,    23,
       0,    61,    21,    62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,  -124,    -9,     3,    51,  -162,  -162,  -162,  -162,
    -162,  -162,    57,  -161,    16,   196,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,   -11,   -20,  -162,  -112,  -162,  -162,  -162,   216,    39,
    -162,  -162,   209
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    12,   115,   171,   107,   215,
     167,   200,   222,   182,    13,    14,    15,   164,   208,    40,
     126,   189,    85,    16,   165,   209,    17,    21,   233,   104,
     195,    51,    27,   112,   148,   149,    35,    76,    77,    18,
      79,    80,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,   108,   161,   158,   109,    19,    67,    24,    69,    52,
     187,    24,    32,    56,    57,    67,    58,    59,    60,    61,
      62,    73,    20,     4,   204,    34,   162,   206,    22,   109,
      29,    72,    86,    74,    87,    63,    23,    88,    89,    90,
     177,   178,    26,    26,   103,    25,    75,    26,    36,    68,
       1,    26,     2,     3,     4,   111,   113,   205,   186,    28,
      33,     6,    72,    91,    92,    93,    94,    73,    39,    78,
      37,    38,    57,    41,    58,    59,    60,    61,    62,    74,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     156,    53,    75,   128,   145,    93,    94,    54,    69,    55,
     228,    65,    66,    81,    82,   159,   160,    83,    42,    84,
      43,    44,    45,    46,    47,    78,    48,   105,    30,   110,
     106,   114,   116,     1,    49,     2,     3,     4,    50,   117,
     118,     5,   121,   166,     6,     7,     1,   119,     2,     3,
       4,    70,    71,   120,   123,   124,   125,     6,    72,     1,
     142,   150,    31,   151,   152,   153,   154,   155,   180,   130,
     143,   144,   180,   146,    32,   147,    26,   157,    31,    31,
     181,   163,   168,   198,   181,   169,   180,    34,   198,   180,
      32,    32,   194,   183,   185,   199,   170,   183,   181,   172,
     199,   181,   176,    34,    34,   198,   188,   198,   201,   190,
      36,   183,   193,   201,   183,   196,   184,   199,   197,   199,
     184,   203,    33,   207,   210,   213,    36,    36,   211,    31,
     201,   202,   201,   212,   184,   214,   202,   184,    33,    33,
     224,    32,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   225,   100,   202,    34,   202,   101,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   226,   100,   229,   232,
     216,   102,   217,   218,   219,   220,   221,    36,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   230,   100,    33,
     227,   127,   131,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   122,   100,     0,   129,     0,   173,    91,    92,
      93,    94,    95,    96,    97,    98,    99,     0,   100,     0,
     175,     1,   174,     2,     3,     4,     0,     0,     0,     5,
       0,     0,     6,     7,   191,     1,     0,     2,     3,     4,
       0,     0,     0,     5,     0,     0,     6,     7,   192,     1,
       0,     2,     3,     4,     0,     0,     0,     5,     0,     0,
       6,     7,   231,     1,     0,     2,     3,     4,     0,     0,
       0,     5,     0,     0,     6,     7,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,   100,     1,   179,     2,
       3,     4,    70,    71,     0,     0,     0,     0,     6,    72,
       1,     0,     2,     3,     4,     0,     0,     0,     5,     0,
       0,     6,     7,     1,     0,     2,     3,     4,     0,     1,
     223,     2,     3,     4,     6,    72,     0,     0,     0,     0,
       6,    72,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,   100
};

static const yytype_int16 yycheck[] =
{
       9,    40,   126,   115,    43,    39,     5,     5,    28,    20,
     171,     5,     9,    24,    19,     5,    21,    22,    23,    24,
      25,    30,    39,    12,   185,     9,    40,   188,    20,    43,
       0,    20,    39,    30,    41,    40,    19,    48,    49,    50,
     164,   165,    41,    41,    53,    39,    30,    41,     9,    39,
       8,    41,    10,    11,    12,    66,    67,    15,   170,    19,
       9,    19,    20,    26,    27,    28,    29,    76,     9,    30,
      38,    38,    19,    38,    21,    22,    23,    24,    25,    76,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     110,    39,    76,    40,   105,    28,    29,    19,   118,    39,
     224,    22,     5,    38,    38,   116,   117,    38,    19,     6,
      21,    22,    23,    24,    25,    76,    27,     5,     3,    42,
      40,    40,    39,     8,    35,    10,    11,    12,    39,    39,
      19,    16,     4,   144,    19,    20,     8,    38,    10,    11,
      12,    13,    14,    38,    38,    38,    38,    19,    20,     8,
       6,    19,   161,    21,    22,    23,    24,    25,   167,    22,
       6,    38,   171,     6,   161,    20,    41,     6,   177,   178,
     167,    42,    19,   182,   171,    40,   185,   161,   187,   188,
     177,   178,   179,   167,     6,   182,    43,   171,   185,    40,
     187,   188,    41,   177,   178,   204,     6,   206,   182,    22,
     161,   185,    19,   187,   188,    38,   167,   204,    38,   206,
     171,    38,   161,    42,    40,     7,   177,   178,    38,   228,
     204,   182,   206,    38,   185,    38,   187,   188,   177,   178,
       6,   228,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     7,    36,   204,   228,   206,    40,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    38,    36,     7,     7,
      19,    40,    21,    22,    23,    24,    25,   228,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    38,    36,   228,
     223,    85,    40,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    76,    36,    -1,    86,    -1,    40,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    -1,
       7,     8,    40,    10,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    19,    20,     7,     8,    -1,    10,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    19,    20,     7,     8,
      -1,    10,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      19,    20,     7,     8,    -1,    10,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    19,    20,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,     8,    38,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    19,    20,
       8,    -1,    10,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    19,    20,     8,    -1,    10,    11,    12,    -1,     8,
      15,    10,    11,    12,    19,    20,    -1,    -1,    -1,    -1,
      19,    20,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    11,    12,    16,    19,    20,    45,    46,
      47,    48,    49,    58,    59,    60,    67,    70,    83,    39,
      39,    71,    20,    19,     5,    39,    41,    76,    19,     0,
       3,    47,    48,    49,    58,    80,    83,    38,    38,     9,
      63,    38,    19,    21,    22,    23,    24,    25,    27,    35,
      39,    75,    75,    39,    19,    39,    75,    19,    21,    22,
      23,    24,    25,    40,    86,    22,     5,     5,    39,    76,
      13,    14,    20,    47,    48,    58,    81,    82,    83,    84,
      85,    38,    38,    38,     6,    66,    39,    41,    75,    75,
      75,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      36,    40,    40,    47,    73,     5,    40,    52,    40,    43,
      42,    75,    77,    75,    40,    50,    39,    39,    19,    38,
      38,     4,    82,    38,    38,    38,    64,    59,    40,    86,
      22,    40,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,     6,     6,    38,    75,     6,    20,    78,    79,
      19,    21,    22,    23,    24,    25,    76,     6,    78,    75,
      75,    46,    40,    42,    61,    68,    75,    54,    19,    40,
      43,    51,    40,    40,    40,     7,    41,    46,    46,    38,
      47,    48,    57,    58,    83,     6,    78,    57,     6,    65,
      22,     7,     7,    19,    48,    74,    38,    38,    47,    48,
      55,    58,    83,    38,    57,    15,    57,    42,    62,    69,
      40,    38,    38,     7,    38,    53,    19,    21,    22,    23,
      24,    25,    56,    15,     6,     7,    38,    56,    46,     7,
      38,     7,     7,    72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    47,    47,    47,    47,    47,    48,    48,
      50,    49,    51,    49,    52,    53,    49,    54,    55,    49,
      56,    56,    56,    56,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    58,    58,    58,    59,    59,    61,
      62,    60,    64,    65,    63,    66,    63,    68,    69,    67,
      71,    72,    70,    73,    73,    74,    74,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      76,    76,    77,    78,    78,    79,    80,    81,    81,    82,
      82,    82,    82,    82,    82,    83,    83,    84,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     3,     2,     3,     1,     2,     1,
       2,     2,     3,     4,     5,     2,     3,     3,     3,     4,
       0,    12,     0,    11,     0,     0,    10,     0,     0,     9,
       1,     1,     1,     1,     1,     1,     2,     3,     2,     3,
       1,     2,     2,     3,     1,     1,     1,     1,     2,     0,
       0,     9,     0,     0,     6,     0,     3,     0,     0,     9,
       0,     0,    13,     1,     0,     1,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     4,     7,     4,     3,
       4,     3,     1,     1,     3,     2,     3,     1,     2,     2,
       2,     2,     1,     2,     2,     4,     3,     4,     4,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3
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
  case 2: /* progr: declarations block  */
#line 78 "limbaj.y"
                          {printf("The programme is correct!\n");}
#line 1389 "limbaj.tab.c"
    break;

  case 13: /* decl: TYPE ID ASSIGN expression  */
#line 92 "limbaj.y"
                                      {
                    if(-1 == (ids.addVar((yyvsp[-3].string), (yyvsp[-2].string), currScope, false, false))){
                         yyerror("[parser]: addVar error");
                         YYERROR;
                    }
                    node* res = (yyvsp[0].node)->evaluate();
                    if(res == nullptr){
                         yyerror("[parser]: Error at AST::evaluate()");
                         YYERROR;
                    }

                    if(res->type == exprType::INTEGER){
                         cout << "[parser]: Updating int value\n";
                         if(ids.updateInt((yyvsp[-2].string), res->val.iVal, currScope) == -1){
                         yyerror("[parser]: error at updateInt");
                         YYERROR; 
                         }
                    }
                    else if(res->type == exprType::FLOAT){
                         cout << "[parser]: Updating float value\n";
                         if(ids.updateFloat((yyvsp[-2].string), res->val.fVal, currScope) == -1){
                         yyerror("[parser]: error at updateFloat");
                         YYERROR; 
                         }
                    }
                    else if(res->type == exprType::BOOL){
                         cout << "[parser]: Updating bool value\n";
                         if(ids.updateBool((yyvsp[-2].string), res->val.bVal, currScope) == -1){
                         yyerror("[parser]: error at updateBool");
                         YYERROR; 
                         }
                    }
                    else if(res->type == exprType::CHAR){ //change this to specific rule
                         cout << "[parser]: Updating char value\n";
                         if(ids.updateChr((yyvsp[-2].string), res->val.cVal, currScope) == -1){
                              yyerror("[parser]: error at updateChr");
                              YYERROR; 
                         }
                    }
                    else if(res->type == exprType::STRING){
                         cout << "[parser]: Updating char value\n";
                         if(ids.updateStr((yyvsp[-2].string), res->val.sVal, currScope) == -1){
                              yyerror("[parser]: error at updateStr");
                              YYERROR; 
                         }
                    }
                    else{
                         cout << "[parser]: Unrecognized type at assignation\n";
                         YYERROR;
                    }
                    (yyvsp[0].node)->clean();
                    res = nullptr;
               }
#line 1447 "limbaj.tab.c"
    break;

  case 14: /* decl: CONST TYPE ID ASSIGN expression  */
#line 146 "limbaj.y"
                                            {
                    if(-1 == (ids.addVar((yyvsp[-3].string), (yyvsp[-2].string), currScope, false, true))){
                         yyerror("[parser]: addVar error");
                         YYERROR;
                    }
                    node* res = (yyvsp[0].node)->evaluate();
                    if(res == nullptr){
                         yyerror("[parser]: Error at AST::evaluate()");
                         YYERROR;
                    }

                    if(res->type == exprType::INTEGER){
                         cout << "[parser]: Updating int value\n";
                         if(ids.updateInt((yyvsp[-2].string), res->val.iVal, currScope) == -1){
                         yyerror("[parser]: error at updateInt");
                         YYERROR; 
                         }
                    }
                    else if(res->type == exprType::FLOAT){
                         cout << "[parser]: Updating float value\n";
                         if(ids.updateFloat((yyvsp[-2].string), res->val.fVal, currScope) == -1){
                         yyerror("[parser]: error at updateFloat");
                         YYERROR; 
                         }
                    }
                    else if(res->type == exprType::BOOL){
                         cout << "[parser]: Updating bool value\n";
                         if(ids.updateBool((yyvsp[-2].string), res->val.bVal, currScope) == -1){
                         yyerror("[parser]: error at updateBool");
                         YYERROR; 
                         }
                    }
                    else if(res->type == exprType::CHAR){ //change this to specific rule
                         cout << "[parser]: Updating char value\n";
                         if(ids.updateChr((yyvsp[-2].string), res->val.cVal, currScope) == -1){
                              yyerror("[parser]: error at updateChr");
                              YYERROR; 
                         }
                    }
                    else if(res->type == exprType::STRING){
                         cout << "[parser]: Updating char value\n";
                         if(ids.updateStr((yyvsp[-2].string), res->val.sVal, currScope) == -1){
                              yyerror("[parser]: error at updateStr");
                              YYERROR; 
                         }
                    }
                    else{
                         cout << "[parser]: Unrecognized type at assignation\n";
                         YYERROR;
                    }
                    (yyvsp[0].node)->clean();
                    res = nullptr;
               }
#line 1505 "limbaj.tab.c"
    break;

  case 15: /* decl: TYPE ID  */
#line 199 "limbaj.y"
                     {
                    if(-1 == (ids.addVar((yyvsp[-1].string),(yyvsp[0].string), currScope, false, false))){
                         yyerror("[parser]: addVar error ");
                         YYERROR;
                    }
               }
#line 1516 "limbaj.tab.c"
    break;

  case 16: /* decl: CONST TYPE ID  */
#line 205 "limbaj.y"
                           {
                         if(-1 == (ids.addVar((yyvsp[-1].string), (yyvsp[0].string), currScope, false, true))){
                              yyerror("[parser]: addVar error ");
                              YYERROR;
                         }
                    }
#line 1527 "limbaj.tab.c"
    break;

  case 17: /* decl: TYPE ID dimension  */
#line 211 "limbaj.y"
                              {
                    if(-1 == (ids.addVar((yyvsp[-2].string), (yyvsp[-1].string), currScope, true, false))){
                         yyerror("[parser]: addVar error ");
                         YYERROR;
                    }
                    if(ids.setArraySize((yyvsp[-1].string), dimensionContainer, currScope) == -1){
                         yyerror("[parser]: setArraySize error ");
                         YYERROR;
                    }
                    if(ids.initializeArray((yyvsp[-1].string), currScope) == -1){
                         yyerror("[parser]: initializeArray error ");
                         YYERROR;
                    }
                    dimensionContainer.clear();
                    }
#line 1547 "limbaj.tab.c"
    break;

  case 18: /* assignation: ID ASSIGN expression  */
#line 228 "limbaj.y"
                                 {
                    node* res = (yyvsp[0].node)->evaluate();
                    if(res == nullptr){
                         cout << "[parser]: Error assign at assignation AST::evaluate()\n";
                         YYERROR;
                    }
                    IdInfo*id = ids.getVar((yyvsp[-2].string), currScope);
                    if(id == nullptr){
                         yyerror("[parser]: error at retrieving assignation id");
                         YYERROR;
                    }
                    if(id->isConst == true){
                         yyerror("[parser]: error at assignation - variable is declared as constant");
                         YYERROR;
                    }
                    if((res->type == exprType::INTEGER) && (id->type == "int")){
                         cout << "[parser]: Updating int value\n";
                         if(ids.updateInt((yyvsp[-2].string), res->val.iVal, currScope) == -1){
                             yyerror("[parser]: error at updateInt");
                             YYERROR; 
                         }
                    }
                    else if((res->type == exprType::FLOAT) && (id->type == "float")){
                         cout << "[parser]: Updating float value\n";
                         if(ids.updateFloat((yyvsp[-2].string), res->val.fVal, currScope) == -1){
                             yyerror("[parser]: error at updateFloat");
                             YYERROR; 
                         }
                    }
                    else if((res->type == exprType::BOOL) && (id->type == "bool")){
                         cout << "[parser]: Updating bool value\n";
                         if(ids.updateBool((yyvsp[-2].string), res->val.bVal, currScope) == -1){
                             yyerror("[parser]: error at updateBool");
                             YYERROR; 
                         }
                    }
                    else if((res->type == exprType::CHAR) && (id->type == "char")){
                         cout << "[parser]: Updating char value\n";
                         // ids.updateChr($1, currScope, res->val.cVal);
                         if(ids.updateChr((yyvsp[-2].string), res->val.cVal, currScope) == -1){
                              yyerror("[parser]: error at updateChr");
                              YYERROR; 
                         }
                    }
                    else if((res->type == exprType::STRING) && (id->type == "string")){
                         cout << "[parser]: Updating char value\n";
                         // ids.updateChr($1, currScope, res->val.cVal);
                         if(ids.updateStr((yyvsp[-2].string), res->val.sVal, currScope) == -1){
                              yyerror("[parser]: error at updateStr");
                              YYERROR; 
                         }
                    }
                    else{
                         yyerror("[ID ASSIGN EXPRESSION]: Unrecognized or incorrect type at assignation");
                         YYERROR; 
                    }
               }
#line 1609 "limbaj.tab.c"
    break;

  case 19: /* assignation: ID dimension ASSIGN array_value  */
#line 299 "limbaj.y"
                                              {
                    if(ids.updateArrayValue((yyvsp[-3].string), currScope, dimensionContainer, temp) == -1){
                         yyerror("[parser]: Error at array assignation ");
                         YYERROR;
                    }
                    dimensionContainer.clear();
               }
#line 1621 "limbaj.tab.c"
    break;

  case 20: /* $@1: %empty  */
#line 307 "limbaj.y"
                        {incrementScope(); flag_func=1;}
#line 1627 "limbaj.tab.c"
    break;

  case 21: /* func_decl: TYPE ID '(' $@1 list_param ')' OPENBRK f_declarations RETURN ret ';' CLOSEDBRK  */
#line 307 "limbaj.y"
                                                                                                                        {
     if (!functions.existsFunc((yyvsp[-10].string), (yyvsp[-11].string), params)) {
          if (ret_val.type != (yyvsp[-11].string)) {
               cout << "[parser]: Return type mismatch\n";
               YYERROR;
          } else {
               functions.addFunc((yyvsp[-11].string), (yyvsp[-10].string), params);
          }
     } else {
          cout << "[parser]: Function already exists\n";
          YYERROR;
     }
     params.clear();
     decrementScope();
     flag_func=0;
}
#line 1648 "limbaj.tab.c"
    break;

  case 22: /* $@2: %empty  */
#line 323 "limbaj.y"
                           {incrementScope();flag_func=1;}
#line 1654 "limbaj.tab.c"
    break;

  case 23: /* func_decl: TYPE ID '(' ')' OPENBRK $@2 f_declarations RETURN ret ';' CLOSEDBRK  */
#line 323 "limbaj.y"
                                                                                                   {             
     if (!functions.existsFunc((yyvsp[-9].string), (yyvsp[-10].string), params)) {
          if (ret_val.type != (yyvsp[-10].string)) {
               cout << "[parser]: Return type mismatch\n";
               YYERROR;
          } else {
               functions.addFunc((yyvsp[-10].string), (yyvsp[-9].string), params);
          }
     } else {
          cout << "[parser]: Function already exists\n";
          YYERROR;
     }
     params.clear();
     decrementScope();
     flag_func=0;
     }
#line 1675 "limbaj.tab.c"
    break;

  case 24: /* $@3: %empty  */
#line 339 "limbaj.y"
              {incrementScope();flag_func=1;}
#line 1681 "limbaj.tab.c"
    break;

  case 25: /* $@4: %empty  */
#line 339 "limbaj.y"
                                                                                    {decrementScope();}
#line 1687 "limbaj.tab.c"
    break;

  case 26: /* func_decl: VOID ID '(' $@3 list_param ')' OPENBRK f_declarations $@4 CLOSEDBRK  */
#line 339 "limbaj.y"
                                                                                                                 {
       
     if (!functions.existsFunc((yyvsp[-8].string), "void", params)) {
          functions.addFunc("void", (yyvsp[-8].string), params);
          }
          else{
               cout<< "[parser]: Function already exists\n";
               YYERROR;
          }
          params.clear();
          flag_func=0;
     }
#line 1704 "limbaj.tab.c"
    break;

  case 27: /* $@5: %empty  */
#line 351 "limbaj.y"
                         {incrementScope();flag_func=1;}
#line 1710 "limbaj.tab.c"
    break;

  case 28: /* $@6: %empty  */
#line 351 "limbaj.y"
                                                                        {decrementScope();}
#line 1716 "limbaj.tab.c"
    break;

  case 29: /* func_decl: VOID ID '(' ')' OPENBRK $@5 f_declarations $@6 CLOSEDBRK  */
#line 351 "limbaj.y"
                                                                                                      {
          if (!functions.existsFunc((yyvsp[-7].string), "void", params)) {
               functions.addFunc("void", (yyvsp[-7].string), params);
          }
          else{
               cout<< "[parser]: Function already exists\n";
               YYERROR;
          }
          flag_func=0;
          params.clear();
          
     }
#line 1733 "limbaj.tab.c"
    break;

  case 30: /* ret: ID  */
#line 364 "limbaj.y"
        {if(ids.existsVar((yyvsp[0].string))){ret_val.type = ids.getVar((yyvsp[0].string), currScope)->type; ret_val.name = (yyvsp[0].string); ret_val.scopeId = currScope;}else{yyerror("[parser]: Error at ret - id not found"); YYERROR;}}
#line 1739 "limbaj.tab.c"
    break;

  case 31: /* ret: NR  */
#line 365 "limbaj.y"
          {ret_val.type = "int"; ret_val.value.iVal = (yyvsp[0].integer_value);}
#line 1745 "limbaj.tab.c"
    break;

  case 32: /* ret: FLT  */
#line 366 "limbaj.y"
           {ret_val.type = "float"; ret_val.value.fVal = (yyvsp[0].float_value);}
#line 1751 "limbaj.tab.c"
    break;

  case 33: /* ret: BOO  */
#line 367 "limbaj.y"
           {ret_val.type = "bool"; ret_val.value.bVal = (yyvsp[0].bool_value);}
#line 1757 "limbaj.tab.c"
    break;

  case 34: /* ret: CHR  */
#line 368 "limbaj.y"
           {ret_val.type = "char"; ret_val.value.cVal = (yyvsp[0].char_value);}
#line 1763 "limbaj.tab.c"
    break;

  case 35: /* ret: STR  */
#line 369 "limbaj.y"
           {ret_val.type = "string"; ret_val.value.sVal = strdup((yyvsp[0].string));}
#line 1769 "limbaj.tab.c"
    break;

  case 49: /* $@7: %empty  */
#line 391 "limbaj.y"
                                           {incrementScope();}
#line 1775 "limbaj.tab.c"
    break;

  case 50: /* $@8: %empty  */
#line 391 "limbaj.y"
                                                                                     {decrementScope();}
#line 1781 "limbaj.tab.c"
    break;

  case 51: /* if_statement: IF '(' expression ')' OPENBRK $@7 declarations CLOSEDBRK $@8  */
#line 391 "limbaj.y"
                                                                                                         {
                         node* res = (yyvsp[-6].node)->evaluate();
                         cout << "[if expr] : if working yay\n";
                         if(res == nullptr){
                              cout << "[parser]: Error at if statement condition evaluate\n";
                              YYERROR;
                         }

                         if(res->type != exprType::BOOL){
                              yyerror("[if expr]: condition does not have bool type ");
                              YYERROR;
                         }
                    }
#line 1799 "limbaj.tab.c"
    break;

  case 52: /* $@9: %empty  */
#line 405 "limbaj.y"
                             {incrementScope();}
#line 1805 "limbaj.tab.c"
    break;

  case 53: /* $@10: %empty  */
#line 405 "limbaj.y"
                                                                       {decrementScope();}
#line 1811 "limbaj.tab.c"
    break;

  case 54: /* else_statement: ELSE OPENBRK $@9 declarations CLOSEDBRK $@10  */
#line 405 "limbaj.y"
                                                                                           {
                         cout << "[else expr] : else working yay\n";
                    }
#line 1819 "limbaj.tab.c"
    break;

  case 55: /* $@11: %empty  */
#line 408 "limbaj.y"
                     {cout << "[if else expr] : if else working yay\n";}
#line 1825 "limbaj.tab.c"
    break;

  case 57: /* $@12: %empty  */
#line 411 "limbaj.y"
                                                  {incrementScope();}
#line 1831 "limbaj.tab.c"
    break;

  case 58: /* $@13: %empty  */
#line 411 "limbaj.y"
                                                                                            {decrementScope();}
#line 1837 "limbaj.tab.c"
    break;

  case 59: /* while_statement: WHILE '(' expression ')' OPENBRK $@12 declarations CLOSEDBRK $@13  */
#line 411 "limbaj.y"
                                                                                                                {
                    node* res = (yyvsp[-6].node)->evaluate();
                    cout << "[while expr] : while working yay\n";
                    if(res == nullptr){
                         cout << "[parser]: Error at while statement condition evaluate\n";
                         YYERROR;
                    }

                    if(res->type != exprType::BOOL){
                         yyerror("[while expr]: condition does not have bool type\n");
                         YYERROR;
                    }
                }
#line 1855 "limbaj.tab.c"
    break;

  case 60: /* $@14: %empty  */
#line 426 "limbaj.y"
                   {incrementScope();}
#line 1861 "limbaj.tab.c"
    break;

  case 61: /* $@15: %empty  */
#line 426 "limbaj.y"
                                                                                                                   {decrementScope();}
#line 1867 "limbaj.tab.c"
    break;

  case 62: /* for_statement: FOR $@14 '(' for_init ';' expression ';' for_step ')' OPENBRK declarations CLOSEDBRK $@15  */
#line 426 "limbaj.y"
                                                                                                                                       {
                    node* res = (yyvsp[-7].node)->evaluate();
                    cout << "[for expr] : for working yay\n";
                    if(res == nullptr){
                         cout << "[parser]: Error at for statement condition evaluate\n";
                         YYERROR;
                    }
                    
                    if(res->type != exprType::BOOL){
                         yyerror("[for expr]: condition does not have bool type\n");
                         YYERROR;
                    }
               }
#line 1885 "limbaj.tab.c"
    break;

  case 67: /* expression: expression "+" expression  */
#line 449 "limbaj.y"
                                     {
                    (yyval.node) = new node(opType::ADD, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 1893 "limbaj.tab.c"
    break;

  case 68: /* expression: expression "-" expression  */
#line 452 "limbaj.y"
                                          {
                    (yyval.node) = new node(opType::SUB, (yyvsp[-2].node), (yyvsp[0].node));
                    }
#line 1901 "limbaj.tab.c"
    break;

  case 69: /* expression: expression "*" expression  */
#line 455 "limbaj.y"
                                          {
                    (yyval.node) = new node(opType::MUL, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 1909 "limbaj.tab.c"
    break;

  case 70: /* expression: expression "/" expression  */
#line 458 "limbaj.y"
                                          {
                    (yyval.node) = new node(opType::DIV, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 1917 "limbaj.tab.c"
    break;

  case 71: /* expression: expression "<" expression  */
#line 461 "limbaj.y"
                                          {
                    (yyval.node) = new node(opType::LE, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 1925 "limbaj.tab.c"
    break;

  case 72: /* expression: expression ">" expression  */
#line 464 "limbaj.y"
                                          {
                    (yyval.node) = new node(opType::GE, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 1933 "limbaj.tab.c"
    break;

  case 73: /* expression: expression "<=" expression  */
#line 467 "limbaj.y"
                                           {
                    (yyval.node) = new node(opType::LEQ, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 1941 "limbaj.tab.c"
    break;

  case 74: /* expression: expression ">=" expression  */
#line 470 "limbaj.y"
                                           {
                    (yyval.node) = new node(opType::GEQ, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 1949 "limbaj.tab.c"
    break;

  case 75: /* expression: expression "==" expression  */
#line 473 "limbaj.y"
                                           {
                    (yyval.node) = new node(opType::EQU, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 1957 "limbaj.tab.c"
    break;

  case 76: /* expression: expression "!=" expression  */
#line 476 "limbaj.y"
                                           {
                    (yyval.node) = new node(opType::NEQ, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 1965 "limbaj.tab.c"
    break;

  case 77: /* expression: "!" expression  */
#line 479 "limbaj.y"
                               {
                    (yyval.node) = new node(opType::NOT, (yyvsp[0].node), nullptr);
               }
#line 1973 "limbaj.tab.c"
    break;

  case 78: /* expression: '(' expression ')'  */
#line 482 "limbaj.y"
                                   {
                    (yyval.node) = (yyvsp[-1].node);
               }
#line 1981 "limbaj.tab.c"
    break;

  case 79: /* expression: "-" expression  */
#line 485 "limbaj.y"
                                            {
                    (yyval.node) = new node(opType::UMIN, (yyvsp[0].node), nullptr);
               }
#line 1989 "limbaj.tab.c"
    break;

  case 80: /* expression: NR  */
#line 488 "limbaj.y"
                   {
                    (yyval.node) = new node((yyvsp[0].integer_value));    
               }
#line 1997 "limbaj.tab.c"
    break;

  case 81: /* expression: FLT  */
#line 491 "limbaj.y"
                    {     
                    (yyval.node) = new node((yyvsp[0].float_value));
               }
#line 2005 "limbaj.tab.c"
    break;

  case 82: /* expression: BOO  */
#line 494 "limbaj.y"
                    {     
                    (yyval.node) = new node((yyvsp[0].bool_value));
               }
#line 2013 "limbaj.tab.c"
    break;

  case 83: /* expression: CHR  */
#line 497 "limbaj.y"
                    {     
                    (yyval.node) = new node((yyvsp[0].char_value));
               }
#line 2021 "limbaj.tab.c"
    break;

  case 84: /* expression: STR  */
#line 500 "limbaj.y"
                    {     
                    (yyval.node) = new node((yyvsp[0].string));
               }
#line 2029 "limbaj.tab.c"
    break;

  case 85: /* expression: ID  */
#line 503 "limbaj.y"
                   {
                    IdInfo*id = ids.getVar((yyvsp[0].string), currScope);
                    if(id == nullptr){
                         yyerror("[parser]: Error at getVar - id not found");
                         YYERROR;
                    }
                    if(id->type == string("int")){
                         cout << "[parser]: Found int variable in expr - generating node\n";

                         if(flag_func==0){
                              (yyval.node) = new node(id->value.iVal); //?crapa
                         }else{
                              int node_val = 0;
                              (yyval.node) = new node(node_val);
                         }

                    }else if(id->type == string("float")){
                         cout << "[parser]: Found float variable in expr - generating node\n";
                         
                         if(flag_func==0){
                              (yyval.node) = new node(id->value.fVal);
                         }else{
                              float node_val = 0;
                              (yyval.node) = new node(node_val);
                         }
                    }
                    else if(id->type == string("bool")){
                         cout << "[parser]: Found bool variable in expr - generating node\n";
                        
                         if(flag_func==0){
                              (yyval.node) = new node(id->value.bVal);
                         }else{
                              bool node_val = false;
                              (yyval.node) = new node(node_val);
                         }
                    }
                    else if(id->type == string("char")){
                         cout << "[parser]: Found char variable in expr - generating node\n";
                         
                         if(flag_func==0){
                              (yyval.node) = new node(id->value.cVal);
                         }else{
                              char node_val = '\0';
                              (yyval.node) = new node(node_val);
                         }
                    }
                    else if(id->type == string("string")){
                         cout << "[parser]: Found string variable in expr - generating node\n";
                        
                         if(flag_func==0){
                              (yyval.node) = new node(id->value.sVal);
                         }else{
                              char* node_val = NULL;
                              (yyval.node) = new node(node_val);
                         }
                    }
                    else{
                         cout << "[parser]: ERROR - INVALID TYPE IN EXPR FOR " << (yyvsp[0].string) << endl;
                    }
               }
#line 2094 "limbaj.tab.c"
    break;

  case 86: /* expression: ID '[' NR ']'  */
#line 563 "limbaj.y"
                               {
                         IdInfo*id = ids.getUArrElemByIndex((yyvsp[-3].string), currScope, (yyvsp[-1].integer_value));
                         if(id == nullptr){
                              yyerror("[parser]: Error at getUArrElemByIndex - element not found");
                              YYERROR;
                         }
                         //dimensionContainer.clear();
                         if(id->type == string("int")){
                              cout << "[parser]: Found int variable in expr - generating node\n";
                              
                              if(flag_func==0){
                                   (yyval.node) = new node(id->value.iVal);
                              }else{
                                   int node_val = 0;
                                   (yyval.node) = new node(node_val);
                              }
                         }else if(id->type == string("float")){
                              cout << "[parser]: Found float variable in expr - generating node\n";
                              
                              if(flag_func==0){
                                   (yyval.node) = new node(id->value.fVal);
                              }else{
                                   float node_val = 0;
                                   (yyval.node) = new node(node_val);
                              }
                         }
                         else if(id->type == string("bool")){
                              cout << "[parser]: Found bool variable in expr - generating node\n";
                              
                              if(flag_func==0){
                                   (yyval.node) = new node(id->value.bVal);
                              }else{
                                   bool node_val = false;
                                   (yyval.node) = new node(node_val);
                              }
                         }
                         else if(id->type == string("char")){
                              cout << "[parser]: Found char variable in expr - generating node\n";
                              
                              if(flag_func==0){
                                   (yyval.node) = new node(id->value.cVal);
                              }else{
                                   char node_val = '\0';
                                   (yyval.node) = new node(node_val);
                              }
                         }
                         else if(id->type == string("string")){
                              cout << "[parser]: Found string variable in expr - generating node\n";
                              
                              if(flag_func==0){
                                   (yyval.node) = new node(id->value.sVal);
                              }else{
                                   char* node_val = NULL;
                                   (yyval.node) = new node(node_val);
                              }

                         }
                         else{
                              cout << "[parser]: ERROR - INVALID TYPE IN EXPR FOR " << (yyvsp[-3].string) << endl;
                              YYERROR;
                         }
                    }
#line 2161 "limbaj.tab.c"
    break;

  case 87: /* expression: ID '[' NR ']' '[' NR ']'  */
#line 625 "limbaj.y"
                                         {
                    IdInfo*id = ids.getMArrElemByIndex((yyvsp[-6].string), currScope, (yyvsp[-4].integer_value), (yyvsp[-1].integer_value));
                    if(id == nullptr){
                         yyerror("[parser]: Error at getMArrElemByIndex - element not found");
                         YYERROR;
                    }
                    //dimensionContainer.clear();
                    if(id->type == string("int")){
                         cout << "[parser]: Found int variable in expr - generating node\n";
                              
                         if(flag_func==0){
                              (yyval.node) = new node(id->value.iVal);
                         }else{
                              int node_val = 0;
                              (yyval.node) = new node(node_val);
                         }
                    }else if(id->type == string("float")){
                         cout << "[parser]: Found float variable in expr - generating node\n";
                         
                         if(flag_func==0){
                              (yyval.node) = new node(id->value.fVal);
                         }else{
                              float node_val = 0;
                              (yyval.node) = new node(node_val);
                         }
                    }
                    else if(id->type == string("bool")){
                         cout << "[parser]: Found bool variable in expr - generating node\n";
                         
                         if(flag_func==0){
                              (yyval.node) = new node(id->value.bVal);
                         }else{
                              bool node_val = false;
                              (yyval.node) = new node(node_val);
                         }
                    }
                    else if(id->type == string("char")){
                         cout << "[parser]: Found char variable in expr - generating node\n";
                         
                         if(flag_func==0){
                              (yyval.node) = new node(id->value.cVal);
                         }else{
                              char node_val = '\0';
                              (yyval.node) = new node(node_val);
                         }
                    }
                    else if(id->type == string("string")){
                         cout << "[parser]: Found string variable in expr - generating node\n";
                         
                         if(flag_func==0){
                              (yyval.node) = new node(id->value.sVal);
                         }else{
                              char* node_val = NULL;
                              (yyval.node) = new node(node_val);
                         }
                    }
                    else{
                         cout << "[parser]: ERROR - INVALID TYPE IN EXPR FOR " << (yyvsp[-6].string) << endl;
                         YYERROR;
                    }
               }
#line 2227 "limbaj.tab.c"
    break;

  case 88: /* expression: ID '(' call_list ')'  */
#line 686 "limbaj.y"
                                     {
                         if(!functions.existsFuncCall((yyvsp[-3].string), params)){
                              yyerror("[parser]: Function does not exist\n");
                              YYERROR;
                         }
                         Function* func = new Function;
                         func = functions.getFunc((yyvsp[-3].string), params);
                         if(func == nullptr){
                              yyerror("[parser]: Error at getFunc - function not found in function table\n");
                              YYERROR;
                         }
                         if(func->type == string("int")){
                              cout << "[parser]: expr functions has type int\n";
                              int node_val = 0;
                              (yyval.node) = new node(node_val);
                         }
                         else if(func->type == string("float")){
                              cout << "[parser]: expr functions has type float\n";
                              float node_val = 0;
                              (yyval.node) = new node(node_val);
                         }
                         else if(func->type == string("bool")){
                              cout << "[parser]: expr functions has type bool\n";
                              bool node_val = false;
                              (yyval.node) = new node(node_val);
                         }else{
                              yyerror("[parser]: prohibited function value used in expression\n");
                              YYERROR;
                         }
                         //free aici?
                         params.clear();
                         }
#line 2264 "limbaj.tab.c"
    break;

  case 89: /* expression: ID '(' ')'  */
#line 718 "limbaj.y"
                             {
                         if(!functions.existsFuncCall((yyvsp[-2].string), params)){
                              yyerror("[parser]: Function does not exist\n");
                              YYERROR;
                         }
                         Function* func = new Function;
                         func = functions.getFunc((yyvsp[-2].string), params);
                         if(func == nullptr){
                              yyerror("[parser]: Error at getFunc - function not found in function table\n");
                              YYERROR;
                         }
                         if(func->type == string("int")){
                              cout << "[parser]: expr functions has type int\n";
                              int node_val = 0;
                              (yyval.node) = new node(node_val);
                         }
                         else if(func->type == string("float")){
                              cout << "[parser]: expr functions has type float\n";
                              float node_val = 0;
                              (yyval.node) = new node(node_val);
                         }
                         else if(func->type == string("bool")){
                              cout << "[parser]: expr functions has type bool\n";
                              bool node_val = false;
                              (yyval.node) = new node(node_val);
                         }else{
                              yyerror("[parser]: prohibited function value used in expression\n");
                              YYERROR;
                         }
                         params.clear();
                         }
#line 2300 "limbaj.tab.c"
    break;

  case 90: /* dimension: '[' NR ']' dimension  */
#line 751 "limbaj.y"
                                 {
                    dimensionContainer.push_back((yyvsp[-2].integer_value));
                    }
#line 2308 "limbaj.tab.c"
    break;

  case 91: /* dimension: '[' NR ']'  */
#line 754 "limbaj.y"
                       {
                    dimensionContainer.push_back((yyvsp[-1].integer_value));
                    }
#line 2316 "limbaj.tab.c"
    break;

  case 92: /* array_value: expression  */
#line 759 "limbaj.y"
                        {
          cout << "[parser]: Arr val is expr\n";
          node* res = (yyvsp[0].node)->evaluate();
          if(res == nullptr){
               yyerror("[parser]: Error at array_value evaluate ");
               YYERROR;
          }

          if(res->type == exprType::INTEGER){
               cout << "[parser]: Updating array int value " << res->val.iVal << endl;
               temp -> type = string("int");
               temp -> name = string("");
               temp -> value.iVal = res->val.iVal;
               temp -> isArr = false;
               temp-> scopeId = currScope;
          }
          else if(res->type == exprType::FLOAT){
               cout << "[parser]: Updating float value\n";
               temp -> type = string("float");
               temp -> name = string("");
               temp -> value.fVal = res->val.fVal;
               temp -> isArr = false;
               temp-> scopeId = currScope;
          }
          else if(res->type == exprType::BOOL){
               cout << "[parser]: Updating bool value\n";
               temp -> type = string("bool");
               temp -> name = string("");
               temp -> value.bVal = res->val.bVal;
               temp -> isArr = false;
               temp-> scopeId = currScope;
          }
          else if(res->type == exprType::CHAR){
               cout << "[parser]: Updating char value\n";
               temp -> type = string("char");
               temp -> name = string("");
               temp -> value.cVal = res->val.cVal;
               temp -> isArr = false;
               temp-> scopeId = currScope;
          }
          else if(res->type == exprType::STRING){
               cout << "[parser]: Updating string value\n";
               temp -> type = string("string");
               temp -> name = string("");
               temp -> value.sVal = strdup(res->val.sVal); //strdup? this may cause issues
               temp -> isArr = false;
               temp-> scopeId = currScope;
          }
          else{
               cout << "[parser]: Unrecognized type at assignation\n";
               YYERROR; //define
          }
          (yyvsp[0].node)->clean();
          res = nullptr;
          
          }
#line 2377 "limbaj.tab.c"
    break;

  case 95: /* param: TYPE ID  */
#line 839 "limbaj.y"
               { ids.addVar((yyvsp[-1].string),(yyvsp[0].string),currScope,false,false); IdInfo arg; arg.type=string((yyvsp[-1].string)); arg.name=string((yyvsp[0].string)); arg.scopeId=currScope; params.push_back(arg);}
#line 2383 "limbaj.tab.c"
    break;

  case 105: /* call_function: ID '(' call_list ')'  */
#line 858 "limbaj.y"
                                     {if(!functions.existsFuncCall((yyvsp[-3].string), params)){
                              yyerror("[parser]: Function does not exist\n");
                              YYERROR;
                         }
                         params.clear();
                         }
#line 2394 "limbaj.tab.c"
    break;

  case 106: /* call_function: ID '(' ')'  */
#line 864 "limbaj.y"
                             {if(!functions.existsFuncCall((yyvsp[-2].string), params)){
                              yyerror("[parser]: Function does not exist\n");
                              YYERROR;
                         }
                         params.clear();
                         }
#line 2405 "limbaj.tab.c"
    break;

  case 107: /* eval_stmt: EVAL '(' expression ')'  */
#line 871 "limbaj.y"
                                    {
     if(flag_func==0){   
          node* res = (yyvsp[-1].node)->evaluate();
          if(res == nullptr){
               yyerror("[parser]: Error at Eval AST::evaluate()");
               YYERROR;
          }
          switch(res->type){
               case exprType::INTEGER:{
                    cout << "[Eval]: expression has type INTEGER and value " << res->val.iVal << endl;
                    break;
               }
               case exprType::FLOAT:{
                    cout << "[Eval]: expression has type FLOAT and value " << res->val.fVal << endl;
                    break;
               }
               case exprType::BOOL:{
                    cout << "[Eval]: expression has type BOOL and value " << boolalpha << res->val.bVal << noboolalpha << endl;
                    break;
               }
               case exprType::CHAR:{
                    cout << "[Eval]: expression has type CHAR and value " << res->val.cVal << endl;
                    break;
               }
               case exprType::STRING:{
                    cout << "[Eval]: expression has type STRING and value " << res->val.sVal << endl;
                    break;
               }
          }
     }
}
#line 2441 "limbaj.tab.c"
    break;

  case 108: /* typeOf_stmt: TOF '(' expression ')'  */
#line 902 "limbaj.y"
                                   {
     if(flag_func==0){
          node* res = (yyvsp[-1].node)->evaluate();
          if(res == nullptr){
               yyerror("[parser]: Error at TypeOf AST::evaluate()");
               YYERROR;
          }
          switch(res->type){
               case exprType::INTEGER:{
                    cout << "[typeOF]: expression has type INTEGER\n";
                    break;
               }
               case exprType::FLOAT:{
                    cout << "[typeOF]: expression has type FLOAT\n";
                    break;
               }
               case exprType::BOOL:{
                    cout << "[typeOF]: expression has type BOOL\n";
                    break;
               }
               case exprType::CHAR:{
                    cout << "[typeOF]: expression has type CHAR\n";
                    break;
               }
               case exprType::STRING:{
                    cout << "[typeOF]: expression has type STRING\n";
                    break;
               }
          }
     }
}
#line 2477 "limbaj.tab.c"
    break;

  case 109: /* call_list: NR  */
#line 933 "limbaj.y"
               {IdInfo arg; arg.type=string("int"); arg.name=string(""); arg.value.iVal=(yyvsp[0].integer_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2483 "limbaj.tab.c"
    break;

  case 110: /* call_list: call_list ',' NR  */
#line 934 "limbaj.y"
                              {IdInfo arg; arg.type=string("int"); arg.name=string(""); arg.value.iVal=(yyvsp[0].integer_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2489 "limbaj.tab.c"
    break;

  case 111: /* call_list: FLT  */
#line 935 "limbaj.y"
                 {IdInfo arg; arg.type=string("float"); arg.name=string(""); arg.value.fVal=(yyvsp[0].float_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2495 "limbaj.tab.c"
    break;

  case 112: /* call_list: call_list ',' FLT  */
#line 936 "limbaj.y"
                               {IdInfo arg; arg.type=string("float"); arg.name=string(""); arg.value.fVal=(yyvsp[0].float_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2501 "limbaj.tab.c"
    break;

  case 113: /* call_list: BOO  */
#line 937 "limbaj.y"
                 {IdInfo arg; arg.type=string("bool"); arg.name=string(""); arg.value.bVal=(yyvsp[0].bool_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2507 "limbaj.tab.c"
    break;

  case 114: /* call_list: call_list ',' BOO  */
#line 938 "limbaj.y"
                               {IdInfo arg; arg.type=string("bool"); arg.name=string(""); arg.value.bVal=(yyvsp[0].bool_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2513 "limbaj.tab.c"
    break;

  case 115: /* call_list: CHR  */
#line 939 "limbaj.y"
                 {IdInfo arg; arg.type=string("char"); arg.name=string(""); arg.value.cVal=(yyvsp[0].char_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2519 "limbaj.tab.c"
    break;

  case 116: /* call_list: call_list ',' CHR  */
#line 940 "limbaj.y"
                               {IdInfo arg; arg.type=string("char"); arg.name=string(""); arg.value.cVal=(yyvsp[0].char_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2525 "limbaj.tab.c"
    break;

  case 117: /* call_list: STR  */
#line 941 "limbaj.y"
                 {IdInfo arg; arg.type=string("string"); arg.name=string(""); arg.value.sVal=strdup((yyvsp[0].string)); arg.scopeId=currScope; params.push_back(arg);}
#line 2531 "limbaj.tab.c"
    break;

  case 118: /* call_list: call_list ',' STR  */
#line 942 "limbaj.y"
                               {IdInfo arg; arg.type=string("string"); arg.name=string(""); arg.value.sVal=strdup((yyvsp[0].string)); arg.scopeId=currScope; params.push_back(arg);}
#line 2537 "limbaj.tab.c"
    break;

  case 119: /* call_list: ID  */
#line 943 "limbaj.y"
                {IdInfo*id = ids.getVar((yyvsp[0].string), currScope);
                         if(id == nullptr){
                              yyerror("[parser]: Error at getVar - id not found");
                              YYERROR;
                         }
                         if(id->type == string("int")){
                              IdInfo arg; arg.type=string("int"); arg.name=string(""); arg.value.iVal=id->value.iVal; arg.scopeId=currScope; params.push_back(arg);
                         }else if(id->type == string("float")){
                              IdInfo arg; arg.type=string("float"); arg.name=string(""); arg.value.fVal=id->value.fVal; arg.scopeId=currScope; params.push_back(arg);
                         }
                         else if(id->type == string("bool")){
                              IdInfo arg; arg.type=string("bool"); arg.name=string(""); arg.value.bVal=id->value.bVal; arg.scopeId=currScope; params.push_back(arg);
                         }
                         else if(id->type == string("char")){
                              IdInfo arg; arg.type=string("char"); arg.name=string(""); arg.value.cVal=id->value.cVal; arg.scopeId=currScope; params.push_back(arg);
                         }
                         else if(id->type == string("string")){
                              IdInfo arg; arg.type=string("string"); arg.name=string(""); arg.value.sVal=strdup(id->value.sVal); arg.scopeId=currScope; params.push_back(arg);
                         }
                         else{
                              cout << "[parser]: ERROR - INVALID TYPE IN CALL LIST FOR " << (yyvsp[0].string) << endl;
                              YYERROR;
                         }
               }
#line 2566 "limbaj.tab.c"
    break;

  case 120: /* call_list: call_list ',' ID  */
#line 967 "limbaj.y"
                             {IdInfo*id = ids.getVar((yyvsp[0].string), currScope);
                         if(id == nullptr){
                              yyerror("[parser]: Error at getVar - id not found");
                              YYERROR;
                         }
                         if(id->type == string("int")){
                              IdInfo arg; arg.type=string("int"); arg.name=string(""); arg.value.iVal=id->value.iVal; arg.scopeId=currScope; params.push_back(arg);
                         }else if(id->type == string("float")){
                              IdInfo arg; arg.type=string("float"); arg.name=string(""); arg.value.fVal=id->value.fVal; arg.scopeId=currScope; params.push_back(arg);
                         }
                         else if(id->type == string("bool")){
                              IdInfo arg; arg.type=string("bool"); arg.name=string(""); arg.value.bVal=id->value.bVal; arg.scopeId=currScope; params.push_back(arg);
                         }
                         else if(id->type == string("char")){
                              IdInfo arg; arg.type=string("char"); arg.name=string(""); arg.value.cVal=id->value.cVal; arg.scopeId=currScope; params.push_back(arg);
                         }
                         else if(id->type == string("string")){
                              IdInfo arg; arg.type=string("string"); arg.name=string(""); arg.value.sVal=strdup(id->value.sVal); arg.scopeId=currScope; params.push_back(arg);
                         }
                         else{
                              cout << "[parser]: ERROR - INVALID TYPE IN CALL LIST FOR " << (yyvsp[0].string) << endl;
                              YYERROR;
                         }}
#line 2594 "limbaj.tab.c"
    break;


#line 2598 "limbaj.tab.c"

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

#line 1160 "limbaj.y"

void yyerror(const char * s){
printf("-ERROR-: %s at line:%d\n",s,yylineno);
}

int main(int argc, char** argv){
     scopes.push(currScope);
     ids.scope_path.push_back(currScope);
     ids.log_flag = atoi(argv[2]);
     yyin=fopen(argv[1],"r");
     yyparse();
     cout << "Variables:" <<endl;
     ids.printVars();
     cout<<"Functions:"<<endl;
     functions.printFuncs();
     delete temp;
} 
