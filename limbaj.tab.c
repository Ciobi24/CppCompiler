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
  YYSYMBOL_44_ = 44,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_progr = 46,                     /* progr  */
  YYSYMBOL_declarations = 47,              /* declarations  */
  YYSYMBOL_decl = 48,                      /* decl  */
  YYSYMBOL_assignation = 49,               /* assignation  */
  YYSYMBOL_func_decl = 50,                 /* func_decl  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_54_4 = 54,                      /* $@4  */
  YYSYMBOL_55_5 = 55,                      /* $@5  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_ret = 57,                       /* ret  */
  YYSYMBOL_f_declarations = 58,            /* f_declarations  */
  YYSYMBOL_control_statement = 59,         /* control_statement  */
  YYSYMBOL_condition_statement = 60,       /* condition_statement  */
  YYSYMBOL_if_statement = 61,              /* if_statement  */
  YYSYMBOL_62_7 = 62,                      /* $@7  */
  YYSYMBOL_63_8 = 63,                      /* $@8  */
  YYSYMBOL_else_statement = 64,            /* else_statement  */
  YYSYMBOL_65_9 = 65,                      /* $@9  */
  YYSYMBOL_66_10 = 66,                     /* $@10  */
  YYSYMBOL_67_11 = 67,                     /* $@11  */
  YYSYMBOL_while_statement = 68,           /* while_statement  */
  YYSYMBOL_69_12 = 69,                     /* $@12  */
  YYSYMBOL_70_13 = 70,                     /* $@13  */
  YYSYMBOL_for_statement = 71,             /* for_statement  */
  YYSYMBOL_72_14 = 72,                     /* $@14  */
  YYSYMBOL_73_15 = 73,                     /* $@15  */
  YYSYMBOL_for_init = 74,                  /* for_init  */
  YYSYMBOL_for_step = 75,                  /* for_step  */
  YYSYMBOL_expression = 76,                /* expression  */
  YYSYMBOL_dimension = 77,                 /* dimension  */
  YYSYMBOL_array_value = 78,               /* array_value  */
  YYSYMBOL_list_param = 79,                /* list_param  */
  YYSYMBOL_param = 80,                     /* param  */
  YYSYMBOL_block = 81,                     /* block  */
  YYSYMBOL_list = 82,                      /* list  */
  YYSYMBOL_statement = 83,                 /* statement  */
  YYSYMBOL_call_function = 84,             /* call_function  */
  YYSYMBOL_eval_stmt = 85,                 /* eval_stmt  */
  YYSYMBOL_typeOf_stmt = 86,               /* typeOf_stmt  */
  YYSYMBOL_call_list = 87,                 /* call_list  */
  YYSYMBOL_class_decl = 88,                /* class_decl  */
  YYSYMBOL_in_class_decl = 89,             /* in_class_decl  */
  YYSYMBOL_var_class_decl = 90,            /* var_class_decl  */
  YYSYMBOL_objects = 91,                   /* objects  */
  YYSYMBOL_methods = 92,                   /* methods  */
  YYSYMBOL_93_16 = 93,                     /* $@16  */
  YYSYMBOL_94_17 = 94,                     /* $@17  */
  YYSYMBOL_95_18 = 95,                     /* $@18  */
  YYSYMBOL_96_19 = 96,                     /* $@19  */
  YYSYMBOL_97_20 = 97,                     /* $@20  */
  YYSYMBOL_98_21 = 98,                     /* $@21  */
  YYSYMBOL_obj_field = 99                  /* obj_field  */
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
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   637

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  317

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
      39,    40,     2,     2,    43,     2,    44,     2,     2,     2,
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
      88,    89,    90,    91,    92,    93,    94,    95,    96,    98,
     152,   205,   211,   217,   234,   305,   313,   313,   332,   332,
     354,   354,   354,   366,   366,   366,   379,   380,   381,   382,
     383,   384,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   400,   401,   402,   405,   406,   410,
     410,   410,   424,   424,   424,   427,   427,   430,   430,   430,
     445,   445,   445,   460,   461,   464,   465,   468,   471,   474,
     477,   480,   483,   486,   489,   492,   495,   498,   501,   504,
     507,   510,   513,   516,   519,   522,   582,   644,   705,   737,
     770,   773,   778,   854,   855,   858,   862,   866,   867,   870,
     871,   872,   873,   874,   875,   876,   877,   879,   885,   892,
     923,   954,   955,   956,   957,   958,   959,   960,   961,   962,
     963,   964,   988,  1012,  1024,  1037,  1038,  1041,  1060,  1079,
    1107,  1108,  1111,  1124,  1124,  1147,  1147,  1169,  1169,  1169,
    1189,  1189,  1189,  1210,  1229,  1261
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
  "';'", "'('", "')'", "'['", "']'", "','", "'.'", "$accept", "progr",
  "declarations", "decl", "assignation", "func_decl", "$@1", "$@2", "$@3",
  "$@4", "$@5", "$@6", "ret", "f_declarations", "control_statement",
  "condition_statement", "if_statement", "$@7", "$@8", "else_statement",
  "$@9", "$@10", "$@11", "while_statement", "$@12", "$@13",
  "for_statement", "$@14", "$@15", "for_init", "for_step", "expression",
  "dimension", "array_value", "list_param", "param", "block", "list",
  "statement", "call_function", "eval_stmt", "typeOf_stmt", "call_list",
  "class_decl", "in_class_decl", "var_class_decl", "objects", "methods",
  "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "obj_field", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-270)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      46,   -34,   -30,  -270,    -3,     3,    13,    18,     9,    22,
      47,   266,    23,    56,  -270,  -270,  -270,    71,  -270,  -270,
      64,  -270,    67,    70,   152,   152,    45,    91,    80,   116,
     106,   152,     2,   105,   110,   125,     5,  -270,   355,    95,
     109,  -270,  -270,  -270,   114,  -270,   115,   124,  -270,  -270,
     142,  -270,  -270,  -270,  -270,   -11,  -270,  -270,  -270,  -270,
    -270,   152,   152,   152,   315,   352,    -8,   165,   146,   108,
    -270,   601,  -270,  -270,  -270,  -270,  -270,  -270,  -270,    39,
     122,   149,   152,   152,   150,  -270,   153,   154,   176,   158,
     162,  -270,   147,  -270,   163,   167,   169,   170,   173,  -270,
    -270,  -270,  -270,  -270,  -270,   189,    53,   192,  -270,    62,
     388,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   209,   210,  -270,   181,   152,   214,   201,   204,   206,
     217,   242,   195,  -270,  -270,  -270,   159,   203,    92,   601,
    -270,   601,   241,   201,   152,   152,    10,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,    46,  -270,  -270,    60,
     208,  -270,    42,    42,  -270,  -270,    62,    62,    62,    62,
      62,    62,  -270,  -270,   152,   601,  -270,   229,   215,   220,
     238,   222,    -6,   226,   232,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,    61,  -270,   231,   413,   438,   469,
    -270,   234,    46,    46,   525,   606,  -270,   273,   201,  -270,
     240,   255,  -270,  -270,  -270,  -270,   606,   275,  -270,  -270,
    -270,   280,   485,   499,   284,   267,   269,   606,  -270,   271,
     272,   274,   606,  -270,   307,   201,   310,   201,   554,   606,
    -270,   277,  -270,  -270,    11,  -270,   281,  -270,  -270,   279,
     285,   317,  -270,   287,   291,   293,  -270,  -270,  -270,   606,
    -270,   292,  -270,   298,   218,   567,  -270,  -270,  -270,   334,
    -270,  -270,  -270,  -270,  -270,  -270,   345,   606,   347,   606,
     348,  -270,  -270,  -270,  -270,  -270,  -270,   320,   218,    46,
    -270,   606,   606,   580,   606,   353,   321,   530,   357,   606,
     218,   593,  -270,   363,  -270,  -270,   369,   324,   218,  -270,
    -270,  -270,   380,   351,  -270,   383,  -270
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     9,    54,    57,    55,    56,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     1,     0,     0,
       0,     8,    10,     2,     0,    16,     0,     0,     3,     5,
      65,    58,    11,    13,    17,    95,    94,    90,    92,    91,
      93,     0,     0,     0,     0,     0,    74,    22,    30,     0,
     142,    24,   131,   129,   121,   125,   123,   127,   118,     0,
       0,   153,     0,     0,    26,    23,     0,     0,     0,     0,
       0,   112,     0,   107,     0,     0,     0,     0,     0,     4,
       6,    12,    14,    18,    62,     0,     0,     0,    89,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   140,   141,   117,     0,   101,     0,   102,
      25,    19,     0,     0,     0,     0,    21,   109,   110,   106,
     108,   111,   113,   114,   115,   116,     0,    66,    99,     0,
       0,    88,    77,    78,    79,    80,    81,    82,    83,    84,
      86,    85,    59,    67,     0,    20,    33,     0,     0,   103,
       0,     0,   137,   134,     0,   135,   132,   130,   122,   126,
     124,   128,   100,   155,     0,    28,     0,     0,     0,     0,
      98,    96,     0,     0,     0,     0,   105,     0,     0,   138,
     147,   143,   139,   133,   136,   154,     0,     0,   119,   120,
      63,     0,     0,     0,    76,     0,     0,    34,    46,     0,
       0,     0,     0,   104,     0,     0,     0,     0,     0,     0,
      64,     0,    60,    68,     0,    75,     0,    42,    44,     0,
       0,     0,    47,     0,     0,     0,    48,    50,    52,    31,
     150,     0,   145,     0,     0,     0,    97,    61,    69,     0,
      43,    45,    35,    49,    51,    53,     0,     0,     0,     0,
       0,    36,    41,    37,    39,    38,    40,     0,     0,     0,
      32,   151,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,    29,     0,    71,   152,     0,     0,     0,    27,
      72,   149,     0,     0,   146,     0,   144
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -270,  -270,  -143,     7,    29,   -10,  -270,  -270,  -270,  -270,
    -270,  -270,  -269,  -196,   112,   289,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
    -270,    24,   -28,  -270,  -140,  -270,  -270,  -270,   303,   134,
    -270,  -270,  -104,    -5,  -270,   265,     0,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,   235
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    10,    11,   225,   226,    14,   143,   216,   127,   276,
     205,   251,   287,   227,   228,    16,    17,   202,   267,    51,
     156,   240,   105,    18,   203,   268,    19,    26,   310,   124,
     246,    64,    35,   140,   178,   179,    43,    92,    93,   229,
      95,    96,    79,    21,   131,   132,   230,   134,   237,   279,
     235,   306,   277,   298,   231
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    41,   159,   196,     4,    24,    45,    12,    85,    25,
      83,    46,    88,   199,    31,    83,    31,    27,    39,   296,
     238,    72,    28,    73,    74,    75,    76,    77,   106,    13,
     107,   307,    29,   211,   194,    33,   259,    30,    97,   313,
      40,    36,    78,   265,    84,    89,    33,    37,    32,    65,
      33,    33,    33,    34,     1,    71,     2,     3,     4,   222,
     223,    48,     5,     6,     7,     8,     9,    90,   233,   133,
     113,   114,    72,   123,    73,    74,    75,    76,    77,   135,
      50,   291,   136,   293,    66,   108,   109,   110,   111,   112,
     113,   114,    97,   158,    49,   261,   299,   263,   301,    89,
     200,   215,    52,   136,   136,    53,   139,   141,    54,   192,
      67,    72,    15,    73,    74,    75,    76,    77,    85,    68,
     128,    90,    69,    42,   129,    70,     7,    80,   130,    81,
      82,   133,   193,    99,    20,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    44,   297,   100,   104,   175,
      91,   149,   101,   102,   212,     1,    22,     2,     3,     4,
      86,    87,   103,    12,   137,     7,     8,    88,   197,   198,
     125,    55,    94,    56,    57,    58,    59,    60,   186,    61,
     187,   188,   189,   190,   191,    13,   126,    62,   138,    41,
     142,    63,   144,   145,    45,   146,   147,     1,   204,    46,
     148,   151,    22,    22,    91,   152,    39,   153,   154,    12,
      12,   155,    41,    41,   160,   172,   173,    45,    45,   174,
     176,   177,    46,    46,   180,   181,    94,   254,    40,    39,
      39,    13,    13,   185,   249,    23,   182,   281,   254,   282,
     283,   284,   285,   286,    33,   249,    47,   195,   206,   183,
     201,    40,    40,   245,   128,   207,   250,   209,   129,   254,
       7,   210,   130,   208,   213,   254,   249,   250,    15,    38,
     214,   217,   249,    98,     1,   221,     2,     3,     4,   232,
     234,   239,     5,     6,     7,     8,     9,    41,   250,    22,
      20,   254,    45,   254,   250,   236,    12,    46,   249,   254,
     249,   254,   241,   244,    39,   247,   249,   248,   249,   256,
     257,    42,   258,   260,    15,    15,   262,   270,    13,   266,
     250,   269,   250,   271,   272,   273,    40,    98,   250,   274,
     250,   275,   278,    44,    42,    42,    20,    20,   280,   252,
     289,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     252,   120,   290,   292,   294,   121,    44,    44,   295,   303,
     302,   253,   312,     1,   305,     2,     3,     4,    86,    87,
     309,   252,   253,     7,     8,    88,   311,   252,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   314,   120,   315,
     316,    23,   122,   253,   157,   150,   184,     0,     0,   253,
       0,    15,     0,   252,     0,   252,     0,     0,     0,    42,
       0,   252,     0,   252,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    20,   120,   253,     0,   253,   161,     0,
       0,    44,     0,   253,    47,   253,     0,    23,    23,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,     0,     0,   218,     0,     0,     0,    47,    47,     0,
       0,     0,   255,     0,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   255,   120,     0,   220,     1,   219,     2,
       3,     4,     0,     0,     0,     5,     6,     7,     8,     9,
       0,     0,   242,     1,   255,     2,     3,     4,     0,     0,
     255,     5,     6,     7,     8,     9,   243,     1,     0,     2,
       3,     4,     0,     0,     0,     5,     6,     7,     8,     9,
       0,     0,     0,     0,    23,     0,   255,     0,   255,     0,
       0,     0,    47,     0,   255,     0,   255,   304,     1,     0,
       2,     3,     4,     0,     0,     0,     5,     6,     7,     8,
       9,   111,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     1,   224,     2,     3,     4,     0,     0,   264,
       0,     0,     7,     8,    88,     1,     0,     2,     3,     4,
       0,     0,   288,     0,     0,     7,     8,    88,     1,     0,
       2,     3,     4,     0,     0,   300,     0,     0,     7,     8,
      88,     1,     0,     2,     3,     4,     0,     0,   308,     0,
       0,     7,     8,    88,     1,     0,     2,     3,     4,     0,
       0,     0,     0,     0,     7,     8,    88,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120
};

static const yytype_int16 yycheck[] =
{
       0,    11,   106,   143,    12,    39,    11,     0,    36,    39,
       5,    11,    20,   156,     5,     5,     5,    20,    11,   288,
     216,    19,    19,    21,    22,    23,    24,    25,    39,     0,
      41,   300,    19,    39,   138,    41,   232,    19,    38,   308,
      11,    19,    40,   239,    39,    38,    41,     0,    39,    25,
      41,    41,    41,    44,     8,    31,    10,    11,    12,   202,
     203,    38,    16,    17,    18,    19,    20,    38,   208,    69,
      28,    29,    19,    66,    21,    22,    23,    24,    25,    40,
       9,   277,    43,   279,    39,    61,    62,    63,    26,    27,
      28,    29,    92,    40,    38,   235,   292,   237,   294,    92,
      40,    40,    38,    43,    43,    38,    82,    83,    38,   137,
      19,    19,     0,    21,    22,    23,    24,    25,   146,    39,
      12,    92,     6,    11,    16,    19,    18,    22,    20,    19,
       5,   131,    40,    38,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    11,   289,    38,     6,   125,
      38,     4,    38,    38,   182,     8,   156,    10,    11,    12,
      13,    14,    38,   156,    42,    18,    19,    20,   144,   145,
       5,    19,    38,    21,    22,    23,    24,    25,    19,    27,
      21,    22,    23,    24,    25,   156,    40,    35,    39,   199,
      40,    39,    39,    39,   199,    19,    38,     8,   174,   199,
      38,    38,   202,   203,    92,    38,   199,    38,    38,   202,
     203,    38,   222,   223,    22,     6,     6,   222,   223,    38,
       6,    20,   222,   223,    20,    19,    92,   227,   199,   222,
     223,   202,   203,    38,   227,     0,    19,    19,   238,    21,
      22,    23,    24,    25,    41,   238,    11,     6,    19,     7,
      42,   222,   223,   224,    12,    40,   227,    19,    16,   259,
      18,    39,    20,    43,    38,   265,   259,   238,   156,     3,
      38,    40,   265,    38,     8,    41,    10,    11,    12,     6,
      40,     6,    16,    17,    18,    19,    20,   297,   259,   289,
     156,   291,   297,   293,   265,    40,   289,   297,   291,   299,
     293,   301,    22,    19,   297,    38,   299,    38,   301,    38,
      38,   199,    38,     6,   202,   203,     6,    38,   289,    42,
     291,    40,   293,    38,     7,    38,   297,    92,   299,    38,
     301,    38,    40,   199,   222,   223,   202,   203,    40,   227,
       6,    26,    27,    28,    29,    30,    31,    32,    33,    34,
     238,    36,     7,     6,     6,    40,   222,   223,    38,    38,
       7,   227,    38,     8,     7,    10,    11,    12,    13,    14,
       7,   259,   238,    18,    19,    20,     7,   265,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     7,    36,    38,
       7,   156,    40,   259,   105,    92,   131,    -1,    -1,   265,
      -1,   289,    -1,   291,    -1,   293,    -1,    -1,    -1,   297,
      -1,   299,    -1,   301,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   289,    36,   291,    -1,   293,    40,    -1,
      -1,   297,    -1,   299,   199,   301,    -1,   202,   203,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      -1,    -1,    -1,    40,    -1,    -1,    -1,   222,   223,    -1,
      -1,    -1,   227,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   238,    36,    -1,     7,     8,    40,    10,
      11,    12,    -1,    -1,    -1,    16,    17,    18,    19,    20,
      -1,    -1,     7,     8,   259,    10,    11,    12,    -1,    -1,
     265,    16,    17,    18,    19,    20,     7,     8,    -1,    10,
      11,    12,    -1,    -1,    -1,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,   289,    -1,   291,    -1,   293,    -1,
      -1,    -1,   297,    -1,   299,    -1,   301,     7,     8,    -1,
      10,    11,    12,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    36,     8,    38,    10,    11,    12,    -1,    -1,    15,
      -1,    -1,    18,    19,    20,     8,    -1,    10,    11,    12,
      -1,    -1,    15,    -1,    -1,    18,    19,    20,     8,    -1,
      10,    11,    12,    -1,    -1,    15,    -1,    -1,    18,    19,
      20,     8,    -1,    10,    11,    12,    -1,    -1,    15,    -1,
      -1,    18,    19,    20,     8,    -1,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    11,    12,    16,    17,    18,    19,    20,
      46,    47,    48,    49,    50,    59,    60,    61,    68,    71,
      84,    88,    91,    99,    39,    39,    72,    20,    19,    19,
      19,     5,    39,    41,    44,    77,    19,     0,     3,    48,
      49,    50,    59,    81,    84,    88,    91,    99,    38,    38,
       9,    64,    38,    38,    38,    19,    21,    22,    23,    24,
      25,    27,    35,    39,    76,    76,    39,    19,    39,     6,
      19,    76,    19,    21,    22,    23,    24,    25,    40,    87,
      22,    19,     5,     5,    39,    77,    13,    14,    20,    48,
      49,    59,    82,    83,    84,    85,    86,    91,    99,    38,
      38,    38,    38,    38,     6,    67,    39,    41,    76,    76,
      76,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      36,    40,    40,    48,    74,     5,    40,    53,    12,    16,
      20,    89,    90,    91,    92,    40,    43,    42,    39,    76,
      78,    76,    40,    51,    39,    39,    19,    38,    38,     4,
      83,    38,    38,    38,    38,    38,    65,    60,    40,    87,
      22,    40,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,     6,     6,    38,    76,     6,    20,    79,    80,
      20,    19,    19,     7,    90,    38,    19,    21,    22,    23,
      24,    25,    77,    40,    87,     6,    79,    76,    76,    47,
      40,    42,    62,    69,    76,    55,    19,    40,    43,    19,
      39,    39,    77,    38,    38,    40,    52,    40,    40,    40,
       7,    41,    47,    47,    38,    48,    49,    58,    59,    84,
      91,    99,     6,    79,    40,    95,    40,    93,    58,     6,
      66,    22,     7,     7,    19,    49,    75,    38,    38,    48,
      49,    56,    59,    84,    91,    99,    38,    38,    38,    58,
       6,    79,     6,    79,    15,    58,    42,    63,    70,    40,
      38,    38,     7,    38,    38,    38,    54,    97,    40,    94,
      40,    19,    21,    22,    23,    24,    25,    57,    15,     6,
       7,    58,     6,    58,     6,    38,    57,    47,    98,    58,
      15,    58,     7,    38,     7,     7,    96,    57,    15,     7,
      73,     7,    38,    57,     7,    38,     7
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    48,
      48,    48,    48,    48,    49,    49,    51,    50,    52,    50,
      53,    54,    50,    55,    56,    50,    57,    57,    57,    57,
      57,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    59,    60,    60,    62,
      63,    61,    65,    66,    64,    67,    64,    69,    70,    68,
      72,    73,    71,    74,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    78,    79,    79,    80,    81,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    83,    84,    84,    85,
      86,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    88,    88,    89,    89,    90,    90,    90,
      90,    90,    91,    93,    92,    94,    92,    95,    96,    92,
      97,    98,    92,    99,    99,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     3,     2,     3,     1,     2,     1,
       2,     2,     3,     2,     3,     1,     2,     2,     3,     4,
       5,     2,     3,     3,     3,     4,     0,    12,     0,    11,
       0,     0,    10,     0,     0,     9,     1,     1,     1,     1,
       1,     1,     2,     3,     2,     3,     1,     2,     2,     3,
       2,     3,     2,     3,     1,     1,     1,     1,     2,     0,
       0,     9,     0,     0,     6,     0,     3,     0,     0,     9,
       0,     0,    13,     1,     0,     1,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     4,     7,     4,     3,
       4,     3,     1,     1,     3,     2,     3,     1,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     4,     3,     4,
       4,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     6,     5,     2,     3,     2,     3,     3,
       1,     1,     3,     0,    12,     0,    11,     0,     0,    10,
       0,     0,     9,     3,     6,     5
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
#line 1479 "limbaj.tab.c"
    break;

  case 19: /* decl: TYPE ID ASSIGN expression  */
#line 98 "limbaj.y"
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
#line 1537 "limbaj.tab.c"
    break;

  case 20: /* decl: CONST TYPE ID ASSIGN expression  */
#line 152 "limbaj.y"
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
#line 1595 "limbaj.tab.c"
    break;

  case 21: /* decl: TYPE ID  */
#line 205 "limbaj.y"
                     {
                    if(-1 == (ids.addVar((yyvsp[-1].string),(yyvsp[0].string), currScope, false, false))){
                         yyerror("[parser]: addVar error ");
                         YYERROR;
                    }
               }
#line 1606 "limbaj.tab.c"
    break;

  case 22: /* decl: CONST TYPE ID  */
#line 211 "limbaj.y"
                           {
                         if(-1 == (ids.addVar((yyvsp[-1].string), (yyvsp[0].string), currScope, false, true))){
                              yyerror("[parser]: addVar error ");
                              YYERROR;
                         }
                    }
#line 1617 "limbaj.tab.c"
    break;

  case 23: /* decl: TYPE ID dimension  */
#line 217 "limbaj.y"
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
#line 1637 "limbaj.tab.c"
    break;

  case 24: /* assignation: ID ASSIGN expression  */
#line 234 "limbaj.y"
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
#line 1699 "limbaj.tab.c"
    break;

  case 25: /* assignation: ID dimension ASSIGN array_value  */
#line 305 "limbaj.y"
                                              {
                    if(ids.updateArrayValue((yyvsp[-3].string), currScope, dimensionContainer, temp) == -1){
                         yyerror("[parser]: Error at array assignation ");
                         YYERROR;
                    }
                    dimensionContainer.clear();
               }
#line 1711 "limbaj.tab.c"
    break;

  case 26: /* $@1: %empty  */
#line 313 "limbaj.y"
                        {incrementScope(); flag_func=1;}
#line 1717 "limbaj.tab.c"
    break;

  case 27: /* func_decl: TYPE ID '(' $@1 list_param ')' OPENBRK f_declarations RETURN ret ';' CLOSEDBRK  */
#line 313 "limbaj.y"
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
#line 1741 "limbaj.tab.c"
    break;

  case 28: /* $@2: %empty  */
#line 332 "limbaj.y"
                           {incrementScope();flag_func=1;}
#line 1747 "limbaj.tab.c"
    break;

  case 29: /* func_decl: TYPE ID '(' ')' OPENBRK $@2 f_declarations RETURN ret ';' CLOSEDBRK  */
#line 332 "limbaj.y"
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
#line 1774 "limbaj.tab.c"
    break;

  case 30: /* $@3: %empty  */
#line 354 "limbaj.y"
              {incrementScope();flag_func=1;}
#line 1780 "limbaj.tab.c"
    break;

  case 31: /* $@4: %empty  */
#line 354 "limbaj.y"
                                                                                    {decrementScope();}
#line 1786 "limbaj.tab.c"
    break;

  case 32: /* func_decl: VOID ID '(' $@3 list_param ')' OPENBRK f_declarations $@4 CLOSEDBRK  */
#line 354 "limbaj.y"
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
#line 1803 "limbaj.tab.c"
    break;

  case 33: /* $@5: %empty  */
#line 366 "limbaj.y"
                         {incrementScope();flag_func=1;}
#line 1809 "limbaj.tab.c"
    break;

  case 34: /* $@6: %empty  */
#line 366 "limbaj.y"
                                                                        {decrementScope();}
#line 1815 "limbaj.tab.c"
    break;

  case 35: /* func_decl: VOID ID '(' ')' OPENBRK $@5 f_declarations $@6 CLOSEDBRK  */
#line 366 "limbaj.y"
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
#line 1832 "limbaj.tab.c"
    break;

  case 36: /* ret: ID  */
#line 379 "limbaj.y"
        {if(ids.getVar((yyvsp[0].string), currScope)!=nullptr){ret_val.type = ids.getVar((yyvsp[0].string), currScope)->type; ret_val.name = (yyvsp[0].string); ret_val.scopeId = currScope;}else{ret_val.name="error";yyerror("[parser]: Error id not found"); YYERROR;}}
#line 1838 "limbaj.tab.c"
    break;

  case 37: /* ret: NR  */
#line 380 "limbaj.y"
          {ret_val.type = "int"; ret_val.value.iVal = (yyvsp[0].integer_value);}
#line 1844 "limbaj.tab.c"
    break;

  case 38: /* ret: FLT  */
#line 381 "limbaj.y"
           {ret_val.type = "float"; ret_val.value.fVal = (yyvsp[0].float_value);}
#line 1850 "limbaj.tab.c"
    break;

  case 39: /* ret: BOO  */
#line 382 "limbaj.y"
           {ret_val.type = "bool"; ret_val.value.bVal = (yyvsp[0].bool_value);}
#line 1856 "limbaj.tab.c"
    break;

  case 40: /* ret: CHR  */
#line 383 "limbaj.y"
           {ret_val.type = "char"; ret_val.value.cVal = (yyvsp[0].char_value);}
#line 1862 "limbaj.tab.c"
    break;

  case 41: /* ret: STR  */
#line 384 "limbaj.y"
           {ret_val.type = "string"; ret_val.value.sVal = strdup((yyvsp[0].string));}
#line 1868 "limbaj.tab.c"
    break;

  case 59: /* $@7: %empty  */
#line 410 "limbaj.y"
                                           {incrementScope();}
#line 1874 "limbaj.tab.c"
    break;

  case 60: /* $@8: %empty  */
#line 410 "limbaj.y"
                                                                                     {decrementScope();}
#line 1880 "limbaj.tab.c"
    break;

  case 61: /* if_statement: IF '(' expression ')' OPENBRK $@7 declarations CLOSEDBRK $@8  */
#line 410 "limbaj.y"
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
#line 1898 "limbaj.tab.c"
    break;

  case 62: /* $@9: %empty  */
#line 424 "limbaj.y"
                             {incrementScope();}
#line 1904 "limbaj.tab.c"
    break;

  case 63: /* $@10: %empty  */
#line 424 "limbaj.y"
                                                                       {decrementScope();}
#line 1910 "limbaj.tab.c"
    break;

  case 64: /* else_statement: ELSE OPENBRK $@9 declarations CLOSEDBRK $@10  */
#line 424 "limbaj.y"
                                                                                           {
                         cout << "[else expr] : else working yay\n";
                    }
#line 1918 "limbaj.tab.c"
    break;

  case 65: /* $@11: %empty  */
#line 427 "limbaj.y"
                     {cout << "[if else expr] : if else working yay\n";}
#line 1924 "limbaj.tab.c"
    break;

  case 67: /* $@12: %empty  */
#line 430 "limbaj.y"
                                                  {incrementScope();}
#line 1930 "limbaj.tab.c"
    break;

  case 68: /* $@13: %empty  */
#line 430 "limbaj.y"
                                                                                            {decrementScope();}
#line 1936 "limbaj.tab.c"
    break;

  case 69: /* while_statement: WHILE '(' expression ')' OPENBRK $@12 declarations CLOSEDBRK $@13  */
#line 430 "limbaj.y"
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
#line 1954 "limbaj.tab.c"
    break;

  case 70: /* $@14: %empty  */
#line 445 "limbaj.y"
                   {incrementScope();}
#line 1960 "limbaj.tab.c"
    break;

  case 71: /* $@15: %empty  */
#line 445 "limbaj.y"
                                                                                                                   {decrementScope();}
#line 1966 "limbaj.tab.c"
    break;

  case 72: /* for_statement: FOR $@14 '(' for_init ';' expression ';' for_step ')' OPENBRK declarations CLOSEDBRK $@15  */
#line 445 "limbaj.y"
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
#line 1984 "limbaj.tab.c"
    break;

  case 77: /* expression: expression "+" expression  */
#line 468 "limbaj.y"
                                     {
                    (yyval.node) = new node(opType::ADD, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 1992 "limbaj.tab.c"
    break;

  case 78: /* expression: expression "-" expression  */
#line 471 "limbaj.y"
                                          {
                    (yyval.node) = new node(opType::SUB, (yyvsp[-2].node), (yyvsp[0].node));
                    }
#line 2000 "limbaj.tab.c"
    break;

  case 79: /* expression: expression "*" expression  */
#line 474 "limbaj.y"
                                          {
                    (yyval.node) = new node(opType::MUL, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 2008 "limbaj.tab.c"
    break;

  case 80: /* expression: expression "/" expression  */
#line 477 "limbaj.y"
                                          {
                    (yyval.node) = new node(opType::DIV, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 2016 "limbaj.tab.c"
    break;

  case 81: /* expression: expression "<" expression  */
#line 480 "limbaj.y"
                                          {
                    (yyval.node) = new node(opType::LE, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 2024 "limbaj.tab.c"
    break;

  case 82: /* expression: expression ">" expression  */
#line 483 "limbaj.y"
                                          {
                    (yyval.node) = new node(opType::GE, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 2032 "limbaj.tab.c"
    break;

  case 83: /* expression: expression "<=" expression  */
#line 486 "limbaj.y"
                                           {
                    (yyval.node) = new node(opType::LEQ, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 2040 "limbaj.tab.c"
    break;

  case 84: /* expression: expression ">=" expression  */
#line 489 "limbaj.y"
                                           {
                    (yyval.node) = new node(opType::GEQ, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 2048 "limbaj.tab.c"
    break;

  case 85: /* expression: expression "==" expression  */
#line 492 "limbaj.y"
                                           {
                    (yyval.node) = new node(opType::EQU, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 2056 "limbaj.tab.c"
    break;

  case 86: /* expression: expression "!=" expression  */
#line 495 "limbaj.y"
                                           {
                    (yyval.node) = new node(opType::NEQ, (yyvsp[-2].node), (yyvsp[0].node));
               }
#line 2064 "limbaj.tab.c"
    break;

  case 87: /* expression: "!" expression  */
#line 498 "limbaj.y"
                               {
                    (yyval.node) = new node(opType::NOT, (yyvsp[0].node), nullptr);
               }
#line 2072 "limbaj.tab.c"
    break;

  case 88: /* expression: '(' expression ')'  */
#line 501 "limbaj.y"
                                   {
                    (yyval.node) = (yyvsp[-1].node);
               }
#line 2080 "limbaj.tab.c"
    break;

  case 89: /* expression: "-" expression  */
#line 504 "limbaj.y"
                                            {
                    (yyval.node) = new node(opType::UMIN, (yyvsp[0].node), nullptr);
               }
#line 2088 "limbaj.tab.c"
    break;

  case 90: /* expression: NR  */
#line 507 "limbaj.y"
                   {
                    (yyval.node) = new node((yyvsp[0].integer_value));    
               }
#line 2096 "limbaj.tab.c"
    break;

  case 91: /* expression: FLT  */
#line 510 "limbaj.y"
                    {     
                    (yyval.node) = new node((yyvsp[0].float_value));
               }
#line 2104 "limbaj.tab.c"
    break;

  case 92: /* expression: BOO  */
#line 513 "limbaj.y"
                    {     
                    (yyval.node) = new node((yyvsp[0].bool_value));
               }
#line 2112 "limbaj.tab.c"
    break;

  case 93: /* expression: CHR  */
#line 516 "limbaj.y"
                    {     
                    (yyval.node) = new node((yyvsp[0].char_value));
               }
#line 2120 "limbaj.tab.c"
    break;

  case 94: /* expression: STR  */
#line 519 "limbaj.y"
                    {     
                    (yyval.node) = new node((yyvsp[0].string));
               }
#line 2128 "limbaj.tab.c"
    break;

  case 95: /* expression: ID  */
#line 522 "limbaj.y"
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
#line 2193 "limbaj.tab.c"
    break;

  case 96: /* expression: ID '[' NR ']'  */
#line 582 "limbaj.y"
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
#line 2260 "limbaj.tab.c"
    break;

  case 97: /* expression: ID '[' NR ']' '[' NR ']'  */
#line 644 "limbaj.y"
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
#line 2326 "limbaj.tab.c"
    break;

  case 98: /* expression: ID '(' call_list ')'  */
#line 705 "limbaj.y"
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
#line 2363 "limbaj.tab.c"
    break;

  case 99: /* expression: ID '(' ')'  */
#line 737 "limbaj.y"
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
#line 2399 "limbaj.tab.c"
    break;

  case 100: /* dimension: '[' NR ']' dimension  */
#line 770 "limbaj.y"
                                 {
                    dimensionContainer.push_back((yyvsp[-2].integer_value));
                    }
#line 2407 "limbaj.tab.c"
    break;

  case 101: /* dimension: '[' NR ']'  */
#line 773 "limbaj.y"
                       {
                    dimensionContainer.push_back((yyvsp[-1].integer_value));
                    }
#line 2415 "limbaj.tab.c"
    break;

  case 102: /* array_value: expression  */
#line 778 "limbaj.y"
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
#line 2476 "limbaj.tab.c"
    break;

  case 105: /* param: TYPE ID  */
#line 858 "limbaj.y"
               { ids.addVar((yyvsp[-1].string),(yyvsp[0].string),currScope,false,false); IdInfo arg; arg.type=string((yyvsp[-1].string)); arg.name=string((yyvsp[0].string)); arg.scopeId=currScope; params.push_back(arg);}
#line 2482 "limbaj.tab.c"
    break;

  case 117: /* call_function: ID '(' call_list ')'  */
#line 879 "limbaj.y"
                                     {if(!functions.existsFuncCall((yyvsp[-3].string), params)){
                              yyerror("[parser]: Function does not exist\n");
                              YYERROR;
                         }
                         params.clear();
                         }
#line 2493 "limbaj.tab.c"
    break;

  case 118: /* call_function: ID '(' ')'  */
#line 885 "limbaj.y"
                             {if(!functions.existsFuncCall((yyvsp[-2].string), params)){
                              yyerror("[parser]: Function does not exist\n");
                              YYERROR;
                         }
                         params.clear();
                         }
#line 2504 "limbaj.tab.c"
    break;

  case 119: /* eval_stmt: EVAL '(' expression ')'  */
#line 892 "limbaj.y"
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
#line 2540 "limbaj.tab.c"
    break;

  case 120: /* typeOf_stmt: TOF '(' expression ')'  */
#line 923 "limbaj.y"
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
#line 2576 "limbaj.tab.c"
    break;

  case 121: /* call_list: NR  */
#line 954 "limbaj.y"
               {IdInfo arg; arg.type=string("int"); arg.name=string(""); arg.value.iVal=(yyvsp[0].integer_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2582 "limbaj.tab.c"
    break;

  case 122: /* call_list: call_list ',' NR  */
#line 955 "limbaj.y"
                              {IdInfo arg; arg.type=string("int"); arg.name=string(""); arg.value.iVal=(yyvsp[0].integer_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2588 "limbaj.tab.c"
    break;

  case 123: /* call_list: FLT  */
#line 956 "limbaj.y"
                 {IdInfo arg; arg.type=string("float"); arg.name=string(""); arg.value.fVal=(yyvsp[0].float_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2594 "limbaj.tab.c"
    break;

  case 124: /* call_list: call_list ',' FLT  */
#line 957 "limbaj.y"
                               {IdInfo arg; arg.type=string("float"); arg.name=string(""); arg.value.fVal=(yyvsp[0].float_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2600 "limbaj.tab.c"
    break;

  case 125: /* call_list: BOO  */
#line 958 "limbaj.y"
                 {IdInfo arg; arg.type=string("bool"); arg.name=string(""); arg.value.bVal=(yyvsp[0].bool_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2606 "limbaj.tab.c"
    break;

  case 126: /* call_list: call_list ',' BOO  */
#line 959 "limbaj.y"
                               {IdInfo arg; arg.type=string("bool"); arg.name=string(""); arg.value.bVal=(yyvsp[0].bool_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2612 "limbaj.tab.c"
    break;

  case 127: /* call_list: CHR  */
#line 960 "limbaj.y"
                 {IdInfo arg; arg.type=string("char"); arg.name=string(""); arg.value.cVal=(yyvsp[0].char_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2618 "limbaj.tab.c"
    break;

  case 128: /* call_list: call_list ',' CHR  */
#line 961 "limbaj.y"
                               {IdInfo arg; arg.type=string("char"); arg.name=string(""); arg.value.cVal=(yyvsp[0].char_value); arg.scopeId=currScope; params.push_back(arg);}
#line 2624 "limbaj.tab.c"
    break;

  case 129: /* call_list: STR  */
#line 962 "limbaj.y"
                 {IdInfo arg; arg.type=string("string"); arg.name=string(""); arg.value.sVal=strdup((yyvsp[0].string)); arg.scopeId=currScope; params.push_back(arg);}
#line 2630 "limbaj.tab.c"
    break;

  case 130: /* call_list: call_list ',' STR  */
#line 963 "limbaj.y"
                               {IdInfo arg; arg.type=string("string"); arg.name=string(""); arg.value.sVal=strdup((yyvsp[0].string)); arg.scopeId=currScope; params.push_back(arg);}
#line 2636 "limbaj.tab.c"
    break;

  case 131: /* call_list: ID  */
#line 964 "limbaj.y"
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
#line 2665 "limbaj.tab.c"
    break;

  case 132: /* call_list: call_list ',' ID  */
#line 988 "limbaj.y"
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
#line 2693 "limbaj.tab.c"
    break;

  case 133: /* class_decl: CLASS ID OPENBRK in_class_decl CLOSEDBRK ';'  */
#line 1012 "limbaj.y"
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
#line 2710 "limbaj.tab.c"
    break;

  case 134: /* class_decl: CLASS ID OPENBRK in_class_decl CLOSEDBRK  */
#line 1024 "limbaj.y"
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
#line 2727 "limbaj.tab.c"
    break;

  case 137: /* var_class_decl: TYPE ID  */
#line 1041 "limbaj.y"
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
#line 2751 "limbaj.tab.c"
    break;

  case 138: /* var_class_decl: CONST TYPE ID  */
#line 1060 "limbaj.y"
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
#line 2775 "limbaj.tab.c"
    break;

  case 139: /* var_class_decl: TYPE ID dimension  */
#line 1079 "limbaj.y"
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
#line 2808 "limbaj.tab.c"
    break;

  case 142: /* objects: NEW ID ID  */
#line 1111 "limbaj.y"
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
#line 2826 "limbaj.tab.c"
    break;

  case 143: /* $@16: %empty  */
#line 1124 "limbaj.y"
                     {incrementScope(); flag_func=1;}
#line 2832 "limbaj.tab.c"
    break;

  case 144: /* methods: TYPE ID '(' $@16 list_param ')' OPENBRK f_declarations RETURN ret ';' CLOSEDBRK  */
#line 1124 "limbaj.y"
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
#line 2860 "limbaj.tab.c"
    break;

  case 145: /* $@17: %empty  */
#line 1147 "limbaj.y"
                           {incrementScope();flag_func=1;}
#line 2866 "limbaj.tab.c"
    break;

  case 146: /* methods: TYPE ID '(' ')' OPENBRK $@17 f_declarations RETURN ret ';' CLOSEDBRK  */
#line 1147 "limbaj.y"
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
#line 2893 "limbaj.tab.c"
    break;

  case 147: /* $@18: %empty  */
#line 1169 "limbaj.y"
              {incrementScope();flag_func=1;}
#line 2899 "limbaj.tab.c"
    break;

  case 148: /* $@19: %empty  */
#line 1169 "limbaj.y"
                                                                                    {decrementScope();}
#line 2905 "limbaj.tab.c"
    break;

  case 149: /* methods: VOID ID '(' $@18 list_param ')' OPENBRK f_declarations $@19 CLOSEDBRK  */
#line 1169 "limbaj.y"
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
#line 2930 "limbaj.tab.c"
    break;

  case 150: /* $@20: %empty  */
#line 1189 "limbaj.y"
                         {incrementScope();flag_func=1;}
#line 2936 "limbaj.tab.c"
    break;

  case 151: /* $@21: %empty  */
#line 1189 "limbaj.y"
                                                                        {decrementScope();}
#line 2942 "limbaj.tab.c"
    break;

  case 152: /* methods: VOID ID '(' ')' OPENBRK $@20 f_declarations $@21 CLOSEDBRK  */
#line 1189 "limbaj.y"
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
#line 2967 "limbaj.tab.c"
    break;

  case 153: /* obj_field: ID '.' ID  */
#line 1210 "limbaj.y"
                     {
     if(!all_obj_class.existsObject((yyvsp[-2].string))){
          yyerror("[parser]: Object does not exist\n");
          YYERROR;
     }
     else {
          bool ok=false;
          for(auto f:all_obj_class.getObject((yyvsp[-2].string))->fields){
               if(f.name == (yyvsp[0].string)){
                    ok=true;
                    break;
               }
          }
          if(!ok){
          yyerror("[parser]: Field does not exist\n");
          YYERROR;
          }    
     }
}
#line 2991 "limbaj.tab.c"
    break;

  case 154: /* obj_field: ID '.' ID '(' call_list ')'  */
#line 1229 "limbaj.y"
                              {
     if(!all_obj_class.existsObject((yyvsp[-5].string))){
          yyerror("[parser]: Object does not exist\n");
          YYERROR;
     }
     else {
          bool ok=false;
          for(auto m:all_obj_class.getObject((yyvsp[-5].string))->methods){
               if(m.name == (yyvsp[-3].string)){
                    ok=true;  
                    if(m.param.size() != params.size()){
                         yyerror("[parser]: Wrong number of parameters\n");
                         YYERROR;
                    }
                    else{
                         for(int i=0;i<m.param.size();i++){
                              if(m.param[i].type != params[i].type){
                                   yyerror("[parser]: Wrong parameter type\n");
                                   YYERROR;
                              }
                         }
                    }
                    break;
               }
          }
          if(!ok){
          yyerror("[parser]: Method does not exist\n");
          YYERROR;
          } 
     }
     params.clear();
}
#line 3028 "limbaj.tab.c"
    break;

  case 155: /* obj_field: ID '.' ID '(' ')'  */
#line 1261 "limbaj.y"
                   {
     if(!all_obj_class.existsObject((yyvsp[-4].string))){
          yyerror("[parser]: Object does not exist\n");
          YYERROR;
     }
     else {
          bool ok=false;
          for(auto m:all_obj_class.getObject((yyvsp[-4].string))->methods){
               if(m.name == (yyvsp[-2].string)){
                    ok=true;
                    if(m.param.size() != params.size()){
                         yyerror("[parser]: Wrong number of parameters\n");
                         YYERROR;
                    }
                    break;
               }
          }
          if(!ok){
          yyerror("[parser]: Method does not exist\n");
          YYERROR;
          } 
     }
     params.clear();
}
#line 3057 "limbaj.tab.c"
    break;


#line 3061 "limbaj.tab.c"

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

#line 1286 "limbaj.y"

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
