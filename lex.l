%{
#define YYSTYPE Node*
#include "node.h"
#include "parser.hpp"
#include<sstream>
#include<string>
#include<string.h>
void yyerror(const char *msg);

%}

letter [A-Za-z_]
digit  [0-9]
integer ([1-9]{digit}*)|(0)
id     {letter}({letter}|{digit})*
space  [ \t]
charval   [']([A-Za-z]|(\a)|(\b)|(\f)|(\n)|(\r)|(\t)|(\v)|(\\)|(\')|(\")|(\?))[']
float  ({digit}+)?(\.{digit}*)?((E|e)[+-]?{digit}+)?
ignore   {space}+
comment_line  \/\/[^\n]*
comment_block \/\*([^\*^\/]*|[\*^\/*]*|[^\**\/]*)*\*\/
newline  \n

%%
void  		{ yylval=new Node(); yylval->var_name=yytext;return TYPE;}
int  		{ yylval=new Node(); yylval->var_name=yytext;return TYPE;}
char  		{ yylval=new Node(); yylval->var_name=yytext;return TYPE;}
double  	{ yylval=new Node(); yylval->var_name=yytext;return TYPE;}
float  		{ yylval=new Node(); yylval->var_name=yytext;return TYPE;}
write       {return WRITE;}
read        {return  READ;}
return  	{return  RETURN;}
continue  	{return  CONTINUE ;}
break  		{return  BREAK ;}
goto  		{return  GOTO ;}
if  		{return IF ;}
else  		{return ELSE ;}
for  		{return FOR ;}
do  		{return DO ;}
while  		{return  WHILE ;}
"{"		    {return LBRACE; }
"}"		    {return  RBRACE; }
"["         {return  LBRACKET; }
"]"         {return  RBRACKET; }
"("		    {return  LPAREN; }
")"		    {return  RPAREN; }
","		    {return  MORE; }
"'"		    {return  SQM; }
";"         {return  ENDSTMT;}
"&"		    {return  BITAND; } 
"*"         {return  MUL;}  
"<<"	    {return  SHL; }  
">>"	    {return  SHR; }  
"="		    {return  ASSIGN; }
"=="        {return  EQ; }  
">="	    {return  RE; }  
">"		    {return  RT; }  
"<="	    {return  LE; }  
"<"		    {return  LT; }  
"!="	    {return  NE; }   
"||"	    {return  OR; }   
"&&"	    {return  AND; }   
"|"		    {return  BITOR; }  
"^"		    {return  XOR; }  
"!"		    {return  NOT; }  
"+"		    {return  PLUS; } 
"-"		    {return  MINUS; }
"/"		    {return  DIV; }    
"~"         {return  BITNOT;}    
"%"         {return  MOD;}     
"++"	    {return  TPLUS;}   
"--"        {return  TMINUS;} 
":"         {return  COLON;}
"?"         {return QUEST; }
{ignore}    {
			}
{newline}   {   
			}
{comment_block}  {}
{comment_line}   {}
{charval}	{
                yylval=new Node();
                string s=yytext; 
                s=s.substr(1,s.length()-2);
                yylval->value=s;
				return CHARVAL ;
            }
{integer}   {  
               yylval= new Node(); 
			  // int val=atoi(yytext);
			   yylval->value=yytext;
               return INTEGER;
	        }
{float}    {
                yylval= new Node(); 
			    double val;
                stringstream ss;
                ss<<yytext;
                ss>>val;
			    yylval->value=yytext;
                return FLOAT;
			}
{id}       {
                yylval=new Node();
                yylval->var_name=yytext;
				return IDENTIFIER ;
            }
.           {
				return CHARS;
            }
%%

int yywrap(void) { 
    return 1;
}

void yyerror(const char *msg) {
    printf("Error: %s\n", msg);
    exit(1);
}