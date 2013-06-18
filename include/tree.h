#ifndef __TREE_H__
#define __TREE_H__

#include "type.h"

extern struct treeNode* createTreeNode(int l, int t);
extern void printTree(struct treeNode *p);
extern void typePrint(struct treeNode *p);

extern struct treeNode *root;
extern int syntaxError;

#endif
