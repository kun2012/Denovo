%{
#include "syntax.tab.h"
#include <string.h>
#include "include/tree.h"
#include "include/type.h"
#define MAX_STR_CONST 1024
char string_buf[MAX_STR_CONST];
char *string_buf_ptr;
int yycolumn = 1;
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;\
yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1;\
yycolumn += yyleng;
%}

%option yylineno
%x str

LETTER [A-Za-z]
DIGIT [0-9]
NONNEWLINE_WHITE_SPACE_CHAR [\ \t\b\f\r]
WHITE_SPACE_CHAR [\n\ \t\b\f\r]

%%

{NONNEWLINE_WHITE_SPACE_CHAR}+ {}
\n	{ yycolumn = 1; }
"//".*	{}
\/\*	{
		char c;
		int commentstar = 0;
		while((c = input()) != EOF) {
		     if (c == '/' && commentstar) {
			break;
		     }
		     if (c == '\n') yycolumn = 1;
		     if (c == '*') commentstar = 1;
		     else commentstar = 0;
		}
	}
"class"  	{ return CLASS;}
"break"  	{ return BREAK;}
"continue" 	{ return CONTINUE; }
"else"	 	{ return ELSE; }
"false"  	{ return FALSE; }
"for"	 	{ return FOR; }
"if"	 	{ return IF; }
"inherits" 	{ return INHERITS; }
"new" 		{ return NEW; }
"null"	 	{ return NUL; }
"return" 	{ return RETURN; }
"true" 		{ return TRUE; }
"void" 		{ return VOID; }
"while" 	{ return WHILE; }
"{" 		{ return LC; }
"}" 		{ return RC; }
"[" 		{ return LB; }
"]" 		{ return RB; }
";" 		{ return SEMI; }
"(" 		{ return LP; }
")" 		{ return RP ;}
"." 		{ return DOT ;}
"+" 		{ return PLUS ;}
"/" 		{ return DIV;}
"-" 		{ return MINUS;}
"*" 		{ return MULT; }
"=" 		{ return ASSIGN; }
"==" 		{ return EQ; }
"<" 		{ return LT; }
">" 		{ return GT; }
"," 		{ return COMMA; }
"!" 		{ return NOT; }
"<=" 		{ return LE; }
">=" 		{ return GE; }
"!=" 		{ return NE; }
"&&" 		{ return AND; }
"||" 		{ return OR; }



\" string_buf_ptr = string_buf; BEGIN(str);

<str>\"	{
		*string_buf_ptr = '\0';
		strcpy(yylval.tstring,string_buf);
		BEGIN(INITIAL);
		return STRCONSTANT;
	}

<str>\n {	
		yycolumn = 1;
		BEGIN(INITIAL);
		printf("error: unterminated string constant\n");
	}

<str>\\[0-7]{1,3} {
			int result;
			(void) sscanf(yytext + 1, "%o", &result);
			if (result > 0xff) {
			    
			    printf("octal escape sequence out of bounds\n");
			}else {
			    *string_buf_ptr++ = result;
			}
		   }
<str>\\[0-9]+ {
		  
		  printf("bad escape sequence.\n");
	      }
<str>\\n     *string_buf_ptr++ = '\n';
<str>\\t     *string_buf_ptr++ = '\t';
<str>\\r     *string_buf_ptr++ = '\r';
<str>\\b     *string_buf_ptr++ = '\b';
<str>\\f     *string_buf_ptr++ = '\f';

<str>\\\r\n    { }
<str>\\\n    { }
<str>\\.  { *string_buf_ptr++ = yytext[1]; }

<str>[^\\\n\"]+	{
			char *yptr = yytext;
			while( *yptr)
			   *string_buf_ptr++ = *yptr++;
		}

{DIGIT}+	{ 
			yylval.tint = atoi(yytext);
			return INT;
		}
[A-Z]+({LETTER}|{DIGIT}|_)* 	{ 
					strcpy(yylval.tstring, yytext);
					return TYPE;
				}
[a-z]+({LETTER}|{DIGIT}|_)* 	{ 
					strcpy(yylval.tstring, yytext);
					return ID;
				}

.	{
	  printf("Error match at line %d: Mysterious character \'%s\'\n", yylineno, yytext);
	}
%%
