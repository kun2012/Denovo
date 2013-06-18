#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

void typePrint(struct treeNode *p)
{
	int typeNum = p->nodeType, line = p->lineNum;
	switch (typeNum) {
	case T_INT: 		printf("INT -> %d \n", p->digit);break;
	case T_STR: 		printf("STR -> %s \n", p->strconst);break;
	case T_TYPE: 		printf("TYPE(%s)\n", p->strconst);break;
	case T_ID: 		printf("ID\n");break;
	case T_CLASS: 		printf("CLASS\n");break; 
	case T_COMMA: 		printf("COMMA\n");break;
	case T_BREAK: 		printf("BREAK\n");break;
	case T_CONTINUE:	printf("CONTINUE\n");break;
	case T_ELSE: 		printf("ELSE\n");break;
	case T_FOR:		printf("FOR\n");break; 
	case T_IF:		printf("IF\n");break;
	case T_INHERITS:	printf("INHERITS\n");break;
	case T_NEW:		printf("NEW\n");break;
	case T_NUL:		printf("NUL\n");break;
	case T_RETURN:		printf("RETURN\n");break;
	case T_TRUE:		printf("TRUE\n");break;
	case T_VOID:		printf("VOID\n");break;
	case T_WHILE:		printf("WHILE\n");break;
	case T_LC:		printf("LC\n");break;
	case T_RC:		printf("RC\n");break;
	case T_LB:		printf("LB\n");break;
	case T_RB:		printf("RB\n");break;
	case T_SEMI:		printf("SEMI\n");break;
	case T_LP:		printf("LP\n");break;
	case T_RP:		printf("RP\n");break;
	case T_DOT:		printf("DOT\n");break;
	case T_PLUS:		printf("PLUS\n");break;
	case T_DIV:		printf("DIV\n");break;
	case T_MINUS:		printf("MINUS\n");break;
	case T_MULT:		printf("MULT\n");break;
	case T_ASSIGN:		printf("ASSIGN\n");break;
	case T_EQ:		printf("EQ\n");break;
	case T_LT:		printf("LT\n");break;
	case T_GT:		printf("GT\n");break;
	case T_LE:		printf("LE\n");break;
	case T_GE:		printf("GE\n");break;
	case T_NE:		printf("NE\n");break;
	case T_AND:		printf("AND\n");break;
	case T_OR:		printf("OR\n");break;
	case T_NOT:		printf("NOT\n");break;
	case T_FALSE:		printf("FALSE\n");break;

	case T_program:		printf("program (%d)\n", line);break;
	case T_class:		printf("class (%d)\n", line);break;
	case T_inherits:	printf("inherits (%d)\n", line);break;
	case T_features:	printf("features (%d)\n", line);break;
	case T_feature:		printf("feature (%d)\n", line);break;
	case T_varDec:		printf("varDec (%d)\n", line);break;
	case T_argDec:		printf("argDec (%d)\n", line);break;
	case T_funDec:		printf("funDec (%d)\n", line);break;            
	case T_type:		printf("type (%d)\n", line);break;
	case T_stmts:		printf("stmts (%d)\n", line);break;
	case T_compSt:		printf("compSt (%d)\n", line);break;
	case T_stmt:		printf("stmt (%d)\n", line);break;
	case T_forexpr:		printf("forexpr (%d)\n", line);break;
	case T_logexpr:		printf("logexpr (%d)\n", line);break;
	case T_expr:		printf("expr (%d)\n", line);break;
	case T_args:		printf("args (%d)\n", line);break;
	}
}

struct treeNode* createTreeNode(int l, int t) {
	struct treeNode * p = (struct treeNode *)malloc(sizeof(struct treeNode));
	p->lineNum = l;
	p->nodeType = t;
	p->childNum = 0;  
	p->errorFlag = 0;
	return p;
}

void preOrder(struct treeNode *p,int dep)
{
	if (p == NULL) return ;
	int i;
	for (i = 1; i < dep; i++) printf("    ");
	typePrint(p);
	for (i = 0; i < p->childNum; i++)
		preOrder(p->ch[i], dep + 1);
}

void printTree(struct treeNode *p)
{
	preOrder(p, 1);
}
