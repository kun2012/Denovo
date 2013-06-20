#ifndef __TYPE_H__
#define __TYPE_H__

#define MAX_STR_LEN 256
#define MAX_TYPE_LEN 16
#define MAX_LABEL_LEN 32
#define MAX_TYPE_NUM 127
#define MAX_CHILDREN_NUM 9
#define MAX_ID_NUM 4096
#define MAX_SCOPE_NUM 64
#define MAX_TEMP_NUM 4096
#define MAX_REG_NUM 17

#define T_INT			1
#define T_STR			2
#define T_TYPE			3
#define T_ID			4
#define T_CLASS			5
#define T_COMMA			6
#define T_BREAK			7
#define T_CONTINUE 		8
#define T_ELSE 			9	
#define T_FOR 			10
#define T_IF 			11
#define T_INHERITS		12
#define T_NEW			13
#define T_NUL			14
#define T_RETURN 		15
#define T_TRUE 			16
#define T_VOID 			17
#define T_WHILE 		18
#define T_LC 			19
#define T_RC 			20
#define T_LB 			21
#define T_RB 			22
#define T_SEMI 			23
#define T_LP 			24
#define T_RP			25
#define T_DOT 			26
#define T_PLUS 			27
#define T_DIV 			28
#define T_MINUS 		29
#define T_MULT 			30
#define T_ASSIGN 		31
#define T_EQ 			32
#define T_LT 			33
#define T_GT 			34
#define T_LE 			35
#define T_GE 			36
#define T_NE			37
#define T_AND 			38
#define T_OR 			39
#define T_NOT 			40
#define T_FALSE			41

#define T_program		42
#define T_class			43
#define T_inherits		44
#define T_features		45
#define T_feature		46
#define T_varDec		47
#define T_argDec		48
#define T_funDec		49
#define T_type			50
#define T_stmts			51
#define T_compSt		52
#define T_stmt			53
#define T_forexpr		54
#define T_logexpr		55
#define T_expr			56
#define T_args			57
#define T_array			58
#define T_arrayExpr		59
#define T_arrayExprDec	60

struct treeNode {
	int lineNum;
	int nodeType;
	int childNum;
	int digit;
	int errorFlag;
	char strconst[MAX_STR_LEN];
	char label[MAX_LABEL_LEN];
	char label1[MAX_LABEL_LEN];
	char place[MAX_LABEL_LEN];
	struct treeNode *ch[MAX_CHILDREN_NUM];
};

struct attriNode {
	char varName[MAX_TYPE_LEN];
	int arraySize;
	char typeName[MAX_TYPE_LEN];
	int offset;
	struct attriNode *next;
	struct attriNode *nextStackNode;
};

struct funNode{
	char funName[MAX_TYPE_LEN];
	char typeName[MAX_TYPE_LEN];
	int arraySize;
	char label[MAX_LABEL_LEN];
	struct attriNode *arghead;
	struct funNode *next;
};

struct typeNode {
    char d[MAX_TYPE_LEN];
    struct attriNode *attriHead;
    struct typeNode *next;
    struct funNode *funhead;
    struct typeNode *father;
};

struct stackNode {
	struct attriNode *next;
};












#endif
