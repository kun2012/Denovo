#ifndef __SEMANTIC_H__
#define __SEMANTIC_H__

#include "type.h"

struct typeNode *typeMap[MAX_TYPE_NUM]; 

struct attriNode *idMap[MAX_ID_NUM];

struct stackNode *idStack[MAX_SCOPE_NUM];

extern int hash(char* name,int size);

extern void checkSemantic(struct treeNode *root);

extern struct typeNode *findType(char* name);

extern struct attriNode *findId(char *name);

extern void insertId(char* idName, char* idType, int arrsize);

extern struct attriNode *findAttribute(struct attriNode *p, char *varn);

extern int semanticError;

extern struct typeNode *cls;

extern int intoFunc;

extern struct funNode *ft;

extern void numToString(int x, char *s); 

extern int top;

#endif
