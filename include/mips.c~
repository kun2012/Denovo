#include "mips.h"
#include "semantic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int stackoffset = 4;
int regturn = 0;

struct idRegNode *findIdReg(char *idName) {
	int k = hash(idName, MAX_ID_NUM);
	struct idRegNode * p = idRegMap[k];
	while(p != NULL) {
		if (strcmp(p->idName, idName) == 0) return p;
		p = p->next;
	}
	return NULL;
}

struct idRegNode *insertIdReg(char *idName, char *regName, int inReg, int offset) {
	int k = hash(idName, MAX_ID_NUM);
	struct idRegNode *p = idRegMap[k];
	while(p != NULL) {
		if (strcmp(p->idName, idName) == 0) return p;
		p = p->next;
	}
	if (p == NULL) {
		p = (struct idRegNode *)malloc(sizeof(struct idRegNode));
		strcpy(p->idName, idName);
		strcpy(p->regName, regName);
		p->inReg = inReg;
		p->offset = offset;
		p->next = idRegMap[k];
		idRegMap[k] = p;
		return idRegMap[k];
	}else {
		strcpy(p->idName, idName);
		strcpy(p->regName, regName);
		p->inReg = inReg;
		p->offset = offset;
		return p;
	}
}

void getRegName(int num, char *regName) {
	strcpy(regName, "t0");
	if (num < 10) regName[1] = num + 48;
	else {
		regName[0] = 's';
		regName[1] = num - 10 + 48;
	}
}

void genlw(char *regName, int offset, FILE *f) {
	fprintf(f, "lw %s, -%d($fp)\n", regName, offset);
}

void regSpill(char *regName, char *idName, FILE *f) {
	struct idRegNode *p = findIdReg(idName);
	fprintf(f, "sw %s, -%d($fp)\n", regName, p->offset);
}

void allocateReg(struct idRegNode *p, char *regName, FILE *f) {
	int i;
	for (i = 0; i < MAX_REG_NUM; i++) {
		if (strlen(regMap[i]) == 0) {
			strcpy(regMap[i], p->idName);
			getRegName(i, regName);
			strcpy(p->regName, regName);
			p->inReg = 1;
			genlw(regName, p->offset, f);
			return ;
		}
	}
	getRegName(regturn, regName);
	regSpill(regName, regMap[regturn], f);
	strcpy(p->regName, regName);
	p->inReg = 1;
	genlw(regName, p->offset, f);
	regturn++;
}

void getReg(char *idName, char *regName, FILE *f) {
	struct idRegNode *p = findIdReg(idName);
	if (p != NULL) {
		if (p->inReg)
			strcpy(regName, p->regName);
		else
			allocateReg(p, regName, f);
		return ;
	}
	stackoffset += 4;
	p = insertIdReg(idName, "", 0, stackoffset);
	allocateReg(p, regName, f);
}


void printData(FILE *f) {
	fprintf(f, ".data\n_prompt: .asciiz \"Enter an integer:\"\n");
	fprintf(f, "_ret: .asciiz \"\\n\"\n.globl main\n");
	fprintf(f, ".text\n");
}

void printRead(FILE *f) {
	fprintf(f, "read:\nli $v0, 4\nla $a0, _prompt\n");
	fprintf(f, "syscall\nli $v0, 5\nsyscall\njr $ra\n\n");
}

void printWrite(FILE *f) {
	fprintf(f, "write:\nli $v0, 1\nsyscall\nli $v0, 4\n");
	fprintf(f, "la $a0, _ret\nsyscall\nmove $v0, $0\njr $ra\n\n");
}

void printInstruction(struct InterCodes *p, FILE *f) {
	int argnum, paranum;
	char reg1[MAX_LABEL_LEN], reg2[MAX_LABEL_LEN], reg3[MAX_LABEL_LEN];
	switch(p->code.kind) {
		case LABEL:
			fprintf(f, "%s:\n", p->code.u.oneop.op1->u.s);
			break;
		case FUNCTION:
			
			break;
		case PARAM:
			break;
		case ARG:
			break;
		case ASSIGN:
			getReg(p->code.u.assign.left->u.s, reg1, f);
			if (p->code.u.assign.left->kind == VARIABLE && 
				p->code.u.assign.right->kind == CONSTANT) {
				fprintf(f, "li %s, %d\n", reg1, p->code.u.assign.right->u.value);
			}
			if (p->code.u.assign.left->kind == VARIABLE &&
				p->code.u.assign.right->kind == VARIABLE){
				getReg(p->code.u.assign.right->u.s, reg2, f);
				fprintf(f, "move %s, %s\n", reg1, reg2);
			}
			if (p->code.u.assign.left->kind == MEM && 
				p->code.u.assign.right->kind == VARIABLE) {
				getReg(p->code.u.assign.right->u.s, reg2, f);
				fprintf(f, "sw %s, 0(%s)\n", reg2, reg1);
				}
			if (p->code.u.assign.left->kind == MEM && 
				p->code.u.assign.right->kind == CONSTANT) {
					getReg(p->code.u.assign.right->u.s, reg2, f);
					fprintf(f, "li $s7, %d\n", p->code.u.assign.right->u.value);
					fprintf(f, "sw $s7, 0(%s)\n", reg1);
				}
			if (p->code.u.assign.left->kind == VARIABLE && 
				p->code.u.assign.right->kind == MEM) {
				getReg(p->code.u.assign.right->u.s, reg2, f);
				fprintf(f, "lw %s, 0(%s)\n", reg1, reg2);
			}
			//ADDRESS
			break;
		case ADD:
			getReg(p->code.u.binop.result->u.s, reg1, f);
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == VARIABLE) {
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "add %s, %s, %s\n", reg1, reg2, reg3);
				}
			if (p->code.u.binop.op1->kind == CONSTANT && 
				p->code.u.binop.op2->kind == VARIABLE) {
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "addi %s, %s, %d\n", reg1, reg3, p->code.u.binop.op1->u.value);
				}
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == CONSTANT) {
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					fprintf(f, "addi %s, %s, %d\n", reg1, reg2, p->code.u.binop.op2->u.value);
				}
			break;
		case SUB:
			getReg(p->code.u.binop.result->u.s, reg1, f);
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == VARIABLE) {
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "sub %s, %s, %s\n", reg1, reg2, reg3);
				}
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == CONSTANT) {
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					fprintf(f, "addi %s, %s, -%d\n", reg1, reg2, p->code.u.binop.op2->u.value);
				}
			if (p->code.u.binop.op1->kind == CONSTANT && 
				p->code.u.binop.op2->kind == VARIABLE) {
					fprintf(f, "li $s7, %d\n", p->code.u.binop.op1->u.value);
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "sub %s, $s7, %s\n", reg1, reg3);
				}
			break;
		case MUL:
			getReg(p->code.u.binop.result->u.s, reg1, f);
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == VARIABLE) {
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "mul %s, %s, %s\n", reg1, reg2, reg3);
				}
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == CONSTANT) {
					fprintf(f, "li $s7, %d\n", p->code.u.binop.op2->u.value);
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					fprintf(f, "mul %s, %s, $s7\n", reg1, reg2);
				}
			if (p->code.u.binop.op1->kind == CONSTANT && 
				p->code.u.binop.op2->kind == VARIABLE) {
					fprintf(f, "li $s7, %d\n", p->code.u.binop.op1->u.value);
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "mul %s, $s7, %s\n", reg1, reg3);
				}
			break;
		case DIV:
			getReg(p->code.u.binop.result->u.s, reg1, f);
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == VARIABLE) {
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "div %s, %s\n", reg2, reg3);
					fprintf(f, "mflo %s\n", reg1);
				}
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == CONSTANT) {
					fprintf(f, "li $s7, %d\n", p->code.u.binop.op2->u.value);
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					fprintf(f, "div %s, $s7\n", reg2);
					fprintf(f, "mflo %s\n", reg1);
				}
			if (p->code.u.binop.op1->kind == CONSTANT && 
				p->code.u.binop.op2->kind == VARIABLE) {
					fprintf(f, "li $s7, %d\n", p->code.u.binop.op1->u.value);
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "div $s7, %s\n", reg3);
					fprintf(f, "mflo %s\n", reg1);
				}
			break;
		case IFGOTO:
			getReg(p->code.u.ifgoto.op1->u.s, reg1, f);
            getReg(p->code.u.ifgoto.op2->u.s, reg2, f);
            if (strcmp(p->code.u.ifgoto.relop->u.s, "==") == 0) {
            	fprintf(f, "beq ");
            }else if (strcmp(p->code.u.ifgoto.relop->u.s, "!=") == 0) {
            	fprintf(f, "bne ");
            }else if (strcmp(p->code.u.ifgoto.relop->u.s, ">") == 0) {
            	fprintf(f, "bgt ");
            }else if (strcmp(p->code.u.ifgoto.relop->u.s, "<") == 0) {
            	fprintf(f, "blt ");
            }else if (strcmp(p->code.u.ifgoto.relop->u.s, ">=") == 0) {
            	fprintf(f, "bge ");
            }else if (strcmp(p->code.u.ifgoto.relop->u.s, "<=") == 0) {
            	fprintf(f, "ble ");
            }
            fprintf(f, "%s, %s, %s\n", reg1, reg2, p->code.u.ifgoto.op3->u.s);
			break;
		case GOTO:
			fprintf(f, "j %s\n", p->code.u.oneop.op1->u.s);
			break;
		case RETURN:
			fprintf(f, "move $v0, %s\n", p->code.u.oneop.op1->u.s);
			fprintf(f, "jr $ra\n");
			break;
		case CALL:
			fprintf(f, "jal %s\n", p->code.u.call.op1->u.s);
			getReg(p->code.u.call.result->u.s, reg1, f);
			fprintf(f, "move %s, $v0\n", reg1);
			break;
		case DEC:
			break;
		case READ:
			break;
		case WRITE:
			break;
	}
}

void generateMIPS(struct InterCodes *p, FILE *f) {
	printData(f);
	printRead(f);
	printWrite(f);
	while(p != NULL) {
		printInstruction(p, f);
		p = p->next;
	}
}
