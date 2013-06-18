%{
	#include <stdio.h>
	#include "include/tree.h"
	#include "include/type.h"
	#include <string.h> 
	struct treeNode *root = NULL;
	int syntaxError = 0;
	int semanticError = 0;
	void yyerror(const char *msg);
%}

%locations
%union {
	int tint;
	char tstring[MAX_STR_LEN];
	struct treeNode *tNode;
}

%token <tint> INT
%token <tstring> STRCONSTANT TYPE ID  
%token <tint> CLASS 
%token <tint> COMMA BREAK CONTINUE ELSE VOID FOR IF INHERITS NEW NUL
%token <tint> RETURN TRUE  WHILE LC RC LB RB SEMI LP RP
%token <tint> DOT PLUS DIV MINUS MULT ASSIGN EQ LT GT LE GE NE
%token <tint> AND OR NOT FALSE

%right ASSIGN
%left OR
%left AND
%left NE EQ GE LE GT LT
%left PLUS MINUS
%left MULT DIV
%right NOT
%left LP RP LB RB DOT

%locations
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%error-verbose
%type <tNode> program class inherits features feature varDec argDec funDec type stmts compSt stmt forexpr logexpr expr args array arrayExpr arrayExprDec
%start program

%%
program	:	class program { 
			$$ = createTreeNode($1->lineNum, T_program); 
			$$->childNum = 2;
			$$->ch[0] = $1;
			$$->ch[1] = $2;
			root = $$;
		      }
	|	{ $$ = NULL; }
	;
class	:	CLASS TYPE inherits LC features RC {
			$$ = createTreeNode(@1.first_line, T_class); 
			$$->childNum = 6;
			$$->ch[0] = createTreeNode(@1.first_line, T_CLASS);
			$$->ch[1] = createTreeNode(@2.first_line, T_TYPE);
			strcpy($$->ch[1]->strconst, $2);
			$$->ch[2] = $3;
			$$->ch[3] = createTreeNode(@4.first_line, T_LC);
			$$->ch[4] = $5;
			$$->ch[5] = createTreeNode(@6.first_line, T_RC);
		}
	|	error TYPE inherits LC features RC {
			$$ = createTreeNode(@1.first_line, T_class); 
		}

	|	CLASS error inherits LC features RC {
			$$ = createTreeNode(@1.first_line, T_class); 
		}
	|	CLASS TYPE inherits error features RC {
			$$ = createTreeNode(@1.first_line, T_class);
		}
	|	CLASS TYPE inherits LC features error {
			$$ = createTreeNode(@1.first_line, T_class);
		}

	;
inherits:	INHERITS TYPE {
			$$ = createTreeNode(@1.first_line, T_inherits); 
			$$->childNum = 2;
			$$->ch[0] = createTreeNode(@1.first_line, T_INHERITS); 
			$$->ch[1] = createTreeNode(@2.first_line, T_TYPE);
			strcpy($$->ch[1]->strconst, $2); 
		}
	|	{ $$ = NULL;}
	|	INHERITS error {}
	;
features:	feature features {
			$$ = createTreeNode($1->lineNum, T_features); 
			$$->childNum = 2;
			$$->ch[0] = $1;
			$$->ch[1] = $2;
		}
	|	{ $$ = NULL; }
	;
feature	:	varDec SEMI {
			$$ = createTreeNode($1->lineNum, T_feature); 
			$$->childNum = 2;
			$$->ch[0] = $1;
			$$->ch[1] = createTreeNode(@2.first_line, T_SEMI); 
		}
	|	funDec {
			$$ = createTreeNode($1->lineNum, T_feature); 
			$$->childNum = 1;
			$$->ch[0] = $1;
		}
	;
varDec	:	varDec COMMA ID {
			$$ = createTreeNode($1->lineNum, T_varDec); 
			$$->childNum = 3;
			$$->ch[0] = $1;
			$$->ch[1] = createTreeNode(@2.first_line, T_COMMA);
			$$->ch[2] = createTreeNode(@3.first_line, T_ID);
			strcpy($$->ch[2]->strconst, $3);
		}
	|	varDec COMMA ID ASSIGN expr {
			$$ = createTreeNode($1->lineNum, T_varDec); 
			$$->childNum = 5;
			$$->ch[0] = $1;
			$$->ch[1] = createTreeNode(@2.first_line, T_COMMA);
			$$->ch[2] = createTreeNode(@3.first_line, T_ID);
			strcpy($$->ch[2]->strconst, $3);
			$$->ch[3] = createTreeNode(@4.first_line, T_ASSIGN);
			$$->ch[4] = $5;
		}
	|	type ID {
			$$ = createTreeNode($1->lineNum, T_varDec); 
			$$->childNum = 2;
			$$->ch[0] = $1;
			$$->ch[1] = createTreeNode(@2.first_line, T_ID);
			strcpy($$->ch[1]->strconst, $2);
		}
	|	type ID ASSIGN expr {
			$$ = createTreeNode($1->lineNum, T_varDec); 
			$$->childNum = 4;
			$$->ch[0] = $1;
			$$->ch[1] = createTreeNode(@2.first_line, T_ID);
			strcpy($$->ch[1]->strconst, $2);
			$$->ch[2] = createTreeNode(@3.first_line, T_ASSIGN);
			$$->ch[3] = $4;
		}
	|	{ $$ = NULL; }
	|	varDec COMMA error {
			$$ = createTreeNode($1->lineNum, T_varDec); 
		}
	|	varDec COMMA error ASSIGN expr{
			$$ = createTreeNode($1->lineNum, T_varDec); 
		}
	|   varDec COMMA ID error expr{
			$$ = createTreeNode($1->lineNum, T_varDec); 
		}
	|	varDec COMMA ID ASSIGN error{
			$$ = createTreeNode($1->lineNum, T_varDec); 
		}
	;
array	:	LB RB {
				$$ = createTreeNode(@1.first_line, T_array); 
				$$->childNum = 2;
				$$->ch[0] = createTreeNode(@1.first_line, T_LB);
				$$->ch[1] = createTreeNode(@2.first_line, T_RB);
			}
		|	array LB RB {
				$$ = createTreeNode(@1.first_line, T_array); 
				$$->childNum = 3;
				$$->ch[0] = $1;
				$$->ch[1] = createTreeNode(@2.first_line, T_LB);
				$$->ch[2] = createTreeNode(@3.first_line, T_RB);
			}
		;
arrayExpr :	arrayExpr LB expr RB {
			$$ = createTreeNode($1->lineNum, T_arrayExpr); 
			$$->childNum = 4;
			$$->ch[0] = $1;
			$$->ch[1] = createTreeNode(@2.first_line, T_LB);
			$$->ch[2] = $3;
			$$->ch[3] = createTreeNode(@4.first_line, T_RB);
			}
		  |  LB expr RB { 
			$$ = createTreeNode(@1.first_line, T_arrayExpr); 
			$$->childNum = 3;
			$$->ch[0] = createTreeNode(@1.first_line, T_LB);
			$$->ch[1] = $2;
			$$->ch[2] = createTreeNode(@3.first_line, T_RB);
		  }
		  ;
arrayExprDec :	arrayExprDec LB INT RB {
				$$ = createTreeNode($1->lineNum, T_arrayExprDec); 
				$$->childNum = 4;
				$$->ch[0] = $1;
				$$->ch[1] = createTreeNode(@2.first_line, T_LB);
				$$->ch[2] = createTreeNode(@3.first_line, T_INT);
				$$->ch[2]->digit = $3;
				$$->ch[3] = createTreeNode(@4.first_line, T_RB);
				}
			  |  LB INT RB { 
				$$ = createTreeNode(@1.first_line, T_arrayExprDec); 
				$$->childNum = 3;
				$$->ch[0] = createTreeNode(@1.first_line, T_LB);
				$$->ch[1] = createTreeNode(@2.first_line, T_INT);
				$$->ch[1]->digit = $2;
				$$->ch[2] = createTreeNode(@3.first_line, T_RB);
			  }
		  ;
argDec	:	argDec COMMA type ID {
			$$ = createTreeNode($1->lineNum, T_argDec); 
			$$->childNum = 4;
			$$->ch[0] = $1;
			$$->ch[1] = createTreeNode(@2.first_line, T_COMMA);
			$$->ch[2] = $3;
			$$->ch[3] = createTreeNode(@4.first_line, T_ID);
			strcpy($$->ch[3]->strconst, $4);
	}
	|	type ID	{
			$$ = createTreeNode($1->lineNum, T_argDec); 
			$$->childNum = 2;
			$$->ch[0] = $1;
			$$->ch[1] = createTreeNode(@2.first_line, T_ID);
			strcpy($$->ch[1]->strconst, $2);
	}
	| 	{ $$ = NULL; } 
	|	error COMMA type ID {
			$$ = createTreeNode(@2.first_line, T_argDec); 
		}
	|	argDec COMMA error ID {
			$$ = createTreeNode($1->lineNum, T_argDec); 
		}
	|	argDec COMMA type error {
			$$ = createTreeNode($1->lineNum, T_argDec); 
		}
	|	error ID {
			$$ = createTreeNode(@2.first_line, T_argDec); 
		}	
	|	type error {
			$$ = createTreeNode($1->lineNum, T_argDec); 
		}	
	;
funDec	:	type ID LP argDec RP LC stmts RC {
			$$ = createTreeNode($1->lineNum, T_funDec); 
			$$->childNum = 8;
			$$->ch[0] = $1;
			$$->ch[1] = createTreeNode(@2.first_line, T_ID);
			strcpy($$->ch[1]->strconst, $2);
			$$->ch[2] = createTreeNode(@3.first_line, T_LP);
			$$->ch[3] = $4;
			$$->ch[4] = createTreeNode(@5.first_line, T_RP);
			$$->ch[5] = createTreeNode(@6.first_line, T_LC);
			$$->ch[6] = $7;
			$$->ch[7] = createTreeNode(@8.first_line, T_RC);
		}
	|	type error LP argDec RP LC stmts RC {
			$$ = createTreeNode($1->lineNum, T_funDec); 
		}
	|	type ID error argDec RP LC stmts RC {
			$$ = createTreeNode($1->lineNum, T_funDec); 
		}
	|	type ID LP error RP LC stmts RC {
			$$ = createTreeNode($1->lineNum, T_funDec); 
		}

	|	type ID LP argDec RP error stmts RC {
			$$ = createTreeNode($1->lineNum, T_funDec); 
		}
	|	type ID LP argDec RP LC error RC {
			$$ = createTreeNode($1->lineNum, T_funDec); 
		}
	;
type	:	TYPE {
			$$ = createTreeNode(@1.first_line, T_type); 
			$$->childNum = 1;
			$$->ch[0] = createTreeNode(@1.first_line, T_TYPE);
			strcpy($$->strconst, $1);
			}
		|	TYPE array {
			$$ = createTreeNode(@1.first_line, T_type); 
			$$->childNum = 2;
			$$->ch[0] = createTreeNode(@1.first_line, T_TYPE);
			strcpy($$->strconst, $1);
			$$->ch[1] = $2;
			}
		|	VOID {
			$$ = createTreeNode(@1.first_line, T_type); 
			$$->childNum = 1;
			$$->ch[0] = createTreeNode(@1.first_line, T_VOID);
			strcpy($$->strconst, "void");
			}
		;
stmts	:	stmt stmts {
			$$ = createTreeNode($1->lineNum, T_stmts); 
			$$->childNum = 2;
			$$->ch[0] = $1;
			$$->ch[1] = $2;
	}
	|	{ $$ = NULL; }
	|	stmt error {
			$$ = createTreeNode($1->lineNum, T_stmts); 
		} 
	;
compSt	:	LC stmts RC {
			$$ = createTreeNode(@1.first_line, T_compSt); 
			$$->childNum = 3;
			$$->ch[0] = createTreeNode(@1.first_line, T_LC);
			$$->ch[1] = $2;
			$$->ch[2] = createTreeNode(@3.first_line, T_RC);
		}
	|	LC error RC {
			$$ = createTreeNode(@1.first_line, T_compSt);
		} 
	;
stmt	:	expr SEMI {
		$$ = createTreeNode($1->lineNum, T_stmt); 
		$$->childNum = 2;
		$$->ch[0] = $1;
		$$->ch[1] = createTreeNode(@2.first_line, T_SEMI);
		}
	|	RETURN expr SEMI{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		$$->childNum = 3;
		$$->ch[0] = createTreeNode(@1.first_line, T_RETURN);
		$$->ch[1] = $2;
		$$->ch[2] = createTreeNode(@3.first_line, T_SEMI);
		}
	|	BREAK SEMI{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		$$->childNum = 2;
		$$->ch[0] = createTreeNode(@1.first_line, T_BREAK);
		$$->ch[1] = createTreeNode(@2.first_line, T_SEMI);
		}
	|	CONTINUE SEMI{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		$$->childNum = 2;
		$$->ch[0] = createTreeNode(@1.first_line, T_CONTINUE);
		$$->ch[1] = createTreeNode(@2.first_line, T_SEMI);
		}
	|	IF LP logexpr RP stmt %prec LOWER_THAN_ELSE{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		$$->childNum = 5;
		$$->ch[0] = createTreeNode(@1.first_line, T_IF);
		$$->ch[1] = createTreeNode(@2.first_line, T_LP);
		$$->ch[2] = $3;
		$$->ch[3] = createTreeNode(@4.first_line, T_RP);
		$$->ch[4] = $5;
		}
	|	IF LP logexpr RP stmt ELSE stmt{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		$$->childNum = 7;
		$$->ch[0] = createTreeNode(@1.first_line, T_IF);
		$$->ch[1] = createTreeNode(@2.first_line, T_LP);
		$$->ch[2] = $3;
		$$->ch[3] = createTreeNode(@4.first_line, T_RP);
		$$->ch[4] = $5;
		$$->ch[5] = createTreeNode(@6.first_line, T_ELSE);
		$$->ch[6] = $7;
		}
	|	WHILE LP logexpr RP stmt{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		$$->childNum = 5;
		$$->ch[0] = createTreeNode(@1.first_line, T_WHILE);
		$$->ch[1] = createTreeNode(@2.first_line, T_LP);
		$$->ch[2] = $3;
		$$->ch[3] = createTreeNode(@4.first_line, T_RP);
		$$->ch[4] = $5;
		}
	|	FOR LP forexpr SEMI logexpr SEMI forexpr RP stmt{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		$$->childNum = 9;
		$$->ch[0] = createTreeNode(@1.first_line, T_FOR);
		$$->ch[1] = createTreeNode(@2.first_line, T_LP);
		$$->ch[2] = $3;
		$$->ch[3] = createTreeNode(@4.first_line, T_SEMI);
		$$->ch[4] = $5;
		$$->ch[5] = createTreeNode(@6.first_line, T_SEMI);
		$$->ch[6] = $7;
		$$->ch[7] = createTreeNode(@8.first_line, T_RP);
		$$->ch[8] = $9;
		}
	|	varDec SEMI{
		$$ = createTreeNode($1->lineNum, T_stmt); 
		$$->childNum = 2;
		$$->ch[0] = $1;
		$$->ch[1] = createTreeNode(@2.first_line, T_SEMI);
		}
	|	compSt{
		$$ = createTreeNode($1->lineNum, T_stmt); 
		$$->childNum = 1;
		$$->ch[0] = $1;
		}
	|	error SEMI {
		$$ = createTreeNode(@1.first_line, T_stmt); 
		}
	|	expr error {
		$$ = createTreeNode($1->lineNum, T_stmt); 
		}
	|	error expr SEMI{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		}
	|	RETURN error SEMI{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		}
	|	RETURN expr error{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		}
	|	BREAK error{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		}
	|	CONTINUE error{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		}
	|	WHILE error logexpr RP stmt{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		}
	|	WHILE LP error RP stmt{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		}
	|	WHILE LP logexpr error stmt{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		}
	|	FOR error forexpr SEMI logexpr SEMI forexpr RP stmt{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		}
	|	FOR LP forexpr SEMI error SEMI forexpr RP stmt{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		}
	|	FOR LP forexpr SEMI logexpr error forexpr RP stmt{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		}
	|	IF error logexpr RP stmt ELSE stmt{
		$$ = createTreeNode(@1.first_line, T_stmt);
		}
	|	IF LP error RP stmt ELSE stmt{
		$$ = createTreeNode(@1.first_line, T_stmt);
		}
	|	IF LP logexpr error stmt ELSE stmt{
		$$ = createTreeNode(@1.first_line, T_stmt);
		}
	|	IF LP logexpr RP error ELSE stmt{
		$$ = createTreeNode(@1.first_line, T_stmt);
		}
	|	IF error logexpr RP stmt %prec LOWER_THAN_ELSE{
		$$ = createTreeNode(@1.first_line, T_stmt); 
		}
	|	IF LP error RP stmt %prec LOWER_THAN_ELSE {
		$$ = createTreeNode(@1.first_line, T_stmt); 
		}
	|	IF LP logexpr error stmt %prec LOWER_THAN_ELSE {
		$$ = createTreeNode(@1.first_line, T_stmt); 
		}
	;
forexpr	:	expr{
		$$ = createTreeNode($1->lineNum, T_forexpr); 
		$$->childNum = 1;
		$$->ch[0] = $1;
		}
	| 	{$$ = NULL;}
	|	error{
		$$ = createTreeNode(@1.first_line, T_forexpr); 
		}
	;

logexpr	:	logexpr AND logexpr{
		$$ = createTreeNode($1->lineNum, T_logexpr); 
		$$->childNum = 3;
		$$->ch[0] = $1;
		$$->ch[1] = createTreeNode(@2.first_line, T_AND);
		$$->ch[2] = $3;
		}
	|	logexpr OR logexpr{
		$$ = createTreeNode($1->lineNum, T_logexpr); 
		$$->childNum = 3;
		$$->ch[0] = $1;
		$$->ch[1] = createTreeNode(@2.first_line, T_OR);
		$$->ch[2] = $3;
		}
	|	expr NE expr{
		$$ = createTreeNode($1->lineNum, T_logexpr); 
		$$->childNum = 3;
		$$->ch[0] = $1;
		$$->ch[1] = createTreeNode(@2.first_line, T_NE);
		$$->ch[2] = $3;
		}
	|	expr EQ expr{
		$$ = createTreeNode($1->lineNum, T_logexpr); 
		$$->childNum = 3;
		$$->ch[0] = $1;
		$$->ch[1] = createTreeNode(@2.first_line, T_EQ);
		$$->ch[2] = $3;
		}
	|	expr GE expr{
		$$ = createTreeNode($1->lineNum, T_logexpr); 
		$$->childNum = 3;
		$$->ch[0] = $1;
		$$->ch[1] = createTreeNode(@2.first_line, T_GE);
		$$->ch[2] = $3;
		}
	|	expr LE expr{
		$$ = createTreeNode($1->lineNum, T_logexpr); 
		$$->childNum = 3;
		$$->ch[0] = $1;
		$$->ch[1] = createTreeNode(@2.first_line, T_LE);
		$$->ch[2] = $3;
		}
	|	expr GT expr{
		$$ = createTreeNode($1->lineNum, T_logexpr); 
		$$->childNum = 3;
		$$->ch[0] = $1;
		$$->ch[1] = createTreeNode(@2.first_line, T_GT);
		$$->ch[2] = $3;
		}
	|	expr LT expr{
		$$ = createTreeNode($1->lineNum, T_logexpr); 
		$$->childNum = 3;
		$$->ch[0] = $1;
		$$->ch[1] = createTreeNode(@2.first_line, T_LT);
		$$->ch[2] = $3;
		}
	| 	NOT logexpr{
		$$ = createTreeNode(@1.first_line, T_logexpr); 
		$$->childNum = 2;
		$$->ch[0] = createTreeNode(@1.first_line, T_NOT);
		$$->ch[1] = $2;
		}
	|	LP logexpr RP{
		$$ = createTreeNode(@1.first_line, T_logexpr); 
		$$->childNum = 3;
		$$->ch[0] = createTreeNode(@1.first_line, T_LP);
		$$->ch[1] = $2;
		$$->ch[2] = createTreeNode(@3.first_line, T_RP);
		}
	|	error AND logexpr{
		$$ = createTreeNode(@1.first_line, T_logexpr); 
		}
	|	error OR logexpr{
		$$ = createTreeNode(@1.first_line, T_logexpr); 
		}
	|	error NE expr{
		$$ = createTreeNode(@1.first_line, T_logexpr);
		}
	|	expr error expr{
		$$ = createTreeNode(@1.first_line, T_logexpr);
		}
	|	expr NE error{
		$$ = createTreeNode(@1.first_line, T_logexpr);
		}
	|	error EQ expr{
		$$ = createTreeNode(@1.first_line, T_logexpr);
		}
	|	expr EQ error{
		$$ = createTreeNode(@1.first_line, T_logexpr);
		}
	|	error GE expr{
		$$ = createTreeNode(@1.first_line, T_logexpr);
		}
	|	expr GE error{
		$$ = createTreeNode(@1.first_line, T_logexpr);
		}
	|	error LE expr{
		$$ = createTreeNode(@1.first_line, T_logexpr);
		}
	|	expr LE error{
		$$ = createTreeNode(@1.first_line, T_logexpr);
		}
	|	error GT expr{
		$$ = createTreeNode(@1.first_line, T_logexpr);
		}
	|	expr GT error{
		$$ = createTreeNode(@1.first_line, T_logexpr);
		}
	|	error LT expr{
		$$ = createTreeNode(@1.first_line, T_logexpr);
		}
	|	expr LT error{
		$$ = createTreeNode(@1.first_line, T_logexpr);
		}
	|	error logexpr RP{
		$$ = createTreeNode(@1.first_line, T_logexpr); 
		}
	|	LP error RP{
		$$ = createTreeNode(@1.first_line, T_logexpr); 
		}
	|	LP logexpr error{
		$$ = createTreeNode(@1.first_line, T_logexpr); 
		}
	;

expr	:	expr MINUS expr	{
		$$ = createTreeNode($1->lineNum, T_expr); 
		$$->childNum = 3;
		$$->ch[0] = $1;
		$$->ch[1] = createTreeNode(@2.first_line, T_MINUS);
		$$->ch[2] = $3;
		}
	|	expr PLUS expr{
		$$ = createTreeNode($1->lineNum, T_expr); 
		$$->childNum = 3;
		$$->ch[0] = $1;
		$$->ch[1] = createTreeNode(@2.first_line, T_PLUS);
		$$->ch[2] = $3;
		}
	|	expr MULT expr{
		$$ = createTreeNode($1->lineNum, T_expr); 
		$$->childNum = 3;
		$$->ch[0] = $1;
		$$->ch[1] = createTreeNode(@2.first_line, T_MULT);
		$$->ch[2] = $3;
		}
	|	expr DIV expr{
		$$ = createTreeNode($1->lineNum, T_expr); 
		$$->childNum = 3;
		$$->ch[0] = $1;
		$$->ch[1] = createTreeNode(@2.first_line, T_DIV);
		$$->ch[2] = $3;
		}
	|	ID ASSIGN expr{
			$$ = createTreeNode(@1.first_line, T_expr); 
			$$->childNum = 3;
			$$->ch[0] = createTreeNode(@1.first_line, T_ID);
			strcpy($$->ch[0]->strconst, $1);
			$$->ch[1] = createTreeNode(@2.first_line, T_ASSIGN);
			$$->ch[2] = $3;
		}
	|	ID arrayExpr ASSIGN expr{
			$$ = createTreeNode(@1.first_line, T_expr); 
			$$->childNum = 4;
			$$->ch[0] = createTreeNode(@1.first_line, T_ID);
			strcpy($$->ch[0]->strconst, $1);
			$$->ch[1] = $2;
			$$->ch[2] = createTreeNode(@3.first_line, T_ASSIGN);
			$$->ch[3] = $4;
		}
	|	ID arrayExpr{
			$$ = createTreeNode(@1.first_line, T_expr); 
			$$->childNum = 2;
			$$->ch[0] = createTreeNode(@1.first_line, T_ID);
			strcpy($$->ch[0]->strconst, $1);
			$$->ch[1] = $2;
		}
	|	ID DOT ID ASSIGN expr{
			$$ = createTreeNode(@1.first_line, T_expr); 
			$$->childNum = 5;
			$$->ch[0] = createTreeNode(@1.first_line, T_ID);
			strcpy($$->ch[0]->strconst, $1);
			$$->ch[1] = createTreeNode(@2.first_line, T_DOT);
			$$->ch[2] = createTreeNode(@3.first_line, T_ID);
			strcpy($$->ch[2]->strconst, $3);
			$$->ch[3] = createTreeNode(@4.first_line, T_ASSIGN);
			$$->ch[4] = $5;
		}
	|	LP expr RP{
			$$ = createTreeNode(@1.first_line, T_expr); 
			$$->childNum = 3;
			$$->ch[0] = createTreeNode(@1.first_line, T_LP);
			$$->ch[1] = $2;
			$$->ch[2] = createTreeNode(@3.first_line, T_RP);
		}
	|	MINUS expr{
			$$ = createTreeNode(@1.first_line, T_expr); 
			$$->childNum = 2;
			$$->ch[0] = createTreeNode(@1.first_line, T_MINUS);
			$$->ch[1] = $2;
		}
	|	ID LP args RP{
		$$ = createTreeNode(@1.first_line, T_expr); 
		$$->childNum = 4;
		$$->ch[0] = createTreeNode(@1.first_line, T_ID);
		strcpy($$->ch[0]->strconst, $1);
		$$->ch[1] = createTreeNode(@2.first_line, T_LP);
		$$->ch[2] = $3;
		$$->ch[3] = createTreeNode(@4.first_line, T_RP);
		}
	|	ID DOT ID LP args RP{
		$$ = createTreeNode(@1.first_line, T_expr); 
		$$->childNum = 6;
		$$->ch[0] = createTreeNode(@1.first_line, T_ID);
		strcpy($$->ch[0]->strconst, $1);
		$$->ch[1] = createTreeNode(@2.first_line, T_DOT);
		$$->ch[2] = createTreeNode(@3.first_line, T_ID);
		strcpy($$->ch[2]->strconst, $3);
		$$->ch[3] = createTreeNode(@4.first_line, T_LP);
		$$->ch[4] = $5;
		$$->ch[5] = createTreeNode(@6.first_line, T_RP);
	}
	|	ID DOT ID{
		$$ = createTreeNode(@1.first_line, T_expr); 
		$$->childNum = 3;
		$$->ch[0] = createTreeNode(@1.first_line, T_ID);
		strcpy($$->ch[0]->strconst, $1);
		$$->ch[1] = createTreeNode(@2.first_line, T_DOT);
		$$->ch[2] = createTreeNode(@3.first_line, T_ID);
		strcpy($$->ch[2]->strconst, $3);
	}
	|	NEW TYPE arrayExprDec{
		$$ = createTreeNode(@1.first_line, T_expr); 
		$$->childNum = 3;
		$$->ch[0] = createTreeNode(@1.first_line, T_NEW);
		$$->ch[1] = createTreeNode(@2.first_line, T_TYPE);
		strcpy($$->ch[1]->strconst, $2);
		$$->ch[2] = $3;
		}
	|	NEW TYPE {
		$$ = createTreeNode(@1.first_line, T_expr); 
		$$->childNum = 2;
		$$->ch[0] = createTreeNode(@1.first_line, T_NEW);
		$$->ch[1] = createTreeNode(@2.first_line, T_TYPE);
		strcpy($$->ch[1]->strconst, $2);
		}
	|	ID{
		$$ = createTreeNode(@1.first_line, T_expr); 
		$$->childNum = 1;
		$$->ch[0] = createTreeNode(@1.first_line, T_ID);
		strcpy($$->ch[0]->strconst, $1);
		}
	|	STRCONSTANT{
		$$ = createTreeNode(@1.first_line, T_expr); 
		$$->childNum = 1;
		$$->ch[0] = createTreeNode(@1.first_line, T_STR);
		strcpy($$->ch[0]->strconst, $1);
		}
	|	INT{
			$$ = createTreeNode(@1.first_line, T_expr); 
			$$->childNum = 1;
			$$->ch[0] = createTreeNode(@1.first_line, T_INT);
			$$->ch[0]->digit = $1;
		}
	|	NUL{
		$$ = createTreeNode(@1.first_line, T_expr); 
		$$->childNum = 1;
		$$->ch[0] = createTreeNode(@1.first_line, T_NUL);
		}
	|	expr MINUS error {
		$$ = createTreeNode($1->lineNum, T_expr); 
		}
	|	expr PLUS error {
		$$ = createTreeNode($1->lineNum, T_expr); 
		}
	|	expr MULT error {
		$$ = createTreeNode($1->lineNum, T_expr); 
		}
	|	expr DIV error {
		$$ = createTreeNode($1->lineNum, T_expr); 
		}
	|	MINUS error{
			$$ = createTreeNode(@1.first_line, T_expr); 
		}
	|	ID LP error RP{
		$$ = createTreeNode(@1.first_line, T_expr); 
		}
	|	error LP RP{
		$$ = createTreeNode(@1.first_line, T_expr); 
		}
	|	NEW error LP RP{
		$$ = createTreeNode(@1.first_line, T_expr); 
		}
	|	error TYPE LP RP{
		$$ = createTreeNode(@1.first_line, T_expr); 
		}
	;
args	:	expr COMMA args{
		$$ = createTreeNode($1->lineNum, T_args); 
		$$->childNum = 3;
		$$->ch[0] = $1;
		$$->ch[1] = createTreeNode(@2.first_line, T_COMMA);
		$$->ch[2] = $3;
		}
	|	expr {
		$$ = createTreeNode($1->lineNum, T_args); 
		$$->childNum = 1;
		$$->ch[0] = $1;
		}
	|	{ $$ = NULL; }
	|	error COMMA args{
		$$ = createTreeNode(@1.first_line, T_args); 
		}
	|	expr error args{
		$$ = createTreeNode($1->lineNum, T_args); 
		}
	|	expr COMMA error{
		$$ = createTreeNode($1->lineNum, T_args); 
		}
	;
%%
#include "lex.yy.c"
void yyerror(const char *msg)
{
	printf("Line %d: %s\n", yylloc.first_line, msg);
	syntaxError = 1;
}


