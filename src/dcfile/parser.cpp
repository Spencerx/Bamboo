/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:339  */

	#include "lex.h"
	#include "parse.h"

	#include <unistd.h>
	#include <stdint.h> // for fixed-width integer limits
	#include <math.h>   // for float-macro INFINITY
	#include <stack>    // std::stack
	#include <fstream>  // std::ifstream
	#include <sstream>  // std::stringstream

	#include "dcfile/token.h"
	#include "dcfile/parser-defs.h"
	#include "dcfile/write.h"           // format_type(Subtype);
	#include "module/Module.h"
	#include "module/DistributedType.h"
	#include "module/NumericRange.h"
	#include "module/NumericType.h"
	#include "module/ArrayType.h"
	#include "module/Struct.h"
	#include "module/Class.h"
	#include "module/Field.h"
	#include "module/Method.h"
	#include "module/Parameter.h"
	#include "module/MolecularField.h"
	#include "traits/buffers.h"

	#define yylex dclex
	#define yyparse dcparse
	#define yyerror dcerror
	#define yywarning dcwarning
	#define yychar dcyychar
	#define yydebug dcyydebug
	#define yynerrs dcyynerrs

	// Because our token type contains objects of type string, which
	// require correct copy construction (and not simply memcpying), we
	// cannot use bison's built-in autTo-stack-grow feature.  As an easy
	// solution, we ensure here that we have enough yacc stack to start
	// with, and that it doesn't ever try to grow.
	#define YYINITDEPTH 1000
	#define YYMAXDEPTH 1000

	using namespace std;
	namespace bamboo   // open namespace bamboo
	{


	// Parser output
	static Module* parsed_module = nullptr;
	static vector<uint8_t>* parsed_value = nullptr;

	// Parser state
	static Class* current_class = nullptr;
	static Struct* current_struct = nullptr;

	// Stack of distributed types for parsing values
	struct TypeAndDepth
	{
		int depth;
		const DistributedType* type;
		TypeAndDepth(const DistributedType* t, int d) : depth(d), type(t) {}
	};
	static stack<TypeAndDepth> type_stack;
	static int current_depth;

	// These two types are really common types the parser doesn't need to make new
	//     duplicates of every time a string or blob is used.
	static ArrayType* basic_string = nullptr;
	static ArrayType* basic_blob = nullptr;

	/* Helper functions */
	static bool check_depth();
	static void depth_error(string what);
	static void depth_error(int depth, string what);
	static vector<uint8_t> number_value(Subtype type, double &number);
	static vector<uint8_t> number_value(Subtype type, int64_t &number);
	static vector<uint8_t> number_value(Subtype type, uint64_t &number);

////////////////////////////////////////////////////////////////////
// Defining the interface to the parser.
////////////////////////////////////////////////////////////////////

	static void dcparser_file(istream& in, const string& filename, Module& module)
	{
		parsed_module = &module;
		dclexer_init(in, filename, STARkTypeDC_FILE);
	}

	static void dcparser_value(istream& in, const string& source,
	                           const DistributedType* type, vector<uint8_t>& output)
	{
		parsed_value = &output;
		current_depth = 0;
		type_stack.push(TypeAndDepth(type, 0));
		dclexer_init(in, source, STARkTypeDC_VALUE);
	}

	static void dcparser_cleanup()
	{
		current_depth = 0;
		type_stack = stack<TypeAndDepth>();
		parsed_module = nullptr;
		parsed_value = nullptr;
	}


#line 174 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser-defs.h".  */
#ifndef YY_YY_MEDIA_STORAGE_DEVEL_GIT_ASTRON_BAMBOO_SRC_DCFILE_PARSER_DEFS_H_INCLUDED
# define YY_YY_MEDIA_STORAGE_DEVEL_GIT_ASTRON_BAMBOO_SRC_DCFILE_PARSER_DEFS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    UNSIGNED_INTEGER = 258,
    REAL = 259,
    STRING = 260,
    HEX_STRING = 261,
    IDENTIFIER = 262,
    CHAR = 263,
    STARkTypeDC_FILE = 264,
    STARkTypeDC_VALUE = 265,
    KW_DCLASS = 266,
    KW_STRUCT = 267,
    KW_FROM = 268,
    KW_IMPORT = 269,
    KW_TYPEDEF = 270,
    KW_KEYWORD = 271,
    KW_INT8 = 272,
    KW_INT16 = 273,
    KW_INT32 = 274,
    KW_INT64 = 275,
    KW_UINT8 = 276,
    KW_UINT16 = 277,
    KW_UINT32 = 278,
    KW_UINT64 = 279,
    KW_FLOAT32 = 280,
    KW_FLOAT64 = 281,
    KW_STRING = 282,
    KW_BLOB = 283,
    KW_CHAR = 284
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MEDIA_STORAGE_DEVEL_GIT_ASTRON_BAMBOO_SRC_DCFILE_PARSER_DEFS_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 250 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   261

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  170
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    43,     2,     2,
      41,    42,    32,    45,    33,    44,    31,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    30,
       2,    40,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   215,   215,   216,   221,   222,   223,   224,   225,   226,
     230,   234,   238,   243,   251,   256,   265,   266,   273,   274,
     281,   285,   293,   294,   301,   346,   350,   358,   368,   383,
     387,   388,   396,   395,   435,   436,   440,   447,   457,   488,
     489,   490,   528,   552,   560,   559,   599,   600,   601,   635,
     636,   640,   641,   642,   643,   647,   652,   651,   666,   673,
     678,   687,   686,   698,   697,   709,   708,   722,   729,   730,
     734,   752,   756,   760,   764,   768,   772,   779,   805,   837,
     859,   887,   910,   911,   912,   913,   917,   921,   930,   939,
     951,   963,   970,   980,   984,   991,  1001,  1014,  1015,  1016,
    1017,  1022,  1021,  1035,  1042,  1047,  1056,  1055,  1067,  1066,
    1080,  1081,  1082,  1086,  1087,  1088,  1092,  1104,  1108,  1121,
    1122,  1123,  1127,  1136,  1140,  1154,  1168,  1182,  1214,  1241,
    1242,  1247,  1246,  1283,  1284,  1294,  1293,  1330,  1331,  1332,
    1338,  1347,  1384,  1383,  1445,  1447,  1446,  1469,  1474,  1493,
    1512,  1531,  1577,  1626,  1627,  1631,  1632,  1636,  1637,  1638,
    1639,  1640,  1641,  1642,  1643,  1644,  1645,  1646,  1650,  1654,
    1667
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "UNSIGNED_INTEGER", "REAL", "STRING",
  "HEX_STRING", "IDENTIFIER", "CHAR", "STARkTypeDC_FILE",
  "STARkTypeDC_VALUE", "KW_DCLASS", "KW_STRUCT", "KW_FROM", "KW_IMPORT",
  "KW_TYPEDEF", "KW_KEYWORD", "KW_INT8", "KW_INT16", "KW_INT32",
  "KW_INT64", "KW_UINT8", "KW_UINT16", "KW_UINT32", "KW_UINT64",
  "KW_FLOAT32", "KW_FLOAT64", "KW_STRING", "KW_BLOB", "KW_CHAR", "';'",
  "'.'", "'*'", "','", "'/'", "'['", "']'", "'{'", "'}'", "':'", "'='",
  "'('", "')'", "'%'", "'-'", "'+'", "$accept", "grammar", "file", "value",
  "import", "import_module", "import_symbols", "import_symbol_list",
  "import_alternatives", "typedef", "typedef_type",
  "nonmethod_type_with_name", "defined_type", "keyword_decl",
  "keyword_decl_list", "dclass", "$@1", "class_inheritance",
  "class_parents", "defined_class", "class_fields", "class_field",
  "dstruct", "$@2", "struct_fields", "struct_field", "named_field",
  "unnamed_field", "$@3", "field_with_name", "field_with_name_as_array",
  "field_with_name_and_default", "$@4", "$@5", "$@6", "method_as_field",
  "nonmethod_type", "nonmethod_type_no_array", "type_with_array",
  "molecular", "defined_field", "builtin_array_type", "numeric_type",
  "numeric_token_only", "numeric_with_range", "numeric_with_modulus",
  "numeric_with_divisor", "method", "method_body", "parameter", "$@7",
  "param_with_name", "param_with_name_as_array",
  "param_with_name_and_default", "$@8", "$@9", "numeric_range",
  "array_range", "char_or_uint", "small_unsigned_integer", "number",
  "char_or_number", "type_value", "method_value", "$@10",
  "parameter_values", "struct_value", "$@11", "field_values",
  "array_value", "$@12", "element_values", "$@13", "array_expansion",
  "signed_integer", "array_type_token", "numeric_type_token",
  "keyword_list", "empty", YY_NULLPTR
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
      59,    46,    42,    44,    47,    91,    93,   123,   125,    58,
      61,    40,    41,    37,    45,    43
};
# endif

#define YYPACT_NINF -196

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-196)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,  -196,    13,    32,    96,  -196,  -196,  -196,  -196,  -196,
       5,  -196,  -196,    73,    79,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,    76,   107,   108,   108,   218,  -196,  -196,
    -196,  -196,    51,  -196,  -196,  -196,  -196,    18,    13,    40,
    -196,  -196,  -196,  -196,  -196,    21,    63,    69,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,    68,   109,  -196,    82,    88,    89,    -1,
    -196,    31,    94,    95,  -196,   124,  -196,    93,   102,   105,
     110,   111,  -196,    28,  -196,   114,  -196,  -196,    66,  -196,
     -13,   100,   103,    24,   108,   134,    93,  -196,    93,    93,
      93,   144,    22,    35,   144,    22,    22,    93,  -196,  -196,
    -196,   112,   106,  -196,  -196,   144,   144,   144,   144,  -196,
    -196,   144,    13,  -196,    40,  -196,   142,   115,  -196,  -196,
    -196,  -196,   136,    63,    63,  -196,   131,   138,   139,   140,
    -196,  -196,  -196,  -196,   128,  -196,   129,  -196,  -196,  -196,
    -196,   130,   135,   153,  -196,    93,  -196,  -196,  -196,  -196,
      18,  -196,  -196,  -196,  -196,  -196,   145,  -196,  -196,   164,
    -196,   108,  -196,  -196,  -196,  -196,  -196,    22,  -196,  -196,
    -196,  -196,  -196,   142,   189,  -196,   156,  -196,  -196,  -196,
     168,  -196,  -196,    78,    90,  -196,   159,    20,    63,  -196,
    -196,    10,  -196,  -196,   170,  -196,   171,   137,  -196,    26,
    -196,    93,  -196,    93,  -196,   160,  -196,   196,  -196,   213,
    -196,   196,  -196,   181,   215,  -196,    92,    98,  -196,   218,
    -196,   187,    40,   188,    40,  -196,    40,  -196,  -196,  -196,
    -196,  -196,  -196,    93,  -196,    93,  -196,  -196,  -196,  -196,
    -196,  -196,    40,  -196,    40,   190,    40,   192,    40,  -196,
    -196,  -196,  -196,  -196,  -196
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   170,   170,     0,     2,     4,   125,   126,   127,   128,
     142,   135,   131,     0,     0,     3,    12,    13,   130,   129,
     124,    11,     1,     0,     0,     0,     0,     0,   170,     5,
       8,     9,    24,    10,     6,     7,   141,     0,     0,     0,
     154,   153,    32,    44,    22,     0,    16,    14,    28,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   155,
     156,   157,    25,    70,     0,    68,    69,    72,    71,    82,
      85,    83,    84,    80,    86,    29,    30,   170,   125,   126,
     127,   128,   147,     0,   144,   124,   137,   138,     0,   133,
       0,   170,     0,     0,     0,     0,   170,    27,   170,   170,
     170,     0,   170,     0,     0,   170,   170,   170,    31,   118,
     116,     0,   114,   117,   113,     0,     0,     0,     0,   145,
     143,     0,     0,   136,     0,   132,     0,     0,    34,   170,
      19,    15,    18,    20,    17,    23,     0,     0,     0,     0,
      91,   119,   121,   122,     0,   123,   111,   120,   110,    90,
      92,     0,     0,     0,    26,     0,   149,   150,   151,   152,
       0,   148,   139,   140,   134,    38,    35,    36,   170,     0,
      46,     0,    74,    76,    75,    73,    87,     0,    88,    89,
      81,   115,   146,     0,     0,    39,    28,    47,    45,    58,
       0,    49,    50,    51,    52,    53,    54,    55,    21,   112,
      37,    28,    40,    33,     0,   170,    43,     0,    67,     0,
      48,   170,    61,   170,    63,     0,    56,     0,    41,    42,
     168,     0,    93,   100,    68,    95,    97,    98,    99,     0,
      94,     0,     0,     0,     0,    65,     0,    79,    77,   169,
      78,   101,   103,   170,   106,   170,   108,    96,    59,    62,
      60,    64,     0,    57,     0,     0,     0,     0,     0,    66,
     102,   104,   107,   105,   109
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,  -196,  -196,  -196,   203,  -196,  -196,   -83,  -196,
    -196,   204,  -196,  -196,  -196,  -196,  -196,  -196,  -196,    50,
    -196,  -196,  -196,  -196,  -196,  -196,    64,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -160,  -195,  -196,  -196,
      30,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,    29,
    -196,  -196,  -196,  -196,  -196,  -196,   -16,   -92,   104,   -23,
     146,    80,    -2,   -35,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,   101,   -32,  -196,  -196,  -196,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    15,    30,    45,   131,   132,    46,    31,
      32,   189,    63,    33,    75,    34,    91,   127,   166,   167,
     184,   204,    35,    92,   169,   190,   191,   192,   236,   193,
     194,   195,   232,   234,   252,   196,    64,    65,    66,   206,
     238,    67,    68,    69,    70,    71,    72,   208,   209,   225,
     254,   226,   227,   228,   256,   258,   144,   111,   112,   113,
     145,   146,    82,    17,    39,    90,    18,    38,    88,    19,
      37,    83,   160,    84,    20,    73,    74,   219,   114
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      16,     5,    21,    87,   136,    85,   137,   138,   139,   197,
     133,   134,   224,     1,     2,   153,     6,     7,     8,     9,
     124,    78,    79,    80,    81,   141,   142,    97,    76,   125,
     143,    44,    22,   101,   224,    93,    86,    89,   141,   142,
     102,    36,   103,     6,     7,     8,     9,   223,    10,   217,
      11,   207,    94,    10,    12,    11,   130,    13,    14,   229,
     216,   119,    13,    14,   120,   104,    13,    14,   230,   223,
     147,   147,   105,   147,   147,    10,    40,    11,   140,    13,
      14,   150,    41,    42,    13,    14,    77,   163,   198,   151,
     152,   128,   156,   157,   158,   159,   109,    95,   161,   122,
      94,   110,   148,    96,   123,   148,   148,    23,    24,    25,
      26,    27,    28,   211,    43,    44,    97,    98,   212,   231,
     162,   233,   164,    99,   100,   213,    29,   243,    85,   170,
     214,   108,   244,   245,   115,   106,   107,   116,   246,   126,
     129,   135,   117,   118,    48,   147,   121,   109,   154,   165,
     155,   255,   168,   257,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   172,   185,   171,
     176,   186,   178,   177,   173,   174,   175,   179,   183,   222,
     235,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,   187,   180,   201,   207,   210,   215,
     218,    12,   188,   237,   221,   220,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   202,
     239,   241,   242,   248,   250,    48,   261,   203,   263,    47,
     249,    62,   251,   200,   253,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,   205,   149,
     259,   240,   260,     0,   262,     0,   264,   199,   247,   181,
       0,   182
};

static const yytype_int16 yycheck[] =
{
       2,     1,     2,    38,    96,    37,    98,    99,   100,   169,
      93,    94,   207,     9,    10,   107,     3,     4,     5,     6,
      33,     3,     4,     5,     6,     3,     4,     7,    28,    42,
       8,     7,     0,    34,   229,    14,    38,    39,     3,     4,
      41,    36,    43,     3,     4,     5,     6,   207,    35,    39,
      37,    41,    31,    35,    41,    37,    32,    44,    45,    33,
      40,    33,    44,    45,    36,    34,    44,    45,    42,   229,
     102,   103,    41,   105,   106,    35,     3,    37,   101,    44,
      45,   104,     3,     7,    44,    45,    35,   122,   171,   105,
     106,    91,   115,   116,   117,   118,     3,    34,   121,    33,
      31,     8,   102,    35,    38,   105,   106,    11,    12,    13,
      14,    15,    16,    35,     7,     7,     7,    35,    40,   211,
     122,   213,   124,    35,    35,    35,    30,    35,   160,   129,
      40,     7,    40,    35,    32,    41,    41,    32,    40,    39,
      37,     7,    32,    32,     7,   177,    32,     3,    36,     7,
      44,   243,    37,   245,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    36,   168,    33,
      42,     7,    42,    44,    36,    36,    36,    42,    33,    42,
     215,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    42,     7,    41,    30,    40,
      30,    41,    38,     7,    33,   205,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       7,    40,     7,    36,    36,     7,    36,    38,    36,    26,
     232,    27,   234,   183,   236,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,   184,   103,
     252,   221,   254,    -1,   256,    -1,   258,   177,   229,   155,
      -1,   160
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    10,    47,    48,   124,     3,     4,     5,     6,
      35,    37,    41,    44,    45,    49,   108,   109,   112,   115,
     120,   124,     0,    11,    12,    13,    14,    15,    16,    30,
      50,    55,    56,    59,    61,    68,    36,   116,   113,   110,
       3,     3,     7,     7,     7,    51,    54,    51,     7,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    57,    58,    82,    83,    84,    87,    88,    89,
      90,    91,    92,   121,   122,    60,   124,    35,     3,     4,
       5,     6,   108,   117,   119,   120,   108,   109,   114,   108,
     111,    62,    69,    14,    31,    34,    35,     7,    35,    35,
      35,    34,    41,    43,    34,    41,    41,    41,     7,     3,
       8,   103,   104,   105,   124,    32,    32,    32,    32,    33,
      36,    32,    33,    38,    33,    42,    39,    63,   124,    37,
      32,    52,    53,    54,    54,     7,   103,   103,   103,   103,
     105,     3,     4,     8,   102,   106,   107,   120,   124,   106,
     105,   102,   102,   103,    36,    44,   105,   105,   105,   105,
     118,   105,   108,   109,   108,     7,    64,    65,    37,    70,
     124,    33,    36,    36,    36,    36,    42,    44,    42,    42,
      42,   104,   119,    33,    66,   124,     7,    30,    38,    57,
      71,    72,    73,    75,    76,    77,    81,    82,    54,   107,
      65,     7,    30,    38,    67,    72,    85,    41,    93,    94,
      30,    35,    40,    35,    40,    40,    40,    39,    30,   123,
     124,    33,    42,    82,    83,    95,    97,    98,    99,    33,
      42,   103,    78,   103,    79,   109,    74,     7,    86,     7,
      86,    40,     7,    35,    40,    35,    40,    95,    36,   108,
      36,   108,    80,   108,    96,   103,   100,   103,   101,   108,
     108,    36,   108,    36,   108
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    49,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    56,    56,    57,    58,    59,
      60,    60,    62,    61,    63,    63,    64,    64,    65,    66,
      66,    66,    67,    67,    69,    68,    70,    70,    70,    71,
      71,    72,    72,    72,    72,    73,    74,    73,    75,    76,
      76,    78,    77,    79,    77,    80,    77,    81,    82,    82,
      83,    83,    83,    84,    84,    84,    84,    85,    85,    86,
      87,    87,    88,    88,    88,    88,    89,    90,    90,    90,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    95,
      95,    96,    95,    97,    98,    98,   100,    99,   101,    99,
     102,   102,   102,   103,   103,   103,   104,   104,   105,   106,
     106,   106,   107,   107,   108,   108,   108,   108,   108,   108,
     108,   110,   109,   111,   111,   113,   112,   114,   114,   114,
     114,   115,   116,   115,   117,   118,   117,   119,   119,   119,
     119,   119,   119,   120,   120,   121,   121,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   123,   123,
     124
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     2,     4,     1,     3,     1,     1,
       1,     3,     1,     3,     1,     2,     4,     2,     1,     2,
       1,     2,     0,     7,     1,     2,     1,     3,     1,     1,
       2,     3,     2,     1,     0,     6,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     1,     4,
       4,     0,     4,     0,     4,     0,     5,     2,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     3,     3,     1,
       1,     4,     1,     1,     1,     1,     1,     4,     4,     4,
       3,     3,     3,     2,     2,     2,     3,     1,     1,     1,
       1,     0,     4,     2,     4,     4,     0,     4,     0,     4,
       1,     1,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     1,     3,     0,     4,     1,     1,     3,
       3,     2,     0,     4,     1,     0,     4,     1,     3,     3,
       3,     3,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0
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
        case 9:
#line 227 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {

	}
#line 1545 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 235 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		parsed_value->clear();
	}
#line 1553 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 239 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		parsed_value->assign((yyvsp[0].buffer).begin(), (yyvsp[0].buffer).end());
		if(!type_stack.empty()) depth_error(0, "type");
	}
#line 1562 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 244 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		parsed_value->assign((yyvsp[0].buffer).begin(), (yyvsp[0].buffer).end());
		if(!type_stack.empty()) depth_error(0, "method");
	}
#line 1571 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 252 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		Import* import = new Import((yyvsp[0].str));
		parsed_module->add_import(import);
	}
#line 1580 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 257 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		Import* import = new Import((yyvsp[-2].str));
		import->symbols.assign((yyvsp[0].strings).begin(), (yyvsp[0].strings).end());
		parsed_module->add_import(import);
	}
#line 1590 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 265 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 1596 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 267 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.str) = (yyvsp[-2].str) + string(".") + (yyvsp[0].str);
	}
#line 1604 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 273 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.strings) = (yyvsp[0].strings); }
#line 1610 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 275 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.strings) = vector<string>();
	}
#line 1618 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 282 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.strings) = vector<string>(1, (yyvsp[0].str));
	}
#line 1626 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 286 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyvsp[-2].strings).push_back((yyvsp[0].str));
		(yyval.strings) = (yyvsp[-2].strings);
	}
#line 1635 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 293 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 1641 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 295 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.str) = (yyvsp[-2].str) + string("/") + (yyvsp[0].str);
	}
#line 1649 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 302 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].nametype).type == nullptr)
		{
			// Ignore this typedef, it should have already produced an error
			break;
		}

		// Set the type's typedef
		(yyvsp[0].nametype).type->set_alias((yyvsp[0].nametype).name);

		bool type_added	= parsed_module->add_typedef((yyvsp[0].nametype).name, (yyvsp[0].nametype).type);
		if(!type_added)
		{
			// Lets be really descriptive about why this failed
			DistributedType* dtype = parsed_module->get_type_by_name((yyvsp[0].nametype).name);
			if(dtype == nullptr)
			{
				dcerror("Unknown error adding typedef to module.");
				break;
			}

			Struct* dstruct = dtype->as_struct();
			if(dstruct == nullptr)
			{
				dcerror("Cannot add 'typedef " + (yyvsp[0].nametype).name
				             + "' to module because a typedef was already declared with that name.");
				break;
			}

			if(dstruct->as_class())
			{
				dcerror("Cannot add 'typedef " + (yyvsp[0].nametype).name
				             + "' to module because a class was already declared with that name.");
			}
			else
			{
				dcerror("Cannot add 'typedef " + (yyvsp[0].nametype).name
				             + "' to module because a struct was already declared with that name.");
			}
		}
	}
#line 1695 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 347 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.nametype) = (yyvsp[0].nametype);
	}
#line 1703 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 351 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.nametype) = (yyvsp[-3].nametype);
		(yyval.nametype).type = new ArrayType((yyvsp[-3].nametype).type, (yyvsp[-1].range));
	}
#line 1712 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 359 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		DCToken::NameType nt;
		nt.type = (yyvsp[-1].dtype);
		nt.name = (yyvsp[0].str);
		(yyval.nametype) = nt;
	}
#line 1723 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 369 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		DistributedType* dtype = parsed_module->get_type_by_name((yyvsp[0].str));
		if(dtype == nullptr)
		{
			dcerror("Subtype '" + string((yyvsp[0].str)) + "' has not been declared.");
			(yyval.dtype) = nullptr;
			break;
		}

		(yyval.dtype) = dtype;
	}
#line 1739 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 389 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		parsed_module->add_keyword((yyvsp[0].str));
	}
#line 1747 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 396 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		current_class = new Class(parsed_module, (yyvsp[0].str));
	}
#line 1755 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 400 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		bool class_added = parsed_module->add_class(current_class);
		if(!class_added)
		{
			// Lets be really descriptive about why this failed
			DistributedType* dtype = parsed_module->get_type_by_name(current_class->get_name());
			if(dtype == nullptr)
			{
				dcerror("Unknown error adding class to module.");
				break;
			}

			Struct* dstruct = dtype->as_struct();
			if(dstruct == nullptr)
			{
				dcerror("Cannot add 'dclass " + current_class->get_name()
				             + "' to module because a typedef was already declared with that name.");
				break;
			}

			if(dstruct->as_class())
			{
				dcerror("Cannot add 'dclass " + current_class->get_name()
				             + "' to module because a class was already declared with that name.");
			}
			else
			{
				dcerror("Cannot add 'dclass " + current_class->get_name()
				             + "' to module because a struct was already declared with that name.");
			}
		}
	}
#line 1792 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 441 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].dclass) != nullptr)
		{
			current_class->add_parent((yyvsp[0].dclass));
		}
	}
#line 1803 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 448 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].dclass) != nullptr)
		{
			current_class->add_parent((yyvsp[0].dclass));
		}
	}
#line 1814 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 458 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		DistributedType* dtype = parsed_module->get_type_by_name((yyvsp[0].str));
		if(dtype == nullptr)
		{
			dcerror("'dclass " + string((yyvsp[0].str)) + "' has not been declared.");
			(yyval.dclass) = nullptr;
			break;
		}

		Struct* dstruct = dtype->as_struct();
		if(dstruct == nullptr)
		{
			dcerror("class cannot inherit from non-class type '" + string((yyvsp[0].str)) + "'.");
			(yyval.dclass) = nullptr;
			break;
		}

		Class* dclass = dstruct->as_class();
		if(dclass == nullptr)
		{
			dcerror("class cannot inherit from struct type '" + string((yyvsp[0].str)) + "'.");
			(yyval.dclass) = nullptr;
			break;
		}

		(yyval.dclass) = dclass;
	}
#line 1846 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 491 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[-1].dfield) == nullptr)
		{
			// Ignore this field, it should have already generated a parser error
			break;
		}

		bool field_added = current_class->add_field((yyvsp[-1].dfield));
		if(!field_added)
		{
			// Lets be really descriptive about why this failed
			if(current_class->get_field_by_name((yyvsp[-1].dfield)->get_name()))
			{
				dcerror("Cannot add field '" + (yyvsp[-1].dfield)->get_name()
				             + "', a field with that name already exists in 'dclass "
				             + current_class->get_name() + "'.");
			}
			else if(current_class->get_name() == (yyvsp[-1].dfield)->get_name())
			{
				if((yyvsp[-1].dfield)->as_molecular())
				{
					dcerror("Cannot use a molecular field as a constructor.");
				}
				else
				{
					dcerror("The constructor must be the first field in the class.");
				}
			}
			else
			{
				dcerror("Unknown error adding field to class.");
			}
		}
	}
#line 1885 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 529 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[-1].dfield) == nullptr)
		{
			// Ignore this field, it should have already generated a parser error
			(yyval.dfield) = nullptr;
			break;
		}

		if((yyvsp[-1].dfield)->get_name().empty())
		{
			dcerror("An unnamed field can't be defined in a class.");
			(yyval.dfield) = nullptr;
			break;
		}

		// Add the keywords to the class
		for(auto it = (yyvsp[0].strings).begin(); it != (yyvsp[0].strings).end(); ++it)
		{
			(yyvsp[-1].dfield)->add_keyword(*it);
		}

		(yyval.dfield) = (yyvsp[-1].dfield);
	}
#line 1913 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 553 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.dfield) = (Field*)(yyvsp[0].dmolecule);
	}
#line 1921 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 560 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		current_struct = new Struct(parsed_module, (yyvsp[0].str));
	}
#line 1929 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 564 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		bool struct_added = parsed_module->add_struct(current_struct);
		if(!struct_added)
		{
			// Lets be really descriptive about why this failed
			DistributedType* dtype = parsed_module->get_type_by_name(current_struct->get_name());
			if(dtype == nullptr)
			{
				dcerror("Unknown error adding struct to module.");
				break;
			}

			Struct* dstruct = dtype->as_struct();
			if(dstruct == nullptr)
			{
				dcerror("Cannot add 'struct " + current_struct->get_name()
				             + "' to module because a typedef was already declared with that name.");
				break;
			}

			if(dstruct->as_class())
			{
				dcerror("Cannot add 'struct " + current_struct->get_name()
				             + "' to module because a class was already declared with that name.");
			}
			else
			{
				dcerror("Cannot add 'struct " + current_struct->get_name()
				             + "' to module because a struct was already declared with that name.");
			}
		}
	}
#line 1966 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 602 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[-1].dfield) == nullptr || (yyvsp[-1].dfield)->get_type() == nullptr)
		{
			// Ignore this field, it should have already generated a parser error
			break;
		}

		if(!current_struct->add_field((yyvsp[-1].dfield)))
		{
			// Lets be really descriptive about why this failed
			if(current_struct->get_field_by_name((yyvsp[-1].dfield)->get_name()))
			{
				dcerror("Cannot add field '" + (yyvsp[-1].dfield)->get_name()
				             + "', a field with that name already exists in 'struct "
				             + current_struct->get_name() + "'.");
			}
			else if(current_struct->get_name() == (yyvsp[-1].dfield)->get_name())
			{
				dcerror("A constructor can't be defined in a struct.");
			}
			else if((yyvsp[-1].dfield)->get_type()->as_method())
			{
				dcerror("A method can't be defined in a struct.");
			}
			else
			{
				dcerror("Unknown error adding field to struct.");
			}
		}
	}
#line 2001 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 648 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.dfield) = new Field((yyvsp[0].dtype));
	}
#line 2009 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 652 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		current_depth = 0;
		type_stack.push(TypeAndDepth((yyvsp[-1].dtype), 0));
	}
#line 2018 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 657 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		Field* field = new Field((yyvsp[-3].dtype));
		if(!type_stack.empty()) depth_error(0, "unnamed field");
		field->set_default_value((yyvsp[0].buffer));
		(yyval.dfield) = field;
	}
#line 2029 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 667 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.dfield) = new Field((yyvsp[0].nametype).type, (yyvsp[0].nametype).name);
	}
#line 2037 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 674 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyvsp[-3].dfield)->set_type(new ArrayType((yyvsp[-3].dfield)->get_type(), (yyvsp[-1].range)));
		(yyval.dfield) = (yyvsp[-3].dfield);
	}
#line 2046 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 679 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyvsp[-3].dfield)->set_type(new ArrayType((yyvsp[-3].dfield)->get_type(), (yyvsp[-1].range)));
		(yyval.dfield) = (yyvsp[-3].dfield);
	}
#line 2055 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 687 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		current_depth = 0;
		type_stack.push(TypeAndDepth((yyvsp[-1].dfield)->get_type(), 0));
	}
#line 2064 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 692 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!type_stack.empty()) depth_error(0, "field '" + (yyvsp[-3].dfield)->get_name() + "'");
		(yyvsp[-3].dfield)->set_default_value((yyvsp[0].buffer));
		(yyval.dfield) = (yyvsp[-3].dfield);
	}
#line 2074 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 698 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		current_depth = 0;
		type_stack.push(TypeAndDepth((yyvsp[-1].dfield)->get_type(), 0));
	}
#line 2083 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 703 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!type_stack.empty()) depth_error(0, "field '" + (yyvsp[-3].dfield)->get_name() + "'");
		(yyvsp[-3].dfield)->set_default_value((yyvsp[0].buffer));
		(yyval.dfield) = (yyvsp[-3].dfield);
	}
#line 2093 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 709 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		current_depth = 0;
		type_stack.push(TypeAndDepth((yyvsp[-2].dfield)->get_type(), 0));
	}
#line 2102 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 714 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!type_stack.empty()) depth_error(0, "method");
		(yyvsp[-4].dfield)->set_default_value((yyvsp[-2].buffer));
		(yyval.dfield) = (yyvsp[-4].dfield);
	}
#line 2112 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 723 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.dfield) = new Field((yyvsp[0].dmethod), (yyvsp[-1].str));
	}
#line 2120 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 735 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].dtype) == nullptr)
		{
			// defined_type should have output an error, pass nullptr upstream
			(yyval.dtype) = nullptr;
			break;
		}

		if((yyvsp[0].dtype)->get_subtype() == kTypeMethod)
		{
			dcerror("Cannot use a method type here.");
			(yyval.dtype) = nullptr;
			break;
		}

		(yyval.dtype) = (yyvsp[0].dtype);
	}
#line 2142 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 753 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.dtype) = (DistributedType*)(yyvsp[0].dnumeric);
	}
#line 2150 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 761 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.dtype) = new ArrayType((yyvsp[-3].dnumeric), (yyvsp[-1].range));
	}
#line 2158 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 765 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.dtype) = new ArrayType((yyvsp[-3].dtype), (yyvsp[-1].range));
	}
#line 2166 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 769 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.dtype) = new ArrayType((yyvsp[-3].dtype), (yyvsp[-1].range));
	}
#line 2174 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 773 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.dtype) = new ArrayType((yyvsp[-3].dtype), (yyvsp[-1].range));
	}
#line 2182 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 780 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		MolecularField* mol = new MolecularField(current_class, (yyvsp[-2].str));
		if((yyvsp[0].dfield) == nullptr)
		{
			// Ignore this field, it should have already generated an error
			(yyval.dmolecule) = mol;
			break;
		}

		bool field_added = mol->add_field((yyvsp[0].dfield));
		if(!field_added)
		{
			if((yyvsp[0].dfield)->as_molecular())
			{
				dcerror("Cannot add molecular '" + (yyvsp[0].dfield)->get_name() + "' to a molecular field.");
			}
			else
			{
				dcerror("Unkown error adding field " + (yyvsp[0].dfield)->get_name() + " to molecular '"
				             + (yyvsp[-2].str) + "'.");
			}
		}

		(yyval.dmolecule) = mol;
	}
#line 2212 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 806 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].dfield) == nullptr)
		{
			// Ignore this field, it should have already generated an error
			(yyval.dmolecule) = (yyvsp[-2].dmolecule);
			break;
		}

		bool field_added = (yyvsp[-2].dmolecule)->add_field((yyvsp[0].dfield));
		if(!field_added)
		{
			if((yyvsp[0].dfield)->as_molecular())
			{
				dcerror("Cannot add molecular '" + (yyvsp[0].dfield)->get_name() + "' to a molecular field.");
			}
			else if(!(yyvsp[-2].dmolecule)->has_matching_keywords(*(yyvsp[0].dfield)))
			{
				dcerror("Mismatched keywords in molecular between " +
					(yyvsp[-2].dmolecule)->get_field(0)->get_name() + " and " + (yyvsp[0].dfield)->get_name() + ".");
			}
			else
			{
				dcerror("Unkown error adding field " + (yyvsp[0].dfield)->get_name() + " to molecular '"
				             + (yyvsp[-2].dmolecule)->get_name() + "'.");
			}
		}

		(yyval.dmolecule) = (yyvsp[-2].dmolecule);
	}
#line 2246 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 838 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!current_class)
		{
			dcerror("Field '" + (yyvsp[0].str) + "' not defined in current class.");
			(yyval.dfield) = nullptr;
			break;
		}

		Field *field = current_class->get_field_by_name((yyvsp[0].str));
		if(field == nullptr)
		{
			dcerror("Field '" + (yyvsp[0].str) + "' not defined in current class.");
			(yyval.dfield) = nullptr;
			break;
		}

		(yyval.dfield) = field;
	}
#line 2269 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 860 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].subtype) == kTypeString)
		{
			if(basic_string == nullptr)
			{
				basic_string = new ArrayType(new NumericType(kTypeChar));
				basic_string->set_alias("string");
			}

			(yyval.dtype) = basic_string;
		}
		else if((yyvsp[0].subtype) == kTypeBlob)
		{
			if(basic_blob == nullptr)
			{
				basic_blob = new ArrayType(new NumericType(kTypeUint8));
				basic_blob->set_alias("blob");
			}

			(yyval.dtype) = basic_blob;
		}
		else
		{
			dcerror("Found builtin ArrayType not handled by parser.");
			(yyval.dtype) = nullptr;
		}
	}
#line 2301 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 888 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[-3].subtype) == kTypeString)
		{
			ArrayType* arr = new ArrayType(new NumericType(kTypeChar), (yyvsp[-1].range));
			arr->set_alias("string");
			(yyval.dtype) = arr;
		}
		else if((yyvsp[-3].subtype) == kTypeBlob)
		{
			ArrayType* arr = new ArrayType(new NumericType(kTypeUint8), (yyvsp[-1].range));
			arr->set_alias("blob");
			(yyval.dtype) = arr;
		}
		else
		{
			dcerror("Found builtin ArrayType not handled by parser.");
			(yyval.dtype) = nullptr;
		}
	}
#line 2325 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 917 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.dnumeric) = new NumericType((yyvsp[0].subtype)); }
#line 2331 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 922 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!(yyvsp[-3].dnumeric)->set_range((yyvsp[-1].range)))
		{
			dcerror("Invalid range for type.");
		}

		(yyval.dnumeric) = (yyvsp[-3].dnumeric);
	}
#line 2344 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 931 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!(yyvsp[-3].dnumeric)->set_range((yyvsp[-1].range)))
		{
			dcerror("Invalid range for type.");
		}

		(yyval.dnumeric) = (yyvsp[-3].dnumeric);
	}
#line 2357 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 940 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!(yyvsp[-3].dnumeric)->set_range((yyvsp[-1].range)))
		{
			dcerror("Invalid range for type.");
		}

		(yyval.dnumeric) = (yyvsp[-3].dnumeric);
	}
#line 2370 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 952 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!(yyvsp[-2].dnumeric)->set_modulus((yyvsp[0].real)))
		{
			dcerror("Invalid modulus for type.");
		}

		(yyval.dnumeric) = (yyvsp[-2].dnumeric);
	}
#line 2383 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 964 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!(yyvsp[-2].dnumeric)->set_divisor((yyvsp[0].uint32)))
		{
			dcerror("Invalid divisor for type.");
		}
	}
#line 2394 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 971 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!(yyvsp[-2].dnumeric)->set_divisor((yyvsp[0].uint32)))
		{
			dcerror("Invalid divisor for type.");
		}
	}
#line 2405 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 981 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.dmethod) = new Method();
	}
#line 2413 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 985 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.dmethod) = (yyvsp[-1].dmethod);
	}
#line 2421 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 992 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		Method* fn = new Method();
		bool param_added = fn->add_parameter((yyvsp[0].dparam));
		if(!param_added)
		{
			dcerror("Unknown error adding parameter to method.");
		}
		(yyval.dmethod) = fn;
	}
#line 2435 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1002 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		bool param_added = (yyvsp[-2].dmethod)->add_parameter((yyvsp[0].dparam));
		if(!param_added)
		{
			dcerror("Cannot add parameter '" + (yyvsp[0].dparam)->get_name()
			             + "', a parameter with that name is already used in this method.");
		}
		(yyval.dmethod) = (yyvsp[-2].dmethod);
	}
#line 2449 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1018 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.dparam) = new Parameter((yyvsp[0].dtype));
	}
#line 2457 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1022 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		current_depth = 0;
		type_stack.push(TypeAndDepth((yyvsp[-1].dtype),0));
	}
#line 2466 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1027 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		Parameter* param = new Parameter((yyvsp[-3].dtype));
		if(!type_stack.empty()) depth_error(0, "type");
		param->set_default_value((yyvsp[0].buffer));
		(yyval.dparam) = param;
	}
#line 2477 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1036 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.dparam) = new Parameter((yyvsp[-1].dtype), (yyvsp[0].str));
	}
#line 2485 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1043 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyvsp[-3].dparam)->set_type(new ArrayType((yyvsp[-3].dparam)->get_type(), (yyvsp[-1].range)));
		(yyval.dparam) = (yyvsp[-3].dparam);
	}
#line 2494 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1048 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyvsp[-3].dparam)->set_type(new ArrayType((yyvsp[-3].dparam)->get_type(), (yyvsp[-1].range)));
		(yyval.dparam) = (yyvsp[-3].dparam);
	}
#line 2503 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1056 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		current_depth = 0;
		type_stack.push(TypeAndDepth((yyvsp[-1].dparam)->get_type(), 0));
	}
#line 2512 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1061 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!type_stack.empty()) depth_error(0, "parameter '" + (yyvsp[-3].dparam)->get_name() + "'");
		(yyvsp[-3].dparam)->set_default_value((yyvsp[0].buffer));
		(yyval.dparam) = (yyvsp[-3].dparam);
	}
#line 2522 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1067 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		current_depth = 0;
		type_stack.push(TypeAndDepth((yyvsp[-1].dparam)->get_type(), 0));
	}
#line 2531 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1072 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!type_stack.empty()) depth_error(0, "parameter '" + (yyvsp[-3].dparam)->get_name() + "'");
		(yyvsp[-3].dparam)->set_default_value((yyvsp[0].buffer));
		(yyval.dparam) = (yyvsp[-3].dparam);
	}
#line 2541 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1080 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.range) = NumericRange(); }
#line 2547 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1081 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.range) = NumericRange((yyvsp[0].real), (yyvsp[0].real)); }
#line 2553 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1082 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.range) = NumericRange((yyvsp[-2].real), (yyvsp[0].real)); }
#line 2559 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1086 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.range) = NumericRange(); }
#line 2565 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1087 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.range) = NumericRange((yyvsp[0].uint32), (yyvsp[0].uint32)); }
#line 2571 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1088 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.range) = NumericRange((yyvsp[-2].uint32), (yyvsp[0].uint32)); }
#line 2577 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1093 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].str).length() != 1)
		{
			dcerror("Single character required.");
			(yyval.uint32) = 0;
		}
		else
		{
			(yyval.uint32) = (unsigned char)(yyvsp[0].str)[0];
		}
	}
#line 2593 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1109 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		unsigned int num = (unsigned int)(yyvsp[0].uint64);
		if(num != (yyvsp[0].uint64))
		{
			dcerror("Number out of range.");
			(yyval.uint32) = 1;
		}
		(yyval.uint32) = num;
	}
#line 2607 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1121 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.real) = (double)(yyvsp[0].uint64); }
#line 2613 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1122 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.real) = (double)(yyvsp[0].int64); }
#line 2619 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1128 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].str).length() != 1) {
			dcerror("Single character required.");
			(yyval.real) = 0;
		} else {
			(yyval.real) = (double)(unsigned char)(yyvsp[0].str)[0];
		}
	}
#line 2632 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1141 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("signed integer");

		const DistributedType* dtype = type_stack.top().type;
		if(dtype == nullptr) {
			// Ignore this field, it should have already generated an error
			(yyval.buffer) = vector<uint8_t>();
			break;
		}
		type_stack.pop(); // Remove numeric type from stack

		(yyval.buffer) = number_value(dtype->get_subtype(), (yyvsp[0].int64));
	}
#line 2650 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1155 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("unsigned integer");

		const DistributedType* dtype = type_stack.top().type;
		if(dtype == nullptr) {
			// Ignore this field, it should have already generated an error
			(yyval.buffer) = vector<uint8_t>();
			break;
		}
		type_stack.pop(); // Remove numeric type from stack

		(yyval.buffer) = number_value(dtype->get_subtype(), (yyvsp[0].uint64));
	}
#line 2668 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1169 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("floating point");

		const DistributedType* dtype = type_stack.top().type;
		if(dtype == nullptr) {
			// Ignore this field, it should have already generated an error
			(yyval.buffer) = vector<uint8_t>();
			break;
		}
		type_stack.pop(); // Remove numeric type from stack

		(yyval.buffer) = number_value(dtype->get_subtype(), (yyvsp[0].real));
	}
#line 2686 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1183 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("string");

		const DistributedType* dtype = type_stack.top().type;
		if(dtype == nullptr) {
			// Ignore this field, it should have already generated an error
			(yyval.buffer) = vector<uint8_t>();
			break;
		}
		type_stack.pop(); // Remove string type from stack

		if(dtype->get_subtype() == kTypeString || dtype->get_subtype() == kTypeBlob) {
			if((yyvsp[0].str).length() != dtype->get_size()) {
				dcerror("Value for fixed-length string has incorrect length.");
			}

			(yyval.buffer) = as_buffer((yyvsp[0].str));
		} else if(dtype->get_subtype() == kTypeVarstring || dtype->get_subtype() == kTypeVarblob) {
			// TODO: Check for range limits
			// Prepend length tag
			sizetag_t length = (yyvsp[0].str).length();
			vector<uint8_t> buf = as_buffer(length);
			pack_value((yyvsp[0].str), buf);
			(yyval.buffer) = buf;
		}
		else {
			dcerror("Cannot use string value for non-string type '"
			             + format_type(dtype->get_subtype()) + "'.");
			(yyval.buffer) = as_buffer((yyvsp[0].str));
		}
	}
#line 2722 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1215 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("hex-string");

		const DistributedType* dtype = type_stack.top().type;
		if(dtype == nullptr) {
			// Ignore this field, it should have already generated an error
			(yyval.buffer) = vector<uint8_t>();
			break;
		}
		type_stack.pop(); // Remove type from stack

		if(dtype->get_subtype() == kTypeBlob) {
			if((yyvsp[0].str).length() != dtype->get_size()) {
				dcerror("Value for fixed-length blob has incorrect length.");
			}

			(yyval.buffer) = as_buffer((yyvsp[0].str));
		} else if(dtype->get_subtype() == kTypeVarblob) {
			// TODO: Check for range limits
			(yyval.buffer) = as_buffer((yyvsp[0].str));
		} else {
			dcerror("Cannot use hex value for non-blob type '"
			             + format_type(dtype->get_subtype()) + "'.");
			(yyval.buffer) = as_buffer((yyvsp[0].str));
		}
	}
#line 2753 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1247 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("method");

		const DistributedType* dtype = type_stack.top().type;
		if(dtype == nullptr) {
			// Ignore this field, it should have already generated an error
			break;
		}

		if(dtype->as_method()) {
			current_depth++;
			const Method* method = dtype->as_method();

			size_t num_params = method->get_num_parameters();
			for(unsigned int i = 1; i <= num_params; ++i) {
				// Reverse iteration
				const Parameter* param = method->get_parameter(num_params-i);
				// Add parameter types to stack such that the first is on top
				type_stack.push(TypeAndDepth(param->get_type(), current_depth));
			}
		} else {
			dcerror("Cannot use method-value for non-method type '"
			             + format_type(dtype->get_subtype()) + "'.");
		}
	}
#line 2783 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1273 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(type_stack.top().type->as_method()) {
			current_depth--;
		}
		type_stack.pop(); // Remove method type from the stack
		(yyval.buffer) = (yyvsp[-1].buffer);
	}
#line 2795 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1285 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		vector<uint8_t> buf = (yyvsp[-2].buffer);
		pack_value((yyvsp[0].buffer), buf);
		(yyval.buffer) = buf;
	}
#line 2805 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1294 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("struct");

		const DistributedType* dtype = type_stack.top().type;
		if(dtype == nullptr) {
			// Ignore this field, it should have already generated an error
			break;
		}

		if(dtype->as_struct()) {
			current_depth++;
			const Struct* dstruct = dtype->as_struct();

			size_t num_fields = dstruct->get_num_fields();
			for(unsigned int i = 1; i <= num_fields; ++i) {
				// Reverse iteration
				const Field* field = dstruct->get_field(num_fields-i);
				// Add field types to stack such that the first is on top
				type_stack.push(TypeAndDepth(field->get_type(), current_depth));
			}
		} else {
			dcerror("Cannot use struct-composition for non-struct type '"
			             + format_type(dtype->get_subtype()) + "'.");
		}
	}
#line 2835 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1320 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(type_stack.top().type->as_struct()) {
			current_depth--;
		}
		type_stack.pop(); // Remove method type from the stack
		(yyval.buffer) = (yyvsp[-1].buffer);
	}
#line 2847 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1333 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		vector<uint8_t> buf = (yyvsp[-2].buffer);
		pack_value((yyvsp[0].buffer), buf);
		(yyval.buffer) = buf;
	}
#line 2857 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1339 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		vector<uint8_t> buf = (yyvsp[-2].buffer);
		pack_value((yyvsp[0].buffer), buf);
		(yyval.buffer) = buf;
	}
#line 2867 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1348 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("array");

		const DistributedType* dtype = type_stack.top().type;
		if(dtype == nullptr) {
			// Ignore this field, it should have already generated an error
			(yyval.buffer) = vector<uint8_t>();;
			break;
		}
		type_stack.pop();
		if(!dtype->as_array()) {
			dcerror("Cannot use array-composition for non-array type '"
			             + format_type(dtype->get_subtype()) + "'.");
			(yyval.buffer) = vector<uint8_t>();;
			break;
		}
		const ArrayType* array = dtype->as_array();

		if(array->get_array_size() > 0) {
			// For fixed size arrays, an empty array is an error
			dcerror("Fixed-sized array of size "
			             + to_string(array->get_array_size())
			             + " can't have 0 elements.");
		} else if(array->has_range()) {
			// If we have a range, 0 elements must be valid in the range
			if(0 < array->get_range().min.uinteger) {
				dcerror("Too few elements in array value, minimum "
				             + to_string(array->get_range().min.uinteger) + ".");
			}
		}

		// Since a fixed-size array can't have zero elements, this always
		// the default value for a varsize array, which is the length-tag 0.
		(yyval.buffer) = vector<uint8_t>(sizeof(sizetag_t), 0);
	}
#line 2907 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1384 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("array");

		const DistributedType* dtype = type_stack.top().type;
		if(dtype == nullptr) {
			// Ignore this field, it should have already generated an error
			break;
		}

		if(dtype->as_array()) {
			const ArrayType* array = dtype->as_array();

			// For arrays we're going to do something pretty hacky:
			//    For every element we had we are going to increment the depth,
			//    and after we finish the element_values production we will compare
			//    the current_depth to the depth of our original symbol to check
			//    if the array size is proper.
			type_stack.push(TypeAndDepth(array->get_element_type(), current_depth));
		} else {
			dcerror("Cannot use array-composition for non-array type '"
			             + format_type(dtype->get_subtype()) + "'.");
		}
	}
#line 2935 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1408 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(type_stack.top().type->as_array()) {
			uint64_t actual_size = current_depth - type_stack.top().depth;

			const DistributedType* dtype = type_stack.top().type;
			if(dtype == nullptr) {
				// Ignore this field, it should have already generated an error
				(yyval.buffer) = vector<uint8_t>();
				break;
			}

			const ArrayType* array = dtype->as_array();
			if(array->has_range()) {
				if(actual_size > array->get_range().max.uinteger) {
					dcerror("Too many elements in array value, maximum "
					             + to_string(array->get_range().max.uinteger) + ".");
				} else if(actual_size < array->get_range().min.uinteger) {
					dcerror("Too few elements in array value, minimum "
					             + to_string(array->get_range().min.uinteger) + ".");
				}
			}

			if(array->get_array_size() == 0) {
				vector<uint8_t> buf = as_buffer(sizetag_t((yyvsp[-1].buffer).size()));
				pack_value((yyvsp[-1].buffer), buf);
				(yyval.buffer) = buf;
			} else {
				(yyval.buffer) = (yyvsp[-1].buffer);
			}
			current_depth = type_stack.top().depth;
		}

		type_stack.pop(); // Remove array type from the stack
	}
#line 2974 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1447 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		// We popped off the only element we added, so we're back to the array
		// Don't increment the depth; the array_expansion will add to
		// the current_depth depending on the number of elements it adds.
		const DistributedType* dtype = type_stack.top().type;
		if(dtype == nullptr) {
			// Ignore this field, it should have already generated an error
			break;
		}
		const ArrayType* array = dtype->as_array();
		type_stack.push(TypeAndDepth(array->get_element_type(), current_depth));
	}
#line 2991 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1460 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		// $4 packed onto end of $1
		std::vector<uint8_t> buf = (yyvsp[-3].buffer);
		pack_value((yyvsp[0].buffer), buf);
		(yyval.buffer) = buf;
	}
#line 3002 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1470 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		current_depth++;
		(yyval.buffer) = (yyvsp[0].buffer);
	}
#line 3011 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1475 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		const DistributedType* dtype = type_stack.top().type;
		if(dtype == nullptr) {
			// Ignore this field, it should have already generated an error
			(yyval.buffer) = vector<uint8_t>();
			break;
		}
		type_stack.pop(); // Pop that array element type
		current_depth += (yyvsp[0].uint32); // For arrays, we add 1 to the depth per element

		vector<uint8_t> buf;
		vector<uint8_t> base = number_value(dtype->get_subtype(), (yyvsp[-2].int64));
		buf.reserve(base.size() * (yyvsp[0].uint32));
		for(unsigned int i = 0; i < (yyvsp[0].uint32); ++i) {
			pack_value(base, buf);
		}
		(yyval.buffer) = buf;
	}
#line 3034 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1494 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		const DistributedType* dtype = type_stack.top().type;
		if(dtype == nullptr) {
			// Ignore this field, it should have already generated an error
			(yyval.buffer) = vector<uint8_t>();
			break;
		}
		type_stack.pop(); // Pop that array element type
		current_depth += (yyvsp[0].uint32); // For arrays, we add 1 to the depth per element

		vector<uint8_t> buf;
		vector<uint8_t> base = number_value(dtype->get_subtype(), (yyvsp[-2].uint64));
		buf.reserve(base.size() * (yyvsp[0].uint32));
		for(unsigned int i = 0; i < (yyvsp[0].uint32); ++i) {
			pack_value(base, buf);
		}
		(yyval.buffer) = buf;
	}
#line 3057 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1513 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		const DistributedType* dtype = type_stack.top().type;
		if(dtype == nullptr) {
			// Ignore this field, it should have already generated an error
			(yyval.buffer) = vector<uint8_t>();
			break;
		}
		type_stack.pop(); // Pop that array element type
		current_depth += (yyvsp[0].uint32); // For arrays, we add 1 to the depth per element

		vector<uint8_t> buf;
		vector<uint8_t> base = number_value(dtype->get_subtype(), (yyvsp[-2].real));
		buf.reserve(base.size() * (yyvsp[0].uint32));
		for(unsigned int i = 0; i < (yyvsp[0].uint32); ++i) {
			pack_value(base, buf);
		}
		(yyval.buffer) = buf;
	}
#line 3080 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1532 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		const DistributedType* dtype = type_stack.top().type;
		if(dtype == nullptr) {
			// Ignore this field, it should have already generated an error
			(yyval.buffer) = vector<uint8_t>();
			break;
		}
		type_stack.pop(); // Pop that array element type
		current_depth += (yyvsp[0].uint32); // For arrays, we add 1 to the depth per element

		if(dtype->get_subtype() == kTypeString) {
			if((yyvsp[-2].str).length() != dtype->get_size()) {
				dcerror("Value for fixed-length string has incorrect length.");
			}

			vector<uint8_t> buf;
			buf.reserve((yyvsp[-2].str).length() * (yyvsp[0].uint32));
			for(unsigned int i = 0; i < (yyvsp[0].uint32); ++i) {
				pack_value((yyvsp[-2].str), buf);
			}
			(yyval.buffer) = buf;
		} else if(dtype->get_subtype() == kTypeVarstring) {
			// Prepend length tag
			vector<uint8_t> buf = as_buffer((yyvsp[-2].str).length());
			vector<uint8_t> base = as_buffer((yyvsp[-2].str));
			buf.reserve(base.size() * (yyvsp[0].uint32));
			for(unsigned int i = 0; i < (yyvsp[0].uint32); ++i) {
				pack_value(base, buf);
			}
			(yyval.buffer) = buf;

			// TODO: Check for range limits

		} else {
			dcerror("Cannot use string value for non-string type '"
			             + format_type(dtype->get_subtype()) + "'.");

			vector<uint8_t> buf;
			buf.reserve((yyvsp[-2].str).length() * (yyvsp[0].uint32));
			for(unsigned int i = 0; i < (yyvsp[0].uint32); ++i) {
				pack_value((yyvsp[-2].str), buf);
			}
			(yyval.buffer) = buf;
		}
	}
#line 3130 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1578 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		const DistributedType* dtype = type_stack.top().type;
		if(dtype == nullptr) {
			// Ignore this field, it should have already generated an error
			(yyval.buffer) = vector<uint8_t>();
			break;
		}
		type_stack.pop(); // Pop that array element type
		current_depth += (yyvsp[0].uint32); // For arrays, we add 1 to the depth per element

		if(dtype->get_subtype() == kTypeBlob) {
			if((yyvsp[-2].str).length() != dtype->get_size()) {
				dcerror("Value for fixed-length blob has incorrect length.");
			}

			vector<uint8_t> buf;
			buf.reserve((yyvsp[-2].str).length() * (yyvsp[0].uint32));
			for(unsigned int i = 0; i < (yyvsp[0].uint32); ++i) {
				pack_value((yyvsp[-2].str), buf);
			}
			(yyval.buffer) = buf;
		} else if(dtype->get_subtype() == kTypeVarblob) {
			// Prepend length tag
			vector<uint8_t> buf = as_buffer((yyvsp[-2].str).length());
			vector<uint8_t> base = as_buffer((yyvsp[-2].str));
			buf.reserve(base.size() * (yyvsp[0].uint32));
			for(unsigned int i = 0; i < (yyvsp[0].uint32); ++i) {
				pack_value(base, buf);
			}
			(yyval.buffer) = buf;

			// TODO: Check for range limits

		} else {
			dcerror("Cannot use hex value for non-blob type '"
			             + format_type(dtype->get_subtype()) + "'.");

			vector<uint8_t> buf;
			buf.reserve((yyvsp[-2].str).length() * (yyvsp[0].uint32));
			for(unsigned int i = 0; i < (yyvsp[0].uint32); ++i) {
				pack_value((yyvsp[-2].str), buf);
			}
			(yyval.buffer) = buf;
		}
	}
#line 3180 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1626 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.int64) = (yyvsp[0].uint64); }
#line 3186 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1627 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.int64) = -(yyvsp[0].uint64); }
#line 3192 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1631 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.subtype) = kTypeString; }
#line 3198 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1632 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.subtype) = kTypeBlob; }
#line 3204 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1636 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.subtype) = kTypeChar; }
#line 3210 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1637 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.subtype) = kTypeInt8; }
#line 3216 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1638 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.subtype) = kTypeInt16; }
#line 3222 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1639 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.subtype) = kTypeInt32; }
#line 3228 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1640 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.subtype) = kTypeInt64; }
#line 3234 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1641 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.subtype) = kTypeUint8; }
#line 3240 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1642 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.subtype) = kTypeUint16; }
#line 3246 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1643 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.subtype) = kTypeUint32; }
#line 3252 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1644 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.subtype) = kTypeUint64; }
#line 3258 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1645 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.subtype) = kTypeFloat32; }
#line 3264 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1646 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    { (yyval.subtype) = kTypeFloat64; }
#line 3270 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1651 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		(yyval.strings) = vector<string>();
	}
#line 3278 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1655 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1646  */
    {
		if(!parsed_module->has_keyword((yyvsp[0].str)))
		{
			dcerror("Keyword '" + (yyvsp[0].str) + "' has not been declared.");
			break;
		}

		(yyvsp[-1].strings).push_back((yyvsp[0].str));
		(yyval.strings) = (yyvsp[-1].strings);
	}
#line 3293 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
    break;


#line 3297 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.cpp" /* yacc.c:1646  */
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
#line 1671 "/media/Storage/Devel/git/astron/bamboo/src/dcfile/parser.ypp" /* yacc.c:1906  */
 /* Start helper function section */


Module *read_dcfile(istream& in, const string& filename) {
    Module *m = new Module();
    bool ok = parse_dcfile(m, in, filename);
    if(ok) {
        return m;
    }

    return nullptr;
}
Module *read_dcfile(const string& filename) {
    Module *m = new Module();
    bool ok = parse_dcfile(m, filename);
    if(ok) {
        return m;
    }

    return nullptr;
}
bool parse_dcfile(Module *m, istream& in, const string& filename) {
    dcparser_file(in, filename, *m);
    dcparse();
    dcparser_cleanup();
    return (dc_errors() == 0);
}
bool parse_dcfile(Module *m, const string& filename) {
    ifstream in;
    in.open(filename.c_str());
    if(!in) {
        cerr << "Cannot open " << filename << " for reading.\n";
        return false;
    }
    return parse_dcfile(m, in, filename);
}
vector<uint8_t> parse_dcvalue(const DistributedType *dtype, const string& formatted, bool& err) {
    istringstream strm(formatted);
    return parse_dcvalue(dtype, strm, err);

}
vector<uint8_t> parse_dcvalue(const DistributedType *dtype, istream& in, bool& err) {
    vector<uint8_t> value;
    try {
        dcparser_value(in, "parse_value()", dtype, value);
        dcparse();
        dcparser_cleanup();
    } catch(const exception& e) {
        err = true;
        return vector<uint8_t>();
    }

    if(dc_errors() > 0) {
        err = true;
        return vector<uint8_t>();
    }

    err = false;
    return value;
}


bool check_depth()
{
	return (!type_stack.empty() && current_depth == type_stack.top().depth);
}

void depth_error(string what)
{
	if(type_stack.empty() || current_depth < type_stack.top().depth) {
		dcerror("Too many nested values while parsing value for " + what + ".");
	} else {
		dcerror("Too few nested values while parsing value for " + what + ".");	
	}
}

void depth_error(int depth, string what)
{
	if(current_depth > depth) {
		dcerror("Too few nested values before this " + what + " value.");
	} else {
		dcerror("Too many nested values before this " + what + " value.");
	}
}

vector<uint8_t> number_value(Subtype type, double &number)
{
	switch(type) {
		case kTypeFloat32:
			if(float(number) == INFINITY || float(number) == -INFINITY) {
				dcerror("Value is out of range for type 'float32'.");
			}
			return as_buffer(float(number));
		case kTypeFloat64:
			return as_buffer(number);
		case kTypeInt8:
		case kTypeInt16:
		case kTypeInt32:
		case kTypeInt64:
		case kTypeChar:
		case kTypeUint8:
		case kTypeUint16:
		case kTypeUint32:
		case kTypeUint64:
			dcerror("Cannot use floating-point value for integer datatype.");
			return vector<uint8_t>();
		default:
			dcerror("Cannot use floating-point value for non-numeric datatype.");
			return vector<uint8_t>();
	}
}

vector<uint8_t> number_value(Subtype type, int64_t &number)
{
	switch(type) {
		case kTypeInt8:
			if(INT8_MIN > number || number > INT8_MAX) {
				dcerror("Signed integer out of range for type 'int8'.");
			}
			return as_buffer(int8_t(number));
		case kTypeInt16:
			if(INT16_MIN > number || number > INT16_MAX) {
				dcerror("Signed integer out of range for type 'int16'.");
			}
			return as_buffer(int16_t(number));
		case kTypeInt32:
			if(INT32_MIN > number || number > INT32_MAX) {
				dcerror("Signed integer out of range for type 'int32'.");
			}
			return as_buffer(int32_t(number));
		case kTypeInt64:
			return as_buffer(number);
		case kTypeChar:
		case kTypeUint8:
		case kTypeUint16:
		case kTypeUint32:
		case kTypeUint64: {
			if(number < 0) {
				dcerror("Can't use negative value for unsigned integer datatype.");
			}
			uint64_t value = number;
			return number_value(type, value);
		}
		case kTypeFloat32:
		case kTypeFloat64: {
			// Note: Expecting number to be converted to a double by value (ie. 3 becomes 3.0)
			double value = number;
			return number_value(type, value);
		}
		default:
			dcerror("Cannot use signed integer value for non-numeric datatype.");
			return vector<uint8_t>();
	}
}

vector<uint8_t> number_value(Subtype type, uint64_t &number)
{
	switch(type)
	{
		case kTypeChar:
			if(number > UINT8_MAX) {
				dcerror("Unsigned integer out of range for type 'char'.");
			}
			return as_buffer(char(number));
		case kTypeUint8:
			if(number > UINT8_MAX) {
				dcerror("Unsigned integer out of range for type 'uint8'.");
			}
			return as_buffer(uint8_t(number));
		case kTypeUint16:
			if(number > UINT16_MAX) {
				dcerror("Unsigned integer out of range for type 'uint16'.");
			}
			return as_buffer(uint16_t(number));
		case kTypeUint32:
			if(number > UINT32_MAX) {
				dcerror("Unsigned integer out of range for type 'uint32'.");
			}
			return as_buffer(uint32_t(number));
		case kTypeUint64:
			return as_buffer(number);
		case kTypeInt8:
		case kTypeInt16:
		case kTypeInt32:
		case kTypeInt64: {
			if(number > INT64_MAX) {
				dcerror("Unsigned integer out of range for signed integer datatype.");
			}
			int64_t value = number;
			return number_value(type, value);
		}
		case kTypeFloat32:
		case kTypeFloat64: {
			// Note: Expecting number to be converted to a double by value (ie. 3 becomes 3.0)
			double value = number;
			return number_value(type, value);
		}
		default:
			dcerror("Cannot use unsigned integer value for non-numeric datatype.");
			return vector<uint8_t>();
	}
}


} // close namespace bamboo