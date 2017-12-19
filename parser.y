%{
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

%}

/*tokens*/
%token NEWLINE IDENTIFIER INTEGER FLOAT CHARVAL CHARS
//STRING NEVERA NEVERB NEVERC NEVERD NEVERE
/*reservedWord*/
%token IF ELSE WHILE DO BREAK CONTINUE TYPE FOR  RETURN READ WRITE GOTO
/*other signs*/
%token ENDSTMT LBRACE RBRACE SQM 
/*operator*/
%left MORE
%right ASSIGN 
%right COLON QUEST
%left OR
%left AND
%left BITOR
%left XOR
%left BITAND
%left EQ NE
%left SHL SHR RT RE LT LE
%left PLUS MINUS
%left MUL DIV MOD
%right _UMINUS TPLUS TMINUS _VAL _ADDR NOT BITNOT
%left LBRACKET RBRACKET LPAREN RPAREN  
%nonassoc _IF
%nonassoc _ELSE

%start translationUnits
%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

/*TranslationUnits*/
translationUnits :	translationUnit		
				|	translationUnits translationUnit	
				;

translationUnit	:	functionDefinition		
				|	declarationStatement	
				;

/*Statement*/
statement		:	simpleStatement		{$$=$1;}
				|	compoundStatement	{$$=$1;}
				;

statementList	:	statement 			{$$=new Node($1,5,"STMT");}
				|	statement statementList		{$$=new Node($1,1,"COMP_STMT");$$->addAllChild($2);}
				;/**/
//statement statementList
simpleStatement	:	declarationStatement	{$$=$1;}
				|	expressionStatement		{$$=$1;}
				|	controlStatement		{$$=$1;}
				| readStatement           {$$=$1;}
				| writeStatement          {$$=$1;}
				;

compoundStatement :	LBRACE RBRACE					 {$$=new Node(1,"STMT_EMPTY");}
				|	LBRACE statementList RBRACE		{$$=$2;}
				;

readStatement :  READ LPAREN identifier RPAREN{$$=new Node($3,1,"STMT READ");}
              ;
writeStatement:  WRITE  LPAREN identifier RPAREN{$$=new Node($3,1,"STMT WRITE");}
              ;
/*declarationStatement*/
	/*type can be "int", "const int", "const int *",..*/
declarationStatement :	type declarationList ENDSTMT	{$$=new Node($1,$2,1,"STMT DECLARE");}
					;

declarationList	:	declaration		{$$=new Node($1,1,"DECLARE_LIST");}
				|	declarationList MORE declaration	{$$=new Node(1,"DECLARE_LIST");$$->addAllChild($1);$$->addChild($3);}
				;

declaration		:	declarator		{$$=new Node($1,2,"EXPR DECLARE_VAR");}
//var_info *vi=get($1->var_name); var_list.insert(make_pair($1->var_name,new var_info()));}
				|	declarator ASSIGN initializer	{$$=new Node($1,$3,2,"EXPR DECLARE_ASSIGN");}
//var_info *vi=get($1->var_name);var_list.insert(make_pair($1->var_name,new var_info()));vi=get($1->var_name);vi->val=$3->value;$1->value=$3->value;} 
				;
declarator		:	identifier		{$$=$1;}
				;


	/*initializer*/
initializer 	:	expression		{$$=$1;}
				;

/*ExpressionStatement*/
expressionStatement :	ENDSTMT		 {$$=new Node(1,"STMT_EMPTY");}
					|	expressionList ENDSTMT	{$$=$1;}
					;

expression 		:	operation		{$$=$1;}
				|	identifier		{$$=$1;}
				|	number			{$$=$1;}
				|	LPAREN expressionList RPAREN	{$$=$2;}
				;

/*Operation*/
operation		//:	conditionOpreration	{$$=$1;}
				:	logicOperation		{$$=$1;}
				|	arithmeticOperation	{$$=$1;}
				|	assignmentOperation	{$$=$1;}
				|	relationOperation	{$$=$1;}
				|	bitOperation		{$$=$1;}
				;

//conditionOpreration	:	expression QUEST expression COLON expression 	{$$=new Node({$1,$3,$5},"conditionOpreration");}
//				;

logicOperation	:	expression OR expression	{$$=new Node($1,$3,"int",2,"EXPR_OR");}
//string res=deal($1,$3,16);if(res=="error"){yyerror("type error");}if(stf($1->value)!=0||stf($3->value)!=0){$$->value="1";}else{$$->value="0";}
				|	expression AND expression	 {$$=new Node($1,$3,"int",2,"EXPR_AND");}
// string res=deal($1,$3,14);if(res=="error"){yyerror("error");}if(stf($1->value)!=0&&stf($3->value)!=0){$$->value="1";}else{$$->value="0";}
				|	NOT expression				{$$=new Node($2,"int",2,"EXPR_NOT");}
//if(judgeType($2)==4){if($2->value=='0')$$->value="1";else $$->value="0";}else{yyerror("error at not expr!");}
				;

arithmeticOperation :	expression PLUS expression		{$$=new Node($1,$3,2,"EXPR_PLUS");}
//string res=deal($1,$3,5);if(res=="int"||res=="char"){$$->value=tostr(sti($1->value)+sti($3->value));$$->type_name="int";}
//lse if(res=="double"||res=="float"){$$->value=tostr(stf($1->value)+stf($3->value));$$->type_name="double";}else{   yyerror("error at PLUS operation!");}}
				|	expression MINUS expression			{$$=new Node($1,$3,2,"EXPR_MINUS");}
//string res=deal($1,$3,6);if(res=="int"||res=="char"){$$->value=tostr(sti($1->value)-sti($3->value));$$->type_name="int";}
//else if(res=="double"||res=="float"){$$->value=tostr(stf($1->value)-stf($3->value));$$->type_name="double";}else{   yyerror("error at MINUS operation!");}
				|	expression MUL expression			{$$=new Node($1,$3,2,"EXPR_MUL");}
//string res=deal($1,$3,7);if(res=="int"||res=="char"){$$->value=tostr(sti($1->value)*sti($3->value));$$->type_name="int";}
//else if(res=="double"||res=="float"){$$->value=tostr(stf($1->value)*stf($3->value));$$->type_name="char";}else{yyerror("error at MUL operation!");}}
				|	expression DIV expression			{$$=new Node($1,$3,2,"EXPR_DIV");}
//string res=deal($1,$3,8);if(res=="int"||res=="char"){$$->value=tostr(sti($1->value)/sti($3->value));$$->type_name="int";}
//else if(res=="double"||res=="float"){$$->value=tostr(stf($1->value)/stf($3->value));$$->type_name="double"; }else{yyerror("error at DIV operation!");}}
				|	expression MOD expression			{$$=new Node($1,$3,"int",2,"EXPR_MOD");}
//string res=deal($1,$3,9);if(res!="error"){$$->value=tostr(sti($1->value)%sti($3->value));}else{yyerror("Type  error!");}}
				|	MINUS expression %prec _UMINUS		 {$$=new Node($2,2,"EXPR_minus expr");}
//if($$->type_name=="int"||$$->type_name=="char"){$$->value="-"+tostr(sti($2->value));$$->type_name="int";}
//else if($$->type_name=="float"||$$->type_name=="double"){$$->value="-"+tostr(stf($2->value));$$->type_name="double";}else{yyerror("error at minus operation;");}}
               |	PLUS expression %prec _UMINUS		 {$$=new Node($2,2,"EXPR_plus expr");}
//if($$->type_name=="int"||$$->type_name=="char"){$$->value=tostr(sti($2->value));$$->type_name="int";}else if($$->type_name=="float"||$$->type_name=="double"){
//$$->value=tostr(stf($2->value));$$->type_name="double";}else{yyerror("error at plus operation;");}}
				|	TPLUS expression			{$$=new Node($2,2,"EXPR_tplus expr");}
//if($1->type_name=="int"||$1->type_name=="char"){$1->value=tostr(sti($1->value)+1);$$->type_name="int";}else if($1->type_name=="float"||$1->type_name=="double"){
//$1->value=tostr(stf($1->value)+1);$$->type_name="double";}else{}$$->value=$1->value;}
				|	expression TPLUS			 {$$=new Node($1,2,"EXPR_expr tplus");}
//$$->value=$1->value;if($1->type_name=="int"||$1->type_name=="char"){$1->value=tostr(sti($1->value)+1);$$->type_name="int";}
//else if($1->type_name=="float"||$1->type_name=="double"){$1->value=tostr(stf($1->value)+1);$$->type_name="double";}else{yyerror("error at tplus operation");}}
				|	TMINUS expression			 {$$=new Node($2,2,"EXPR_tminus expr");}
//if($1->type_name=="int"||$1->type_name=="char"){$1->value=tostr(sti($1->value)-1);$$->type_name="int";}
//else if($1->type_name=="float"||$1->type_name=="double"){$1->value=tostr(stf($1->value)-1);$$->type_name="double";}else{}$$->value=$1->value;}
				|	expression TMINUS			{$$=new Node($1,2,"EXPR_expr tminus");}
//$$->value=$1->value;if($1->type_name=="int"||$1->type_name=="char"){$1->value=tostr(sti($1->value)-1);$$->type_name="int";}
//else if($1->type_name=="float"||$1->type_name=="double"){$1->value=tostr(stf($1->value)-1);$$->type_name="double";}else{yyerror("error");}}
				
assignmentOperation :	expression ASSIGN expression	 {$$=new Node($1,$3,1,"STMT_ASSIGN");}
                    ;
    /*if($1->type_name=="expr_list"&&$3->type_name=="expr_list"){
      if($1->child.size()!=$3->child.size())
          yyerror("the number of arguments are not equal!");
       int z=$1->child.size();
      if($1->child[z-1]->type==4){
        var_info * vi=get($1->child[z-1]->var_name);
        if(vi!=NULL){
        $1->child[z-1]->value=$3->child[z-1]->value;
        vi->val=$3->child[z-1]->value;
        var_list[$1->child[z-1]->var_name]=vi;
        $$->value=$3->child[z-1]->value;
        //DOU stmt de value is the last
        }
      }
    }
    else if($1->type_name=="expr_list"&&$3->type_name=="expr_list"){
    }
    else{
    var_info * vi=get($1->var_name);
    if(vi!=NULL){
    $1->value=$3->value;
    vi->val=$3->value;
    var_list[$1->var_name]=vi;
    $$->value=$3->value;
    }
    }
  }	*/


relationOperation : expression EQ expression	{ $$=new Node($1,$3,"int",2,"CMP_EQ");}
   /* string res=deal($1,$3,13);
    if(res=="error"){
    yyerror("error!");
    }
    if(stf($1->value)==stf($3->value)){
      $$->value="1";
    }
    else{
      $$->value="0";
    }
    }*/
				|	expression RE expression	{$$=new Node($1,$3,"int",2,"CMP_RE");}
  /*  string res=deal($1,$3,11);
    if(res=="error"){
    yyerror("error!");
    }
    if(stf($1->value)>=stf($3->value)){
      $$->value="1";
    }
    else{
      $$->value="0";
    }
    }*/

				|	expression RT expression	{$$=new Node($1,$3,"int",2,"CMP_RT");}
   /* string res=deal($1,$3,11);
    if(res=="error"){
    yyerror("error!");
    }
    if(stf($1->value)>stf($3->value)){
      $$->value="1";
    }
    else{
      $$->value="0";
    }
    }*/
				|	expression LE expression    {$$=new Node($1,$3,"int",2,"CMP_LE");}
  /*  string res=deal($1,$3,11);
    if(res=="error"){
    yyerror("error!");
    }
    if(stf($1->value)<=stf($3->value)){
      $$->value="1";
    }
    else{
      $$->value="0";
    }
    }*/
				|	expression LT expression	{$$=new Node($1,$3,"int",2,"CMP_LT");}
    /*string res=deal($1,$3,11);
    if(res=="error"){
    yyerror("error!");
    }
    if(stf($1->value)<stf($3->value)){
      $$->value="1";
    }
    else{
      $$->value="0";
    }
    }*/
				|	expression NE expression	{ $$=new Node($1,$3,"int",2,"CMP_NE");}
   /* string res=deal($1,$3,12);
    if(res=="error"){
    yyerror("error!");
    }
    if(stf($1->value)!=stf($3->value)){
      $$->value="1";
    }
    else{
      $$->value="0";
    }
    }*/
				;

bitOperation	:	expression BITAND expression     {$$=new Node($1,$3,"int",2,"EXPR_BITAND");}
  /*  string res=deal($1,$3,3);
    if(res=="error"){
    yyerror("type error");
    }
    $$->value=tostr(sti($1->value)&sti($3->value));
  }*/
				|	expression BITOR expression		{$$=new Node($1,$3,"int",2,"EXPR_BITOR");}
  /*  string res=deal($1,$3,4);
    if(res=="error"){
    yyerror("type error");
    }
    $$->value=tostr(sti($1->value)|sti($3->value));
  }*/
				|	expression XOR expression		{$$=new Node($1,$3,"int",2,"EXPR_XOR");}
   /* string res=deal($1,$3,10);
    if(res=="error"){
    yyerror("type error");
    }
    $$->value=tostr(sti($1->value)^sti($3->value));
  }*/
				|	BITNOT expression			     {$$=new Node($2,"int",2,"EXPR_BITNOT");}
   /* if($2->type_name=="int"||$2->type_name=="char"){
      $$->value=tostr(~sti($2->value));
    }
    else{
      yyerror("type error");
    }
    }*/
				|	expression SHL expression		{$$=new Node($1,$3,"int",2,"EXPR_SHL");}
   /*string res=deal($1,$3,2);
    if(res=="error"){
      yyerror("type error!");
    }
    else{
       $$->value=tostr(sti($1->value)<<sti($3->value));
    }
    }*/
				|	expression SHR expression		{$$=new Node($1,$3,"int",2,"EXPR_SHR");}
 /*  string res=deal($1,$3,1);
    if(res=="error"){
      yyerror("type error!");
    }
    else{
       $$->value=tostr(sti($1->value)>>sti($3->value));
    }
    }*/
				;

/*ControlStatement*/
controlStatement :	selectionStatement	{$$=$1;}
				|	loopStatement		{$$=$1;}
				|	jumpStatement		{$$=$1;}
				;

selectionStatement :	ifStatement		{$$=$1;}
				;

ifStatement		:	IF LPAREN expressionList RPAREN statement %prec _IF			{
    $3->node_name=$3->node_name+"   CONDITION";
    node=new Node();
    node->type=1;
    node->node_name="STMT   null   IF  BRANCH";
    node->children.push_back($5);
    $$=new Node($3,node,1,"STMT_IF");
    }
				|	IF LPAREN expressionList RPAREN statement ELSE statement	 {
    $3->node_name=$3->node_name+"   CONDITION";
    Node* node1=new Node();
    node1->type=1;
    node1->node_name="STMT   null   IF  BRANCH";
    node1->children.push_back($5);
    Node* node2=new Node();
    node2->type=1;
    node2->node_name="STMT   null   ELSE  BRANCH";
    node2->children.clear();
    node2->children.push_back($7);
    $$=new Node($3,node1,1,"STMT_IF");
    $$->children.push_back(node2);
  }
  |IF LPAREN declarationStatement RPAREN statement %prec _IF			{
    $3->node_name=$3->node_name+"   CONDITION";
    node=new Node();
    node->type=1;
    node->node_name="STMT   null   IF  BRANCH";
    node->children.push_back($5);
    $$=new Node($3,node,1,"STMT_IF");
    }//to satisfy the testcase,wmp thinks it's wrong
			;

loopStatement	:	forStatement		{$$=$1;}
				|	whileStatement		{$$=$1;}
				|	doWhileStatement	{$$=$1;}
				;

forStatement	:	FOR LPAREN expressionStatement expressionStatement expressionList RPAREN statement	{  
    $3->node_name=$3->node_name+"   START";
    $4->node_name=$4->node_name+"   CONDITION";
    $5->node_name=$5->node_name+"   ITERATOR";
    $$=new Node($3,$4,1,"STMT_FOR");
    $$->children.push_back($5);
    $$->children.push_back($7);
    }
				|	FOR LPAREN expressionStatement expressionStatement RPAREN statement			{  
    $3->node_name=$3->node_name+"   START";
    $4->node_name=$4->node_name+"   CONDITION";
    $$=new Node($3,$4,1,"STMT_FOR");
    $$->children.push_back($6);
    }
				|	FOR LPAREN declarationStatement expressionStatement expressionList RPAREN statement {  
    $3->node_name=$3->node_name+"   START";
    $4->node_name=$4->node_name+"   CONDITION";
    $5->node_name=$5->node_name+"   ITERATOR";
    $$=new Node($3,$4,1,"STMT_FOR");
    $$->children.push_back($5);
    $$->children.push_back($7);
    }
				|	FOR LPAREN declarationStatement expressionStatement RPAREN statement			{  
    $3->node_name=$3->node_name+"   START";
    $4->node_name=$4->node_name+"   CONDITION";
    $$=new Node($3,$4,1,"STMT_FOR");
    $$->children.push_back($6);
    }
				;

whileStatement	:	WHILE LPAREN expressionList RPAREN statement	{$3->node_name=$3->node_name+"   CONDITION";$$=new Node($3,$5,1,"STMT_WHILE");}
                | WHILE LPAREN declarationStatement RPAREN statement	{$3->node_name=$3->node_name+"   CONDITION";$$=new Node($3,$5,1,"STMT_WHILE");}
				;

doWhileStatement :	DO statement WHILE LPAREN expressionList RPAREN ENDSTMT		{ $5->node_name=$5->node_name+"   CONDITION";$$=new Node($2,$5,1,"STMT_DOWHILE");}
				;

jumpStatement	:	CONTINUE ENDSTMT		{$$=new Node(1,"JUMP_STMT   CONTINUE");}
				|	RETURN ENDSTMT			{$$=new Node(1,"JUMP_STMT   RETURN");}
				|	RETURN expressionList ENDSTMT	{$$=new Node($2,1,"JUMP_STMT   RETURN");}
				|	RETURN LPAREN expressionList RPAREN ENDSTMT	{$$=new Node($3,1,"JUMP_STMT   RETURN");}
				|	BREAK ENDSTMT			{$$=new Node(1,"JUMP_STMT   BREAK");}
				;

/*function*/

functionDefinition :	type identifier LPAREN RPAREN compoundStatement			{$$=new Node($5,"Start");dfs($$,1);}
				|	type identifier LPAREN TYPE RPAREN compoundStatement			{$$=new Node($6,"Start");dfs($$,1);}
				|	type identifier LPAREN parameterList RPAREN compoundStatement		{$$=new Node($6,"Start");dfs($$,1);}
				;
				;

expressionList	:	expression			{$$=$1;}
				|	expressionList MORE expression	{$$=new Node(1,"EXPRESSION_LIST");$$->addAllChild($1);$$->addChild($3);}
				;

parameter		:	type declaration		
				;

parameterList	:	parameter			
				|	parameterList MORE parameter	
				;

	/*cannot assgn while TMINUSlare*/
//declaratorStatementList :	declaratorStatement		{$$=new Node({$1},"declaratorStatementList");}
				//|	declaratorStatementList declaratorStatement		{$$=$1;$$->addChild($2);}
				//;


declaratorStatement :	type declaratorList ENDSTMT		{$$=new Node($1,$2,1,"STMT_DECLARE");}
				;

declaratorList	:	declarator		{$$=new Node($1,1,"DECLARE_LIST");}
				|	declaratorList MORE declarator		{$$=new Node(1,"DECLARE_LIST");$$.addAllChild($1);$$.addChild($3);}                   
				;
/*T*/
identifier		:	LPAREN identifier RPAREN	{$$=$2;}
				|	IDENTIFIER		{ $$=new Node($1,4,"VAR");$$->var_name=yylval->var_name;}
   /* var_info * vi=get($$->var_name);
    if(vi==NULL){
      yyerror("error!");
    }
    $$->type_name=vi->type;
    $$->value=vi->val;
    }*/
				;

	/*think about pointer and const*/
type			:	TYPE		{$$=new Node(6,"TYPE_"+yylval->var_name);}
				;


number			:	INTEGER		{$$=new Node($1,"int",3,"VAL");$$->value=yylval->value;}
				|	FLOAT	{$$=new Node($1,"double",3,"VAL");$$->value=yylval->value;}
				|	CHARVAL		{$$=new Node($1,"char",3,"VAL");$$->value=yylval->value;}
				;

%%
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

