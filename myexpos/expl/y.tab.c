/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20221106

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "abstree.y"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "abstree.h"
    #include "symboltable.h"
    #include "symboltable.c"
    #include "aa.c"
    #include "codegen.c"
    #include "userdtype.c"
    #include "typecheck.h"
    #include "typecheck.c"

    int yylex();
    void yyerror(char const *s);
    struct ASTNode *head1, *head;
    int result;
    FILE *fp;
    extern FILE *yyin;
    extern int yylineno, lineno;
    struct Fieldlist *ftemp;
    struct Typetable *declarationType, *FdeclarationType, *functype, *temp1, *temp2;
    struct Gsymbol *Gtemp;
    struct Lsymbol *Ltemp;
    struct Paramstruct *Argtemp1, *Argtemp2;
    int indicator = 0; /*for no.of arguments passed*/
    int declcount = 0, defcount = 0, exprcount = 0;
    int init_counter = 0, f_counter = 0;	/*to check whether initialize is called or not.*/
    int wr = 0;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 33 "abstree.y"
typedef union YYSTYPE
{
    struct ASTNode *nptr;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 66 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NUM 257
#define ID 258
#define PLUS 259
#define MUL 260
#define DIV 261
#define MOD 262
#define ASGN 263
#define READ 264
#define WRITE 265
#define MINUS 266
#define NEWLINE 267
#define LT 268
#define GT 269
#define DEQ 270
#define NEQ 271
#define ELSE 272
#define IF 273
#define THEN 274
#define ENDIF 275
#define ENDWHILE 276
#define WHILE 277
#define DO 278
#define START 279
#define END 280
#define DECL 281
#define ENDDECL 282
#define INT 283
#define STR 284
#define LE 285
#define GE 286
#define NOT 287
#define AND 288
#define OR 289
#define MAIN 290
#define RETURN 291
#define ALLOC 292
#define FREE 293
#define INIT 294
#define BRK 295
#define CONTINUE 296
#define BRKP 297
#define TYPE 298
#define ENDTYPE 299
#define NILL 300
#define DEQNILL 301
#define NEQNILL 302
#define STRVAL 303
#define EXPOSCALL 304
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   11,   11,   14,   14,   15,   16,   16,   17,
   12,   12,   19,   19,   20,   22,   22,   22,   22,   22,
   22,   18,   18,   18,   21,   21,   21,   24,   24,   24,
   23,   23,   23,   25,   26,   13,   13,    7,   27,   27,
   28,   28,   29,   30,   30,    5,    4,    4,    6,    2,
    2,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,   10,   10,    8,    8,    9,    9,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,
};
static const YYINT yylen[] = {                            2,
    4,    3,    3,    0,    2,    1,    4,    2,    1,    3,
    3,    0,    1,    2,    3,    1,    4,    4,    3,    6,
    6,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    3,    0,    2,    1,    1,    2,    9,    3,    0,
    1,    2,    3,    1,    3,    8,    4,    3,    3,    2,
    1,    4,    7,    5,    8,    5,    8,   10,    8,    6,
    6,    4,    4,    5,    5,    5,    4,    4,    7,    6,
    2,    2,    2,    3,    3,    1,    3,    1,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    3,    1,    1,    2,    1,    1,    4,
    4,    3,    2,    2,    2,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    6,    0,    0,    0,    3,
    5,   27,   25,   26,    0,   13,    0,    2,   36,    0,
    0,   24,   22,   23,    0,    9,    0,   11,   14,    0,
    0,    1,   37,    0,    0,    7,    8,    0,    0,    0,
   15,    0,    0,    0,   10,    0,   30,   28,   29,    0,
    0,   31,    0,    0,    0,   17,   18,    0,   35,   34,
    0,    0,    0,    0,   32,    0,    0,    0,    0,    0,
   20,   21,    0,    0,    0,   41,    0,    0,    0,   44,
    0,   39,   42,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   51,    0,    0,   46,   38,   43,
    0,    0,    0,    0,    0,    0,    0,    0,   96,    0,
    0,    0,   98,    0,    0,    0,    0,   71,   72,   73,
   50,    0,   48,    0,    0,   45,    0,    0,    0,    0,
    0,    0,   74,    0,    0,    0,    0,    0,  103,  104,
    0,    0,   97,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   49,  105,
  106,    0,    0,   47,    0,    0,    0,    0,   75,    0,
    0,   67,    0,   52,    0,    0,    0,    0,    0,    0,
    0,    0,  102,    0,    0,   94,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   68,   63,   62,    0,    0,    0,    0,    0,
    0,   54,   66,   56,    0,    0,  100,  101,    0,   64,
   65,    0,   60,   70,    0,    0,    0,    0,    0,    0,
    0,   61,   69,    0,   53,    0,    0,    0,    0,   55,
    0,   57,   59,    0,   58,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  298,  306,  317,  258,  320,  321,  281,  318,  123,  299,
  321,  258,  283,  284,  325,  326,  327,  311,  313,  319,
  327,  258,  283,  284,  322,  323,  324,  282,  326,  258,
  328,  311,  313,  258,  290,  125,  323,  258,   91,   40,
   59,   44,   40,   40,   59,  257,  258,  283,  284,  329,
  330,  331,  258,  329,   41,   93,   41,   44,  258,  332,
   91,   40,   41,  123,  331,  257,  329,  123,  281,  333,
   93,   41,  333,  330,  334,  335,  279,  310,  310,  258,
  336,  282,  335,  258,  264,  265,  273,  277,  291,  293,
  295,  296,  297,  308,  309,  312,  316,  125,  125,   59,
   44,  263,   91,   46,   40,   40,   40,   40,  257,  258,
  266,  287,  303,   40,  307,  316,   40,   59,   59,   59,
  309,  312,  280,  263,   46,  258,  292,  294,  300,  304,
  307,  307,  258,  258,  316,  307,  307,  307,  301,  302,
   91,   40,  257,  307,  307,  259,  260,  261,  262,  266,
  268,  269,  270,  271,  285,  286,  288,  289,   59,  301,
  302,  258,  316,  280,  292,  300,  307,  316,  258,   40,
   40,   59,   40,   59,   93,   91,   41,   41,   41,   41,
   41,  307,   41,  307,  314,   41,  307,  307,  307,  307,
  307,  307,  307,  307,  307,  307,  307,  307,  307,   41,
   41,   40,   59,   59,   59,   41,   41,  307,  315,  263,
  307,   59,   59,   59,  274,  278,   93,   41,   44,   59,
   59,   41,   59,   59,   41,   44,  307,   93,  308,  308,
  307,   59,   59,  307,   59,   41,  272,  275,  276,   59,
  308,   59,   59,  275,   59,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          2,
  115,   94,   95,   78,   18,   96,   19,  185,  209,  116,
    3,    8,   20,    5,    6,   25,   26,   27,   15,   16,
   17,   31,   50,   51,   52,   60,   70,   75,   76,   81,
};
static const YYINT yysindex[] = {                      -288,
 -227,    0, -238,  -79, -253,    0, -235, -235, -203,    0,
    0,    0,    0,    0, -246,    0, -205,    0,    0, -235,
 -250,    0,    0,    0, -114,    0, -196,    0,    0,  -20,
   20,    0,    0,   23,   43,    0,    0,   55, -172, -191,
    0, -142, -191,   87,    0,   41,    0,    0,    0,   58,
 -116,    0,  -18,   85,   30,    0,    0, -191,    0,    0,
 -108, -191,   34, -118,    0,   75,   97, -118, -191, -105,
    0,    0, -105,  -73, -206,    0, -160,   53,   68,    0,
   38,    0,    0,  -30,  158,  161,  162,  163,  -36,  164,
  140,  148,  151, -160,    0,  -69,  -28,    0,    0,    0,
  -33,  -40,  -36,  -27,  -24,  -36,  -36,  -36,    0,  -31,
  -44,  -36,    0,  -36,  275,  -29,  -22,    0,    0,    0,
    0,  -53,    0,  -34,  -21,    0,  189,  198,  180,  202,
  319,  -80,    0,  -16,  -14,  102,  115,  146,    0,    0,
  -36,  -38,    0, -229,  159,  -36,  -36,  -36,  -36,  -36,
  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,    0,    0,
    0,   -7,   86,    0,  203,  181,  350,  -45,    0,  204,
  205,    0,  -36,    0,  -15,  -36,  191,  196,  209,  -13,
    1,  541,    0,  688,  106,    0,   81, -146, -146, -146,
   81, -229, -229, -229,   -9, -229, -229,   81,   81,  219,
  221,  241,    0,    0,    0,  232,  233,  688,  107,  -36,
  554,    0,    0,    0,  649,  649,    0,    0,  -36,    0,
    0,  236,    0,    0,  243,  -36,  510,  264, -207,  -81,
  688,    0,    0,  688,    0,  248,  649,  249,  251,    0,
  644,    0,    0,  252,    0,
};
static const YYINT yyrindex[] = {                      -174,
    0,    0, -164,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   47,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  117,
    0,    0,  117,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   52,    0,    0,    0,    0,    0,    0,    0,
    0,  117,    0,   33,    0,    0,    0,   33,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   15,
    0,    0,    0,    0,    0,   28,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  200,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  719,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  121,    0,    0,  458,  265,  382,  392,
  463,  413,  423,   71,   59,  437,  454,  474,  479,    0,
    0,    0,    0,    0,    0,    0,    0,  131,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  132,    0,    0,  153,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
  742, -187,  -75,  242,  302,  229,  306,    0,    0,  -70,
    0,    0,    0,    0,  330,    0,  311,    0,    0,  323,
   13,    0,  -17,   26,  288,    0,  285,    0,  279,    0,
};
#define YYTABLESIZE 1008
static const YYINT yytable[] = {                        114,
  125,  114,  183,  114,    4,  114,   97,   34,  142,    1,
   36,   12,  175,  205,  104,  104,  125,  125,  121,   40,
   21,   62,   12,   97,  177,   54,  178,  229,  230,  104,
    4,  125,   21,  200,  135,   28,   13,   14,  104,   35,
  153,  154,    7,    9,   67,   10,  163,   13,   14,  241,
   84,   47,   30,  168,   22,   99,   85,   86,   99,  141,
  103,   38,   43,   42,  237,   87,   47,  238,   95,   88,
   39,   95,   61,   99,  176,   82,   48,   49,   41,   23,
   24,  101,   44,    4,   46,   90,   95,   91,   92,   93,
   16,   48,   49,   12,   74,   19,  100,   84,   57,   90,
   74,   58,   90,   85,   86,   16,    4,   99,    4,    4,
   19,   89,   87,   45,   89,   53,   88,   90,   12,   12,
   95,  151,  152,  153,  154,   63,  201,   55,   58,   89,
   89,  125,   90,   56,   91,   92,   93,   72,  155,  156,
   58,   59,  179,   22,   97,   97,  218,  225,   66,  219,
  226,   90,   64,  121,  121,  180,   68,   33,   97,   97,
   33,   76,   69,   89,   76,  121,   97,   71,   23,   24,
   97,   78,   77,   77,   78,   77,   84,   98,  146,  147,
  148,  149,   85,   86,   80,  150,  181,  151,  152,  153,
  154,   87,   99,   79,  239,   88,   79,  105,  118,  186,
  106,  107,  108,  117,  155,  156,  119,  157,  158,  120,
  123,   90,  143,   91,   92,   93,  109,  110,  109,  110,
  109,  110,  109,  110,  126,  111,  164,  111,  170,  111,
  133,  111,  102,  134,  124,  162,  169,  171,  172,  203,
   93,  173,  202,   93,  206,  207,  112,  210,  112,  212,
  112,  127,  112,  128,  213,  160,  161,  165,   93,  129,
  215,  154,  113,  130,  113,  166,  113,  214,  113,  139,
  140,  160,  161,   99,   99,   99,   99,  220,  216,  221,
   99,  222,   99,   99,   99,   99,   95,   95,   95,   95,
  223,  224,   93,   95,  232,   95,   95,   95,   95,   99,
   99,  233,   99,   99,  236,   82,  240,  242,   82,  243,
  245,   40,   95,   95,   79,   95,   95,   90,   90,   90,
   90,   32,  122,   82,   90,   33,   90,   90,   90,   89,
   89,   89,   89,  159,   11,   37,   89,   29,   89,   89,
  147,  148,  149,   90,   90,   65,   90,   90,  151,  152,
  153,  154,   73,   83,    0,   89,   89,   82,   89,   89,
  146,  147,  148,  149,    0,  155,  156,  150,    0,  151,
  152,  153,  154,  146,  147,  148,  149,  174,    0,    0,
  150,    0,  151,  152,  153,  154,  155,  156,    0,  157,
  158,    0,    0,    0,    0,    0,    0,    0,    0,  155,
  156,    0,  157,  158,  146,  147,  148,  149,  204,    0,
    0,  150,    0,  151,  152,  153,  154,  146,  147,  148,
  149,    0,   83,    0,  150,   83,  151,  152,  153,  154,
  155,  156,   84,  157,  158,   84,    0,    0,    0,    0,
   83,    0,    0,  155,  156,    0,  157,  158,    0,    0,
   84,    0,    0,   85,    0,    0,   85,    0,   93,   93,
   93,   93,    0,   87,    0,   93,   87,    0,    0,    0,
    0,   85,    0,    0,   83,    0,    0,   86,    0,    0,
   86,   87,    0,    0,   84,    0,    0,   93,   93,    0,
    0,    0,    0,    0,   88,   86,    0,   88,   80,    0,
    0,   80,    0,   81,    0,   85,   81,    0,    0,    0,
    0,    0,   88,    0,   91,   87,   80,   91,    0,   92,
    0,   81,   92,   82,   82,   82,   82,    0,    0,   86,
   82,    0,   91,  146,  147,  148,  149,   92,    0,    0,
  150,    0,  151,  152,  153,  154,   88,    0,    0,    0,
   80,    0,   82,   82,    0,   81,    0,    0,    0,  155,
  156,    0,  157,  158,    0,    0,   91,    0,  235,    0,
    0,   92,    0,    0,    0,    0,    0,  146,  147,  148,
  149,    0,    0,    0,  150,    0,  151,  152,  153,  154,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  155,  156,    0,  157,  158,  146,  147,
  148,  149,    0,    0,    0,  150,    0,  151,  152,  153,
  154,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  217,  155,  156,    0,  157,  158,    0,
   83,   83,   83,   83,    0,    0,  228,   83,    0,    0,
   84,   84,   84,   84,    0,    0,    0,   84,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   83,
   83,   85,   85,   85,   85,    0,    0,    0,   85,   84,
   84,   87,   87,   87,   87,    0,    0,    0,   87,    0,
    0,    0,    0,    0,    0,   86,   86,   86,   86,    0,
   85,   85,   86,    0,    0,    0,    0,    0,    0,    0,
   87,   87,   88,   88,   88,   88,   80,    0,    0,   88,
    0,   81,    0,   80,   86,   86,    0,    0,   81,    0,
    0,    0,   91,    0,    0,    0,    0,   92,    0,   91,
    0,   88,   88,    0,   92,   80,   80,    0,    0,    0,
   81,   81,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   91,   91,    0,    0,    0,   92,   92,  146,  147,
  148,  149,    0,    0,    0,  150,    0,  151,  152,  153,
  154,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  155,  156,    0,  157,  158,  146,
  147,  148,  149,    0,    0,    0,  150,    0,  151,  152,
  153,  154,  146,  147,  148,  149,    0,    0,    0,  150,
    0,  151,  152,  153,  154,  155,  156,    0,  157,  158,
    0,    0,    0,    0,    0,    0,    0,    0,  155,  156,
    0,  157,  158,  131,  132,    0,    0,  136,  137,  138,
    0,    0,    0,  144,    0,  145,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  167,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  182,  184,    0,    0,    0,  187,  188,  189,
  190,  191,  192,  193,  194,  195,  196,  197,  198,  199,
    0,   84,    0,    0,    0,    0,   84,   85,   86,    0,
    0,    0,   85,   86,  208,    0,   87,  211,  244,    0,
   88,   87,    0,    0,    0,   88,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   90,    0,   91,   92,
   93,   90,    0,   91,   92,   93,  146,  147,  148,  149,
    0,  227,    0,  150,    0,  151,  152,  153,  154,    0,
  231,    0,    0,    0,    0,    0,    0,  234,    0,    0,
    0,    0,  155,  156,    0,  157,  158,   95,   95,   95,
   95,    0,    0,    0,   95,    0,   95,   95,   95,   95,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   95,   95,    0,   95,   95,
};
static const YYINT yycheck[] = {                         40,
   46,   40,   41,   40,  258,   40,   77,  258,   40,  298,
  125,  258,   93,   59,   46,   46,   46,   46,   94,   40,
    8,   40,  258,   94,   41,   43,   41,  215,  216,   46,
  258,   46,   20,   41,  105,  282,  283,  284,   46,  290,
  270,  271,  281,  123,   62,  299,  117,  283,  284,  237,
  258,  258,  258,  124,  258,   41,  264,  265,   44,   91,
   91,  258,   40,   44,  272,  273,  258,  275,   41,  277,
   91,   44,   91,   59,   91,  282,  283,  284,   59,  283,
  284,   44,   40,  258,  257,  293,   59,  295,  296,  297,
   44,  283,  284,  258,   69,   44,   59,  258,   41,   41,
   75,   44,   44,  264,  265,   59,  281,   93,  283,  284,
   59,   41,  273,   59,   44,  258,  277,   59,  283,  284,
   93,  268,  269,  270,  271,   41,   41,   41,   44,   59,
  291,   46,  293,   93,  295,  296,  297,   41,  285,  286,
   44,  258,   41,  258,  215,  216,   41,   41,  257,   44,
   44,   93,  123,  229,  230,   41,  123,   41,  229,  230,
   44,   41,  281,   93,   44,  241,  237,   93,  283,  284,
  241,   41,   41,  279,   44,   44,  258,  125,  259,  260,
  261,  262,  264,  265,  258,  266,   41,  268,  269,  270,
  271,  273,  125,   41,  276,  277,   44,   40,   59,   41,
   40,   40,   40,   40,  285,  286,   59,  288,  289,   59,
  280,  293,  257,  295,  296,  297,  257,  258,  257,  258,
  257,  258,  257,  258,  258,  266,  280,  266,   40,  266,
  258,  266,  263,  258,  263,  258,  258,   40,   59,   59,
   41,   40,   40,   44,   41,   41,  287,  263,  287,   59,
  287,  292,  287,  294,   59,  301,  302,  292,   59,  300,
  274,  271,  303,  304,  303,  300,  303,   59,  303,  301,
  302,  301,  302,  259,  260,  261,  262,   59,  278,   59,
  266,   41,  268,  269,  270,  271,  259,  260,  261,  262,
   59,   59,   93,  266,   59,  268,  269,  270,  271,  285,
  286,   59,  288,  289,   41,   41,   59,   59,   44,   59,
   59,  279,  285,  286,   73,  288,  289,  259,  260,  261,
  262,   20,   94,   59,  266,   20,  268,  269,  270,  259,
  260,  261,  262,   59,    5,   25,  266,   15,  268,  269,
  260,  261,  262,  285,  286,   58,  288,  289,  268,  269,
  270,  271,   68,   75,   -1,  285,  286,   93,  288,  289,
  259,  260,  261,  262,   -1,  285,  286,  266,   -1,  268,
  269,  270,  271,  259,  260,  261,  262,   59,   -1,   -1,
  266,   -1,  268,  269,  270,  271,  285,  286,   -1,  288,
  289,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  285,
  286,   -1,  288,  289,  259,  260,  261,  262,   59,   -1,
   -1,  266,   -1,  268,  269,  270,  271,  259,  260,  261,
  262,   -1,   41,   -1,  266,   44,  268,  269,  270,  271,
  285,  286,   41,  288,  289,   44,   -1,   -1,   -1,   -1,
   59,   -1,   -1,  285,  286,   -1,  288,  289,   -1,   -1,
   59,   -1,   -1,   41,   -1,   -1,   44,   -1,  259,  260,
  261,  262,   -1,   41,   -1,  266,   44,   -1,   -1,   -1,
   -1,   59,   -1,   -1,   93,   -1,   -1,   41,   -1,   -1,
   44,   59,   -1,   -1,   93,   -1,   -1,  288,  289,   -1,
   -1,   -1,   -1,   -1,   41,   59,   -1,   44,   41,   -1,
   -1,   44,   -1,   41,   -1,   93,   44,   -1,   -1,   -1,
   -1,   -1,   59,   -1,   41,   93,   59,   44,   -1,   41,
   -1,   59,   44,  259,  260,  261,  262,   -1,   -1,   93,
  266,   -1,   59,  259,  260,  261,  262,   59,   -1,   -1,
  266,   -1,  268,  269,  270,  271,   93,   -1,   -1,   -1,
   93,   -1,  288,  289,   -1,   93,   -1,   -1,   -1,  285,
  286,   -1,  288,  289,   -1,   -1,   93,   -1,   59,   -1,
   -1,   93,   -1,   -1,   -1,   -1,   -1,  259,  260,  261,
  262,   -1,   -1,   -1,  266,   -1,  268,  269,  270,  271,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  285,  286,   -1,  288,  289,  259,  260,
  261,  262,   -1,   -1,   -1,  266,   -1,  268,  269,  270,
  271,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   93,  285,  286,   -1,  288,  289,   -1,
  259,  260,  261,  262,   -1,   -1,   93,  266,   -1,   -1,
  259,  260,  261,  262,   -1,   -1,   -1,  266,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  288,
  289,  259,  260,  261,  262,   -1,   -1,   -1,  266,  288,
  289,  259,  260,  261,  262,   -1,   -1,   -1,  266,   -1,
   -1,   -1,   -1,   -1,   -1,  259,  260,  261,  262,   -1,
  288,  289,  266,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  288,  289,  259,  260,  261,  262,  259,   -1,   -1,  266,
   -1,  259,   -1,  266,  288,  289,   -1,   -1,  266,   -1,
   -1,   -1,  259,   -1,   -1,   -1,   -1,  259,   -1,  266,
   -1,  288,  289,   -1,  266,  288,  289,   -1,   -1,   -1,
  288,  289,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  288,  289,   -1,   -1,   -1,  288,  289,  259,  260,
  261,  262,   -1,   -1,   -1,  266,   -1,  268,  269,  270,
  271,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  285,  286,   -1,  288,  289,  259,
  260,  261,  262,   -1,   -1,   -1,  266,   -1,  268,  269,
  270,  271,  259,  260,  261,  262,   -1,   -1,   -1,  266,
   -1,  268,  269,  270,  271,  285,  286,   -1,  288,  289,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  285,  286,
   -1,  288,  289,  102,  103,   -1,   -1,  106,  107,  108,
   -1,   -1,   -1,  112,   -1,  114,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  141,  142,   -1,   -1,   -1,  146,  147,  148,
  149,  150,  151,  152,  153,  154,  155,  156,  157,  158,
   -1,  258,   -1,   -1,   -1,   -1,  258,  264,  265,   -1,
   -1,   -1,  264,  265,  173,   -1,  273,  176,  275,   -1,
  277,  273,   -1,   -1,   -1,  277,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  293,   -1,  295,  296,
  297,  293,   -1,  295,  296,  297,  259,  260,  261,  262,
   -1,  210,   -1,  266,   -1,  268,  269,  270,  271,   -1,
  219,   -1,   -1,   -1,   -1,   -1,   -1,  226,   -1,   -1,
   -1,   -1,  285,  286,   -1,  288,  289,  259,  260,  261,
  262,   -1,   -1,   -1,  266,   -1,  268,  269,  270,  271,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  285,  286,   -1,  288,  289,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 304
#define YYUNDFTOKEN 337
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'('","')'",0,0,"','",0,"'.'",0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"error","NUM","ID","PLUS","MUL","DIV","MOD","ASGN","READ","WRITE","MINUS",
"NEWLINE","LT","GT","DEQ","NEQ","ELSE","IF","THEN","ENDIF","ENDWHILE","WHILE",
"DO","START","END","DECL","ENDDECL","INT","STR","LE","GE","NOT","AND","OR",
"MAIN","RETURN","ALLOC","FREE","INIT","BRK","CONTINUE","BRKP","TYPE","ENDTYPE",
"NILL","DEQNILL","NEQNILL","STRVAL","EXPOSCALL","$accept","program","Expr",
"Slist","Stmt","Body","mainblock","Retstmt","fdef","exprlist",
"exprlist_exposcall","FIELD","TypeDefBlock","gdeclaration","fdeflist",
"TypeDefList","TypeDef","FieldDeclList","FieldDecl","FieldType","GDeclList",
"GDecl","TypeName","Gidlist","ParamList","FType","Param","fvlist","LdeclBlock",
"ldlist","ldec","lvlist","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : TypeDefBlock gdeclaration fdeflist mainblock",
"program : TypeDefBlock gdeclaration mainblock",
"TypeDefBlock : TYPE TypeDefList ENDTYPE",
"TypeDefBlock :",
"TypeDefList : TypeDefList TypeDef",
"TypeDefList : TypeDef",
"TypeDef : ID '{' FieldDeclList '}'",
"FieldDeclList : FieldDeclList FieldDecl",
"FieldDeclList : FieldDecl",
"FieldDecl : FieldType ID ';'",
"gdeclaration : DECL GDeclList ENDDECL",
"gdeclaration :",
"GDeclList : GDecl",
"GDeclList : GDeclList GDecl",
"GDecl : TypeName Gidlist ';'",
"Gidlist : ID",
"Gidlist : ID '[' NUM ']'",
"Gidlist : ID '(' ParamList ')'",
"Gidlist : Gidlist ',' ID",
"Gidlist : Gidlist ',' ID '[' NUM ']'",
"Gidlist : Gidlist ',' ID '(' ParamList ')'",
"FieldType : INT",
"FieldType : STR",
"FieldType : ID",
"TypeName : INT",
"TypeName : STR",
"TypeName : ID",
"FType : INT",
"FType : STR",
"FType : ID",
"ParamList : Param",
"ParamList : ParamList ',' Param",
"ParamList :",
"Param : FType fvlist",
"fvlist : ID",
"fdeflist : fdef",
"fdeflist : fdeflist fdef",
"fdef : TypeName ID '(' ParamList ')' '{' LdeclBlock Body '}'",
"LdeclBlock : DECL ldlist ENDDECL",
"LdeclBlock :",
"ldlist : ldec",
"ldlist : ldlist ldec",
"ldec : FType lvlist ';'",
"lvlist : ID",
"lvlist : lvlist ',' ID",
"mainblock : TypeName MAIN '(' ')' '{' LdeclBlock Body '}'",
"Body : START Slist Retstmt END",
"Body : START Retstmt END",
"Retstmt : RETURN Expr ';'",
"Slist : Slist Stmt",
"Slist : Stmt",
"Stmt : ID ASGN Expr ';'",
"Stmt : ID '[' Expr ']' ASGN Expr ';'",
"Stmt : READ '(' ID ')' ';'",
"Stmt : READ '(' ID '[' Expr ']' ')' ';'",
"Stmt : WRITE '(' Expr ')' ';'",
"Stmt : IF '(' Expr ')' THEN Slist ENDIF ';'",
"Stmt : IF '(' Expr ')' THEN Slist ELSE Slist ENDIF ';'",
"Stmt : WHILE '(' Expr ')' DO Slist ENDWHILE ';'",
"Stmt : ID ASGN ALLOC '(' ')' ';'",
"Stmt : FIELD ASGN ALLOC '(' ')' ';'",
"Stmt : FIELD ASGN FIELD ';'",
"Stmt : FIELD ASGN Expr ';'",
"Stmt : FREE '(' ID ')' ';'",
"Stmt : FREE '(' FIELD ')' ';'",
"Stmt : READ '(' FIELD ')' ';'",
"Stmt : ID ASGN NILL ';'",
"Stmt : FIELD ASGN NILL ';'",
"Stmt : ID ASGN EXPOSCALL '(' exprlist_exposcall ')' ';'",
"Stmt : ID ASGN INIT '(' ')' ';'",
"Stmt : BRK ';'",
"Stmt : CONTINUE ';'",
"Stmt : BRKP ';'",
"FIELD : ID '.' ID",
"FIELD : FIELD '.' ID",
"exprlist : Expr",
"exprlist : exprlist ',' Expr",
"exprlist_exposcall : Expr",
"exprlist_exposcall : exprlist_exposcall ',' Expr",
"Expr : Expr PLUS Expr",
"Expr : Expr MINUS Expr",
"Expr : Expr MUL Expr",
"Expr : Expr DIV Expr",
"Expr : Expr MOD Expr",
"Expr : Expr LT Expr",
"Expr : Expr LE Expr",
"Expr : Expr GT Expr",
"Expr : Expr GE Expr",
"Expr : Expr DEQ Expr",
"Expr : Expr NEQ Expr",
"Expr : Expr AND Expr",
"Expr : Expr OR Expr",
"Expr : NOT Expr",
"Expr : '(' Expr ')'",
"Expr : FIELD",
"Expr : NUM",
"Expr : MINUS NUM",
"Expr : STRVAL",
"Expr : ID",
"Expr : ID '[' Expr ']'",
"Expr : ID '(' exprlist ')'",
"Expr : ID '(' ')'",
"Expr : ID DEQNILL",
"Expr : ID NEQNILL",
"Expr : FIELD DEQNILL",
"Expr : FIELD NEQNILL",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 744 "abstree.y"

void yyerror(char const *s)
{
    printf("%d: %s\n", lineno, s);
    return ;
}

int main(int argc, char *argv[])
{
    TInstall("integer", 1, NULL);
    TInstall("string", 1, NULL);
    TInstall("boolean", 1, NULL);
    TInstall("array_integer", 1, NULL);
    TInstall("array_string", 1, NULL);
    TInstall("void", 0, NULL);
    TInstall("dummy", 0, NULL); // This is for creating the fieldlist in case of udt

    if (argc < 2)
    {
        printf("Please provide an input filename\n");
        exit(1);
    }
    else
    {
        fp = fopen(argv[1], "r");
        if (!fp)
        {
            printf("Invalid input file specified\n");
            exit(1);
        }
        else
            yyin = fp;
    }
    yyparse();
    return 0;
}
#line 944 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 97 "abstree.y"
	{
			                                            fclose(intermediate);
                        								}
#line 1619 "y.tab.c"
break;
case 2:
#line 100 "abstree.y"
	{
		                                            fclose(intermediate);
                                    			 }
#line 1626 "y.tab.c"
break;
case 3:
#line 105 "abstree.y"
	{}
#line 1631 "y.tab.c"
break;
case 4:
#line 106 "abstree.y"
	{}
#line 1636 "y.tab.c"
break;
case 7:
#line 113 "abstree.y"
	{
	                                    TInstall(yystack.l_mark[-3].nptr->name, 0, Fhead); /*size is initialized to 0. actual size is calculated in TInstall*/
                               		}
#line 1643 "y.tab.c"
break;
case 10:
#line 122 "abstree.y"
	{
	                                if(FLookup (yystack.l_mark[-1].nptr->name, Fhead) != NULL)
	                                {
	                                    yyerror("Re-declaration of field element\n");
	                                    exit(1);
	                                }
						            FInstall(declarationType, yystack.l_mark[-1].nptr->name);
								}
#line 1655 "y.tab.c"
break;
case 11:
#line 131 "abstree.y"
	{
                                            start();
                                        }
#line 1662 "y.tab.c"
break;
case 12:
#line 134 "abstree.y"
	{
                                            start();
                                        }
#line 1669 "y.tab.c"
break;
case 13:
#line 139 "abstree.y"
	{}
#line 1674 "y.tab.c"
break;
case 14:
#line 140 "abstree.y"
	{}
#line 1679 "y.tab.c"
break;
case 15:
#line 143 "abstree.y"
	{}
#line 1684 "y.tab.c"
break;
case 16:
#line 146 "abstree.y"
	{
                            verify(yystack.l_mark[0].nptr, 1, 0, 0, NULL);
                            GInstall(yystack.l_mark[0].nptr->name, declarationType, 1, NULL);
                        }
#line 1692 "y.tab.c"
break;
case 17:
#line 150 "abstree.y"
	{
                            verify(yystack.l_mark[-3].nptr, 1, 0, 0, NULL);
                            install_id(yystack.l_mark[-3].nptr, yystack.l_mark[-1].nptr, declarationType);
                        }
#line 1700 "y.tab.c"
break;
case 18:
#line 154 "abstree.y"
	{
                                declcount++; /*  to keep track of number of functions declared*/
                                verify(yystack.l_mark[-3].nptr, 1, 0, 0, NULL);
                                GInstall(yystack.l_mark[-3].nptr->name, declarationType, -1, Phead);
                                Phead = NULL;
                                Ptail = NULL;
                            }
#line 1711 "y.tab.c"
break;
case 19:
#line 161 "abstree.y"
	{
                                verify(yystack.l_mark[0].nptr, 1, 0, 0, NULL);
                                GInstall(yystack.l_mark[0].nptr->name,declarationType,1,NULL);
                            }
#line 1719 "y.tab.c"
break;
case 20:
#line 165 "abstree.y"
	{
                                    verify(yystack.l_mark[-3].nptr, 1, 0, 0, NULL);
                                    install_id(yystack.l_mark[-3].nptr, yystack.l_mark[-1].nptr, declarationType);
                                }
#line 1727 "y.tab.c"
break;
case 21:
#line 169 "abstree.y"
	{
                                            declcount++; /*  to keep track of number of functions declared*/
                                            verify(yystack.l_mark[-3].nptr, 1, 0, 0, NULL);
                                            GInstall(yystack.l_mark[-3].nptr->name, declarationType, -1, Phead);
                                            Phead = NULL;
                                            Ptail = NULL;
                                        }
#line 1738 "y.tab.c"
break;
case 22:
#line 178 "abstree.y"
	{declarationType = TLookup("integer");}
#line 1743 "y.tab.c"
break;
case 23:
#line 179 "abstree.y"
	{declarationType = TLookup("string");}
#line 1748 "y.tab.c"
break;
case 24:
#line 180 "abstree.y"
	{
                        declarationType = TLookup(yystack.l_mark[0].nptr->name);
                        if (declarationType == NULL)
                            declarationType = TLookup("dummy");
                    }
#line 1757 "y.tab.c"
break;
case 25:
#line 187 "abstree.y"
	{declarationType = TLookup("integer");}
#line 1762 "y.tab.c"
break;
case 26:
#line 188 "abstree.y"
	{declarationType = TLookup("string");}
#line 1767 "y.tab.c"
break;
case 27:
#line 189 "abstree.y"
	{
                        declarationType = TLookup(yystack.l_mark[0].nptr->name);
                        if (declarationType == NULL)
                        {
                            yyerror("Unknown user-defined type\n");
                            exit(1);
                        }
                    }
#line 1779 "y.tab.c"
break;
case 28:
#line 199 "abstree.y"
	{FdeclarationType = TLookup("integer");}
#line 1784 "y.tab.c"
break;
case 29:
#line 200 "abstree.y"
	{FdeclarationType = TLookup("string");}
#line 1789 "y.tab.c"
break;
case 30:
#line 201 "abstree.y"
	{
                   FdeclarationType = TLookup(yystack.l_mark[0].nptr->name);
                    if (FdeclarationType == NULL)
                    {
                        yyerror("Unknown user-defined type\n");
                        exit(1);
                    }
                }
#line 1801 "y.tab.c"
break;
case 31:
#line 211 "abstree.y"
	{}
#line 1806 "y.tab.c"
break;
case 32:
#line 212 "abstree.y"
	{}
#line 1811 "y.tab.c"
break;
case 33:
#line 213 "abstree.y"
	{}
#line 1816 "y.tab.c"
break;
case 34:
#line 216 "abstree.y"
	{}
#line 1821 "y.tab.c"
break;
case 35:
#line 219 "abstree.y"
	{
                                        verify(yystack.l_mark[0].nptr, 0, 0, 1, NULL);
                                        PInstall(yystack.l_mark[0].nptr->name, FdeclarationType);
                                    }
#line 1829 "y.tab.c"
break;
case 36:
#line 225 "abstree.y"
	{}
#line 1834 "y.tab.c"
break;
case 37:
#line 226 "abstree.y"
	{}
#line 1839 "y.tab.c"
break;
case 38:
#line 229 "abstree.y"
	{
                                                                defcount++; /*  to keep track of number of functions defined*/

                                                                Gtemp = GLookup(yystack.l_mark[-7].nptr->name);

                                                                if (Gtemp == NULL)
                                                                {
                                                                    printf("Function not declared in GST\n");
                                                                    exit(1);
                                                                }

                                                                /*storing arguments in LST*/

                                                                Argtemp1 = Phead;
                                                                Argtemp2 = Gtemp->paramlist;

                                                                while ((Argtemp1 != NULL) && (Argtemp2 != NULL))
                                                                {
                                                                    if (strcmp(Argtemp1->name, Argtemp2->name) == 0)
                                                                    {
                                                                        if (Argtemp1->type != Argtemp2->type)
                                                                        {
                                                                            printf("Conflict in argument types \n");
                                                                            exit(1);
                                                                        }
                                                                    }
                                                                    else
                                                                    {
                                                                        printf("Conflict in argument names \n");
                                                                        exit(1);
                                                                    }

                                                                    Argtemp1 = Argtemp1->next;
                                                                    Argtemp2 = Argtemp2->next;
                                                                }

                                                                if ((Argtemp1 != NULL) || (Argtemp2 != NULL))
                                                                {
                                                                    printf("Unequal number of arguments \n");
                                                                    exit(1);
                                                                }

                                                                yystack.l_mark[-7].nptr->Lentry = Lhead;

                                                                fprintf(intermediate, "F%d:\n",Gtemp->binding);
                                                                fprintf(intermediate, "PUSH BP\n");
                                                                fprintf(intermediate, "MOV BP,SP\n");

                                                                Ltemp = Lhead;

                                                                while(Ltemp != NULL)
                                                                {
                                                                    fprintf(intermediate, "PUSH R0\n");
                                                                    Ltemp = Ltemp->next;
                                                                }

                                                                codegen(yystack.l_mark[-1].nptr);

                                                                Phead = NULL;
                                                                Ptail = NULL;
                                                                Lhead = NULL;
                                                                Ltail = NULL;
                                                            }
#line 1906 "y.tab.c"
break;
case 39:
#line 294 "abstree.y"
	{}
#line 1911 "y.tab.c"
break;
case 40:
#line 295 "abstree.y"
	{}
#line 1916 "y.tab.c"
break;
case 41:
#line 298 "abstree.y"
	{}
#line 1921 "y.tab.c"
break;
case 42:
#line 299 "abstree.y"
	{}
#line 1926 "y.tab.c"
break;
case 43:
#line 302 "abstree.y"
	{}
#line 1931 "y.tab.c"
break;
case 44:
#line 305 "abstree.y"
	{
                            verify(yystack.l_mark[0].nptr, 0, 1, 0, NULL);
                            LInstall(yystack.l_mark[0].nptr->name, FdeclarationType);
                         }
#line 1939 "y.tab.c"
break;
case 45:
#line 309 "abstree.y"
	{
                            verify(yystack.l_mark[0].nptr, 0, 1, 0, NULL);
                            LInstall(yystack.l_mark[0].nptr->name, FdeclarationType);
                        }
#line 1947 "y.tab.c"
break;
case 46:
#line 316 "abstree.y"
	{
                                if (declcount != defcount)
                                {
                                    yyerror("All functions declared need to be defined\n");
                                    exit(1);
                                }
                                if (declarationType != TLookup("integer"))
                                {
                                    yyerror("Main return type should be of integer type\n");
                                    exit(1);
                                }

                                fprintf(intermediate, "MAIN:\n");
                                fprintf(intermediate, "PUSH BP\n");
                                fprintf(intermediate, "MOV BP,SP\n");

                                Ltemp = Lhead;

                                while (Ltemp != NULL)
                                {
                                    fprintf(intermediate, "PUSH R0\n");
                                    Ltemp = Ltemp->next;
                                }

                                codegen(yystack.l_mark[-1].nptr);

                                Lhead = NULL;
                                Ltail = NULL;
                            }
#line 1980 "y.tab.c"
break;
case 47:
#line 347 "abstree.y"
	{
                                    yyval.nptr = TreeCreate(TLookup("void"), DEFAULT, NULL, NULL, NULL, yystack.l_mark[-2].nptr, yystack.l_mark[-1].nptr, NULL);
                                }
#line 1987 "y.tab.c"
break;
case 48:
#line 350 "abstree.y"
	{
                                    yyval.nptr = TreeCreate(TLookup("void"), DEFAULT, NULL, NULL, NULL, NULL, yystack.l_mark[-1].nptr, NULL);
                                }
#line 1994 "y.tab.c"
break;
case 49:
#line 355 "abstree.y"
	{
                                if (declarationType == yystack.l_mark[-1].nptr->type)
                                    yyval.nptr = TreeCreate(yystack.l_mark[-1].nptr->type, NODE_RET, NULL, NULL, NULL, NULL, yystack.l_mark[-1].nptr, NULL);
                                else
                                {
                                    yyerror("return type do not match with the function return type\n");
                                    exit(1);
                                }
                            }
#line 2007 "y.tab.c"
break;
case 50:
#line 366 "abstree.y"
	{
                            head = (struct ASTNode *)malloc(sizeof(struct ASTNode));
                            head->nodetype = DEFAULT;
                            head->ptr1 = yystack.l_mark[-1].nptr;
                            head->ptr2 = yystack.l_mark[0].nptr;
                            yyval.nptr = head;
                        }
#line 2018 "y.tab.c"
break;
case 51:
#line 373 "abstree.y"
	{
                            yyval.nptr = yystack.l_mark[0].nptr;
                        }
#line 2025 "y.tab.c"
break;
case 52:
#line 378 "abstree.y"
	{
                                    type_assign(yystack.l_mark[-3].nptr, NULL, 0, 0, 0, 0, 0);
                                    if ((yystack.l_mark[-3].nptr->nodetype == NODE_FIELD) || (yystack.l_mark[-1].nptr->nodetype == NODE_FIELD))
                                    {
                                    	head = get_last(yystack.l_mark[-3].nptr);
                                    	head1 = get_last(yystack.l_mark[-1].nptr);
                                    	type_comp(head->type, head1->type, 'a');
                                    }
                                    else
                                    	type_comp(yystack.l_mark[-3].nptr->type, yystack.l_mark[-1].nptr->type, 'a');
                                    yyval.nptr = TreeCreate(TLookup("void"), NODE_ASGN, NULL, NULL, NULL, yystack.l_mark[-3].nptr, yystack.l_mark[-1].nptr, NULL);
                                }
#line 2041 "y.tab.c"
break;
case 53:
#line 390 "abstree.y"
	{
                                            type_assign_arr(yystack.l_mark[-6].nptr, yystack.l_mark[-4].nptr, 0);
                                            type_comp(yystack.l_mark[-6].nptr->type, yystack.l_mark[-1].nptr->type, 'a');
                                            yyval.nptr = TreeCreate(TLookup("void"), NODE_ARRAY_ASGN, NULL, NULL, NULL, yystack.l_mark[-6].nptr, yystack.l_mark[-4].nptr, yystack.l_mark[-1].nptr);
                                        }
#line 2050 "y.tab.c"
break;
case 54:
#line 395 "abstree.y"
	{
                                    type_assign(yystack.l_mark[-2].nptr, NULL, 0, 0, 0, 0, 1);
                                    yyval.nptr = TreeCreate(TLookup("void"), NODE_READ, NULL, NULL, NULL, NULL, yystack.l_mark[-2].nptr, NULL);
                                }
#line 2058 "y.tab.c"
break;
case 55:
#line 399 "abstree.y"
	{
                                                type_assign_arr(yystack.l_mark[-5].nptr, yystack.l_mark[-3].nptr, 0);
                                                yyval.nptr = TreeCreate(TLookup("void"), NODE_ARRAY_READ, NULL, NULL, NULL, NULL, yystack.l_mark[-5].nptr, yystack.l_mark[-3].nptr);
                                            }
#line 2066 "y.tab.c"
break;
case 56:
#line 403 "abstree.y"
	{
                                    if (yystack.l_mark[-2].nptr->type == TLookup("integer") || yystack.l_mark[-2].nptr->type == TLookup("string"))
                                    {
                                        yyval.nptr = TreeCreate(TLookup("void"), NODE_WRITE, NULL, NULL, NULL, NULL, yystack.l_mark[-2].nptr, NULL);
                                    }
                                    else
                                    {
                                        head = get_last(yystack.l_mark[-2].nptr);
                                        if (head->type == TLookup("integer") || head->type == TLookup("string"))
                                        {
                                            yyval.nptr = TreeCreate(TLookup("void"), NODE_WRITE, NULL, NULL, NULL, NULL, yystack.l_mark[-2].nptr, NULL);
                                        }
                                        else
                                        {
                                            yyerror("Cannot write a udt type\n");
                                            exit(1);
                                        }
                                    }

                                }
#line 2090 "y.tab.c"
break;
case 57:
#line 424 "abstree.y"
	{
                               		type_comp(yystack.l_mark[-5].nptr->type, TLookup("boolean"), 'i');
                                    yyval.nptr = TreeCreate(TLookup("void"), NODE_IF, NULL, NULL, NULL, yystack.l_mark[-5].nptr, yystack.l_mark[-2].nptr, NULL);
                               }
#line 2098 "y.tab.c"
break;
case 58:
#line 429 "abstree.y"
	{
                               		type_comp(yystack.l_mark[-7].nptr->type, TLookup("boolean"), 'e');
                                    yyval.nptr = TreeCreate(TLookup("void"), NODE_IF_ELSE, NULL, NULL, NULL, yystack.l_mark[-7].nptr, yystack.l_mark[-4].nptr, yystack.l_mark[-2].nptr);
                                }
#line 2106 "y.tab.c"
break;
case 59:
#line 434 "abstree.y"
	{
                               		type_comp(yystack.l_mark[-5].nptr->type, TLookup("boolean"), 'w');
                                    yyval.nptr = TreeCreate(TLookup("void"), NODE_WHILE, NULL, NULL, NULL, yystack.l_mark[-5].nptr, yystack.l_mark[-2].nptr, NULL);
                                }
#line 2114 "y.tab.c"
break;
case 60:
#line 438 "abstree.y"
	{
        								type_assign(yystack.l_mark[-5].nptr, NULL, 1, 0, 1, 0, 0);
                                        head = TreeCreate(TLookup("integer"), NODE_ALLOC, NULL, NULL, NULL, NULL, NULL, NULL);
                                        yyval.nptr = TreeCreate(TLookup("void"), NODE_ASGN, NULL, NULL, NULL, yystack.l_mark[-5].nptr, head, NULL);
                                    }
#line 2123 "y.tab.c"
break;
case 61:
#line 443 "abstree.y"
	{
                                            head = get_last(yystack.l_mark[-5].nptr);
                                            if ((head->type == TLookup("integer")) || (head->type == TLookup("string")))
                                            {
                                                yyerror("Cannot ALLOC to string or integer variable\n");
                                                exit(1);
                                            }
                                            else
                                            {
                                                head = TreeCreate(TLookup("integer"), NODE_ALLOC, NULL, NULL, NULL, NULL, NULL, NULL);
                                                yyval.nptr = TreeCreate(TLookup("void"), NODE_ASGN, NULL, NULL, NULL, yystack.l_mark[-5].nptr, head, NULL);
                                            }
                                        }
#line 2140 "y.tab.c"
break;
case 62:
#line 456 "abstree.y"
	{
                                            head = get_last(yystack.l_mark[-3].nptr);
                                            head1 = get_last(yystack.l_mark[-1].nptr);
                                            if (head1->type == head->type)
                                                yyval.nptr = TreeCreate(TLookup("void"), NODE_ASGN, NULL, NULL, NULL, yystack.l_mark[-3].nptr, yystack.l_mark[-1].nptr, NULL);
                                            else
                                            {
                                                yyerror("conflicting assignment types in field1\n");
                                                exit(1);
                                            }
                                        }
#line 2155 "y.tab.c"
break;
case 63:
#line 467 "abstree.y"
	{
                                            head = get_last(yystack.l_mark[-3].nptr);
                                            if (yystack.l_mark[-1].nptr->type == head->type)
                                                yyval.nptr = TreeCreate(TLookup("void"), NODE_ASGN, NULL, NULL, NULL, yystack.l_mark[-3].nptr, yystack.l_mark[-1].nptr, NULL);
                                            else
                                            {
                                                yyerror("conflicting assignment types in field2\n");
                                                exit(1);
                                            }
                                        }
#line 2169 "y.tab.c"
break;
case 64:
#line 477 "abstree.y"
	{
                                            type_assign(yystack.l_mark[-2].nptr, NULL, 1, 1, 0, 0, 0);
                                            yyval.nptr = TreeCreate(TLookup("void"), NODE_FREE, NULL, NULL, NULL, NULL, yystack.l_mark[-2].nptr, NULL);
                                        }
#line 2177 "y.tab.c"
break;
case 65:
#line 481 "abstree.y"
	{
                                            head = get_last(yystack.l_mark[-2].nptr);
                                            if ((head->type == TLookup("integer")) || (head->type == TLookup("string")))
                                            {
                                                yyerror("cannot FREE non-udt\n");
                                                exit(1);
                                            }
                                            yyval.nptr = TreeCreate(TLookup("void"), NODE_FREE, NULL, NULL, NULL, NULL, yystack.l_mark[-2].nptr, NULL);
	                                    }
#line 2190 "y.tab.c"
break;
case 66:
#line 490 "abstree.y"
	{
                                            head = get_last(yystack.l_mark[-2].nptr);

                                            if ((head->type != TLookup("integer")) && (head->type != TLookup("string")))
                                            {
                                                yyerror("cannot READ a udt type\n");
                                                exit(1);
                                            }
                                            yyval.nptr = TreeCreate(TLookup("void"), NODE_READ, NULL, NULL, NULL, NULL, yystack.l_mark[-2].nptr, NULL);
	                                    }
#line 2204 "y.tab.c"
break;
case 67:
#line 500 "abstree.y"
	{
			                                type_assign(yystack.l_mark[-3].nptr, NULL, 1, 0, 0, 0, 0);
			                                yyval.nptr = TreeCreate(TLookup("void"), NODE_ASGN, NULL, NULL, NULL, yystack.l_mark[-3].nptr, yystack.l_mark[-1].nptr, NULL);
			        					}
#line 2212 "y.tab.c"
break;
case 68:
#line 504 "abstree.y"
	{
                                head = get_last(yystack.l_mark[-3].nptr);

                                if (head->type == TLookup("integer") || head->type == TLookup("string")
                                    || head->type == TLookup("array_integer") || head->type == TLookup("array_string"))
                                {
                                    yyerror("cannot assign null to a non-udt\n");
                                    exit(1);
                                }
								yyval.nptr = TreeCreate(TLookup("void"), NODE_ASGN, NULL, NULL, NULL, yystack.l_mark[-3].nptr, yystack.l_mark[-1].nptr, NULL);
						    }
#line 2227 "y.tab.c"
break;
case 69:
#line 516 "abstree.y"
	{
                                                        if ((exprcount < 1) || (exprcount > 4))
                                                        {
                                                           yyerror("Incorrect number of arguments to exposcall function\n");
                                                           exit(1);
                                                        }

                                                        type_comp(NULL, yystack.l_mark[-2].nptr->type, 'x');
                                                        type_assign(yystack.l_mark[-6].nptr, NULL, 0, 0, 0, 0, 0);
                                                        type_comp(yystack.l_mark[-6].nptr -> type, NULL, 'x');

                                                        head1 = TreeCreate(TLookup("void"), NODE_EXPOSCALL, "exposcall", NULL, NULL, NULL, NULL, yystack.l_mark[-2].nptr);
                                                        yyval.nptr = TreeCreate(TLookup("void"), NODE_ASGN, NULL, NULL, NULL, yystack.l_mark[-6].nptr, head1, NULL);

													}
#line 2246 "y.tab.c"
break;
case 70:
#line 531 "abstree.y"
	{
                                        head = TreeCreate(TLookup("void"), NODE_INIT, NULL, NULL, NULL, NULL, NULL, NULL);
        								yyval.nptr = TreeCreate(TLookup("void"), NODE_ASGN, NULL, NULL, NULL, yystack.l_mark[-5].nptr, head, NULL);
							        }
#line 2254 "y.tab.c"
break;
case 71:
#line 536 "abstree.y"
	{
                            yyval.nptr = TreeCreate(TLookup("void"), NODE_BRK, NULL, NULL, NULL, NULL, NULL, NULL);
                        }
#line 2261 "y.tab.c"
break;
case 72:
#line 540 "abstree.y"
	{
                            yyval.nptr = TreeCreate(TLookup("void"), NODE_CONTINUE, NULL, NULL, NULL, NULL, NULL, NULL);
                        }
#line 2268 "y.tab.c"
break;
case 73:
#line 543 "abstree.y"
	{
                        yyval.nptr = TreeCreate(TLookup("void"), NODE_BRKP, NULL, NULL, NULL, NULL, NULL, NULL);
                    }
#line 2275 "y.tab.c"
break;
case 74:
#line 548 "abstree.y"
	{
                            yystack.l_mark[-2].nptr->nodetype = NODE_FIELD;
                            type_assign(yystack.l_mark[-2].nptr, yystack.l_mark[0].nptr, 1, 0, 0, 1, 0);
                            yyval.nptr = yystack.l_mark[-2].nptr;
                        }
#line 2284 "y.tab.c"
break;
case 75:
#line 553 "abstree.y"
	{
                            head1 = head = get_last(yystack.l_mark[-2].nptr);

                            temp1 = head->type;
                            if(temp1 != TLookup("string") && temp1 != TLookup("integer")
                                && temp1 != TLookup("array_integer") && temp1 != TLookup("array_string"))
                            {
                                ftemp = FLookup(yystack.l_mark[0].nptr->name, temp1->fields);
                                if(ftemp != NULL)
                                {
                                    yystack.l_mark[0].nptr->type = ftemp->type;
                                    head->ptr2 = yystack.l_mark[0].nptr;
                                    yyval.nptr = yystack.l_mark[-2].nptr;
                                }
                                else
                                {
                                    yyerror("Un-declared field variable\n");
                                    exit(1);
                                }
                            }
                            else
                            {
                                yyerror("Illegal access of identifier\n");
                                exit(1);
                            }
                        }
#line 2314 "y.tab.c"
break;
case 76:
#line 581 "abstree.y"
	{
                                    exprcount = 1;
                                    yyval.nptr = yystack.l_mark[0].nptr;
                                }
#line 2322 "y.tab.c"
break;
case 77:
#line 585 "abstree.y"
	{
                                    indicator = 1;
                                    exprcount++;
                                    head = (struct ASTNode *)malloc(sizeof(struct ASTNode));
                                    head->nodetype = NODE_EXPR;
                                    head->ptr1 = yystack.l_mark[0].nptr;
                                    head->ptr2 = yystack.l_mark[-2].nptr;
                                    yyval.nptr = head;
                                }
#line 2335 "y.tab.c"
break;
case 78:
#line 596 "abstree.y"
	{
                                exprcount = 1;
                                yyval.nptr = yystack.l_mark[0].nptr;
                            }
#line 2343 "y.tab.c"
break;
case 79:
#line 600 "abstree.y"
	{
                                                    exprcount++;
                                                    head = yystack.l_mark[-2].nptr;

                                                    while (head->ptr1 != NULL)
                                                        head = head->ptr1;

                                                    head->ptr1 = yystack.l_mark[0].nptr;
                                                    yyval.nptr = yystack.l_mark[-2].nptr;
                                                }
#line 2357 "y.tab.c"
break;
case 80:
#line 612 "abstree.y"
	{
                                type_comp(yystack.l_mark[-2].nptr->type, yystack.l_mark[0].nptr->type, '+');
                                yyval.nptr = TreeCreate(TLookup("integer"), NODE_PLUS , NULL, NULL, NULL, yystack.l_mark[-2].nptr, yystack.l_mark[0].nptr, NULL);
                            }
#line 2365 "y.tab.c"
break;
case 81:
#line 616 "abstree.y"
	{
                                type_comp(yystack.l_mark[-2].nptr->type, yystack.l_mark[0].nptr->type, '-');
                                yyval.nptr = TreeCreate(TLookup("integer"), NODE_MINUS , NULL, NULL , NULL, yystack.l_mark[-2].nptr, yystack.l_mark[0].nptr, NULL);
                            }
#line 2373 "y.tab.c"
break;
case 82:
#line 620 "abstree.y"
	{
                                type_comp(yystack.l_mark[-2].nptr->type, yystack.l_mark[0].nptr->type, '*');
                                yyval.nptr = TreeCreate(TLookup("integer"), NODE_MUL , NULL, NULL , NULL, yystack.l_mark[-2].nptr, yystack.l_mark[0].nptr, NULL);
                            }
#line 2381 "y.tab.c"
break;
case 83:
#line 624 "abstree.y"
	{
                                type_comp(yystack.l_mark[-2].nptr->type, yystack.l_mark[0].nptr->type, '/');
                                yyval.nptr = TreeCreate(TLookup("integer"), NODE_DIV , NULL, NULL , NULL, yystack.l_mark[-2].nptr, yystack.l_mark[0].nptr, NULL);
                            }
#line 2389 "y.tab.c"
break;
case 84:
#line 628 "abstree.y"
	{
                                type_comp(yystack.l_mark[-2].nptr->type, yystack.l_mark[0].nptr->type, '%');
                                yyval.nptr = TreeCreate(TLookup("integer"), NODE_MOD , NULL, NULL , NULL, yystack.l_mark[-2].nptr, yystack.l_mark[0].nptr, NULL);
                            }
#line 2397 "y.tab.c"
break;
case 85:
#line 632 "abstree.y"
	{
                                type_comp(yystack.l_mark[-2].nptr->type, yystack.l_mark[0].nptr->type, '<');
                                yyval.nptr = TreeCreate(TLookup("boolean"), NODE_LT , NULL, NULL, NULL, yystack.l_mark[-2].nptr, yystack.l_mark[0].nptr, NULL);
                            }
#line 2405 "y.tab.c"
break;
case 86:
#line 636 "abstree.y"
	{
                                type_comp(yystack.l_mark[-2].nptr->type, yystack.l_mark[0].nptr->type, '#');
                                yyval.nptr = TreeCreate(TLookup("boolean"), NODE_LE , NULL, NULL, NULL, yystack.l_mark[-2].nptr, yystack.l_mark[0].nptr, NULL);
                            }
#line 2413 "y.tab.c"
break;
case 87:
#line 640 "abstree.y"
	{
                                type_comp(yystack.l_mark[-2].nptr->type, yystack.l_mark[0].nptr->type, '>');
                                yyval.nptr = TreeCreate(TLookup("boolean"), NODE_GT , NULL, NULL, NULL, yystack.l_mark[-2].nptr, yystack.l_mark[0].nptr, NULL);
                            }
#line 2421 "y.tab.c"
break;
case 88:
#line 644 "abstree.y"
	{
                                type_comp(yystack.l_mark[-2].nptr->type, yystack.l_mark[0].nptr->type, '$');
                                yyval.nptr = TreeCreate(TLookup("boolean"), NODE_GE , NULL, NULL, NULL, yystack.l_mark[-2].nptr, yystack.l_mark[0].nptr, NULL);
                            }
#line 2429 "y.tab.c"
break;
case 89:
#line 648 "abstree.y"
	{
                                type_comp(yystack.l_mark[-2].nptr->type, yystack.l_mark[0].nptr->type, 'd');
                                yyval.nptr = TreeCreate(TLookup("boolean"), NODE_DEQ, NULL, NULL, NULL, yystack.l_mark[-2].nptr, yystack.l_mark[0].nptr, NULL);
                            }
#line 2437 "y.tab.c"
break;
case 90:
#line 652 "abstree.y"
	{
                                type_comp(yystack.l_mark[-2].nptr->type, yystack.l_mark[0].nptr->type, 'n');
                                yyval.nptr = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, yystack.l_mark[-2].nptr, yystack.l_mark[0].nptr, NULL);
                            }
#line 2445 "y.tab.c"
break;
case 91:
#line 656 "abstree.y"
	{
                                type_comp(yystack.l_mark[-2].nptr->type, yystack.l_mark[0].nptr->type, '&');
                                yyval.nptr = TreeCreate(TLookup("boolean"), NODE_AND, NULL, NULL, NULL, yystack.l_mark[-2].nptr, yystack.l_mark[0].nptr, NULL);
                            }
#line 2453 "y.tab.c"
break;
case 92:
#line 660 "abstree.y"
	{
                                type_comp(yystack.l_mark[-2].nptr->type, yystack.l_mark[0].nptr->type, '|');
                                yyval.nptr = TreeCreate(TLookup("boolean"), NODE_OR, NULL, NULL, NULL, yystack.l_mark[-2].nptr, yystack.l_mark[0].nptr, NULL);
                            }
#line 2461 "y.tab.c"
break;
case 93:
#line 664 "abstree.y"
	{
                                type_comp(yystack.l_mark[0].nptr->type, NULL, '!');
                                yyval.nptr = TreeCreate(TLookup("boolean"), NODE_NOT, NULL, NULL, NULL, NULL, yystack.l_mark[0].nptr, NULL);
                            }
#line 2469 "y.tab.c"
break;
case 94:
#line 668 "abstree.y"
	{
                                yyval.nptr = yystack.l_mark[-1].nptr;
                            }
#line 2476 "y.tab.c"
break;
case 95:
#line 671 "abstree.y"
	{
                                yyval.nptr = yystack.l_mark[0].nptr;
                            }
#line 2483 "y.tab.c"
break;
case 96:
#line 674 "abstree.y"
	{
                                yyval.nptr = yystack.l_mark[0].nptr;
				                yyval.nptr->type = TLookup("integer");
                            }
#line 2491 "y.tab.c"
break;
case 97:
#line 678 "abstree.y"
	{
                                yystack.l_mark[0].nptr->value.intval = (yystack.l_mark[0].nptr->value.intval) * -1;   /*negating the value*/
                                yyval.nptr = yystack.l_mark[0].nptr;
				                yyval.nptr->type = TLookup("integer");
                            }
#line 2500 "y.tab.c"
break;
case 98:
#line 683 "abstree.y"
	{
        						yyval.nptr = yystack.l_mark[0].nptr;
							    yyval.nptr->type = TLookup("string");
        					}
#line 2508 "y.tab.c"
break;
case 99:
#line 687 "abstree.y"
	{
				    			type_assign(yystack.l_mark[0].nptr, NULL, 0, 0, 0, 0, 0);
				    			yyval.nptr = yystack.l_mark[0].nptr;
				            }
#line 2516 "y.tab.c"
break;
case 100:
#line 691 "abstree.y"
	{
								type_assign_arr(yystack.l_mark[-3].nptr, yystack.l_mark[-1].nptr, 0);
								yyval.nptr = TreeCreate(yystack.l_mark[-3].nptr->type, NODE_ARRAY, NULL, NULL, NULL, yystack.l_mark[-3].nptr, yystack.l_mark[-1].nptr, NULL);
                            }
#line 2524 "y.tab.c"
break;
case 101:
#line 695 "abstree.y"
	{
        						type_assign_arr(yystack.l_mark[-3].nptr, yystack.l_mark[-1].nptr, 1);

                                yystack.l_mark[-1].nptr->ptr3 = Gtemp->paramlist;
                                Arg_callee = Gtemp->paramlist;
                                while (Arg_callee != NULL)
                                {
                                    exprcount--;
                                    Arg_callee = Arg_callee->next;
                                }
                                if (exprcount)
                                {
                                    yyerror("Unequal number of arguments\n");
                                    exit(1);
                                }
                                
                                /*differentiating b/w one and more than one arguments*/
                                if (indicator == 1)
                                {
                                    yyval.nptr = TreeCreate(yystack.l_mark[-3].nptr->type, NODE_FUNC, yystack.l_mark[-3].nptr->name, NULL, Gtemp->paramlist, NULL, yystack.l_mark[-1].nptr, NULL);
                                    indicator = 0;
                                }

                                else
                                    yyval.nptr = TreeCreate(yystack.l_mark[-3].nptr->type, NODE_FUNC, yystack.l_mark[-3].nptr->name, NULL, Gtemp->paramlist, NULL, NULL, yystack.l_mark[-1].nptr);
                            }
#line 2554 "y.tab.c"
break;
case 102:
#line 721 "abstree.y"
	{
    							type_assign_arr(yystack.l_mark[-2].nptr, NULL, 1);
                                yyval.nptr = TreeCreate(yystack.l_mark[-2].nptr->type, NODE_FUNC, yystack.l_mark[-2].nptr->name, NULL, Gtemp->paramlist, NULL, NULL, NULL);
                            }
#line 2562 "y.tab.c"
break;
case 103:
#line 725 "abstree.y"
	{
	   						    type_assign(yystack.l_mark[-1].nptr, NULL, 1, 0, 0, 0, 0);
		                    	yyval.nptr = TreeCreate(TLookup("boolean"), NODE_DEQ, NULL, NULL, NULL, yystack.l_mark[-1].nptr, yystack.l_mark[0].nptr, NULL);
			    			}
#line 2570 "y.tab.c"
break;
case 104:
#line 729 "abstree.y"
	{
	   						    type_assign(yystack.l_mark[-1].nptr, NULL, 1, 0, 0, 0, 0);
	                        	yyval.nptr = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, yystack.l_mark[-1].nptr, yystack.l_mark[0].nptr, NULL);
	        				}
#line 2578 "y.tab.c"
break;
case 105:
#line 733 "abstree.y"
	{
	                            type_comp(yystack.l_mark[-1].nptr, NULL, '=');
	                            yyval.nptr = TreeCreate(TLookup("boolean"), NODE_DEQ, NULL, NULL, NULL, yystack.l_mark[-1].nptr, yystack.l_mark[0].nptr, NULL);
	        				}
#line 2586 "y.tab.c"
break;
case 106:
#line 737 "abstree.y"
	{
	                            type_comp(yystack.l_mark[-1].nptr, NULL, '^');
	                            yyval.nptr = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, yystack.l_mark[-1].nptr, yystack.l_mark[0].nptr, NULL);
	        				}
#line 2594 "y.tab.c"
break;
#line 2596 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
