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
  YYSYMBOL_call_list = 86,                 /* call_list  */
  YYSYMBOL_class_decl = 87,                /* class_decl  */
  YYSYMBOL_in_class_decl = 88,             /* in_class_decl  */
  YYSYMBOL_var_class_decl = 89,            /* var_class_decl  */
  YYSYMBOL_objects = 90,                   /* objects  */
  YYSYMBOL_methods = 91,                   /* methods  */
  YYSYMBOL_92_16 = 92,                     /* $@16  */
  YYSYMBOL_93_17 = 93,                     /* $@17  */
  YYSYMBOL_94_18 = 94,                     /* $@18  */
  YYSYMBOL_95_19 = 95,                     /* $@19  */
  YYSYMBOL_96_20 = 96,                     /* $@20  */
  YYSYMBOL_97_21 = 97                      /* $@21  */
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
typedef yytype_int16 yy_state_t;

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
#define YYLAST   549

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  295

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
      88,    89,    90,    91,    92,    93,    94,    96,   150,   203,
     209,   215,   232,   303,   311,   311,   330,   330,   352,   352,
     352,   364,   364,   364,   377,   378,   379,   380,   381,   382,
     384,   385,   386,   387,   388,   389,   390,   391,   394,   395,
     396,   399,   400,   404,   404,   404,   418,   418,   418,   421,
     421,   424,   424,   424,   439,   439,   439,   454,   455,   458,
     459,   462,   465,   468,   471,   474,   477,   480,   483,   486,
     489,   492,   495,   498,   501,   504,   507,   510,   513,   516,
     576,   638,   699,   731,   764,   767,   772,   848,   849,   852,
     856,   860,   861,   864,   865,   866,   867,   868,   869,   871,
     877,   884,   915,   946,   947,   948,   949,   950,   951,   952,
     953,   954,   955,   956,   980,  1004,  1016,  1029,  1030,  1033,
    1052,  1071,  1099,  1100,  1103,  1116,  1116,  1139,  1139,  1161,
    1161,  1161,  1181,  1181,  1181
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
  "statement", "call_function", "eval_stmt", "typeOf_stmt", "call_list",
  "class_decl", "in_class_decl", "var_class_decl", "objects", "methods",
  "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-208)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     338,   -15,   -14,  -208,    14,     9,    20,    25,    -1,    33,
      41,   153,    34,    36,  -208,  -208,  -208,    68,  -208,  -208,
      43,  -208,    51,   119,   119,    54,    89,    71,   105,    93,
     119,     8,    95,   118,    15,  -208,   480,    88,   101,  -208,
    -208,  -208,   109,  -208,   110,  -208,  -208,   125,  -208,  -208,
    -208,    -4,  -208,  -208,  -208,  -208,  -208,   119,   119,   119,
     262,   311,     3,   146,   113,   162,  -208,   513,  -208,  -208,
    -208,  -208,  -208,  -208,  -208,   -30,   115,   119,   119,   120,
    -208,   123,   127,   140,   129,   130,  -208,    72,  -208,   137,
     139,   141,  -208,  -208,  -208,  -208,  -208,   176,    97,   163,
    -208,    39,   334,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   182,   185,  -208,   154,   119,   188,   175,
     180,   183,   191,   207,   169,  -208,  -208,  -208,   111,   170,
     513,  -208,   513,   206,   175,   119,   119,     4,  -208,  -208,
    -208,  -208,  -208,  -208,  -208,   338,  -208,  -208,   -26,   179,
    -208,    77,    77,  -208,  -208,    39,    39,    39,    39,    39,
      39,  -208,  -208,   119,   513,  -208,   199,   184,   187,   214,
     195,    22,   197,   198,  -208,  -208,  -208,  -208,  -208,  -208,
    -208,  -208,  -208,   186,   368,   383,   414,  -208,   196,   338,
     338,   451,   518,  -208,   241,   175,  -208,   208,   209,  -208,
    -208,  -208,   518,   247,  -208,  -208,  -208,   232,   428,   442,
     237,   220,   222,   518,  -208,   223,   518,  -208,   251,   175,
     256,   175,   367,   518,  -208,   221,  -208,  -208,    16,  -208,
     226,  -208,  -208,   230,   235,   273,  -208,   245,  -208,   518,
    -208,   257,  -208,   259,   219,   493,  -208,  -208,  -208,   279,
    -208,  -208,  -208,  -208,   294,   518,   299,   518,   300,  -208,
    -208,  -208,  -208,  -208,  -208,   269,   219,   338,  -208,   518,
     518,   499,   518,   301,   272,   456,   305,   518,   219,   512,
    -208,   307,  -208,  -208,   308,   278,   219,  -208,  -208,  -208,
     313,   280,  -208,   317,  -208
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     9,    48,    51,    49,    50,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     1,     0,     0,     0,     8,
      10,     2,     0,    16,     0,     3,     5,    59,    52,    11,
      13,    89,    88,    84,    86,    85,    87,     0,     0,     0,
       0,     0,    68,    20,    28,     0,   134,    22,   123,   121,
     113,   117,   115,   119,   110,     0,     0,     0,     0,    24,
      21,     0,     0,     0,     0,     0,   106,     0,   101,     0,
       0,     0,     4,     6,    12,    14,    56,     0,     0,     0,
      83,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132,   133,   109,     0,    95,
      96,    23,    17,     0,     0,     0,     0,    19,   103,   104,
     100,   102,   105,   107,   108,     0,    60,    93,     0,     0,
      82,    71,    72,    73,    74,    75,    76,    77,    78,    80,
      79,    53,    61,     0,    18,    31,     0,     0,    97,     0,
       0,   129,   126,     0,   127,   124,   122,   114,   118,   116,
     120,    94,    26,     0,     0,     0,     0,    92,    90,     0,
       0,     0,     0,    99,     0,     0,   130,   139,   135,   131,
     125,   128,     0,     0,   111,   112,    57,     0,     0,     0,
      70,     0,     0,    32,    44,     0,     0,    98,     0,     0,
       0,     0,     0,     0,    58,     0,    54,    62,     0,    69,
       0,    40,    42,     0,     0,     0,    45,     0,    46,    29,
     142,     0,   137,     0,     0,     0,    91,    55,    63,     0,
      41,    43,    33,    47,     0,     0,     0,     0,     0,    34,
      39,    35,    37,    36,    38,     0,     0,     0,    30,   143,
       0,     0,     0,     0,     0,     0,     0,   140,     0,     0,
      27,     0,    65,   144,     0,     0,     0,    25,    66,   141,
       0,     0,   138,     0,   136
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -208,  -208,  -143,     0,     7,    -5,  -208,  -208,  -208,  -208,
    -208,  -208,  -207,  -197,    42,   228,  -208,  -208,  -208,  -208,
    -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,
    -208,    -8,   -22,  -208,  -131,  -208,  -208,  -208,   239,   114,
    -208,  -208,   231,    -3,  -208,   205,   -10,  -208,  -208,  -208,
    -208,  -208,  -208,  -208
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    10,    11,   211,   212,    14,   134,   202,   119,   254,
     192,   235,   265,   213,   214,    16,    17,   189,   247,    48,
     145,   224,    97,    18,   190,   248,    19,    25,   288,   116,
     230,    60,    33,   131,   167,   168,    41,    87,    88,   215,
      90,    91,    75,    21,   123,   124,    22,   126,   221,   257,
     219,   284,   255,   276
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    44,   186,   183,    30,   222,    39,    13,    43,    78,
     127,    37,    80,   128,   187,     4,    61,   128,    38,   239,
      78,    30,    67,    83,    23,    24,   245,    68,    27,    69,
      70,    71,    72,    73,    26,    98,    84,    99,    31,    28,
      32,    35,    15,    85,    29,    32,   208,   209,    74,   100,
     101,   102,    34,    40,    79,   125,    32,    32,   269,   274,
     271,   198,   115,    32,   217,   103,   104,   105,   106,   130,
     132,   285,    45,   277,    46,   279,   140,    47,    86,   291,
       1,    49,     2,     3,     4,    81,    82,    84,   241,    50,
     243,     8,    83,    62,    85,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   105,   106,   181,    63,   164,
      64,    65,    66,   125,    20,    80,    68,    76,    69,    70,
      71,    72,    73,    77,   275,    42,    92,   184,   185,    86,
     175,    96,   176,   177,   178,   179,   180,   147,    51,    93,
      52,    53,    54,    55,    56,    12,    57,    94,    95,   199,
      89,   117,    13,   118,    58,   191,    36,   129,    59,   137,
     133,     1,   135,     2,     3,     4,   136,   138,   139,     5,
       6,     7,     8,     9,   120,   142,    44,   143,   121,   144,
       7,    39,   122,    43,     1,   149,    37,    15,   161,    12,
      12,   162,   163,    38,   165,   166,    13,    13,    44,    44,
     169,    89,   170,    39,    39,    43,    43,   174,    37,    37,
     171,    32,   182,   233,   172,    38,    38,   229,   193,   120,
     234,   188,   233,   121,   194,     7,   203,   122,    40,   234,
     195,    15,    15,   196,   197,   200,   201,   207,   259,   233,
     260,   261,   262,   263,   264,   233,   234,   216,   218,   220,
      40,    40,   234,   223,   225,   236,   228,   240,   231,    20,
     232,   238,   242,   246,   236,    44,   249,    12,   250,   233,
      39,   233,    43,   251,    13,    37,   234,   233,   234,   233,
     252,   236,    38,   253,   234,   267,   234,   236,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   256,   112,   258,
      42,   268,   113,    20,    20,   270,   272,   273,   280,    15,
     281,   236,   283,   236,   287,   289,   290,    40,   293,   236,
     292,   236,    42,    42,   294,   146,   141,   237,   173,   148,
       0,     0,     0,     0,     0,     0,   237,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     1,   112,     2,     3,
       4,   114,     0,   237,     5,     6,     7,     8,     9,   237,
     103,   104,   105,   106,   107,   108,   109,   110,   111,     0,
     112,     0,     0,     0,   150,     1,     0,     2,     3,     4,
       0,    20,   244,   237,     0,   237,     8,    83,     0,    42,
       0,   237,     0,   237,   103,   104,   105,   106,   107,   108,
     109,   110,   111,     0,   112,     0,     0,     0,   204,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   112,
       0,   206,     1,   205,     2,     3,     4,     0,     0,     0,
       5,     6,     7,     8,     9,   226,     1,     0,     2,     3,
       4,     0,     0,     0,     5,     6,     7,     8,     9,   227,
       1,     0,     2,     3,     4,     0,     0,     0,     5,     6,
       7,     8,     9,   282,     1,     0,     2,     3,     4,     0,
       0,     0,     5,     6,     7,     8,     9,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     0,   112,     1,   210,
       2,     3,     4,    81,    82,     0,     0,     0,     0,     8,
      83,     1,     0,     2,     3,     4,     0,     1,   266,     2,
       3,     4,     8,    83,   278,     0,     0,     0,     8,    83,
       1,     0,     2,     3,     4,     0,     1,   286,     2,     3,
       4,     8,    83,     0,     0,     0,     0,     8,    83,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   112
};

static const yytype_int16 yycheck[] =
{
       0,    11,   145,   134,     5,   202,    11,     0,    11,     5,
      40,    11,    34,    43,    40,    12,    24,    43,    11,   216,
       5,     5,    30,    20,    39,    39,   223,    19,    19,    21,
      22,    23,    24,    25,    20,    39,    36,    41,    39,    19,
      41,     0,     0,    36,    19,    41,   189,   190,    40,    57,
      58,    59,    19,    11,    39,    65,    41,    41,   255,   266,
     257,    39,    62,    41,   195,    26,    27,    28,    29,    77,
      78,   278,    38,   270,    38,   272,     4,     9,    36,   286,
       8,    38,    10,    11,    12,    13,    14,    87,   219,    38,
     221,    19,    20,    39,    87,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    28,    29,   129,    19,   117,
      39,     6,    19,   123,     0,   137,    19,    22,    21,    22,
      23,    24,    25,     5,   267,    11,    38,   135,   136,    87,
      19,     6,    21,    22,    23,    24,    25,    40,    19,    38,
      21,    22,    23,    24,    25,   145,    27,    38,    38,   171,
      36,     5,   145,    40,    35,   163,     3,    42,    39,    19,
      40,     8,    39,    10,    11,    12,    39,    38,    38,    16,
      17,    18,    19,    20,    12,    38,   186,    38,    16,    38,
      18,   186,    20,   186,     8,    22,   186,   145,     6,   189,
     190,     6,    38,   186,     6,    20,   189,   190,   208,   209,
      20,    87,    19,   208,   209,   208,   209,    38,   208,   209,
      19,    41,     6,   213,     7,   208,   209,   210,    19,    12,
     213,    42,   222,    16,    40,    18,    40,    20,   186,   222,
      43,   189,   190,    19,    39,    38,    38,    41,    19,   239,
      21,    22,    23,    24,    25,   245,   239,     6,    40,    40,
     208,   209,   245,     6,    22,   213,    19,     6,    38,   145,
      38,    38,     6,    42,   222,   275,    40,   267,    38,   269,
     275,   271,   275,    38,   267,   275,   269,   277,   271,   279,
       7,   239,   275,    38,   277,     6,   279,   245,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    40,    36,    40,
     186,     7,    40,   189,   190,     6,     6,    38,     7,   267,
      38,   269,     7,   271,     7,     7,    38,   275,    38,   277,
       7,   279,   208,   209,     7,    97,    87,   213,   123,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   222,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     8,    36,    10,    11,
      12,    40,    -1,   239,    16,    17,    18,    19,    20,   245,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    -1,    -1,    -1,    40,     8,    -1,    10,    11,    12,
      -1,   267,    15,   269,    -1,   271,    19,    20,    -1,   275,
      -1,   277,    -1,   279,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    36,    -1,    -1,    -1,    40,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      -1,     7,     8,    40,    10,    11,    12,    -1,    -1,    -1,
      16,    17,    18,    19,    20,     7,     8,    -1,    10,    11,
      12,    -1,    -1,    -1,    16,    17,    18,    19,    20,     7,
       8,    -1,    10,    11,    12,    -1,    -1,    -1,    16,    17,
      18,    19,    20,     7,     8,    -1,    10,    11,    12,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,     8,    38,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    19,
      20,     8,    -1,    10,    11,    12,    -1,     8,    15,    10,
      11,    12,    19,    20,    15,    -1,    -1,    -1,    19,    20,
       8,    -1,    10,    11,    12,    -1,     8,    15,    10,    11,
      12,    19,    20,    -1,    -1,    -1,    -1,    19,    20,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    11,    12,    16,    17,    18,    19,    20,
      45,    46,    47,    48,    49,    58,    59,    60,    67,    70,
      83,    87,    90,    39,    39,    71,    20,    19,    19,    19,
       5,    39,    41,    76,    19,     0,     3,    47,    48,    49,
      58,    80,    83,    87,    90,    38,    38,     9,    63,    38,
      38,    19,    21,    22,    23,    24,    25,    27,    35,    39,
      75,    75,    39,    19,    39,     6,    19,    75,    19,    21,
      22,    23,    24,    25,    40,    86,    22,     5,     5,    39,
      76,    13,    14,    20,    47,    48,    58,    81,    82,    83,
      84,    85,    38,    38,    38,    38,     6,    66,    39,    41,
      75,    75,    75,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    36,    40,    40,    47,    73,     5,    40,    52,
      12,    16,    20,    88,    89,    90,    91,    40,    43,    42,
      75,    77,    75,    40,    50,    39,    39,    19,    38,    38,
       4,    82,    38,    38,    38,    64,    59,    40,    86,    22,
      40,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,     6,     6,    38,    75,     6,    20,    78,    79,    20,
      19,    19,     7,    89,    38,    19,    21,    22,    23,    24,
      25,    76,     6,    78,    75,    75,    46,    40,    42,    61,
      68,    75,    54,    19,    40,    43,    19,    39,    39,    76,
      38,    38,    51,    40,    40,    40,     7,    41,    46,    46,
      38,    47,    48,    57,    58,    83,     6,    78,    40,    94,
      40,    92,    57,     6,    65,    22,     7,     7,    19,    48,
      74,    38,    38,    47,    48,    55,    58,    83,    38,    57,
       6,    78,     6,    78,    15,    57,    42,    62,    69,    40,
      38,    38,     7,    38,    53,    96,    40,    93,    40,    19,
      21,    22,    23,    24,    25,    56,    15,     6,     7,    57,
       6,    57,     6,    38,    56,    46,    97,    57,    15,    57,
       7,    38,     7,     7,    95,    56,    15,     7,    72,     7,
      38,    56,     7,    38,     7
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    47,    47,    47,
      47,    47,    48,    48,    50,    49,    51,    49,    52,    53,
      49,    54,    55,    49,    56,    56,    56,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      58,    59,    59,    61,    62,    60,    64,    65,    63,    66,
      63,    68,    69,    67,    71,    72,    70,    73,    73,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    76,    76,    77,    78,    78,    79,
      80,    81,    81,    82,    82,    82,    82,    82,    82,    83,
      83,    84,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    87,    87,    88,    88,    89,
      89,    89,    89,    89,    90,    92,    91,    93,    91,    94,
      95,    91,    96,    97,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     3,     2,     3,     1,     2,     1,
       2,     2,     3,     2,     3,     1,     2,     4,     5,     2,
       3,     3,     3,     4,     0,    12,     0,    11,     0,     0,
      10,     0,     0,     9,     1,     1,     1,     1,     1,     1,
       2,     3,     2,     3,     1,     2,     2,     3,     1,     1,
       1,     1,     2,     0,     0,     9,     0,     0,     6,     0,
       3,     0,     0,     9,     0,     0,    13,     1,     0,     1,
       0,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     7,     4,     3,     4,     3,     1,     1,     3,     2,
       3,     1,     2,     2,     2,     2,     1,     2,     2,     4,
       3,     4,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     6,     5,     2,     3,     2,
       3,     3,     1,     1,     3,     0,    12,     0,    11,     0,
       0,    10,     0,     0,     9
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
#line 1450 "limbaj.tab.c"
    break;

  case 17: /* decl: TYPE ID ASSIGN expression  */
#line 96 "limbaj.y"
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
#line 1508 "limbaj.tab.c"
    break;

  case 18: /* decl: CONST TYPE ID ASSIGN expression  */
#line 150 "limbaj.y"
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
#line 1566 "limbaj.tab.c"
    break;

  case 19: /* decl: TYPE ID  */
#line 203 "limbaj.y"
                     {
                    if(-1 == (ids.addVar((yyvsp[-1].string),(yyvsp[0].string), currScope, false, false))){
                         yyerror("[parser]: addVar error ");
                         YYERROR;
                    }
               }
#line 1577 "limbaj.tab.c"
    break;

  case 20: /* decl: CONST TYPE ID  */
#line 209 "limbaj.y"
                           {
                         if(-1 == (ids.addVar((yyvsp[-1].string), (yyvsp[0].string), currScope, false, true))){
                              yyerror("[parser]: addVar error ");
                              YYERROR;
                         }
                    }
#line 1588 "limbaj.tab.c"
    break;

  case 21: /* decl: TYPE ID dimension  */
#line 215 "limbaj.y"
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
#line 1608 "limbaj.tab.c"
    break;

  case 22: /* assignation: ID ASSIGN expression  */
#line 232 "limbaj.y"
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
#line 1670 "limbaj.tab.c"
    break;

  case 23: /* assignation: ID dimension ASSIGN array_value  */
#line 303 "limbaj.y"
                                              {
                    if(ids.updateArrayValue((yyvsp[-3].string), currScope, dimensionContainer, temp) == -1){
                         yyerror("[parser]: Error at array assignation ");
                         YYERROR;
                    }
                    dimensionContainer.clear();
               }
#line 1682 "limbaj.tab.c"
    break;

  case 24: /* $@1: %empty  */
#line 311 "limbaj.y"
                        {incrementScope(); flag_func=1;}
#line 1688 "limbaj.tab.c"
    break;

  case 25: /* func_decl: TYPE ID '(' $@1 list_param ')' OPENBRK f_declarations RETURN ret ';' CLOSEDBRK  */
#line 311 "limbaj.y"
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
     ret_val.name = "";
     ret_val.type = "";

}
#line 1712 "limbaj.tab.c"
    break;

  case 26: /* $@2: %empty  */
#line 330 "limbaj.y"
                           {incrementScope();flag_func=1;}
#line 1718 "limbaj.tab.c"
    break;

  case 27: /* func_decl: TYPE ID '(' ')' OPENBRK $@2 f_declarations RETURN ret ';' CLOSEDBRK  */
#line 330 "limbaj.y"
                                                                                                   {             
     if (!functions.existsFunc((yyvsp[-9].string), (yyvsp[-10].string), params)) {
          if(ret_val.name == "error"){
               yyerror("[parser]: return var not found\n");
               YYERROR;
          }
          else if (ret_val.type != (yyvsp[-10].string)) {
               yyerror("[parser]: Return type mismatch\n");
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
     ret_val.name = "";
     ret_val.type = "";
     }
#line 1745 "limbaj.tab.c"
    break;

  case 28: /* $@3: %empty  */
#line 352 "limbaj.y"
              {incrementScope();flag_func=1;}
#line 1751 "limbaj.tab.c"
    break;

  case 29: /* $@4: %empty  */
#line 352 "limbaj.y"
                                                                                    {decrementScope();}
#line 1757 "limbaj.tab.c"
    break;

  case 30: /* func_decl: VOID ID '(' $@3 list_param ')' OPENBRK f_declarations $@4 CLOSEDBRK  */
#line 352 "limbaj.y"
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
#line 1774 "limbaj.tab.c"
    break;

  case 31: /* $@5: %empty  */
#line 364 "limbaj.y"
                         {incrementScope();flag_func=1;}
#line 1780 "limbaj.tab.c"
    break;

  case 32: /* $@6: %empty  */
#line 364 "limbaj.y"
                                                                        {decrementScope();}
#line 1786 "limbaj.tab.c"
    break;

  case 33: /* func_decl: VOID ID '(' ')' OPENBRK $@5 f_declarations $@6 CLOSEDBRK  */
#line 364 "limbaj.y"
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
#line 1803 "limbaj.tab.c"
    break;

  case 34: /* ret: ID  */
#line 377 "limbaj.y"
        {if(ids.getVar((yyvsp[0].string), currScope)!=nullptr){ret_val.type = ids.getVar((yyvsp[0].string), currScope)->type; ret_val.name = (yyvsp[0].string); ret_val.scopeId = currScope;}else{ret_val.name="error";yyerror("[parser]: Error id not found"); YYERROR;}}
#line 1809 "limbaj.tab.c"
    break;

  case 35: /* ret: NR  */
#line 378 "limbaj.y"
          {ret_val.type = "int"; ret_val.value.iVal = (yyvsp[0].integer_value);}
#line 1815 "limbaj.tab.c"
    break;

  case 36: /* ret: FLT  */
#line 379 "limbaj.y"
           {ret_val.type = "float"; ret_val.value.fVal = (yyvsp[0].float_value);}
#line 1821 "limbaj.tab.c"
    break;

  case 37: /* ret: BOO  */
#line 380 "limbaj.y"
           {ret_val.type = "bool"; ret_val.value.bVal = (yyvsp[0].bool_value);}
#line 1827 "limbaj.tab.c"
    break;

  case 38: /* ret: CHR  */
#line 381 "limbaj.y"
           {ret_val.type = "char"; ret_val.value.cVal = (yyvsp[0].char_value);}
#line 1833 "limbaj.tab.c"
    break;

  case 39: /* ret: STR  */
#line 382 "limbaj.y"
           {ret_val.type = "string"; ret_val.value.sVal = strdup((yyvsp[0].string));}
#line 1839 "limbaj.tab.c"
    break;

  case 53: /* $@7: %empty  */
#line 404 "limbaj.y"
                                           {incrementScope();}
#line 1845 "limbaj.tab.c"
    break;

  case 54: /* $@8: %empty  */
#line 404 "limbaj.y"
                                                                                     {decrementScope();}
#line 1851 "limbaj.tab.c"
    break;

  case 55: /* if_statement: IF '(' expression ')' OPENBRK $@7 declarations CLOSEDBRK $@8  */
#line 404 "limbaj.y"
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
#line 1869 "limbaj.tab.c"
    break;

  case 56: /* $@9: %empty  */
#line 418 "limbaj.y"
                             {incrementScope();}
#line 1875 "limbaj.tab.c"
    break;

  case 57: /* $@10: %empty  */
#line 418 "limbaj.y"
                                                                       {decrementScope();}
#line 1881 "limbaj.tab.c"
    break;

  case 58: /* else_statement: ELSE OPENBRK $@9 declarations CLOSEDBRK $@10  */
#line 418 "limbaj.y"
                                                                                           {
                         cout << "[else expr] : else working yay\n";
                    }
#line 1889 "limbaj.tab.c"
    break;

  case 59: /* $@11: %empty  */
#line 421 "limbaj.y"
                     {cout << "[if else expr] : if else working yay\n";}
#line 1895 "limbaj.tab.c"
    break;

  case 61: /* $@12: %empty  */
#line 424 "limbaj.y"
                                                  {incrementScope();}
#line 1901 "limbaj.tab.c"
    break;

  case 62: /* $@13: %empty  */
#line 424 "limbaj.y"
                                                                                            {decrementScope();}
#line 1907 "limbaj.tab.c"
    break;

  case 63: /* while_statement: WHILE '(' expression ')' OPENBRK $@12 declarations CLOSEDBRK $@13  */
#line 424 "limbaj.y"
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
#line 1925 "limbaj.tab.c"
    break;

  case 64: /* $@14: %empty  */
#line 439 "limbaj.y"
                   {incrementScope();}
#line 1931 "limbaj.tab.c"
    break;

  case 65: /* $@15: %empty  */
#line 439 "limbaj.y"
                                                                                                                   {decrementScope();}
#line 1937 "limbaj.tab.c"
    break;

  case 66: /* for_statement: FOR $@14 '(' for_init ';' expression ';' for_step ')' OPENBRK declarations CLOSEDBRK $@15  */
#line 439 "limbaj.y"
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
#line 1955 "limbaj.tab.c"
    break;

  case 71: /* expression: expression "+" expression  */
#line 462 "limbaj.y"
                                     {
                    (yyval.node) = new node(opType::ADD, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 1963 "limbaj.tab.c"
    break;

  case 72: /* expression: expression "-" expression  */
#line 465 "limbaj.y"
                                          {
                    (yyval.node) = new node(opType::SUB, (yyvsp[-2].node), (yyvsp[0].node));
                    }
#line 1971 "limbaj.tab.c"
    break;

  case 73: /* expression: expression "*" expression  */
#line 468 "limbaj.y"
                                          {
                    (yyval.node) = new node(opType::MUL, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 1979 "limbaj.tab.c"
    break;

  case 74: /* expression: expression "/" expression  */
#line 471 "limbaj.y"
                                          {
                    (yyval.node) = new node(opType::DIV, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 1987 "limbaj.tab.c"
    break;

  case 75: /* expression: expression "<" expression  */
#line 474 "limbaj.y"
                                          {
                    (yyval.node) = new node(opType::LE, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 1995 "limbaj.tab.c"
    break;

  case 76: /* expression: expression ">" expression  */
#line 477 "limbaj.y"
                                          {
                    (yyval.node) = new node(opType::GE, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 2003 "limbaj.tab.c"
    break;

  case 77: /* expression: expression "<=" expression  */
#line 480 "limbaj.y"
                                           {
                    (yyval.node) = new node(opType::LEQ, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 2011 "limbaj.tab.c"
    break;

  case 78: /* expression: expression ">=" expression  */
#line 483 "limbaj.y"
                                           {
                    (yyval.node) = new node(opType::GEQ, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 2019 "limbaj.tab.c"
    break;

  case 79: /* expression: expression "==" expression  */
#line 486 "limbaj.y"
                                           {
                    (yyval.node) = new node(opType::EQU, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 2027 "limbaj.tab.c"
    break;

  case 80: /* expression: expression "!=" expression  */
#line 489 "limbaj.y"
                                           {
                    (yyval.node) = new node(opType::NEQ, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 2035 "limbaj.tab.c"
    break;

  case 81: /* expression: "!" expression  */
#line 492 "limbaj.y"
                               {
                    (yyval.node) = new node(opType::NOT, (yyvsp[0].node), nullptr);
               }
#line 2043 "limbaj.tab.c"
    break;

  case 82: /* expression: '(' expression ')'  */
#line 495 "limbaj.y"
                                   {
                    (yyval.node) = (yyvsp[-1].node);
               }
#line 2051 "limbaj.tab.c"
    break;

  case 83: /* expression: "-" expression  */
#line 498 "limbaj.y"
                                            {
                    (yyval.node) = new node(opType::UMIN, (yyvsp[0].node), nullptr);
               }
#line 2059 "limbaj.tab.c"
    break;

  case 84: /* expression: NR  */
#line 501 "limbaj.y"
                   {
                    (yyval.node) = new node((yyvsp[0].integer_value));    
               }
#line 2067 "limbaj.tab.c"
    break;

  case 85: /* expression: FLT  */
#line 504 "limbaj.y"
                    {     
                    (yyval.node) = new node((yyvsp[0].float_value));
               }
#line 2075 "limbaj.tab.c"
    break;

  case 86: /* expression: BOO  */
#line 507 "limbaj.y"
                    {     
                    (yyval.node) = new node((yyvsp[0].bool_value));
               }
#line 2083 "limbaj.tab.c"
    break;

  case 87: /* expression: CHR  */
#line 510 "limbaj.y"
                    {     
                    (yyval.node) = new node((yyvsp[0].char_value));
               }
#line 2091 "limbaj.tab.c"
    break;

  case 88: /* expression: STR  */
#line 513 "limbaj.y"
                    {     
                    (yyval.node) = new node((yyvsp[0].string));
               }
#line 2099 "limbaj.tab.c"
    break;

  case 89: /* expression: ID  */
#line 516 "limbaj.y"
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
#line 2164 "limbaj.tab.c"
    break;

  case 90: /* expression: ID '[' NR ']'  */
#line 576 "limbaj.y"
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
#line 2231 "limbaj.tab.c"
    break;

  case 91: /* expression: ID '[' NR ']' '[' NR ']'  */
#line 638 "limbaj.y"
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
#line 2297 "limbaj.tab.c"
    break;

  case 92: /* expression: ID '(' call_list ')'  */
#line 699 "limbaj.y"
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
#line 2334 "limbaj.tab.c"
    break;

  case 93: /* expression: ID '(' ')'  */
#line 731 "limbaj.y"
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
#line 2370 "limbaj.tab.c"
    break;

  case 94: /* dimension: '[' NR ']' dimension  */
#line 764 "limbaj.y"
                                 {
                    dimensionContainer.push_back((yyvsp[-2].integer_value));
                    }
#line 2378 "limbaj.tab.c"
    break;

  case 95: /* dimension: '[' NR ']'  */
#line 767 "limbaj.y"
                       {
                    dimensionContainer.push_back((yyvsp[-1].integer_value));
                    }
#line 2386 "limbaj.tab.c"
    break;

  case 96: /* array_value: expression  */
#line 772 "limbaj.y"
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
#line 2447 "limbaj.tab.c"
    break;

  case 99: /* param: TYPE ID  */
#line 852 "limbaj.y"
               { ids.addVar((yyvsp[-1].string),(yyvsp[0].string),currScope,false,false); IdInfo arg; arg.type=string((yyvsp[-1].string)); arg.name=string((yyvsp[0].string)); arg.scopeId=currScope; params.push_back(arg);}
#line 2453 "limbaj.tab.c"
    break;

  case 109: /* call_function: ID '(' call_list ')'  */
#line 871 "limbaj.y"
                                     {if(!functions.existsFuncCall((yyvsp[-3].string), params)){
                              yyerror("[parser]: Function does not exist\n");
                              YYERROR;
                         }
                         params.clear();
                         }
#line 2464 "limbaj.tab.c"
    break;

  case 110: /* call_function: ID '(' ')'  */
#line 877 "limbaj.y"
                             {if(!functions.existsFuncCall((yyvsp[-2].string), params)){
                              yyerror("[parser]: Function does not exist\n");
                              YYERROR;
                         }
                         params.clear();
                         }
#line 2475 "limbaj.tab.c"
    break;

  case 111: /* eval_stmt: EVAL '(' expression ')'  */
#line 884 "limbaj.y"
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
#line 2511 "limbaj.tab.c"
    break;

  case 112: /* typeOf_stmt: TOF '(' expression ')'  */
#line 915 "limbaj.y"
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
#line 2547 "limbaj.tab.c"
    break;

  case 113: /* call_list: NR  */
#line 946 "limbaj.y"
               {IdInfo arg; arg.type=string("int"); arg.name=string(""); arg.value.iVal=(yyvsp[0].integer_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2553 "limbaj.tab.c"
    break;

  case 114: /* call_list: call_list ',' NR  */
#line 947 "limbaj.y"
                              {IdInfo arg; arg.type=string("int"); arg.name=string(""); arg.value.iVal=(yyvsp[0].integer_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2559 "limbaj.tab.c"
    break;

  case 115: /* call_list: FLT  */
#line 948 "limbaj.y"
                 {IdInfo arg; arg.type=string("float"); arg.name=string(""); arg.value.fVal=(yyvsp[0].float_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2565 "limbaj.tab.c"
    break;

  case 116: /* call_list: call_list ',' FLT  */
#line 949 "limbaj.y"
                               {IdInfo arg; arg.type=string("float"); arg.name=string(""); arg.value.fVal=(yyvsp[0].float_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2571 "limbaj.tab.c"
    break;

  case 117: /* call_list: BOO  */
#line 950 "limbaj.y"
                 {IdInfo arg; arg.type=string("bool"); arg.name=string(""); arg.value.bVal=(yyvsp[0].bool_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2577 "limbaj.tab.c"
    break;

  case 118: /* call_list: call_list ',' BOO  */
#line 951 "limbaj.y"
                               {IdInfo arg; arg.type=string("bool"); arg.name=string(""); arg.value.bVal=(yyvsp[0].bool_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2583 "limbaj.tab.c"
    break;

  case 119: /* call_list: CHR  */
#line 952 "limbaj.y"
                 {IdInfo arg; arg.type=string("char"); arg.name=string(""); arg.value.cVal=(yyvsp[0].char_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2589 "limbaj.tab.c"
    break;

  case 120: /* call_list: call_list ',' CHR  */
#line 953 "limbaj.y"
                               {IdInfo arg; arg.type=string("char"); arg.name=string(""); arg.value.cVal=(yyvsp[0].char_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2595 "limbaj.tab.c"
    break;

  case 121: /* call_list: STR  */
#line 954 "limbaj.y"
                 {IdInfo arg; arg.type=string("string"); arg.name=string(""); arg.value.sVal=strdup((yyvsp[0].string)); arg.scopeId=currScope; params.push_back(arg);}
#line 2601 "limbaj.tab.c"
    break;

  case 122: /* call_list: call_list ',' STR  */
#line 955 "limbaj.y"
                               {IdInfo arg; arg.type=string("string"); arg.name=string(""); arg.value.sVal=strdup((yyvsp[0].string)); arg.scopeId=currScope; params.push_back(arg);}
#line 2607 "limbaj.tab.c"
    break;

  case 123: /* call_list: ID  */
#line 956 "limbaj.y"
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
#line 2636 "limbaj.tab.c"
    break;

  case 124: /* call_list: call_list ',' ID  */
#line 980 "limbaj.y"
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
#line 2664 "limbaj.tab.c"
    break;

  case 125: /* class_decl: CLASS ID OPENBRK in_class_decl CLOSEDBRK ';'  */
#line 1004 "limbaj.y"
                                                          {
               if(!all_obj_class.existsClass((yyvsp[-4].string))){
                    all_obj_class.addClass((yyvsp[-4].string), fields, methods );
               }
               else{
                    yyerror("[parser]: Class already exists\n");
                    YYERROR;
               }
               fields.clear();
               methods.clear();
               
     }
#line 2681 "limbaj.tab.c"
    break;

  case 126: /* class_decl: CLASS ID OPENBRK in_class_decl CLOSEDBRK  */
#line 1016 "limbaj.y"
                                                        {
                     if(!all_obj_class.existsClass((yyvsp[-3].string))){
                    all_obj_class.addClass((yyvsp[-3].string),fields,methods );
               }
               else{
                    yyerror("[parser]: Class already exists\n");
                    YYERROR;
               }
               fields.clear();
               methods.clear();
               
     }
#line 2698 "limbaj.tab.c"
    break;

  case 129: /* var_class_decl: TYPE ID  */
#line 1033 "limbaj.y"
                        {
                    bool ok=true;
                  for(auto f:fields){
                       if(f.name == (yyvsp[0].string)){
                         ok=false;
                            yyerror("[parser]: Field already exists\n");
                            YYERROR;
                       }
                  }
                  if(ok){
                       IdInfo field;
                       field.type=strdup((yyvsp[-1].string));
                       field.name=strdup((yyvsp[0].string));
                       field.isArr=false;
                       field.isConst=false;
                       field.scopeId=currScope;
                       fields.push_back(field);
                  }
               }
#line 2722 "limbaj.tab.c"
    break;

  case 130: /* var_class_decl: CONST TYPE ID  */
#line 1052 "limbaj.y"
                           {
                   bool ok=true;
                  for(auto f:fields){
                       if(f.name == (yyvsp[-1].string)){
                         ok=false;
                            yyerror("[parser]: Field already exists\n");
                            YYERROR;
                       }
                  }
                  if(ok){
                       IdInfo field;
                       field.type=strdup((yyvsp[-1].string));
                       field.name=strdup((yyvsp[0].string));
                       field.isArr=false;
                       field.isConst=true;
                       field.scopeId=currScope;
                       fields.push_back(field);
                  }
                    }
#line 2746 "limbaj.tab.c"
    break;

  case 131: /* var_class_decl: TYPE ID dimension  */
#line 1071 "limbaj.y"
                              {
                    bool ok=true;for(auto f:fields){
                       if(f.name == (yyvsp[-1].string)){
                         ok=false;
                            yyerror("[parser]: Field already exists\n");
                            YYERROR;
                       }
                    }
                    if(ok){
                         IdInfo field;
                         field.type=strdup((yyvsp[-2].string));
                         field.name=strdup((yyvsp[-1].string));
                         field.isArr=true;
                         field.isConst=false;
                         field.scopeId=currScope;
                         if(ids.setArraySize((yyvsp[-1].string), dimensionContainer, currScope) == -1){
                              yyerror("[parser]: setArraySize error ");
                              YYERROR;
                         }
                         if(ids.initializeArray((yyvsp[-1].string), currScope) == -1){
                              yyerror("[parser]: initializeArray error ");
                              YYERROR;
                         }
                         field.dimensions=dimensionContainer;
                         fields.push_back(field);
                         dimensionContainer.clear();
                    }
               }
#line 2779 "limbaj.tab.c"
    break;

  case 134: /* objects: NEW ID ID  */
#line 1103 "limbaj.y"
                   {
     if(all_obj_class.existsObject((yyvsp[0].string))){
          yyerror("[parser]: Object already exists\n");
          YYERROR;
     }
     else if(!all_obj_class.existsClass((yyvsp[-1].string))){
          yyerror("[parser]: Class does not exist\n");
          YYERROR;
     }
     else{
          all_obj_class.addObject((yyvsp[0].string), (yyvsp[-1].string), all_obj_class.getClass((yyvsp[-1].string))->fields, all_obj_class.getClass((yyvsp[-1].string))->methods);
     }
}
#line 2797 "limbaj.tab.c"
    break;

  case 135: /* $@16: %empty  */
#line 1116 "limbaj.y"
                     {incrementScope(); flag_func=1;}
#line 2803 "limbaj.tab.c"
    break;

  case 136: /* methods: TYPE ID '(' $@16 list_param ')' OPENBRK f_declarations RETURN ret ';' CLOSEDBRK  */
#line 1116 "limbaj.y"
                                                                                                                     {
             bool ok=true;
          for(auto m: methods){
               if((yyvsp[-10].string) == m.name){
                    ok=false;
                    yyerror("[parser]: Method already exists\n");
                    YYERROR;
               }
          }
          if(ok){
               Function m;
               m.type=string((yyvsp[-11].string));
               m.name=string((yyvsp[-10].string));
               m.param=params;
               methods.push_back(m);
          }
     params.clear();
     decrementScope();
     flag_func=0;
     ret_val.name = "";
     ret_val.type = "";

}
#line 2831 "limbaj.tab.c"
    break;

  case 137: /* $@17: %empty  */
#line 1139 "limbaj.y"
                           {incrementScope();flag_func=1;}
#line 2837 "limbaj.tab.c"
    break;

  case 138: /* methods: TYPE ID '(' ')' OPENBRK $@17 f_declarations RETURN ret ';' CLOSEDBRK  */
#line 1139 "limbaj.y"
                                                                                                   {             
              bool ok=true;
          for(auto m: methods){
               if((yyvsp[-9].string) == m.name){
                    ok=false;
                    yyerror("[parser]: Method already exists\n");
                    YYERROR;
               }
          }
          if(ok){
               Function m;
               m.type=string((yyvsp[-10].string));
               m.name=string((yyvsp[-9].string));
               m.param=params;
               methods.push_back(m);
          }
     params.clear();
     decrementScope();
     flag_func=0;
     ret_val.name = "";
     ret_val.type = "";
     }
#line 2864 "limbaj.tab.c"
    break;

  case 139: /* $@18: %empty  */
#line 1161 "limbaj.y"
              {incrementScope();flag_func=1;}
#line 2870 "limbaj.tab.c"
    break;

  case 140: /* $@19: %empty  */
#line 1161 "limbaj.y"
                                                                                    {decrementScope();}
#line 2876 "limbaj.tab.c"
    break;

  case 141: /* methods: VOID ID '(' $@18 list_param ')' OPENBRK f_declarations $@19 CLOSEDBRK  */
#line 1161 "limbaj.y"
                                                                                                                 {
       
              bool ok=true;
          for(auto m: methods){
               if((yyvsp[-8].string) == m.name){
                    ok=false;
                    yyerror("[parser]: Method already exists\n");
                    YYERROR;
               }
          }
          if(ok){
               Function m;
               m.type=string("void");
               m.name=string((yyvsp[-8].string));
               m.param=params;
               methods.push_back(m);
          }
          params.clear();
          flag_func=0;
     }
#line 2901 "limbaj.tab.c"
    break;

  case 142: /* $@20: %empty  */
#line 1181 "limbaj.y"
                         {incrementScope();flag_func=1;}
#line 2907 "limbaj.tab.c"
    break;

  case 143: /* $@21: %empty  */
#line 1181 "limbaj.y"
                                                                        {decrementScope();}
#line 2913 "limbaj.tab.c"
    break;

  case 144: /* methods: VOID ID '(' ')' OPENBRK $@20 f_declarations $@21 CLOSEDBRK  */
#line 1181 "limbaj.y"
                                                                                                      {
         bool ok=true;
          for(auto m: methods){
               if((yyvsp[-7].string) == m.name){
                    ok=false;
                    yyerror("[parser]: Method already exists\n");
                    YYERROR;
               }
          }
          if(ok){
               Function m;
               m.type=string("void");
               m.name=string((yyvsp[-7].string));
               m.param=params;
               methods.push_back(m);
          }
          flag_func=0;
          params.clear();
          
     }
#line 2938 "limbaj.tab.c"
    break;


#line 2942 "limbaj.tab.c"

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

#line 1203 "limbaj.y"

void yyerror(const char * s){
printf("-ERROR-: %s at line:%d\n",s,yylineno);
}

int main(int argc, char** argv){
     scopes.push(currScope);
     ids.scope_path.push_back(currScope);
     ids.log_flag = atoi(argv[2]);
     yyin=fopen(argv[1],"r");
     yyparse();
     cout << endl<<endl<<"Variables:" <<endl;
     ids.printVars();
     cout<<endl<<endl<<"Functions:"<<endl;
     functions.printFuncs();
     cout<<endl<<endl<<"Classes:"<<endl;
     all_obj_class.printClasses();
     cout<<endl<<endl<<"Objects:";
     all_obj_class.printObjects();    
     delete temp;
} 
