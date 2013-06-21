#ifndef __MIPS_H__
#define __MIPS_H__

#include "type.h"
#include "ir.h"
#include <stdio.h>

struct idRegNode {
	char idName[MAX_LABEL_LEN];
	char regName[3];
	int inReg;
	int offset;
	struct idRegNode *next;
};

struct idRegNode *idRegMap[MAX_ID_NUM];
char regMap[MAX_REG_NUM][MAX_LABEL_LEN];

extern void generateMIPS(struct InterCodes *p, FILE *f);

#endif
