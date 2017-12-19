/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
